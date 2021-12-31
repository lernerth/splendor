#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QTextEdit>

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
