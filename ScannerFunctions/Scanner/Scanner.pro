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
    STLGeneration.h \
        #scannerfunctions.h

SOURCES += main.cpp \ 
    xygrid.cpp \
    test/tests.cpp \
    STLGeneration.cpp\
        #scannerfunctions.cpp


    
INCLUDEPATH += ../

include(common.pro)
include(shared.pro)
INCLUDEPATH += ../shared/math\
               ../shared/ \
               ../shared/utils



OTHER_FILES += \
















































