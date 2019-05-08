#ifndef ABSTRACTBUILDER_H
#define ABSTRACTBUILDER_H

#include "device.h"
#include "bundle.h"
#include "phone.h"
#include "laptop.h"

#include<QString>
#include<QList>


class AbstractBuilder
{
protected:

public:
    AbstractBuilder(){}
    ~AbstractBuilder(){}

    Phone buildPhone(QString n, double price, QString name, QString s_a)
    {
        Phone newPhone(n, price, name, s_a);
        return newPhone; // Builder for the phone
    }

    Laptop buildLaptop(QString n, double price, QString name, QString s_a)
    {
        Laptop newLaptop(n, price, name, s_a);
        return newLaptop; // Builder for the Laptop
    }

    Bundle buildBundle(QString n, double p, QStringList d)
    {
        Bundle newBundle(n, p, d);
        return newBundle; // Builder for the Bundle
    }
};

#endif // ABSTRACTBUILDER_H
