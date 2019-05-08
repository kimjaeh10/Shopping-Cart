#include "fileparser.h"
#include "abstractbuilder.h"

QList<Device> FileParser::getItems()
{
    QString backPath = "../Project2/";
    QFile test(backPath + file1);
    QStringList rowOfData;
    QStringList rowData;
    QString data;
    QList<Device> listOfDevices;


    if(!test.open(QIODevice::ReadOnly))
    {
        // gives the reason opening the file didn’t work. Usually because it wasn’t found.
        qDebug() << test.errorString();
        // gives the current path the program’s .exe file is running at
        qDebug() << QDir::currentPath();
        throw test.error();
    }
    else
    {
        data = test.readAll();
        rowOfData = data.split("\n");
        test.close();
        for(int i = 0; i < rowOfData.size(); i++) {
            rowData = rowOfData.at(i).split(",");
            QString name = rowData[1];
            QString type = rowData[0];
            double price = rowData[4].toDouble();
            QString spAtt = rowData[5];
            if(type == "Phone")
            {
                listOfDevices.append(absBuilder.buildPhone(type, price, name, spAtt)); // Builds the Phone and appends it to the list of devices.
            }
            else if(type == "Laptop")
            {
                listOfDevices.append(absBuilder.buildLaptop(type, price, name, spAtt)); // Builds a laptop and appends it to the list of devices.
            }

        }
    }
    return listOfDevices;
}

QList<Bundle> FileParser::getBundles()
{
    QString backPath = "../Project2/";
    QFile test(backPath + file2);
    QStringList rowOfData;
    QStringList rowData;
    QString data;
    QList<Bundle> bundle;
    QStringList devices;

    if(!test.open(QIODevice::ReadOnly))
    {
        // gives the reason opening the file didn’t work. Usually because it wasn’t found.
        qDebug() << test.errorString();
        // gives the current path the program’s .exe file is running at
        qDebug() << QDir::currentPath();
        throw test.error();
    }
    else
    {
        data = test.readAll();
        rowOfData = data.split("\n");
        test.close();
        for(int i = 0; i < rowOfData.size(); i++) {
            rowData = rowOfData.at(i).split(",");

            //qDebug()<<rowData.size();
            QString name = rowData[0];
            double price = rowData[1].toDouble();
            for(int i = 2; i < rowData.size(); i++) {
                devices.append(rowData[i]);
            }
            bundle.append(absBuilder.buildBundle(name, price, devices)); // Builds a bundle and appends it to the list of bundles.
            devices.clear();
        }
    }
    return bundle;
}
