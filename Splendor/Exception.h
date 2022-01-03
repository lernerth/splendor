#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <QDebug>
#include <QString>

using namespace std;

class Exception {
public:
    Exception(const string& i) :info(i) { qDebug()<< QString::fromStdString(info);}
    string getInfo() const {return info; }
private:
    string info;
};

#endif // EXCEPTION_H
