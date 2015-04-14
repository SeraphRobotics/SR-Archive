#include "stlgeneration.h"
#include "stl/stlmesh.h"
#include "stl/stlfile.h"
#include "stl/stlfacet.h"





template <class T>
void addSquareToSTL(int i, int j, XYGrid<T>* grid, STLMesh *mesh,
                    const FAHLoopInXYPlane& OuterLoop,
                    QList<FAHLoopInXYPlane> innerLoops, bool top){

    /** calculated vOuterLoophe 4 points and determin case
     *  p1--p2 -->i x  thesebounds
     *  | \  |
     *  p3--p4         nextbounds
     *  |
     * \|/
     *  j
     *  y
     *
     *
     **/
    FAHVector3 p1,p2,p3,p4,d(0,0,-1);
    bool b1=true,b2=true,b3=true,b4=true;

    int numInBounds=0;
//    int numOnLoop=0;

    p1=vectorFromIJ(i,j,grid->at(i,j),grid->stepSize());
    b1=loopsContain(p1,OuterLoop,innerLoops);
    if(b1){numInBounds++;}

    p2=vectorFromIJ(i+1,j,grid->at(i+1,j),grid->stepSize());
    b2=loopsContain(p2,OuterLoop,innerLoops);
    if(b2){numInBounds++;}

    p3=vectorFromIJ(i,j+1,grid->at(i,j+1),grid->stepSize());
    b3=loopsContain(p3,OuterLoop,innerLoops);
    if(b3){numInBounds++;}

    p4=vectorFromIJ(i+1,j+1,grid->at(i+1,j+1),grid->stepSize());
    b4=loopsContain(p4,OuterLoop,innerLoops);
    if(b4){numInBounds++;}

    if(!top){// if its the bottom set all Z points to 0
        p1.z=0;
        p2.z=0;
        p3.z=0;
        p4.z=0;
        d.z=1;
    }

    FAHLine l12(p1,p2);
    l12.a.z=0;
    l12.b.z=0;
    FAHLine l13(p1,p3);
    l13.a.z=0;
    l13.b.z=0;
    FAHLine l24(p2,p4);
    l24.a.z=0;
    l24.b.z=0;
    FAHLine l34(p3,p4);
    l34.a.z=0;
    l34.b.z=0;
    QList<FAHLine> lines;
    lines.append(l12);
    lines.append(l13);
    lines.append(l24);
    lines.append(l34);


    QVector<FAHVector3> outerpoints;
    for(int k=0;k<OuterLoop.points.size(); k++){
        if ((OuterLoop.points[k].x > p1.x) &&
            (OuterLoop.points[k].x < p4.x) &&
            (OuterLoop.points[k].y > p1.y) &&
            (OuterLoop.points[k].y < p4.y) ){
            outerpoints.append(OuterLoop.points[k]);
        }
    }

    QVector<FAHVector3> innerpoints;
    for(int l=0; l<innerLoops.size();l++){
        for(int k=0;k<innerLoops[l].points.size(); k++){
            if ((OuterLoop.points[k].x > p1.x) &&
                (OuterLoop.points[k].x < p4.x) &&
                (OuterLoop.points[k].y > p1.y) &&
                (OuterLoop.points[k].y < p4.y) ){
                innerpoints.append(OuterLoop.points[k]);
            }
        }
    }


    QVector<FAHVector3> intersected;
    QVector<FAHVector3> points;
    QVector<FAHVector3> sorted_points;
    FAHVector3 anchor_main(0,0,0), anchor_left(0,0,0), anchor_right(0,0,0);
    FAHVector3 anchor1(0,0,0), anchor2(0,0,0);
    FAHVector3 anchor(0,0,0);

    switch(numInBounds){
    case 4:
        addFacetWithDirection(p1,p2,p4,mesh,d);
        addFacetWithDirection(p1,p3,p4,mesh,d);
        break;
    case 3:
        intersected = intersection_points(lines,OuterLoop,innerLoops);
        points = outerpoints;
        points =points + innerpoints;
        points =points + intersected;


        if(!b4){
            anchor_main = p1;
            anchor_left = p2;
            anchor_right = p3;
            sorted_points = sortByIndex(points,0,false);
        }else if(!b3){
            anchor_main = p2;
            anchor_left = p4;
            anchor_right = p1;
            sorted_points = sortByIndex(points,1,false);
        }else if(!b2){
            anchor_main = p3;
            anchor_left = p1;
            anchor_right = p4;
            sorted_points = sortByIndex(points,1,true);
        }else if(!b1){
            anchor_main = p4;
            anchor_left = p3;
            anchor_right = p2;
            sorted_points = sortByIndex(points,0,true);
//            break;
        }
        for(int m=0; m<sorted_points.size()-1; m++){
            addFacetWithDirection(anchor_main,sorted_points[m],sorted_points[m+1],mesh,d);
        }
        addFacetWithDirection(anchor_main, anchor_left, sorted_points.last(), mesh, d);
        addFacetWithDirection(anchor_main, anchor_right, sorted_points.first(), mesh, d);

        break;
    case 2:
        intersected = intersection_points(lines,OuterLoop,innerLoops);
        points = outerpoints;
        points =points + innerpoints;
        points = points + intersected;

        if(b1&&b2){
            anchor1 = p1;
            anchor2 = p2;
            sorted_points = sortByIndex(points,0,false);
        }else if(b2&&b4){
            anchor1 = p2;
            anchor2 = p4;
            sorted_points = sortByIndex(points,1,false);
        }else if(b1&&b3){
            anchor1 = p1;
            anchor2 = p3;
            sorted_points = sortByIndex(points,1,false);
        }else if(b3&&b4){
            anchor1 = p3;
            anchor2 = p4;
            sorted_points = sortByIndex(points,0,false);
        }
        for(int m=0; m<sorted_points.size()-1; m++){
            addFacetWithDirection(anchor1,sorted_points[m],sorted_points[m+1],mesh,d);
        }
        addFacetWithDirection(anchor1,anchor2,sorted_points.last(),mesh,d);

        break;
    case 1:

        intersected = intersection_points(lines,OuterLoop,innerLoops);
//        for(int k=0;k<intersected.size(); k++){
//            qDebug()<<"I: "<<intersected[k].x<<","<<intersected[k].y<<","<<intersected[k].z;
////            intersected[k].z=getHeightAt(intersected[k].x,intersected[k].y,grid);
//        }
        points = intersected;
        points = points + outerpoints;
        points = points + innerpoints;


//        qDebug()<<"N=1: ";
//        qDebug()<<"points: "<<points.size();
//        qDebug()<<"\touterpoints: "<<outerpoints.size();
//        qDebug()<<"\tinnerpoints: "<<innerpoints.size();
//        qDebug()<<"\tintersected points:" <<intersected.size();

        if(b1){
            sorted_points = sortByIndex(points,0,false);
            anchor = p1;
        }else if(b2){
            sorted_points = sortByIndex(points,0,false);
            anchor = p2;
        }else if(b3){
            sorted_points = sortByIndex(points,1,false);
            anchor = p3;
        }else if(b4){
            sorted_points = sortByIndex(points,1,false);
            anchor = p4;
        }

//        qDebug()<<"Sorted size:"<<sorted_points.size();


        for(int m=0; m<sorted_points.size()-1; m++){
            addFacetWithDirection(anchor,sorted_points[m],sorted_points[m+1],mesh,d);
        }
        break;
    default:
        break;

    }



}



void addChannelToSTL(int i, int j, XYGrid<float>* grid, STLMesh* mesh, const FAHLoopInXYPlane &OuterLoop, QList<FAHLoopInXYPlane> innerLoops, kChannelType type, float depth){
    FAHVector3 p1,p2,p3,p4,d(0,0,-1);
    FAHVector3 d1,d2,d3,d4;
    bool b1=true,b2=true,b3=true,b4=true;

    int numInBounds=0;

    p1=vectorFromIJ(i,j,grid->at(i,j),grid->stepSize());
    d1=p1;
    d1.z=p1.z-depth;
    b1=loopsContain(p1,OuterLoop,innerLoops);
    if(b1){numInBounds++;}

    p2=vectorFromIJ(i+1,j,grid->at(i+1,j),grid->stepSize());
    d2=p2;
    d2.z=p2.z-depth;
    b2=loopsContain(p2,OuterLoop,innerLoops);
    if(b2){numInBounds++;}

    p3=vectorFromIJ(i,j+1,grid->at(i,j+1),grid->stepSize());
    d3=p3;
    d3.z=p3.z-depth;
    b3=loopsContain(p3,OuterLoop,innerLoops);
    if(b3){numInBounds++;}

    p4=vectorFromIJ(i+1,j+1,grid->at(i+1,j+1),grid->stepSize());
    d4=p4;
    d4.z=p4.z-depth;
    b4=loopsContain(p4,OuterLoop,innerLoops);
    if(b4){numInBounds++;}


    if(numInBounds<4){
        addSquareToSTL(i,j,grid, mesh, OuterLoop, innerLoops,true);
        return;
    }

        addFacetWithDirection(d1,d2,d4,mesh,d);
        addFacetWithDirection(d1,d3,d4,mesh,d);
        /** calculated vOuterLoophe 4 points and determin case
         *  p1--p2 -->i x  thesebounds
         *  | \  |
         *  p3--p4         nextbounds
         *  |
         * \|/
         *  j
         *  y
         *
         *
         **/
        //enum kChannelType{sqr,left,right,top,bottom,tlc,trc,brc,blc};
        //ctb,clr,cltb,crtb
        QList<kChannelType> types;
        if(type==ctlc){
            types.append(cleft);
            types.append(ctop);

        }else if(type == ctrc){
            types.append(cright);
            types.append(ctop);

        }else if(type == cbrc){
            types.append(cright);
            types.append(cbottom);

        }else if(type == cblc){
            types.append(cleft);
            types.append(cbottom);

        }else if(type == ctb){
            types.append(ctop);
            types.append(cbottom);

        }else if(type == clr){
            types.append(cleft);
            types.append(cright);

        }else if(type == cltb){
            types.append(cleft);
            types.append(ctop);
            types.append(cbottom);

        }else if(type == crtb){
            types.append(cright);
            types.append(ctop);
            types.append(cbottom);

        }else{
            types.append(type);
        }

        QListIterator<kChannelType> t(types);

        while (t.hasNext()){
            kChannelType next = t.next();
            if(ctop == next){
                d=FAHVector3(0,-1,0);
                addFacetWithDirection(p1,d1,d2,mesh,d);
                addFacetWithDirection(p1,p2,d2,mesh,d);
            }else if(cbottom==next){
                d=FAHVector3(0,1,0);
                addFacetWithDirection(p3,d3,d4,mesh,d);
                addFacetWithDirection(p3,p4,d4,mesh,d);
            }else if(cleft==next){
                d=FAHVector3(-1,1,0);
                addFacetWithDirection(p1,d1,d3,mesh,d);
                addFacetWithDirection(p1,p3,d3,mesh,d);
            }else if(cright==next){
                d=FAHVector3(1,0,0);
                addFacetWithDirection(p2,d2,d4,mesh,d);
                addFacetWithDirection(p2,p4,d4,mesh,d);
            }
        }
}


template <class T>
STLMesh* makeSTLfromScan(XYGrid<T>* grid ){
    STLMesh* mesh= new STLMesh();
    for(int j=0;j<grid->ny()-1;j++){
        for(int i=0;i<grid->nx()-1;i++){
            /** calculated vectors of the 4 points and determin case
             *  p1--p2 -->i x  thesebounds
             *  | \  |
             *  p3--p4         nextbounds
             *  |
             * \|/
             *  j
             *  y
             *
             *
             **/
            FAHVector3 p1,p2,p3,p4;
            FAHVector3 p1prime,p2prime,p3prime,p4prime;


            p1=vectorFromIJ(i,j,grid->at(i,j),grid->stepSize());
            p1prime = FAHVector3(&p1);
            p1prime[2]=0;


            p2=vectorFromIJ(i+1,j,grid->at(i+1,j),grid->stepSize());
            p2prime = FAHVector3(&p2);
            p2prime[2]=0;


            p3=vectorFromIJ(i,j+1,grid->at(i,j+1),grid->stepSize());
            p3prime = FAHVector3(&p3);
            p3prime[2]=0;


            p4=vectorFromIJ(i+1,j+1,grid->at(i+1,j+1),grid->stepSize());
            p4prime = FAHVector3(&p4);
            p4prime[2]=0;


            /// Generate top and bottom

            /** MAKE TRIANGLES
             *  p1--p2 --> x
             *  | \ |
             *  p3--p4
             *   |
             *  \|/
             *   Y
             *
             *  x Z
             *  STLs use right hand rule to determin normal
             **/
            /// Make Triangles  p1-p4-p3 and p2-p4-p1 which form the top
            addFacetToSTL(p1,p4,p3,mesh);
            addFacetToSTL(p2,p4,p1,mesh);

            /// Make Triangles p4'-p1'-p3' and p4'-p2'-p1' with Zs=0 to form bottom
            addFacetToSTL(p4prime,p1prime,p3prime,mesh);
            addFacetToSTL(p4prime,p2prime,p1prime,mesh);

            /// BOUNDARIES
            /// NEED CASSES FOR i=0,j=0,i=nx-1,j=ny-1 to make walls
            if ( (0==j) ){ // FRONT section
                /**
                 * p1--p2
                 *  | \ |
                 * p1'--p2'
                 *
                 * need facets p1-p1'-p2' ,   p2-p1-p2'
                **/
                addFacetToSTL(p1,p1prime,p2prime,mesh);
                addFacetToSTL(p2,p1,p2prime,mesh);
            }
            if ( ((grid->ny()-2)==j) ){//BACK
                /**
                 * p3--p4
                 *  | \ |
                 * p3'--p4'
                 *
                 * need facets p3-p3'-p4' ,   p4-p3-p4'
                **/
                addFacetToSTL(p3,p3prime,p4prime,mesh);
                addFacetToSTL(p4,p3,p4prime,mesh);
            }




            if (0==i){//LEFT
                /**
                 * p1--pb
                 *  | \ |
                 * p1'--pb'
                 *
                 * need facets p1-p1'-pb' ,   pb-p1'-pb'
                **/
                FAHVector3 pb, pbprime;
                pb=vectorFromIJ(i,j+1,grid->at(i,j+1),grid->stepSize());
                pbprime = FAHVector3(&pb);
                pbprime[2]=0;

                addFacetToSTL(p1,p1prime,pbprime,mesh);
                addFacetToSTL(pb,p1,pbprime,mesh);
            }
            if (grid->nx()-2==i){//RIGHT
                /**
                 * p2--p4
                 *  | \ |
                 * p2'--p4'
                 *
                 * need facets p1-p1'-pb' ,   pb-p1-pb'
                **/
                addFacetToSTL(p4prime,p4,p2,mesh);
                addFacetToSTL(p2,p2prime,p4prime,mesh);
            }
        }
    }
    return mesh;
}

void addFacetWithNormal(FAHVector3 p1, FAHVector3 p2, FAHVector3 p3, STLMesh* mesh, bool zpositive){
    FAHTriangle t1(p1,p2,p3);
    STLFacet s1;
    if(((t1.normal().z>0)&&zpositive)||((t1.normal().z<0)&&!zpositive)){

        s1.triangle=t1;
        s1.normal=t1.normal();
    }else{
        FAHTriangle t2(p1,p3,p2);
        s1.triangle=t2;
        s1.normal=t2.normal();
    }
    if(!s1.normal.isInvalid()){
        mesh->AddFacet(s1);
    }

}

void addFacetWithDirection(FAHVector3 p1,FAHVector3 p2,FAHVector3 p3,STLMesh* mesh, FAHVector3 direction){
    FAHTriangle t1(p1,p2,p3);
    STLFacet s1;
    bool used1=false;
    if( (t1.normal().dot(direction))<0){
        used1=true;
        s1.triangle=t1;
        s1.normal=t1.normal();
    }else{
        FAHTriangle t2(p1,p3,p2);
        s1.triangle=t2;
        s1.normal=t2.normal();
    }
    if(!s1.normal.isInvalid()){
        mesh->AddFacet(s1);
    }else{
        printf("\nERROR IN NORMAL\t used:%s",(used1?"1":"2"));
        printPoint(p1);
        printPoint(p2);
        printPoint(p3);
    }
}




template <class T>
void addLoopToSTL(const FAHLoopInXYPlane& loop, XYGrid<T>* grid, STLMesh* mesh , bool inner){
    FAHLoopInXYPlane newloop;
    float ds = 10;

    for(int i=1;i<loop.points.size()+1;i++){
        FAHLine line(loop.points.at(i-1),loop.points.at(i%loop.points.size()));
        newloop.add(line.a);
        bool inseg = true;
        int j=0;
        while(inseg && (j<10000)){
            j++;
            FAHVector3 ab = (line.b.copy().sub(line.a));
            ab.normalize();
            ab*=j*ds;
            FAHVector3 pt= line.a.copy()+=ab;
            if(line.pointOnSegment(pt)){
                newloop.add(pt);
//                printf("\n added point");

            }
            else{
//                printf("\n\n Segment");
//                printPoint(line.a);
//                printPoint(line.b);
//                printPoint(pt);
                inseg=false;
            }
        }

    }


    // get point values
    QVector<FAHVector3> points(newloop.points.size());
    QVector<FAHVector3> primepoints(newloop.points.size());
    for(int k=0;k<points.size();k++){
        points[k]=newloop.points.at(k).copy();
        primepoints[k]=newloop.points.at(k).copy();
        primepoints[k].z=0;
        points[k].z=getHeightAt(points[k].x,points[k].y,grid);
    }


    // Add loop to STL
    for (int i = 1; i < points.size() + 1; i++) {
        FAHVector3 p1,p2,p1p,p2p;
        p1=points[i-1];
        p2=points[i%points.size()];
        p1p=primepoints[i-1];
        p2p=primepoints[i%points.size()];

        FAHTriangle t1(p1,p2,p2p);
        FAHVector3 testpt = p1.copy().add(t1.normal());
        bool contains = loop.pointInside(testpt);
        if(!inner){
            if(contains){
                addFacetToSTL(p2p,p2,p1,mesh);
                addFacetToSTL(p1,p1p,p2p,mesh);
            }else{
                addFacetToSTL(p1,p2,p2p,mesh);
                addFacetToSTL(p2p,p1p,p1,mesh);
            }
        }else{
            if(!contains){
                addFacetToSTL(p2p,p2,p1,mesh);
                addFacetToSTL(p1,p1p,p2p,mesh);
            }else{
                addFacetToSTL(p1,p2,p2p,mesh);
                addFacetToSTL(p2p,p1p,p1,mesh);
            }
        }

    }




}

//enum kChannelType{csqr,cleft,cright,ctop,cbottom,ctlc,ctrc,cbrc,cblc};
STLMesh* STLFromSection(XYGrid<float>* grid,const FAHLoopInXYPlane& OuterLoop, FAHLoopInXYPlane angleLoop, QList<FAHLoopInXYPlane> innerLoop){
    STLMesh* mesh= new STLMesh();

    QMap<int,QVector<int> > map;

    QVector<int> row1(3,10); //J
    row1[1]=44;
    row1[2]=66;
    map[10]=row1;

    float offset=10;
    QVector<int> row2(3,20);//T
    row2[1]=34-offset;
    row2[2]=68-offset;
    map[20]=row2;

    QVector<int> row3(3,30);//AD
    row3[1]=29-offset;
    row3[2]=74-offset;
    map[30]=row3;

    QVector<int> row4(3,40);//AN
    row4[1]=25-offset;
    row4[2]=78-offset;
    map[40]=row4;

    QVector<int> row5(3,50);//AX
    row5[1]=24-offset;
    row5[2]=80-offset;
    map[50]=row5;

    QVector<int> row6(3,60);//BH
    row6[1]=22-offset;
    row6[2]=80-offset;
    map[60]=row6;

    QVector<int> row7(3,70);//BR
    row7[1]=22-offset;
    row7[2]=80-offset;
    map[70]=row7;

    QVector<int> row8(3,80);//CB
    row8[1]=18-offset;
    row8[2]=80-offset;
    map[80]=row8;

    QVector<int> row9(3,90);//CL
    row9[1]=18-offset;
    row9[2]=80-offset;
    map[90]=row9;

    QVector<int> row10(3,100);//CV
    row10[1]=18-offset;
    row10[2]=80-offset;
    map[100]=row10;

    QVector<int> row11(3,110);//DF
    row11[1]=18-offset;
    row11[2]=80-offset;
    map[110]=row11;

    QVector<int> row12(3,120);//DP
    row12[1]=18-offset;
    row12[2]=80-offset;
    map[120]=row12;

    QVector<int> row13(3,130);//DP
    row13[1]=18-offset;
    row13[2]=80-offset;
    map[130]=row13;

    QVector<int> row14(3,140);//EJ
    row14[1]=18-offset;
    row14[2]=80-offset;
    map[140]=row14;

    QVector<int> row15(3,150);//ET
    row15[1]=21-offset;
    row15[2]=80-offset;
    map[150]=row15;

    QVector<int> row16(3,160);//FD
    row16[1]=23-offset;
    row16[2]=75-offset;
    map[160]=row16;

    QVector<int> row17(3,170);//FN
    row17[1]=27-offset;
    row17[2]=65-offset;
    map[170]=row17;




    QList<int> keys = map.keys();
    kChannelType type;

    for(int j=0;j<grid->ny()-1;j++){
        for(int i=0;i<grid->nx()-1;i++){
            float depth = .8;

            // j, i_max, i_min


            if(keys.contains(j)){
                QVector<int> row = map[j];

                if( (i<row[2]) && (i>row[1]) ){
                    type= ctb;
                    addChannelToSTL(i,j,grid,mesh, OuterLoop, innerLoop, type, depth);
                }else if( (i==row[2]) ){
                    type= crtb;
                    addChannelToSTL(i,j,grid,mesh, OuterLoop, innerLoop, type, depth);
                }else if( (i==row[1]) ){
                    type= cltb;
                    addChannelToSTL(i,j,grid,mesh, OuterLoop, innerLoop, type, depth);
                }else{
                    addSquareToSTL(i,j,grid, mesh, OuterLoop, innerLoop,true);
                }
            }else{
                addSquareToSTL(i,j,grid, mesh, OuterLoop, innerLoop,true);
            }
            addSquareToSTL(i,j,grid, mesh, angleLoop, innerLoop,false);
        }
    }
    return mesh;
}



template <class T>
STLMesh* makeSTLfromScanSection(XYGrid<T>* grid, const FAHLoopInXYPlane& OuterLoop, QList<FAHLoopInXYPlane> innerLoops){
    STLMesh* mesh= new STLMesh();
    // Construct triangles for top and bottom


    for(int j=0;j<grid->ny()-1;j++){
        for(int i=0;i<grid->nx()-1;i++){
            /** calculated vOuterLoophe 4 points and determin case
             *  p1--p2 -->i x  thesebounds
             *  | \  |
             *  p3--p4         nextbounds
             *  |
             * \|/
             *  j
             *  y
             *
             *
             **/
            FAHVector3 p1,p2,p3,p4;
            FAHVector3 p1prime,p2prime,p3prime,p4prime;
            bool b1=true,b2=true,b3=true,b4=true;
            //bool l1=false, l2=false, l3=false, l4=false;
            int numInBounds=0;
            //int numOnLoop=0;

            p1=vectorFromIJ(i,j,grid->at(i,j),grid->stepSize());
            p1prime = FAHVector3(&p1);
            p1prime[2]=0;
            b1=loopsContain(p1,OuterLoop,innerLoops);
            //l1=onLoops(p1,OuterLoop,innerLoops);
            if(b1){numInBounds++;}
            //if(l1){numOnLoop++;}

            p2=vectorFromIJ(i+1,j,grid->at(i+1,j),grid->stepSize());
            p2prime = FAHVector3(&p2);
            p2prime[2]=0;
            b2=loopsContain(p2,OuterLoop,innerLoops);
            //l2=onLoops(p1,OuterLoop,innerLoops);
            if(b2){numInBounds++;}
            //if(l2){numOnLoop++;}


            p3=vectorFromIJ(i,j+1,grid->at(i,j+1),grid->stepSize());
            p3prime = FAHVector3(&p3);
            p3prime[2]=0;
            b3=loopsContain(p3,OuterLoop,innerLoops);
            //l3=onLoops(p1,OuterLoop,innerLoops);
            if(b3){numInBounds++;}
            //if(l3){numOnLoop++;}

            p4=vectorFromIJ(i+1,j+1,grid->at(i+1,j+1),grid->stepSize());
            p4prime = FAHVector3(&p4);
            p4prime[2]=0;
            b4=loopsContain(p4,OuterLoop,innerLoops);
            //l4=onLoops(p4,OuterLoop,innerLoops);
            if(b4){numInBounds++;}
            //if(l4){numOnLoop++;}



//            printf("\n\nGrid:%i,%i\tX:%.1f - %.1f\tY:%.1f-%.1f",
//                   i,j,p1.x,p4.x,p1.y,p4.y);

//            printf("\n Case:%i \tb1:%s\tb2:%s\tb3:%s\tb4:%s",numInBounds,
//                   (b1)?"true":"false",
//                   (b2)?"true":"false",
//                   (b3)?"true":"false",
//                   (b4)?"true":"false");


            /// THere are 5 cases 0,1,2,3,4 points are in bound
            /// for case 0 do nothing


            if(4==numInBounds){
                /// Make Triangles  p1-p4-p3 and p2-p4-p1 which form the top
                addFacetToSTL(p1,p4,p3,mesh);
                addFacetToSTL(p2,p4,p1,mesh);

                /// Make Triangles p4'-p1'-p3' and p4'-p2'-p1' with Zs=0 to form bottom
                addFacetToSTL(p4prime,p1prime,p3prime,mesh);
                addFacetToSTL(p4prime,p2prime,p1prime,mesh);
            }else if(1<=numInBounds){
                // All other cases
                bool fromOuterloop = false;
                FAHVector3 direction;


                QVector<FAHVector3> allpoints;
                QVector<FAHVector3> points;

                fromOuterloop= getPointsInGrid(i,j,grid->stepSize(),OuterLoop,innerLoops,&allpoints);
                QList<FAHVector3> gridpoints;
                gridpoints.append(p1);
                gridpoints.append(p2);
                gridpoints.append(p3);
                gridpoints.append(p4);
                for(int k=0;k<allpoints.size();k++){
                    allpoints[k].z=getHeightAt(allpoints[k].x,allpoints[k].y,p1,p2,p3,p4);
                }

                /// get rid of overlap

                removePointsIfInList(&allpoints,&points,gridpoints);

                QVector<FAHVector3> primepoints(points);
                for(int k=0;k<points.size();k++){
                    primepoints[k].z=0;
                }

                QVector<FAHVector3> allprimepoints(allpoints);
                for(int k=0;k<allpoints.size();k++){
                    allprimepoints[k].z=0;
                }

                if(2<=points.size()){
                    if(3==numInBounds){
                        FAHVector3 anchorPt, anchorPtPrime;
                        FAHVector3 leftPt, leftPtPrime;
                        FAHVector3 rightPt, rightPtPrime;
                        FAHVector3 leftBorderPt, leftBorderPtPrime;
                        FAHVector3 rightBorderPt, rightBorderPtPrime;

                        if(!b1){ // anchor to p4
                            direction = p4.copy().sub(p1);
                            anchorPt = p4;
                            anchorPtPrime=p4prime;
                            leftPt=p3;
                            leftPtPrime=p3prime;
                            rightPt=p2;
                            rightPtPrime=p2prime;
                            if(Math::floatsEqual(points.first().x,leftPt.x)){
                                leftBorderPt = points.first();
                                leftBorderPtPrime = primepoints.first();
                                rightBorderPt = points.last();
                                rightBorderPtPrime=primepoints.last();

                            }else if (Math::floatsEqual(points.last().x,leftPt.x)){
                                rightBorderPt = points.first();
                                rightBorderPtPrime = primepoints.first();
                                leftBorderPt = points.last();
                                leftBorderPtPrime=primepoints.last();
                            }

                        }else if (!b2){
                            direction = p3.copy().sub(p2);
                            anchorPt = p3;
                            anchorPtPrime=p3prime;
                            leftPt=p1;
                            leftPtPrime=p1prime;
                            rightPt=p4;
                            rightPtPrime=p4prime;
                            if(Math::floatsEqual(points.first().y,leftPt.y)){
                                leftBorderPt = points.first();
                                leftBorderPtPrime = primepoints.first();
                                rightBorderPt = points.last();
                                rightBorderPtPrime=primepoints.last();

                            }else {//if (Math::floatsEqual(points.last().y,leftPt.y)){
                                rightBorderPt = points.first();
                                rightBorderPtPrime = primepoints.first();
                                leftBorderPt = points.last();
                                leftBorderPtPrime=primepoints.last();
                            }

                        }else if (!b3){
                            direction = p2.copy().sub(p3);
                            anchorPt = p2;
                            anchorPtPrime=p2prime;
                            leftPt=p4;
                            leftPtPrime=p4prime;
                            rightPt=p1;
                            rightPtPrime=p1prime;
                            if(Math::floatsEqual(points.first().y,leftPt.y)){
                                leftBorderPt = points.first();
                                leftBorderPtPrime = primepoints.first();
                                rightBorderPt = points.last();
                                rightBorderPtPrime=primepoints.last();

                            }else {//if (Math::floatsEqual(points.last().y,leftPt.y)){
                                rightBorderPt = points.first();
                                rightBorderPtPrime = primepoints.first();
                                leftBorderPt = points.last();
                                leftBorderPtPrime=primepoints.last();
                            }

                        }else if (!b4){
                            direction = p1.copy().sub(p4);
                            anchorPt = p1;
                            anchorPtPrime=p1prime;
                            leftPt=p2;
                            leftPtPrime=p2prime;
                            rightPt=p3;
                            rightPtPrime=p3prime;
                            if(Math::floatsEqual(points.first().x,leftPt.x)){
                                leftBorderPt = points.first();
                                leftBorderPtPrime = primepoints.first();
                                rightBorderPt = points.last();
                                rightBorderPtPrime=primepoints.last();

                            }else {//if (Math::floatsEqual(points.last().x,leftPt.x)){
                                rightBorderPt = points.first();
                                rightBorderPtPrime = primepoints.first();
                                leftBorderPt = points.last();
                                leftBorderPtPrime=primepoints.last();
                            }

                        }
                        //ADD TOP AND BOTTOM
                        for(int k=0;k<points.size()-1;k++){
                            addFacetWithNormal(points[k+1],points[k],anchorPt,mesh,true);
                            addFacetWithNormal(anchorPtPrime,primepoints[k],primepoints[k+1],mesh,false);
                        }
                        addFacetWithNormal(leftBorderPt,anchorPt,leftPt,mesh,true);
                        addFacetWithNormal(leftPtPrime,anchorPtPrime,leftBorderPtPrime,mesh,false);

                        addFacetWithNormal(rightBorderPt,rightPt,anchorPt,mesh,true);
                        addFacetWithNormal(anchorPtPrime,rightPtPrime,rightBorderPtPrime,mesh,false);

//                        for(int k=0;k<points.size()-1;k++){
//                            addFacetWithDirection(points[k],points[k+1],primepoints[k],mesh,direction);
//                            addFacetWithDirection(points[k+1],primepoints[k+1],primepoints[k],mesh,direction);
//                        }
//                        addFacetWithDirection(leftPt,leftBorderPt,leftBorderPtPrime, mesh,direction);
//                        addFacetWithDirection(leftBorderPtPrime, leftPtPrime,leftPt, mesh,direction);

//                        addFacetWithDirection(rightPt,rightBorderPt, rightBorderPtPrime, mesh,direction);
//                        addFacetWithDirection(rightBorderPtPrime, rightPtPrime,rightPt, mesh,direction);


                    }else if(2==numInBounds){
                    /// 4 sub cases, left,right,top and bottom
                        FAHVector3 anchorPt, anchorPtPrime;
                        FAHVector3 farPt, farPtPrime;
                        FAHVector3 farPtBorder, farPtBorderPrime;

                        if(b2&&b4){// right
                            direction = p2.copy().sub(p1);
                            anchorPt=p4;
                            anchorPtPrime=p4prime;
                            farPt=p2;
                            farPtPrime=p2prime;
                            if(Math::floatsEqual(points.last().y,farPt.y)){
                                farPtBorder=points.last();
                                farPtBorderPrime=primepoints.last();
                            }else{
                                farPtBorder=points.first();
                                farPtBorderPrime=primepoints.first();
                            }

                        }else if(b1&&b3){//left
                            direction = p1.copy().sub(p2);
                            anchorPt=p3;
                            anchorPtPrime=p3prime;
                            farPt=p1;
                            farPtPrime=p1prime;
                            if(Math::floatsEqual(points.last().y,farPt.y)){
                                farPtBorder=points.last();
                                farPtBorderPrime=primepoints.last();
                            }else{
                                farPtBorder=points.first();
                                farPtBorderPrime=primepoints.first();
                            }

                        }else if(b1&&b2){//top
                            direction = p1.copy().sub(p3);
                            anchorPt=p1;
                            anchorPtPrime=p1prime;
                            farPt=p2;
                            farPtPrime=p2prime;
                            if(Math::floatsEqual(points.last().x,farPt.x)){
                                farPtBorder=points.last();
                                farPtBorderPrime=primepoints.last();
                            }else{
                                farPtBorder=points.first();
                                farPtBorderPrime=primepoints.first();
                            }

                        }else if(b3&&b4){//bottom
                            direction = p3.copy().sub(p1);
                            anchorPt=p3;
                            anchorPtPrime=p3prime;
                            farPt=p4;
                            farPtPrime=p4prime;
                            if(Math::floatsEqual(points.last().x,farPt.x)){
                                farPtBorder=points.last();
                                farPtBorderPrime=primepoints.last();
                            }else{
                                farPtBorder=points.first();
                                farPtBorderPrime=primepoints.first();
                            }
                        }
                        //STLs use right hand rule to determin normal

                        for(int k=0;k<points.size()-1;k++){
                            addFacetWithNormal(points[k+1],points[k],anchorPt,mesh,true);
                            addFacetWithNormal(anchorPtPrime,primepoints[k],primepoints[k+1],mesh,false);
                        }
                        addFacetWithNormal(anchorPt,farPt,farPtBorder,mesh,true);
                        addFacetWithNormal(farPtBorderPrime,farPtPrime,anchorPtPrime,mesh,false);


//                        for(int k=0;k<points.size()-1;k++){
//                            addFacetWithDirection(points[k],points[k+1],primepoints[k],mesh,direction);
//                            addFacetWithDirection(points[k+1],primepoints[k+1],primepoints[k],mesh,direction);
//                        }
                        //addFacetWithDirection(leftPt,leftBorderPt,leftBorderPtPrime, mesh,direction);
                        //addFacetWithDirection(leftBorderPtPrime, leftPtPrime,leftPt, mesh,direction);

                        //addFacetWithDirection(rightPt,rightBorderPt, rightBorderPtPrime, mesh,direction);
                        //addFacetWithDirection(rightBorderPtPrime, rightPtPrime,rightPt, mesh,direction);




                    }else if(1==numInBounds){
                        FAHVector3 anchorPt, anchorPtPrime;

                        if(b1){
                            direction = p1.copy().sub(p4);
                            anchorPt=p1;
                            anchorPtPrime=p1prime;
                        }else if(b2){
                            direction = p2.copy().sub(p3);
                            anchorPt=p2;
                            anchorPtPrime=p2prime;
                        }else if(b3){
                            direction = p3.copy().sub(p2);
                            anchorPt=p3;
                            anchorPtPrime=p3prime;
                        }else if(b4){
                            direction = p4.copy().sub(p1);
                            anchorPt=p4;
                            anchorPtPrime=p4prime;
                        }

                        for(int k=0;k<points.size()-1;k++){
                            addFacetWithNormal(points[k+1],points[k],anchorPt,mesh,true);
                            addFacetWithNormal(anchorPtPrime,primepoints[k],primepoints[k+1],mesh,false);
                        }




                    }

                    for(int k=0;k<points.size()-1;k++){
                        addFacetWithDirection(points[k],points[k+1],primepoints[k],mesh,direction);
                        addFacetWithDirection(points[k+1],primepoints[k+1],primepoints[k],mesh,direction);
                    }

                    // ADD LOOP POINTS
//                    for(int k=1; k<allpoints.size(); k++){
//                        addFacetWithDirection(allpoints[k-1],allpoints[k],allprimepoints[k-1],mesh, direction);
//                        addFacetWithDirection(allpoints[k],allprimepoints[k-1],allprimepoints[k],mesh,direction);
//                    }


                }else{

                    printf("\n found %i points",points.size());
                    for(int k=0;k<allpoints.size()-1;k++){
                        direction.operator *=(-1);
                        addFacetWithDirection(allpoints[k],allpoints[k+1],allprimepoints[k],mesh,direction);
                        addFacetWithDirection(allpoints[k+1],allprimepoints[k+1],allprimepoints[k],mesh,direction);
                    }

                }
            }
//            if(1<numOnLoop){
//                FAHVector3 direction;
//                qDebug()<<"onloop at "<<i<<","<<j ;
//                if(l1&&l2){//top
//                    direction = p1.copy().sub(p3);
//                    addFacetWithDirection(p1,p2,p2prime,mesh,direction);
//                    addFacetWithDirection(p2prime,p1prime,p1,mesh,direction);

//                }else if(l2&&l4){//right
//                    direction = p2.copy().sub(p1);
//                    addFacetWithDirection(p2,p4,p4prime,mesh,direction);
//                    addFacetWithDirection(p4prime,p2prime,p2,mesh,direction);
//                }else if(l1&&l3){//left
//                    direction = p1.copy().sub(p2);
//                    addFacetWithDirection(p1,p3,p3prime,mesh,direction);
//                    addFacetWithDirection(p3prime,p1prime,p1,mesh,direction);
//                }else if(l3&&l4){//bottom
//                    direction = p3.copy().sub(p1);
//                    addFacetWithDirection(p3,p4,p4prime,mesh,direction);
//                    addFacetWithDirection(p4prime,p3prime,p3,mesh,direction);
//                }
//            }
        }
    }




    // Construct triangles for the borders.

    //addLoopToSTL(OuterLoop,grid,mesh,false);
    //for(int i=0;i<innerLoops.size();i++){
    //    addLoopToSTL(innerLoops.at(i),grid,mesh,true);
    //}
    return mesh;
}



void addFacetToSTL(FAHVector3 p1,FAHVector3 p2,FAHVector3 p3,STLMesh* mesh){
    /// need to make sure that no 2 vectors are the same or it will not define a plane

        FAHTriangle t1(p1,p2,p3);
        STLFacet s1;
        s1.triangle=t1;
        s1.normal=t1.normal();
        if(!s1.normal.isInvalid()){
            mesh->AddFacet(s1);
       }

}

bool stlToFile(STLMesh* m, QString file){
    STLFile stl;
    stl.SetMesh(m);
    return stl.WriteASCII(file);
}


template void addSquareToSTL(int i, int j, XYGrid<float>* grid,STLMesh* mesh, const FAHLoopInXYPlane& OuterLoop, QList<FAHLoopInXYPlane> innerLoops, bool top);
template void addSquareToSTL(int i, int j, XYGrid<int>* grid,STLMesh* mesh, const FAHLoopInXYPlane& OuterLoop, QList<FAHLoopInXYPlane> innerLoops, bool top);
template STLMesh* makeSTLfromScan(XYGrid<float>* grid );
template STLMesh* makeSTLfromScan(XYGrid<int>* grid );
template STLMesh* makeSTLfromScanSection(XYGrid<float>* grid,const FAHLoopInXYPlane& OuterLoop, QList<FAHLoopInXYPlane> innerLoops);
template STLMesh* makeSTLfromScanSection(XYGrid<int>* grid,const FAHLoopInXYPlane& OuterLoop, QList<FAHLoopInXYPlane> innerLoops);
template void addLoopToSTL(const FAHLoopInXYPlane& loop,XYGrid<float>* grid,STLMesh* mesh, bool inner );
template void addLoopToSTL(const FAHLoopInXYPlane& loop,XYGrid<int>* grid,STLMesh* mesh, bool inner );