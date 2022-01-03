#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "global.h"
#include "Partie.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QString>
#include <QSignalMapper>
#include <string>

class Partie;

namespace Ui {
class GameWindow;
}

class GameWindow_t : public QMainWindow
{
    Q_OBJECT

public:
    //GameWindow_t();
    GameWindow_t(Partie* p);
    ~GameWindow_t();
    void setNom1(QString nom1);
    void setNom2(QString nom2);
    void setNom3(QString nom3);
    void setNom4(QString nom4);
    void setNbJoueurs(size_t nb);
    void AffichernbJetons();
    void AfficherNobles();
    void AfficherJoueur();
    static int choix;

private:
    Ui::GameWindow *ui;
    QString nom1;
    QString nom2;
    QString nom3;
    QString nom4;
    Partie* partie;
    QMap<QPushButton*, Carte*> BoutonCarte;
    QPushButton* TableauBouton[12];
    int nb;
    QSignalMapper* mapper;


private slots :
    void afficherJetons();
    void highlight();
    void afficherCartes();
    void afficherImages();
    void FindeTour();
    void print(){qDebug()<<choix;};

public slots:
    void numChoix();

};

#endif // GAMEWINDOW_H

