#include "iocontroler.h"


IOControler::IOControler() :id_(0),addr_(0),PWM1_val_(0),PWM2_val_(0), numbits_(12),initialized_(false){
}

IOControler::IOControler(int id, int addr):PWM1_val_(0),PWM2_val_(0), numbits_(12),initialized_(false){
    addr_=(byte) addr;
    id_=id;
    QMap<int,int> input;
    QMap<int,int> output;
    for(int i=0;i<numbits_;i++){
        input[i]=i;
    }
    setMapping(input,output);
    setPWM1(PWM1_val_);
    setPWM2(PWM2_val_);
}

IOControler::IOControler(QDomNode node):initialized_(false){
    PWM1_val_=0;
    PWM2_val_=0;
    numbits_=12;
    QString tempString;
    QDomElement el;
    QMap<int,int> inputmap;
    QMap<int,int> outputmap;


    QDomNodeList actuatorChildren = node.childNodes();
    for (unsigned int i = 0; i < actuatorChildren.length(); i++) {
        QDomNode achild = actuatorChildren.at(i);
        if (achild.isComment() || !achild.isElement()) {continue;}
        if ("id"==achild.nodeName().toLower()) {
            el=achild.toElement();
            tempString=el.text();
            id_=tempString.toUInt();
        } else if ("address"==achild.nodeName().toLower()) {
            el=achild.toElement();
            tempString=el.text();
            addr_ = (byte)tempString.toUInt();
        } else if ("pwm"==achild.nodeName().toLower()){
            //DETERMINE IF PWM is for 1 or 2 and set value
            QDomNodeList pwmChildren = achild.childNodes();
            QDomNode pwmchild;
            int id=0,value=0;
            for (unsigned int j = 0; j < pwmChildren.length(); j++){
                pwmchild = pwmChildren.at(j);
                if ("id"==pwmchild.nodeName().toLower()){
                    el=pwmchild.toElement();
                    tempString=el.text();
                    id=tempString.toUInt();
                }else if("value"==pwmchild.nodeName().toLower()){
                    el=pwmchild.toElement();
                    tempString=el.text();
                    value=tempString.toUInt();
                }
            }
            if (1==id){PWM1_val_=value;}
            else if(2==id){PWM2_val_=value;}
        } else if("digitalio"==achild.nodeName().toLower()){
            QDomNodeList digitalChildren = achild.childNodes();
            QDomNode digchild;
            for (unsigned int j = 0; j < digitalChildren.length(); j++){
                digchild = digitalChildren.at(j);
                if ("numbits"==digchild.nodeName().toLower()){
                    el=digchild.toElement();
                    tempString=el.text();
                    numbits_=tempString.toUInt();
                }else if ("inputmap"==digchild.nodeName().toLower()){
                    QDomNodeList mapChildren = digchild.childNodes();
                    QDomNode keypair;
                    for (int k=0;k<mapChildren.size();k++){
                        keypair = mapChildren.at(k);
                        if ("keypair"==keypair.nodeName().toLower()){
                            QDomNodeList keypairchildren = keypair.childNodes();
                            QDomNode keyelement;
                            int key=0, val=0;
                            for (int l=0;l<keypairchildren.size();l++){
                                keyelement=keypairchildren.at(l);
                                if ("id"==keyelement.nodeName().toLower()){
                                    el=keyelement.toElement();
                                    tempString=el.text();
                                    key=tempString.toUInt();
                                }else if("value"==keyelement.nodeName().toLower()){
                                    el=keyelement.toElement();
                                    tempString=el.text();
                                    val=tempString.toUInt();
                                }
                            }
                            inputmap[key]=val;
                        }
                    }
                }else if ("outputmap"==digchild.nodeName().toLower()){
                    QDomNodeList mapChildren = digchild.childNodes();
                    QDomNode keypair;
                    for (int k=0;k<mapChildren.size();k++){
                        keypair = mapChildren.at(k);
                        if ("keypair"==keypair.nodeName().toLower()){
                            QDomNodeList keypairchildren = keypair.childNodes();
                            QDomNode keyelement;
                            int key=0, val=0;
                            for (int l=0;l<keypairchildren.size();l++){
                                keyelement=keypairchildren.at(l);
                                if ("id"==keyelement.nodeName().toLower()){
                                    el=keyelement.toElement();
                                    tempString=el.text();
                                    key=tempString.toUInt();
                                }else if("value"==keyelement.nodeName().toLower()){
                                    el=keyelement.toElement();
                                    tempString=el.text();
                                    val=tempString.toUInt();
                                }
                            }
                            outputmap[key]=val;
                        }
                    }
                }
            }

        }





    }
    setMapping(inputmap,outputmap);


}

int IOControler::id(){
    return id_;
}
QString IOControler::getErrors(){
    return QString(error_);
}


void IOControler::setPWM1(int val){
    PWM1_val_ =(byte) val;
    if (initialized_){IoSetPWMVal(addr_,PWM1_val_,PWM2_val_,&error_);}
}
void IOControler::setPWM2(int val){
    PWM2_val_ =(byte) val;
    if (initialized_){IoSetPWMVal(addr_,PWM1_val_,PWM2_val_,&error_);}
}

QVector<int> IOControler::readAnalog(){
    byte analog0,analog1,analog2;
    byte status;
    status = SEND_AD1|SEND_AD2|SEND_AD3;
    NmcReadStatus(addr_,status, &error_);
    analog0= IoGetADCVal(addr_,0);
    analog1= IoGetADCVal(addr_,1);
    analog2= IoGetADCVal(addr_,2);
    QVector<int> val(3,0);
    val[0] = (int) analog0;
    val[1] = (int) analog1;
    val[2] = (int) analog2;
    return val;
}

int IOControler::numInputs(){
    return inputToStateMap_.keys().size();
}
int IOControler::numOutputs(){
    return outputToStateMap_.keys().size();
}

QVector<bool> IOControler::readInputBits(){
    int numIn = numInputs();
    QVector<bool> vals(numIn);
    for(int i=0;i<numIn;i++){
        int bit = inputToStateMap_[i];
        vals[i]=IoInBitVal(addr_,bit);
    }
    return vals;
}

void IOControler::setOutputs(QVector<bool> outputs){
    int numOut = numOutputs();
    if (outputs.size()==numOut){
        for(int i=0;i<outputs.size();i++){
            int bit = outputToStateMap_[i];
            if(outputs[i]){
                IoSetOutBit(addr_,bit,&error_);
            }else{
                IoClrOutBit(addr_,bit,&error_);
            }
        }
    }
}


QMap<int,int> IOControler::getInputMap(){
    return QMap<int,int>(inputToStateMap_);
}
QMap<int,int> IOControler::getOutputMap(){
    return QMap<int,int>(outputToStateMap_);
}

bool IOControler::initialize(){
    if (initialized_){return true;}
    if (inputToStateMap_.isEmpty() && outputToStateMap_.isEmpty()){return false;}

    if (!inputToStateMap_.isEmpty()){
        //Set pins to input
        QMapIterator<int, int> i(inputToStateMap_);
        while(i.hasNext()){
            i.next();
            IoBitDirIn(addr_,i.value(),&error_);
        }
    }

    if(!outputToStateMap_.isEmpty()){
        //Set pints to output
        QMapIterator<int, int> j(outputToStateMap_);
        while(j.hasNext()){
            j.next();
            IoBitDirOut(addr_,j.value(),&error_);
        }
    }

    IoSetPWMVal(addr_,PWM1_val_,PWM2_val_,&error_);

    if (error_.isEmpty()){initialized_=true;}
    return initialized_;

}
bool IOControler::isInitialized(){return initialized_;}

bool IOControler::setMapping(QMap<int,int> inputs, QMap<int,int> outputs){
    QList<int> inputStates = inputs.values();
    QList<int> outputStates = outputs.values();
    bool overlap = false;
    bool threshold = false;

    // check for overlap in input and output space
    for (int i=0; i<inputStates.size(); i++){
        threshold = threshold && (inputStates.at(i)<numbits_);
        overlap = overlap && outputStates.contains(inputStates[i]);
    }
    for (int j=0;j<outputStates.size();j++){
        threshold = threshold && (outputStates.at(j)<numbits_);
    }

    //returns false and makes no changes if there is an overlap
    // or if there is a value greater than the pin number
    if (overlap || threshold){return false;}


    if(initialized_){
        //Set pins to input
        QMapIterator<int, int> i(inputs);
        while(i.hasNext()){
            i.next();
            IoBitDirIn(addr_,i.value(),&error_);
        }

        //Set pints to output
        QMapIterator<int, int> j(outputs);
        while(j.hasNext()){
            j.next();
            IoBitDirOut(addr_,j.value(),&error_);
        }
    }


    inputToStateMap_ = inputs;
    outputToStateMap_= outputs;
    return true;
}
