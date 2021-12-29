#include "pioche_noble.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>

Pioche_Noble::Pioche_Noble(){
    tous = new const Noble*[10];

    //ouverture et lecture du fichier .json
    QFile file_obj("../ressources/nobles.json");
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
        QImage sprite("../ressources/ready/cartes/"+QString::fromStdString(std::to_string(j))+".png");

        // on crée une carte et on ajoute son adresse au tableau nivx correspondant
        tous[j] = new Noble(
                    noble["pts"].toInt(),
                    requirements,
                    sprite
        );
    }

}
