#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QWindow>
#include <QTextEdit>
=======
#include "Exception.h"
>>>>>>> 2804a584d5030270d3d713b4a42df63781415eef

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
};


#endif // MAINWINDOW_H
