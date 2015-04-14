#include "ortho.h"
#include "stlgeneration.h"

FAHLoopInXYPlane angledBase(float theta, float threshold, FAHLoopInXYPlane baseloop){
    qDebug()<<"started";
    QVector<FAHVector3>points = baseloop.points;
    QVector<FAHVector3>new_points;
    new_points += points;

    // Set displacements for the loop
    for (int i = 0; i < points.size(); ++i) {

      //Dont use loop less than threshold
      if(points[i].z<threshold){
          continue;
      }
      float amount = points[i].z*tan(Math::kPi/180*theta);

      int before = i - 1;
      if (before == -1) before = points.size() - 1;
      int after = i + 1;
      if (after == points.size()) after = 0;

      FAHLine before_segment(points[before], points[i]);
      FAHLine after_segment(points[i], points[after]);

      FAHVector3 before_ray = before_segment.ray();
      FAHVector3 after_ray  = after_segment.ray();

      // form the perpendicular displacement vector
      FAHVector3 before_displacement;
      before_displacement.x =  before_ray.y;
      before_displacement.y = -before_ray.x;
      before_displacement.z = 0.0;
      before_displacement.normalize();

      FAHVector3 after_displacement;
      after_displacement.x =  after_ray.y;
      after_displacement.y = -after_ray.x;
      after_displacement.z = 0.0;
      after_displacement.normalize();

      // sum the displacements and adjust the current vertex
      FAHVector3 pt_displacement;
      pt_displacement.set(before_displacement).add(after_displacement);
      pt_displacement.normalize().scale(amount);
      pt_displacement.z=0;
      new_points[i].add(pt_displacement);
    }
    FAHLoopInXYPlane returnloop;
    returnloop.points=new_points;
    for(int i=0;i<new_points.size();i++){
        returnloop.points[i].z=0;
    }
    return returnloop;


//    // Create new points at every location where the loop
//    // self-intersects.
//    { // Creating new points creates new segments, which could each intersect
//      // with other segments and in turn create more points.  The 'filling' variable
//      // is set each loop that  the process changes the set of points.
//      bool filling;
//      do { // terminates once we scan the points and find no intersections
//        filling = false;
//        for (int i = 0; i < new_points.size(); ++i) {
//          FAHLine segment(new_points[i], new_points[(i+1)%new_points.size()]);
//          FAHVector3 pt;
//          for (int j = i+1; j < new_points.size(); ++j) {
//            FAHLine test_segment(new_points[j], new_points[(j+1)%new_points.size()]);
//            if (segment.intersectSegmentWithSegment2DXY(test_segment, &pt) &&
//                !segment.isEndpoint(pt) && !test_segment.isEndpoint(pt)) {
//              new_points.insert(j+1, pt);
//              new_points.insert(i+1, pt); // ORDER MATTERS! j > i
//              filling = true;
//              break;
//            }
//          }
//        }
//      } while (filling);
//    }

//    // next, create loops by pruning out newly created loops
//    QVector<FAHLoopInXYPlane> loops;
//    {
//      FAHLoopInXYPlane new_loop;
//      new_loop.points += new_points;
//      new_points.clear();
//      loops.append(new_loop);
//    }

//    // TODO: speed could be improved by not restarting every time
//    //       a loop is pruned off
////  RESTART_PRUNE:
////    for (int i = 0; i < loops.size(); ++i) {
////      FAHLoopInXYPlane& loop = loops.operator [](i);
////      int loop_size = loop.points.size();
////      for (int j = 0; j < loop_size; ++j) {
////        const FAHVector3& j_point = loop.points.at(j);
////        for (int k = j+1; k < loop_size; ++k) {
////          const FAHVector3& k_point = loop.points.at(k);
////          if (j_point.equals(k_point)) {
////            // form a new loop between these points
////            FAHLoopInXYPlane new_loop;
////            for (int l = j; l < k; ++l) {
////              new_loop.add(loop.points.at(l));
////            }
////            // remove the new loop's points from the original loop;
////            // however, leave one copy (at k) of the duplicate point
////            // in the original loop.  This must be done *before*
////            // the new loop is added, since appending the loop
////            // could change the referenced location
////            loop.points.remove(j, k - j);
////            loops.append(new_loop);
////            qDebug()<<"restarted";
////            goto RESTART_PRUNE;
////          }
////        }
////      }
////    }

////    loops.append(loop);

//    qDebug()<<"done pruning";
//    // now that we have a set of loops, remove any loops that have the
//    // opposite sense of our own loop since these are invalid
//    FAHLoopInXYPlane::Sense my_sense = baseloop.sense();
//    for (int i = loops.size() - 1; i >= 0; --i) {
//      if (loops.at(i).sense() != my_sense) {
//        loops[i].reverse();
//      }
//    }

//    // Finally, get rid of loops that were generated in error.  I'm
//    // not quite sure if this is a correct algorithm, but it should
//    // work as long as the displacement amount isn't huge.
//    // 1. find the biggest loop (greatest area loop) in the list
//    // 2. remove all loops that share a vertex with that loop
//    // 3. remove the loop and add it to the output list
//    // 4. repeat until there are no more loops
////    todo("kwg8", "correctly implement the algorithm for picking valid loops");

//    // The below code doesn't actually implement the above algorithm; it's
//    // set up to do so, but the algorithm written here simply takes the
//    // biggest remaining loop and is done with it.  This means that areas
//    // connected by a narrow passage will NOT be correctly contracted, since
//    // only one of the two regions will be returned.
////    while (!loops.isEmpty()) {
//      int biggest_loop = 0;
//      float biggest_area = loops.at(0).areaEstimate();
//      for (int i = 1; i < loops.size(); ++i) {
//        // find a bigger loop
//        const FAHLoopInXYPlane& bigger_loop = loops.at(i);
//        float area = bigger_loop.areaEstimate();
//        if (area > biggest_area) {
//          biggest_area = area;
//          biggest_loop = i;
//        }
//      }

//      qDebug()<<"ending";
//      return loops.at(biggest_loop);
////      loops.clear();
////    }
////    return loops.first();
}


FAHVector3 CMfromLoop(FAHLoopInXYPlane loop){
    FAHVector3 cm;
    cm=cm.zero();

    if(loop.points.size()<1){return cm;}

    int size = loop.points.size();

    for(int i=0; i<loop.points.size(); i++){
        cm=cm.add(loop.points[i]);
    }

    cm.scale(1.0/size);

    return cm;
}


void makeSides(STLMesh* mesh, FAHLoopInXYPlane outerboarder, FAHLoopInXYPlane trimmed){

    for(int i=0;i<outerboarder.points.size();i++){

        int before = i - 1;
        if (before == -1) before = outerboarder.points.size() - 1;
        int after = i + 1;
        if (after == outerboarder.points.size()) after = 0;
        int current = i;

        FAHVector3 outerpt1 = outerboarder.points[current];
        FAHVector3 outerpt2 = outerboarder.points[after];
        FAHVector3 inner1 = trimmed.points[current];
        FAHVector3 inner2 = trimmed.points[after];

        FAHLine before_segment(trimmed.points[before], inner2);
        FAHLine after_segment(inner1, trimmed.points[after]);

        FAHVector3 ray, norm;

        if(before_segment.length() > after_segment.length()){
            ray = after_segment.ray();
            norm.x =  ray.y;
            norm.y = -ray.x;
            norm.z = 0.0;
        }else{
            ray = before_segment.ray();
            norm.x =  ray.y;
            norm.y = -ray.x;
            norm.z = 0.0;
        }


        if( (inner1.x>0.01) && (inner1.y>0.01) && (inner2.x>0.01) && (inner2.y>0.01)){
            addFacetWithDirection(outerpt1,outerpt2,inner1,mesh,norm);
            addFacetWithDirection(outerpt2,inner2,inner1,mesh,norm);
        }
    }
    //    FAHVector3 cm = CMfromLoop(trimmed);
//    cm.z=0;
//    qDebug()<<"CM x:"<<cm.x<<" y:"<<cm.y;
//    qDebug()<<"Sizes outer:"<<outerboarder.points.size() <<" inner:"<<trimmed.points.size();
//    //makesure z i at zero
//    for(int i=0; i<trimmed.points.size();i++){trimmed.points[i].z=0;}

//    for(int i=1; i<outerboarder.points.size(); i++){
//        FAHVector3 outerpt = outerboarder.points[i];
////        qDebug()<<"outerpt x:"<<outerpt.x<<", y:"<<outerpt.y;
//        int kinner=-1;
//        outerpt.z=0;

//        //Finder intersects

//        FAHLine segment(outerpt,cm);
//        FAHVector3 intersected;
//        int intersectpoint=-1;
//        QVector<int> intersected_ints;

//        for (int j = 0; j < trimmed.points.size()+1; ++j) {
//          FAHLine current_segment(trimmed.points[j-1], trimmed.points[j%trimmed.points.size()]);
//          if (current_segment.intersectSegmentWithSegment2DXY(segment, &intersected) ) {
//              intersected_ints.append(j);
////              qDebug()<<"intersect: "<<j;
//          }
//        }


//        if(intersected_ints.size()>0){
//            //find closest intersect point
//            int closest=-1;
//            float length=100000000;
//            for(int j=0; j< intersected_ints.size(); j++){
//                FAHLine line(outerpt,trimmed.points[intersected_ints[j]]);
//                if(line.length()<length){
//                    length=line.length();
//                    closest=j;
//                }
//            }
//            intersected = trimmed.points[ intersected_ints[closest] ];
//            intersectpoint = intersected_ints[closest];
////            qDebug()<<"found intersect at "<<intersectpoint;


//            FAHLine before_segment(trimmed.points[intersectpoint-1], intersected);
//            FAHLine after_segment(intersected, trimmed.points[intersectpoint]);

//            FAHVector3 ray, norm;

//            if(before_segment.length() > after_segment.length()){
//                kinner = intersectpoint;
//                ray = after_segment.ray();
//                norm.x =  ray.y;
//                norm.y = -ray.x;
//                norm.z = 0.0;
//            }else{
//                kinner = intersectpoint-1;
//                ray = before_segment.ray();
//                norm.x =  ray.y;
//                norm.y = -ray.x;
//                norm.z = 0.0;
//            }

//            FAHVector3 outerpt1 = outerboarder.points[i];
//            FAHVector3 outerpt2 = outerboarder.points[i+1];
//            FAHVector3 inner1 = trimmed.points[kinner];
//            FAHVector3 inner2 = trimmed.points[kinner+1];

//            if( (inner1.x>0.01) && (inner1.y>0.01) && (inner2.x>0.01) && (inner2.y>0.01)){
//                addFacetWithDirection(outerpt1,outerpt2,inner1,mesh,norm);
//                addFacetWithDirection(outerpt2,inner2,inner1,mesh,norm);
//            }
//        }else{
//            qDebug()<<"No intersects";
//        }

//    }


}
