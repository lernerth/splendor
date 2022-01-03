#include "Pioche_carte.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>

//constructeur
Pioche_carte::Pioche_carte() {
    nb_cartes = 90;
    nb_carteslvl1 = 40;
    nb_carteslvl2 = 30;
    nb_carteslvl3 = 20;
    toutes = new Carte*[nb_cartes];
    lvl1 = new Carte*[nb_carteslvl1];
    lvl2 = new Carte*[nb_carteslvl2];
    lvl3 = new Carte*[nb_carteslvl3];


    //ouverture et lecture du fichier .json
    QFile file_obj("ressources/cartes.json");
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


    Carte** tableaux_niveaux[3] = {lvl1, lvl2, lvl3};

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
            QPixmap sprite("ressources/ready/cartes/"+QString::fromStdString(std::to_string(i))+"/"+QString::fromStdString(std::to_string(j))+".png");

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
        Carte* p;
        while((p=tableaux_niveaux[i][j])){
            toutes[j] = p;
            j++;
        }
    }


}

size_t Pioche_carte::getNbCartes(int niveau) {
    switch (niveau) {
        case 1:
            return nb_carteslvl1;
            break;
        case 2:
            return nb_carteslvl2;
            break;
        case 3:
            return nb_carteslvl3;
            break;
        default:
            return nb_cartes;
            break;
    }
}

Carte* Pioche_carte::piocher(int niveau, Pioche_carte* p) {
    size_t x;
    Carte* c = nullptr;
    qDebug()<<"pioche niveau"<<niveau;
    switch (niveau) {
        case 1:
            if (p->nb_carteslvl1 == 0) throw Exception("Pioche vide");
            x = rand() % p->nb_carteslvl1;
            c = p->lvl1[x];
            for (size_t i = x + 1; i < p->nb_carteslvl1; i++) p->lvl1[i - 1] = p->lvl1[i];
            p->nb_carteslvl1--;
            break;
        case 2:
            if (p->nb_carteslvl2 == 0) throw Exception("Pioche vide");
            x = rand() % p->nb_carteslvl2;
            c = p->lvl2[x];
            for (size_t i = x + 1; i < p->nb_carteslvl2; i++) p->lvl2[i - 1] = p->lvl2[i];
            p->nb_carteslvl2--;
            break;
        case 3:
            if (p->nb_carteslvl3 == 0) throw Exception("Pioche vide");
            x = rand() % p->nb_carteslvl3;
            c = p->lvl3[x];
            for (size_t i = x + 1; i < p->nb_carteslvl3; i++) p->lvl3[i - 1] = p->lvl3[i];
            p->nb_carteslvl3--;
            break;
        default:
            throw Exception("La pioche Carte n'existe pas");
            break;
    }
    return c;
    }


