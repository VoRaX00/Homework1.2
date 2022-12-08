#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()==""){
        ui->lineEdit->text().clear();
        ui->lineEdit_2->text().clear();
        ui->lineEdit_3->text().clear();
        return;
    }
    double a,b;
    double corner = ui->lineEdit_3->text().toInt();
    a = ui->lineEdit->text().toInt();
    b = ui->lineEdit_2->text().toInt();
    corner = ui->lineEdit_3->text().toDouble();
    if(ui->radioButton->isChecked())
    {
        double l = qCos(corner);
        ui->lineEdit_4->setText(QString::number(qSqrt((qPow(a,2)+qPow(b,2) - 2*a*b*l))));
    }
    else{
        ui->lineEdit_4->setText(QString::number(qSqrt(qPow(a,2)+qPow(b,2) - 2*a*b*qCos((double(corner)/57.2958)))));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
