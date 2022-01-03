/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Configurationdelapartie;
    QSpinBox *nbJoueurs;
    QLabel *NombreDeJoueurs;
    QPushButton *boutonLancer;
    QLabel *ActiverUneExtension;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *ChoirExtension;
    QLabel *Joueur1;
    QLabel *Joueur2;
    QLabel *Joueur3;
    QLabel *Joueur4;
    QCheckBox *J2bot;
    QCheckBox *J3bot;
    QCheckBox *J4bot;
    QComboBox *extension;
    QLineEdit *nomJoueur1;
    QLineEdit *nomJoueur2;
    QLineEdit *nomJoueur3;
    QLineEdit *nomJoueur4;
    QLabel *avertissement;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(561, 613);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Configurationdelapartie = new QLabel(centralwidget);
        Configurationdelapartie->setObjectName(QString::fromUtf8("Configurationdelapartie"));
        Configurationdelapartie->setGeometry(QRect(190, 20, 181, 41));
        Configurationdelapartie->setFrameShape(QFrame::Box);
        Configurationdelapartie->setFrameShadow(QFrame::Sunken);
        Configurationdelapartie->setScaledContents(false);
        Configurationdelapartie->setAlignment(Qt::AlignCenter);
        nbJoueurs = new QSpinBox(centralwidget);
        nbJoueurs->setObjectName(QString::fromUtf8("nbJoueurs"));
        nbJoueurs->setGeometry(QRect(340, 90, 61, 31));
        nbJoueurs->setCursor(QCursor(Qt::IBeamCursor));
        nbJoueurs->setAlignment(Qt::AlignCenter);
        nbJoueurs->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        nbJoueurs->setMinimum(2);
        nbJoueurs->setMaximum(4);
        NombreDeJoueurs = new QLabel(centralwidget);
        NombreDeJoueurs->setObjectName(QString::fromUtf8("NombreDeJoueurs"));
        NombreDeJoueurs->setGeometry(QRect(120, 90, 191, 31));
        NombreDeJoueurs->setFrameShape(QFrame::NoFrame);
        boutonLancer = new QPushButton(centralwidget);
        boutonLancer->setObjectName(QString::fromUtf8("boutonLancer"));
        boutonLancer->setGeometry(QRect(210, 490, 131, 51));
        boutonLancer->setCursor(QCursor(Qt::OpenHandCursor));
        boutonLancer->setMouseTracking(false);
        boutonLancer->setCheckable(false);
        ActiverUneExtension = new QLabel(centralwidget);
        ActiverUneExtension->setObjectName(QString::fromUtf8("ActiverUneExtension"));
        ActiverUneExtension->setGeometry(QRect(70, 320, 141, 41));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(330, 330, 99, 22));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(400, 330, 99, 22));
        ChoirExtension = new QLabel(centralwidget);
        ChoirExtension->setObjectName(QString::fromUtf8("ChoirExtension"));
        ChoirExtension->setGeometry(QRect(60, 390, 171, 21));
        Joueur1 = new QLabel(centralwidget);
        Joueur1->setObjectName(QString::fromUtf8("Joueur1"));
        Joueur1->setGeometry(QRect(110, 160, 71, 21));
        Joueur2 = new QLabel(centralwidget);
        Joueur2->setObjectName(QString::fromUtf8("Joueur2"));
        Joueur2->setGeometry(QRect(110, 200, 71, 21));
        Joueur3 = new QLabel(centralwidget);
        Joueur3->setObjectName(QString::fromUtf8("Joueur3"));
        Joueur3->setGeometry(QRect(110, 240, 71, 21));
        Joueur4 = new QLabel(centralwidget);
        Joueur4->setObjectName(QString::fromUtf8("Joueur4"));
        Joueur4->setGeometry(QRect(110, 280, 71, 21));
        J2bot = new QCheckBox(centralwidget);
        J2bot->setObjectName(QString::fromUtf8("J2bot"));
        J2bot->setGeometry(QRect(460, 190, 86, 22));
        J3bot = new QCheckBox(centralwidget);
        J3bot->setObjectName(QString::fromUtf8("J3bot"));
        J3bot->setGeometry(QRect(460, 230, 86, 22));
        J4bot = new QCheckBox(centralwidget);
        J4bot->setObjectName(QString::fromUtf8("J4bot"));
        J4bot->setGeometry(QRect(460, 270, 86, 22));
        extension = new QComboBox(centralwidget);
        extension->addItem(QString());
        extension->addItem(QString());
        extension->addItem(QString());
        extension->addItem(QString());
        extension->setObjectName(QString::fromUtf8("extension"));
        extension->setEnabled(false);
        extension->setGeometry(QRect(290, 390, 191, 24));
        nomJoueur1 = new QLineEdit(centralwidget);
        nomJoueur1->setObjectName(QString::fromUtf8("nomJoueur1"));
        nomJoueur1->setGeometry(QRect(300, 150, 141, 31));
        nomJoueur2 = new QLineEdit(centralwidget);
        nomJoueur2->setObjectName(QString::fromUtf8("nomJoueur2"));
        nomJoueur2->setGeometry(QRect(300, 190, 141, 31));
        nomJoueur3 = new QLineEdit(centralwidget);
        nomJoueur3->setObjectName(QString::fromUtf8("nomJoueur3"));
        nomJoueur3->setGeometry(QRect(300, 230, 141, 31));
        nomJoueur4 = new QLineEdit(centralwidget);
        nomJoueur4->setObjectName(QString::fromUtf8("nomJoueur4"));
        nomJoueur4->setGeometry(QRect(300, 270, 141, 31));
        avertissement = new QLabel(centralwidget);
        avertissement->setObjectName(QString::fromUtf8("avertissement"));
        avertissement->setGeometry(QRect(150, 450, 261, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 561, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cr\303\251ation de la partie de Splendor", nullptr));
        Configurationdelapartie->setText(QCoreApplication::translate("MainWindow", "Configuration de la partie", nullptr));
        NombreDeJoueurs->setText(QCoreApplication::translate("MainWindow", "Nombre de joueurs : ", nullptr));
        boutonLancer->setText(QCoreApplication::translate("MainWindow", "Lancer la partie ", nullptr));
        ActiverUneExtension->setText(QCoreApplication::translate("MainWindow", "Activer une extension : ", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Oui", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        ChoirExtension->setText(QCoreApplication::translate("MainWindow", "Choisir l'extension \303\240 activer ", nullptr));
        Joueur1->setText(QCoreApplication::translate("MainWindow", "Joueur 1 ", nullptr));
        Joueur2->setText(QCoreApplication::translate("MainWindow", "Joueur 2", nullptr));
        Joueur3->setText(QCoreApplication::translate("MainWindow", "Joueur 3", nullptr));
        Joueur4->setText(QCoreApplication::translate("MainWindow", "Joueur 4", nullptr));
        J2bot->setText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        J3bot->setText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        J4bot->setText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        extension->setItemText(0, QCoreApplication::translate("MainWindow", "Cities", nullptr));
        extension->setItemText(1, QCoreApplication::translate("MainWindow", "The Orient", nullptr));
        extension->setItemText(2, QCoreApplication::translate("MainWindow", "Trading Posts", nullptr));
        extension->setItemText(3, QCoreApplication::translate("MainWindow", "Strongholds", nullptr));

        avertissement->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
