#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow();
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void setNom1(QString nom1);
    void setNom2(QString nom2);
    void setNom3(QString nom3);
    void setNom4(QString nom4);
    void setNbJoueurs(int nb);

private:
    Ui::GameWindow *ui;
    QString nom1;
    QString nom2;
    QString nom3;
    QString nom4;
    int nb;

private slots :
    void afficherJetons();
    void afficherJetonsJoueurs();
    void highlight();

public slots:

};

#endif // GAMEWINDOW_H
