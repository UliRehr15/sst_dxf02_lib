TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows
CONFIG += c++11


# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH += ../dxflib/Header
INCLUDEPATH += ../sstLibreCAD2Lib/Header
INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ../sst_misc01_lib/Header
INCLUDEPATH += ../sst_rec04_lib/Header
INCLUDEPATH += ./Header


# SOURCES		+= str1_lib1.cpp
HEADERS		+= ./Header/sstDxf02Lib.h

SOURCES		+=  \
#    sst_dxf02_lib1.cpp \
#    sst_dxf02_lib2.cpp \
    sstDxf02Arc.cpp \
    sstDxf02Base.cpp \
    sstDxf02Insert.cpp \
    sstDxf02Read.cpp \
    sstDxf02Block.cpp \
    sstDxf02Layer.cpp \
    sstDxf02Database.cpp \
    sstDxf02EntityType.cpp \
    sstDxf02Write.cpp \
    sstDxf02Main.cpp \
    sstDxf02Vertex.cpp \
    sstDxf02Polyline.cpp \
    sstDxf02Hatch.cpp \
    sstDxf02HatchLoop.cpp \
    sstDxf02HatchEdge.cpp \
    sstDxf02LType.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sst_dxf02_lib_d
}
release{
  TARGET		= sst_dxf02_lib_r
}

DESTDIR     = ../libs

