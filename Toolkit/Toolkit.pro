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
    tilesetwindow.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    tilesetwindow.h

LIBS += -L../Engine/Debug -lMap.o -lSprite.o -lGraphics.o -lLog.o -L/opt/local/lib -lpng

FORMS    += mainwindow.ui




