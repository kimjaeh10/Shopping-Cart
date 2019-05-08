#ifndef SHOWBUTTON_H
#define SHOWBUTTON_H
#include <QPushButton>

class ShowButton: public QPushButton
{
    Q_OBJECT

public:
    ShowButton(QWidget* qw):QPushButton(qw){}

signals:
    void iChanged(QObject*); // Custom signal.

public slots:
    void myClicked(); // Emits a custom signal.
};

#endif // SHOWBUTTON_H
