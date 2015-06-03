# -------------------------------------------------
# Project created by QtCreator 2011-06-10T00:48:58
# -------------------------------------------------
DEFINES += CONFIRM_ENABLED
QT += core \
    script \
    xml

TARGET = Scanner
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

HEADERS += \
    xygrid.h \
    test/tests.h \
    scannerfunctions.h

SOURCES += main.cpp \ 
    xygrid.cpp \
    test/tests.cpp \
    scannerfunctions.cpp


    
INCLUDEPATH += ../

include(FabConLib.pro)
include(common.pro)
include(shared.pro)
INCLUDEPATH += ../shared/math\
               ../shared/ \
               ../shared/utils



OTHER_FILES += \
    ../media/testxdfl.xdfl \
    ../media/TestScript.js \
    ../media/testConfig.config \
    ../media/testxdfl-test.xdfl \
    ../media/testxdfl-mid.xdfl \
    ../media/JrKerr-Valve.config \
    ../media/JrKerr-Single-deposition.config \
    ../media/JrKerr-Duel-deposition.config
















































