#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QTextEdit>
#include "ui_mainwindow.h"
#include <string>
#include <QString>
#include "Partie.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

/*!
 *  \class MainWindow
   * \brief classe créant la fenêtre de paramétrage de la partie
   */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
        *\fn MainWindow(QWidget *parent = nullptr)
        *\brief construit la fenêtre de paramétrage
        *\param parent = nullptr : la fenêtre s'affiche dès l'ouverture, et n'a pas de parents
        */
    MainWindow(QWidget *parent = nullptr);
    /*!
        *\fn ~MainWindow()
        *\brief détruit la fenêtre de paramétrage
        */
    ~MainWindow();
    /*!
        *\fn size_t getNbJoueurs()
        *\brief récupère le nombre de joueurs de la partie
        *\return le nombre de joueurs
        */
    size_t getNbJoueurs() const ;

private slots :

    void oui();
    void non();
    void setPlayers();
    void autofillName2();
    void autofillName3();
    void autofillName4();
    void fermer();
    void checkName();


private:

    Ui::MainWindow *ui;

signals:

};


#endif // MAINWINDOW_H
