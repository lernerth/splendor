#include "Pioche_carte.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>

//constructeur
Pioche_carte::Pioche_carte() {
    toutes = new const Carte*[90];
    lvl1 = new const Carte*[40];
    lvl2 = new const Carte*[30];
    lvl3 = new const Carte*[20];


    //ouverture et lecture du fichier .json
    QFile file_obj("../ressources/cartes.json");
    if(!file_obj.open(QIODevice::ReadOnly)){
        throw Exception("Erreur d'ouverture du fichier");
        exit(1);
    }
    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();

    //traduction du contenu du fichier en objet QJsonDocument
    QByteArray json_bytes = json_string.toLocal8Bit();
    auto json_doc = QJsonDocument::fromJson(json_bytes);

    // on avance dans "niveaux"
    const QJsonValue json_niveaux = json_doc["niveaux"];

    // pour chaque niveau, on itère sur les cartes

    QMap<QString, Couleur> traduction_couleur = {
        {"vert", Couleur::vert},
        {"bleu", Couleur::bleu},
        {"rouge", Couleur::rouge},
        {"blanc", Couleur::blanc},
        {"noir", Couleur::noir}
    };


    const Carte** tableaux_niveaux[3] = {lvl1, lvl2, lvl3};

    for (int i=1; i <= 3; i++){
        QJsonValue json_niveau = json_niveaux[QString::fromStdString(std::to_string(i))];
        for(int j=0; j < json_niveau["nombre"].toInt(); j++){
            QJsonValue carte = json_niveau["liste"][i];
            QMap<Couleur,int> requirements = {
                {Couleur::noir, carte["demande"]["noir"].toInt()},
                {Couleur::rouge, carte["demande"]["rouge"].toInt()},
                {Couleur::vert, carte["demande"]["vert"].toInt()},
                {Couleur::bleu, carte["demande"]["bleu"].toInt()},
                {Couleur::blanc, carte["demande"]["blanc"].toInt()},
            };
            QPixmap sprite("../ressources/ready/cartes/"+QString::fromStdString(std::to_string(i))+"/"+QString::fromStdString(std::to_string(j))+".png");

            // on crée une carte et on ajoute son adresse au tableau nivx correspondant
            tableaux_niveaux[i-1][j] = new Carte(
                        carte["id"].toInt(),
                        i-1,
                        carte["pts"].toInt(),
                        traduction_couleur.value(carte["couleur"].toString()),
                        requirements,
                        sprite
            );
        }
    }

    // on concatène les tableaux nivx pour obtenir le tableau toutes
    for (size_t i=0; i < 3; i++){
        size_t j=0;
        const Carte* p;
        while((p=tableaux_niveaux[i][j])){
            toutes[j] = p;
            j++;
        }
    }


}

const Carte& Pioche_carte::piocher() {//issu de set.cpp
    if (this->nb_cartes == 0) throw SetException("Pioche vide");
    size_t x = rand() % nb;
    const Carte* c = this->cartes[x];
    for (size_t i = x + 1; i < nb; i++) this->cartes[i - 1] = this->cartes[i];
    nb--;
    return *c;
    }


