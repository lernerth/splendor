#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <QDebug>
#include <QString>

using namespace std;

/*!
 *  \class Exception
   * \brief classe regroupant les exceptions du jeu
   */

class Exception {
public:
    /*!
        *\fn Exception(const string& i)
        *\brief contruit l'exception
        *\param i : une adresse de chaine de caractères
        */
    Exception(const string& i) :info(i) { qDebug()<< QString::fromStdString(info);}
    /*!
        *\fn string getInfo()
        *\brief affiche un message d'erreur au joueur
        *\return une chaine de caractère correspondant au message à afficher
        */
    string getInfo() const {return info; }
private:
    string info;/*!< chaine de caractères qui sera affiché au joueur pour le prévenir de l'exception*/
};

#endif // EXCEPTION_H
