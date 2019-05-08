#ifndef CHECKOUTVISITOR_H
#define CHECKOUTVISITOR_H

#include "visitor.h"
#include "shoppingcart.h"
#include "ui_shoppingcart.h"

#include<QTableWidgetItem>

class CheckoutVisitor: public Visitor
{
protected:
    double price; // Price member variable
public:
    virtual void visitShoppingCart(ShoppingCart*); // Function to visit the shopping cart
    double getResult();
};

void CheckoutVisitor::visitShoppingCart(ShoppingCart *sc)
{
    double toDouble;
    QString result;
    for(int i = 0; i < sc->getUi()->tableWidget->rowCount(); i++) {
        QTableWidgetItem *item = sc->getUi()->tableWidget->item(i, 1);
        toDouble = item -> text().toDouble();
        price += toDouble; // Calculating the price.
    }
    result = "Total: $" + QString::number(price);
    sc->getUi()->label->setText(result);
    sc->getUi()->deleteButton->setEnabled(false);
    sc->getUi()->checkoutButton->setEnabled(false); // Disabling the required buttons.
}

double CheckoutVisitor::getResult()
{
    double temp = price;
    price = 0;
    return temp;
}

#endif // CHECKOUTVISITOR_H
