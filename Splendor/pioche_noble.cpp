#include "pioche_noble.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>

Pioche_Noble::Pioche_Noble(){
    nbNoble = 10;
    tous = new Noble*[nbNoble];

    //ouverture et lecture du fichier .json
    QFile file_obj("ressources/nobles.json");
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

    for(int j=0; j < json_doc["nombre"].toInt(); j++){
        QJsonValue noble = json_doc["liste"][j];
        QMap<Couleur,int> requirements = {
            {Couleur::noir, noble["demande"]["noir"].toInt()},
            {Couleur::rouge, noble["demande"]["rouge"].toInt()},
            {Couleur::vert, noble["demande"]["vert"].toInt()},
            {Couleur::bleu, noble["demande"]["bleu"].toInt()},
            {Couleur::blanc, noble["demande"]["blanc"].toInt()},
        };
        QString sprite = "ressources/ready/nobles/"+QString::fromStdString(std::to_string(j))+".png";

        // on crée une carte et on ajoute son adresse au tableau nivx correspondant
        tous[j] = new Noble(
                    noble["pts"].toInt(),
                    requirements,
                    sprite
        );
    }

}

Noble* Pioche_Noble::piocherNoble(Pioche_Noble* n) {
    size_t x;
    Noble* c = nullptr;
    x = rand() % n->nbNoble;
    c = n->tous[x];
    for (int i = x + 1; i < n->nbNoble; i++) n->tous[i - 1] = n->tous[i];
    n->nbNoble--;
    return c;
    }
