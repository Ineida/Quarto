#-------------------------------------------------
#
# Project created by QtCreator 2019-03-17T23:47:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Quarto
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        sources/main.cpp \
        sources/quarto.cpp \
    sources/Grille.cpp \
    sources/main.cpp \
    sources/Pion.cpp \
    sources/IAbrutale.cpp

HEADERS += \
        Header/quarto.h \
    Header/Grille.h \
    Header/Pion.h \
    Header/jeu.h \
    Header/IAbrutale.h \
    Header/IAoptimisee.h \
    Header/Joueur.h

FORMS += \
        quarto.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
