#ifndef CHECKBUTTON_H
#define CHECKBUTTON_H
#include<QPushButton>

#include "visitor.h"
class CheckButton: public QPushButton
{
public:
    CheckButton(QWidget* qw): QPushButton(qw){}

signals:
    void iChanged(Visitor*);

public slots:
    void iWasClicked();
};

void CheckButton::iWasClicked()
{
   // Visitor* v;
    //emit iChanged(v);
}

#endif // CHECKBUTTON_H
