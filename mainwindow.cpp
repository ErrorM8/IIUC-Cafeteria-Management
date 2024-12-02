#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::btnFun);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnFun()
{
    QString item = ui->comboBox->currentText();
    QString quant = ui->lineEdit->text();

    int quant_int = quant.toInt();
    if (quant.isEmpty() || quant_int <= 0) {
        QMessageBox::warning(this, "Error", "Please enter a valid quantity!");
        return;
    }

    int bill = 0;
    if (item == "Dim Khichuri") {
        bill = 50 * quant_int;
    } else if (item == "Murgi Khichuri") {
        bill = 60 * quant_int;
    } else if (item == "SadaVat + Sobji + Dim") {
        bill = 50 * quant_int;
    } else if (item == "SadaVat + Sobji + Murgi / Mach") {
        bill = 60 * quant_int;
    } else if (item == "Morog Polaw") {
        bill = 100 * quant_int;
    } else {
        QMessageBox::warning(this, "Error", "Invalid item selected!");
        return;
    }

    QString message = QString("Total Bill For %1 %2 is %3 Only!")
                          .arg(quant)
                          .arg(item)
                          .arg(QString::number(bill));
    QMessageBox::information(this, "Bill", message);
}
