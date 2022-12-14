#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

class Exception {
public:
    Exception(const string& i) :info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};

#endif // EXCEPTION_H
