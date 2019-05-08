#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QList>
#include "checkoutvisitor.h"

ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Shopping Cart");
    connect(ui->checkoutButton,SIGNAL(clicked()),this,SLOT(checkoutClicked())); // Connection between the checkout button and the shopping cart.
}
void ShoppingCart::checkoutClicked() {

    CheckoutVisitor* cv = new CheckoutVisitor();
    this->Accept(cv); // Accepting the hook
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}

void ShoppingCart::Accept(Visitor *v)
{
    v->visitShoppingCart(this);
}

