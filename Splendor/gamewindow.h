#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "global.h"
#include "Partie.h"

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
    int numChoix();
    static int choix;

private:
    Ui::GameWindow *ui;
    QString nom1;
    QString nom2;
    QString nom3;
    QString nom4;
    Partie* partie;
    int nb;

private slots :
    void afficherJetons();
    void afficherJetonsJoueurs();
    void highlight();

//public slots:

};

#endif // GAMEWINDOW_H
