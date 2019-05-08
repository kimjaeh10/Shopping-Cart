#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fileparser.h"
#include "shoppingcart.h"
#include "device.h"
#include "bundle.h"
#include <QMainWindow>

using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void actByYourChange(QObject*);
    void loadClicked();
    void deleteClicked();
    void checkClicked();
    void showClicked(); // Custom slots

private:
    Ui::MainWindow *ui;
    ShoppingCart* shoppingCart = new ShoppingCart(this); // Creating a new shopping cart object.
};

#endif // MAINWINDOW_H
