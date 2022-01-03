QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Carte.cpp \
    Noble.cpp \
    Partie.cpp \
    Pioche_carte.cpp \
    Plateau.cpp \
    controleur.cpp \
    debug.cpp \
    gamewindow.cpp \
    joueur.cpp \
    main.cpp \
    mainwindow.cpp \
    pioche_noble.cpp

HEADERS += \
    Carte.h \
    Exception.h \
    Noble.h \
    Partie.h \
    Pioche_carte.h \
    Plateau.h \
    controleur.h \
    gamewindow.h \
    global.h \
    joueur.h \
    mainwindow.h \
    pioche_noble.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ressources/.DS_Store \
    ressources/background.jpeg \
    ressources/cartes.json \
    ressources/cartes/1.png \
    ressources/cartes/10.png \
    ressources/cartes/11.png \
    ressources/cartes/12.png \
    ressources/cartes/13.png \
    ressources/cartes/14.png \
    ressources/cartes/15.png \
    ressources/cartes/2.png \
    ressources/cartes/3.png \
    ressources/cartes/4.png \
    ressources/cartes/5.png \
    ressources/cartes/6.png \
    ressources/cartes/7.png \
    ressources/cartes/8.png \
    ressources/cartes/9.png \
    ressources/deck/1.png \
    ressources/deck/2.png \
    ressources/deck/3.png \
    ressources/gemmes/blanc.png \
    ressources/gemmes/bleu.png \
    ressources/gemmes/noir.png \
    ressources/gemmes/rouge.png \
    ressources/gemmes/vert.png \
    ressources/jetons/blanc.png \
    ressources/jetons/bleu.png \
    ressources/jetons/noir.png \
    ressources/jetons/or.png \
    ressources/jetons/rouge.png \
    ressources/jetons/vert.png \
    ressources/labels.png \
    ressources/nobles.json \
    ressources/nobles/1.png \
    ressources/nobles/10.png \
    ressources/nobles/2.png \
    ressources/nobles/3.png \
    ressources/nobles/4.png \
    ressources/nobles/5.png \
    ressources/nobles/6.png \
    ressources/nobles/7.png \
    ressources/nobles/8.png \
    ressources/nobles/9.png \
    ressources/ready/cartes/1/0.png \
    ressources/ready/cartes/1/1.png \
    ressources/ready/cartes/1/10.png \
    ressources/ready/cartes/1/11.png \
    ressources/ready/cartes/1/12.png \
    ressources/ready/cartes/1/13.png \
    ressources/ready/cartes/1/14.png \
    ressources/ready/cartes/1/15.png \
    ressources/ready/cartes/1/16.png \
    ressources/ready/cartes/1/17.png \
    ressources/ready/cartes/1/18.png \
    ressources/ready/cartes/1/19.png \
    ressources/ready/cartes/1/2.png \
    ressources/ready/cartes/1/20.png \
    ressources/ready/cartes/1/21.png \
    ressources/ready/cartes/1/22.png \
    ressources/ready/cartes/1/23.png \
    ressources/ready/cartes/1/24.png \
    ressources/ready/cartes/1/25.png \
    ressources/ready/cartes/1/26.png \
    ressources/ready/cartes/1/27.png \
    ressources/ready/cartes/1/28.png \
    ressources/ready/cartes/1/29.png \
    ressources/ready/cartes/1/3.png \
    ressources/ready/cartes/1/30.png \
    ressources/ready/cartes/1/31.png \
    ressources/ready/cartes/1/32.png \
    ressources/ready/cartes/1/33.png \
    ressources/ready/cartes/1/34.png \
    ressources/ready/cartes/1/35.png \
    ressources/ready/cartes/1/36.png \
    ressources/ready/cartes/1/37.png \
    ressources/ready/cartes/1/38.png \
    ressources/ready/cartes/1/39.png \
    ressources/ready/cartes/1/4.png \
    ressources/ready/cartes/1/5.png \
    ressources/ready/cartes/1/6.png \
    ressources/ready/cartes/1/7.png \
    ressources/ready/cartes/1/8.png \
    ressources/ready/cartes/1/9.png \
    ressources/ready/cartes/2/0.png \
    ressources/ready/cartes/2/1.png \
    ressources/ready/cartes/2/10.png \
    ressources/ready/cartes/2/11.png \
    ressources/ready/cartes/2/12.png \
    ressources/ready/cartes/2/13.png \
    ressources/ready/cartes/2/14.png \
    ressources/ready/cartes/2/15.png \
    ressources/ready/cartes/2/16.png \
    ressources/ready/cartes/2/17.png \
    ressources/ready/cartes/2/18.png \
    ressources/ready/cartes/2/19.png \
    ressources/ready/cartes/2/2.png \
    ressources/ready/cartes/2/20.png \
    ressources/ready/cartes/2/21.png \
    ressources/ready/cartes/2/22.png \
    ressources/ready/cartes/2/23.png \
    ressources/ready/cartes/2/24.png \
    ressources/ready/cartes/2/25.png \
    ressources/ready/cartes/2/26.png \
    ressources/ready/cartes/2/27.png \
    ressources/ready/cartes/2/28.png \
    ressources/ready/cartes/2/29.png \
    ressources/ready/cartes/2/3.png \
    ressources/ready/cartes/2/4.png \
    ressources/ready/cartes/2/5.png \
    ressources/ready/cartes/2/6.png \
    ressources/ready/cartes/2/7.png \
    ressources/ready/cartes/2/8.png \
    ressources/ready/cartes/2/9.png \
    ressources/ready/cartes/3/0.png \
    ressources/ready/cartes/3/1.png \
    ressources/ready/cartes/3/10.png \
    ressources/ready/cartes/3/11.png \
    ressources/ready/cartes/3/12.png \
    ressources/ready/cartes/3/13.png \
    ressources/ready/cartes/3/14.png \
    ressources/ready/cartes/3/15.png \
    ressources/ready/cartes/3/16.png \
    ressources/ready/cartes/3/17.png \
    ressources/ready/cartes/3/18.png \
    ressources/ready/cartes/3/19.png \
    ressources/ready/cartes/3/2.png \
    ressources/ready/cartes/3/3.png \
    ressources/ready/cartes/3/4.png \
    ressources/ready/cartes/3/5.png \
    ressources/ready/cartes/3/6.png \
    ressources/ready/cartes/3/7.png \
    ressources/ready/cartes/3/8.png \
    ressources/ready/cartes/3/9.png \
    ressources/ready/nobles/0.png \
    ressources/ready/nobles/1.png \
    ressources/ready/nobles/2.png \
    ressources/ready/nobles/3.png \
    ressources/ready/nobles/4.png \
    ressources/ready/nobles/5.png \
    ressources/ready/nobles/6.png \
    ressources/ready/nobles/7.png \
    ressources/ready/nobles/8.png \
    ressources/ready/nobles/9.png \
    ressources/sprites/cards.jpeg \
    ressources/sprites/chips.jpeg \
    ressources/sprites/deck.jpeg \
    ressources/sprites/gems.png \
    ressources/sprites/nobles.jpeg
