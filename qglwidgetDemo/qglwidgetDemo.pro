#-------------------------------------------------
#
# Project created by QtCreator 2013-08-10T16:45:03
#
#-------------------------------------------------

QT       += core gui widgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qglwidgetDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

INCLUDEPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v5.0\include"
INCLUDEPATH += "C:\Users\CJlegend\Desktop\openCLstd\ld_opencl_template"

#LIBPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v5.0\Win32"

LIBS += -LC:\Program\ Files\NVIDIA\ GPU\ Computing\ Toolkit\CUDA\v5.0\lib\Win32
LIBS += -lopencl

DEFINES += "__CL_ENABLE_EXCEPTIONS"
