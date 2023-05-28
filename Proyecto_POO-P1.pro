TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        administrador.cpp \
        asiento.cpp \
        boleto.cpp \
        cine.cpp \
        main.cpp \
        pelicula.cpp \
        sala.cpp \
        tiempo.cpp

HEADERS += \
    Terminal.h \
    administrador.h \
    asiento.h \
    boleto.h \
    cine.h \
    pelicula.h \
    sala.h \
    tiempo.h
