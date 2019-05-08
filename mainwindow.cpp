#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "addbutton.h"
#include "showbutton.h"
#include <QtGui>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Device Database");
    ui->addButton->setEnabled(false);
    ui->showButton->setEnabled(false);
    //ShoppingCart* shoppingCart = new ShoppingCart(this);
    connect(ui->loadButton,SIGNAL(clicked()),this,SLOT(loadClicked())); // Connection between the load button and the main window.
    connect(shoppingCart->getUi()->checkoutButton, SIGNAL(clicked()), this, SLOT(checkClicked())); // Connection between the checkout button and the main window.
    connect(shoppingCart->getUi()->deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked())); // Connection between the delete button and the main window.

    connect(ui->addButton,SIGNAL(clicked()),ui->addButton,SLOT(myClicked())); // Mediator pattern using the add button.
    connect(ui->addButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->showButton,SIGNAL(clicked()),this, SLOT(showClicked())); // Observer Pattern using the show/hide cart button.
}

void MainWindow::loadClicked() {
    ui->loadButton->setEnabled(false);
    FileParser test("Technology.csv", "Bundles.csv");
    QList<Device> devices = test.getItems();
    QList<Bundle> bundle = test.getBundles();

    ui->productTable->setRowCount(devices.size());
    for(int i = 0; i<devices.size(); i++)
    {
        QTableWidgetItem* proName = new QTableWidgetItem(devices[i].getProductName());
        ui->productTable->setItem(i, 0, proName);

        QTableWidgetItem* type = new QTableWidgetItem(devices[i].getType());
        ui->productTable->setItem(i, 1, type);

        QTableWidgetItem* price = new QTableWidgetItem(QString::number(devices[i].getPrice()));
        ui->productTable->setItem(i, 2, price);

        QTableWidgetItem* spAtt = new QTableWidgetItem(devices[i].getSpecialAttribute());
        ui->productTable->setItem(i, 3, spAtt); // Setting the items in the product table.
    }

    ui->bundleTable->setRowCount(bundle.size());
    for(int i = 0; i<bundle.size(); i++)
    {
        QTableWidgetItem* name = new QTableWidgetItem(bundle[i].name);
        ui->bundleTable->setItem(i, 0, name);

        QTableWidgetItem* price = new QTableWidgetItem(QString::number(bundle[i].price));
        ui->bundleTable->setItem(i, 1, price); //  Setting the items in the bundle table.

        double calculation = 0;
        for(int j = 0; j < bundle[i].devices.size(); j++) {
            for(int k = 0; k < devices.size(); k++) {
                if(bundle[i].devices[j] == devices[k].getProductName()) {
                    calculation += devices[k].getPrice();
                }
            }
        } // Doing the calculation for the savings.
        calculation = int((1 - (bundle[i].price / calculation)) * 100 + 0.5);
        QString p = QString::number(calculation) + "%";
        QTableWidgetItem* percent = new QTableWidgetItem(p);
        ui->bundleTable->setItem(i, 2, percent);
        calculation = 0;
    }

    ui->addButton->setEnabled(true);
    ui->showButton->setEnabled(true); // Enabling the required buttons.
}

void MainWindow::deleteClicked()
{
    QList<int> selected;
    QModelIndexList product_selection = shoppingCart->getUi()->tableWidget->selectionModel()->selectedRows();
    for(int i = 0; i < product_selection.count(); i++)
    {
        QModelIndex product_index = product_selection.at(i);
        selected.append(product_index.row()); // Getting the selected rows.
    }

    for(auto row:selected)
    {
        shoppingCart->getUi()->tableWidget->removeRow(row); // Deleting the rows selected.
    }
}

void MainWindow::checkClicked()
{
    ui->addButton->setEnabled(false);
}

void MainWindow::showClicked()
{
    if(ui->showButton->text() == "Show Cart") {
        shoppingCart->show();
        ui->showButton->setText("Hide Cart");
    }
    else {
        ui->showButton->setText("Show Cart");
        shoppingCart->close(); // Observer pattern to show/hide the cart.
    }
}
void MainWindow::actByYourChange(QObject* sender) {
    if(sender == ui->addButton) {
        QList<int> product_rows;
        QList<int> bundle_rows;

        QModelIndexList product_selection = ui->productTable->selectionModel()->selectedRows();
        // Multiple rows can be selected
        for(int i = 0; i < product_selection.count(); i++)
        {
            QModelIndex product_index = product_selection.at(i);
            product_rows.append(product_index.row());
        }

        QModelIndexList bundle_selection = ui->bundleTable->selectionModel()->selectedRows();
        // Multiple rows can be selected
        for(int i = 0; i < bundle_selection.count(); i++)
        {
            QModelIndex bundle_index = bundle_selection.at(i);
            bundle_rows.append(bundle_index.row());
        }


        QList<int> everything = product_rows;
        everything.append(bundle_rows);

        for(int i = 0; i<everything.size(); i++)
        {
            shoppingCart->getUi()->tableWidget->insertRow(shoppingCart->getUi()->tableWidget->rowCount()); //Adding the required amount of rows.
        }

        for(int i = 0; i < product_rows.size(); i++) {
            QTableWidgetItem* name = ui->productTable->item(product_rows[i],0);
            QTableWidgetItem* name_copy = new QTableWidgetItem(*name);
            QTableWidgetItem* price = ui->productTable->item(product_rows[i],2);
            QTableWidgetItem* price_copy = new QTableWidgetItem(*price);
            shoppingCart -> getUi() -> tableWidget -> setItem(i+shoppingCart->getUi()->tableWidget->rowCount()-(bundle_rows.size()+product_rows.size()), 0, name_copy);
            shoppingCart -> getUi() -> tableWidget -> setItem(i+shoppingCart->getUi()->tableWidget->rowCount()-(bundle_rows.size()+product_rows.size()), 1, price_copy); // Adding the devices to the cart
        }

        for(int i = 0; i < bundle_rows.size(); i++) {
            QTableWidgetItem* name = ui->bundleTable->item(bundle_rows[i],0);
            QTableWidgetItem* name_copy = new QTableWidgetItem(*name);
            QTableWidgetItem* price = ui->bundleTable->item(bundle_rows[i],1);
            QTableWidgetItem* price_copy = new QTableWidgetItem(*price);
            shoppingCart -> getUi() -> tableWidget -> setItem(i+shoppingCart->getUi()->tableWidget->rowCount()-(bundle_rows.size()), 0, name_copy);
            shoppingCart -> getUi() -> tableWidget -> setItem(i+shoppingCart->getUi()->tableWidget->rowCount()-(bundle_rows.size()), 1, price_copy); // Adding the selected bundles to the cart.
            shoppingCart->getUi()->tableWidget->rowCount();
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete shoppingCart;
}
