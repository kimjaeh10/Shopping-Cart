#ifndef BUNDLE_H
#define BUNDLE_H
#include<QString>
#include<QStringList>

//#include "abstractbuilder.h"

class Bundle
{
public:
    QString name;
    double price;
    QStringList devices;

    Bundle(QString n, double p, QStringList d): name(n), price(p), devices(d){}; // Constructor which will be used to build object.
};

#endif // BUNDLE_H
