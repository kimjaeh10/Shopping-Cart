#ifndef PHONE_H
#define PHONE_H
#include "device.h"

class Phone: public Device
{
public:
    Phone(QString n, double price, QString name, QString s_a): Device(n, price, name, s_a){}; //Constructor which will be used to build object
};

#endif // PHONE_H
