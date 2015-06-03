#ifndef IOCONTROLER_H
#define IOCONTROLER_H
/**
Yes, you can use the PIC-I/O board (or PIC-SERVO or PIC-STEP) with the
 snap hub if you make the following cable:

 Signal  RJ45                    PIC-I/O JP2
 +12v    1 (orange/white)        9
 RX+     3 (green/white)         3
 TX+     4 (blue)                1
 TX-     5 (blue/white)          2
 RX-     6 (green)               4
 ADR_OUT 7 (brown/white)         5
 GND     8 (brown)               10

 RJ45-2 and JP2-6,7,8 are not connected.

 When using our other boards with the snap hub, you should create a
 daisy-chain (with jumpers JP3,4 & 5 installed on the most distant board)
 as described in the board's documentation.  Then, instead of plugging
 into our SSA-485 converter, you use the cable above to connect JP2 (of
 the board closest to the hub) to Port 1 of the snap hub.  Any snap
 motors you have will then plug into the hub starting at Port 2.  (Note -
you cannot skip ports.)

 Lastly, if you already have a snap hub, you should make sure that the
 internal Motion Basic firmware is version 1.03 (or higher).  If you have
 an older version, you should send it back to us and we can reprogram it
 with the current version which fixes a bug relating to the PIC-I/O.

 Regards,
 Jeff

 JEFFREY KERR, LLC
**/


#include <QObject>
#include <QMap>
#include "picio.h"
#include "nmccom.h"
#include <QDomNode>
#include <QVector>

class IOControler : public QObject
{
    Q_OBJECT
public:
    IOControler();
    IOControler(int id,int addr);
    IOControler(QDomNode node);

    int id();
    bool initialize();
    bool isInitialized();
    QString getErrors();

    void setPWM1(int val);
    void setPWM2(int val);

    QVector<int> readAnalog();
    QVector<bool> readInputBits();
    int numInputs();
    int numOutputs();
    void setOutputs(QVector<bool>);

    bool setMapping(QMap<int,int> inputs, QMap<int,int> outputs);
    QMap<int,int> getInputMap();
    QMap<int,int> getOutputMap();



private:
    int id_;
    byte addr_; // needs to be set
    byte PWM1_val_;//preset to 0
    byte PWM2_val_; //preset to 0
    int numbits_;//set to 12 to represent 0-11
    QMap<int,int> inputToStateMap_;
    QMap<int,int> outputToStateMap_;
    QString error_;
    bool initialized_;
    
};

#endif // IOCONTROLER_H
