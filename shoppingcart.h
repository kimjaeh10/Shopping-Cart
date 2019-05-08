#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include "visitor.h"

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();

    Ui::ShoppingCart* getUi() const {return ui;}

    void Accept(Visitor*); // Accepts a visitor.

public slots:
    void checkoutClicked();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
