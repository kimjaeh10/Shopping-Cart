#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QString>
#include "device.h"
#include "bundle.h"
#include "phone.h"
#include "laptop.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QList>
#include "abstractbuilder.h"

using namespace std;
class FileParser
{
protected:
    QString file1;
    QString file2;
    AbstractBuilder absBuilder;

public:
    FileParser(QString fname1, QString fname2): file1(fname1), file2(fname2){}
    QList<Device> getItems(); // List of devices
    QList<Bundle> getBundles(); // List of bundles.
};

#endif // FILEPARSER_H
