#ifndef BUTTON_H
#define BUTTON_H
#include <QPushButton>

class Button: public QPushButton
{
public:
    Button(QWidget* qw):QPushButton(qw){}

signals:
    void iChanged(QObject*);

public slots:
    void myClicked();
};

#endif // BUTTON_H
