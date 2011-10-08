#-------------------------------------------------
#
# Project created by QtCreator 2011-09-21T09:21:57
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Toolkit
TEMPLATE = app

INCLUDEPATH += ../Engine/ \
                /opt/local/include
SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    tilesetwindow.cpp \
    mapwidget.cpp \
    propertieswindow.cpp \
    tileselection.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    tilesetwindow.h \
    mapwidget.h \
    propertieswindow.h \
    tileselection.h

LIBS += -L../Engine/Debug -lMap.o -lSprite.o -lGraphics.o -lLog.o -lpng

FORMS    += mainwindow.ui \
    propertieswindow.ui

RESOURCES += \
    ../Resources/resources.qrc
















