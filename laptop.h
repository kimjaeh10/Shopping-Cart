#ifndef LAPTOP_H
#define LAPTOP_H
#include "device.h"

class Laptop: public Device
{
public:
    Laptop(QString n, double price, QString name, QString s_a): Device(n, price, name, s_a){}; //Constructor which will be used to build object.
};

#endif // LAPTOP_H
