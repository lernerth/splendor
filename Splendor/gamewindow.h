#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "global.h"
#include "Partie.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QString>
#include <QSignalMapper>
#include <QButtonGroup>
#include <string>

class Partie;
/*! \namespace Ui
 *
 * espace de l'interface graphique
 */
namespace Ui {
class GameWindow;
}
/*!
 *  \class GameWindow_t
   * \brief classe créant la fenêtre de jeu
   */

class GameWindow_t : public QMainWindow
{
    Q_OBJECT

public:
    //GameWindow_t();
    /*!
        *\fn GameWindow_t(Partie* p)
        *\brief contruit la fenêtre du jeu
        *\param p : le pointeur sur la partie à lancer
        */
    GameWindow_t(Partie* p);
    /*!
        *\fn ~GameWindow_t()
        *\brief détruit la fenêtre du jeu
        */
    ~GameWindow_t();
    /*!
        *\fn void setNom1(QString nom1)
        *\brief enregistre le nom du premier joueur
        *\param nom1 : chaîne de caractères
        */
    void setNom1(QString nom1);
    /*!
        *\fn void setNom1(QString nom2)
        *\brief enregistre le nom du deuxième joueur
        *\param nom1 : chaîne de caractères
        */
    void setNom2(QString nom2);
    /*!
        *\fn void setNom1(QString nom3)
        *\brief enregistre le nom du troisème joueur
        *\param nom1 : chaîne de caractères
        */
    void setNom3(QString nom3);
    /*!
        *\fn void setNom1(QString nom4)
        *\brief enregistre le nom du quatrième joueur
        *\param nom1 : chaîne de caractères
        */
    void setNom4(QString nom4);
    /*!
        *\fn void setNbJoueurs(size_t nb)
        *\brief crée les joueurs sur la fenêtre
        *\param nb : un nombre 'size_t' correspondant au nombre de joueur pour la partie
        */
    void setNbJoueurs(size_t nb);
    /*!
        *\fn void AffichernbJetons()
        *\brief affiche le nombre de jeton dans la banque
        */
    void AffichernbJetons();
    /*!
        *\fn void AfficherNobles()
        *\brief affiche les nobles pour la partie
        */
    void AfficherNobles();
    /*!
        *\fn void AfficherJoueur()
        *\brief Affiche le joueur qui commence
        */
    void AfficherJoueur();
    /*!
        *\fn void afficherPrestige()
        *\brief Affiche le prestige de chaque joueur
        */
    void afficherPrestige();

    static int choix;/*!< le numéro correspondant au choix du joueur pour son tour (récupérer des jetons, acheter ou réserver une carte)*/

private:
    Ui::GameWindow *ui;/*!< interface graphique*/
    QString nom1;/*!< nom du joueur 1*/
    QString nom2;/*!< nom du joueur 2*/
    QString nom3;/*!< nom du joueur 3*/
    QString nom4;/*!< nom du joueur 4*/
    Partie* partie;/*!< partie en cours*/
    QMap<QPushButton*, Carte*> BoutonCarte;/*!<association d'un bouton de la grille à une carte*/
    QPushButton* TableauBouton[12];/*!<association d'un bouton de la grille à une position*/
    int nb;/*!< nombre de joueurs*/
    //QSignalMapper* mapper;
    QButtonGroup* cartes;/*!< groupe des cartes affichées*/



private slots :
    /*!
        *\fn void afficherJetons()
        *\brief affiche les jetons sur l'interface
        */
    void afficherJetons();
    /*!
        *\fn void highlight()
        *\brief met en exergue les cartes ou les jetons en fonction du choix du joueur pour son tour
        */
    void highlight();
    /*!
        *\fn void afficherCartes()
        *\brief affiche les cartes sur l'interface
        */
    void afficherCartes();
    /*!
        *\fn void afficherImages()
        *\brief affiche les images sur l'interface
        */
    void afficherImages();
    /*!
        *\fn void FindeTour()
        *\brief Gère les tours via le bouton fin de tour
        */
    void FindeTour();

    //void creerGroupeCartes(QButtonGroup* group);
    /*Couleur clicJetonBlanc();
    Couleur clicJetonNoir();
    Couleur clicJetonBleu();
    Couleur clicJetonRouge();
    Couleur clicJetonVert();
    Couleur priseJeton();*/

public slots:
    /*!
        *\fn void numChoix()
        *\brief recupère le numéro correspondant au choix d'action du joueur à son tour (récupérer des jetons, acheter ou réserver une carte)
        */
    void numChoix();

};

#endif // GAMEWINDOW_H

