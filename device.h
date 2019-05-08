#ifndef DEVICE_H
#define DEVICE_H
#include<QString>


class Device {

protected:
    QString type;
    double price;
    QString productName;
    QString specialAttribute; // Member variables
public:
    Device(QString n, double p, QString name, QString s_a): type(n), price(p), productName(name), specialAttribute(s_a){} // Constructor for a device.
    void setType(QString q){type = q;}
    void setPrice(double d){price = d;}
    void setProductName(QString q){productName = q;} // Setters
    void setSpecialAttribute(QString q){specialAttribute = q;}


    QString getType(){return type;}
    double getPrice(){return price;}
    QString getProductName(){return productName;}
    QString getSpecialAttribute(){return specialAttribute;} // Getters
};

#endif // DEVICE_H
