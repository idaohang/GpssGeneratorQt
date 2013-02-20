#-------------------------------------------------
#
# Project created by QtCreator 2012-11-24T20:51:45
#
#-------------------------------------------------

QT       += core gui

TARGET = GpssGeneratorQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    generatewindow.cpp \
    networkdescriptor.cpp \
    transfermatrixwindow.cpp \
    abstractnavigatablewindow.cpp \
    facilitywindow.cpp \
    threadswindow.cpp \
    nodeswindow.cpp \
    statisticswindow.cpp \
    Generator/UniformFunction.cpp \
    Generator/TriangularFunction.cpp \
    Generator/Terminator.cpp \
    Generator/Statistics.cpp \
    Generator/SingleGenerator.cpp \
    Generator/Router.cpp \
    Generator/ObjectGPSS.cpp \
    Generator/Model.cpp \
    Generator/IntervalStatistics.cpp \
    Generator/Generator.cpp \
    Generator/GaussianFunction.cpp \
    Generator/Function.cpp \
    Generator/Facility.cpp \
    Generator/ExponentialFunction.cpp \
    Generator/Node.cpp \
    Generator/MultipleGenerator.cpp

HEADERS  += mainwindow.h \
    threadswindow.h \
    nodeswindow.h \
    generatewindow.h \
    facilitywindow.h \
    networkdescriptor.h \
    transfermatrixwindow.h \
    abstractnavigatablewindow.h \
    statisticswindow.h \
    Generator/UniformFunction.h \
    Generator/TriangularFunction.h \
    Generator/Statistics.h \
    Generator/SingleGenerator.h \
    Generator/Router.h \
    Generator/ObjectGPSS.h \
    Generator/Node.h \
    Generator/Terminator.h \
    Generator/ExponentialFunction.h \
    Generator/Facility.h \
    Generator/Function.h \
    Generator/GaussianFunction.h \
    Generator/Generator.h \
    Generator/IntervalStatistic.h \
    Generator/Model.h \
    Generator/MultipleGenerator.h

FORMS    +=


TRANSLATIONS =  GeneratorGpssQt_en.ts \
                GeneratorGpssQt_ru.ts
