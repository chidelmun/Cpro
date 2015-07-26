#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString src =  ui->pushButton->text();
   QString des = ui->pushButton_2->text();
//   if(qstrcmp(src,des) != 0){
//   QMessageBox::critical(this,"ERROR",NULL,"SRC and DES Mismatch");
//   }
    ui->progressBar->reset();
    for(int i =0;i<1000 ;i++){
        ui->progressBar->setValue(i);
        if(i==100)
            break;
        system("sleep 0.1");
    }
    ui->pushButton->setText("Done");

}

void MainWindow::on_pushButton_2_clicked()
{

}
