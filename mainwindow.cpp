#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMessageBox"
#include <QFileDialog>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
     ui->progressBar->setStyleSheet(safe);
    this->setStyleSheet("background-color:rgb(155,68,222)");
    ui->progressBar->reset();
    this->setFixedSize(600,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString src =  ui->pushButton->text();
   QString des = ui->pushButton_2->text();



    ui->progressBar->reset();
    for(int i =0;i<1000 ;i++){
        ui->progressBar->setValue(i);
        if(i==100)
            break;
        system("sleep 0.1");
    }
    std::string str = ui->lineEdit->text().toStdString();
    std::cout << str << std::endl;
    system("");
   QMessageBox::information(this,"DONE",NULL,"Complete");

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QString src = QFileDialog::getOpenFileName(

                this,
                tr("Browse to Location..."),
                "~/Desktop",
                "All files (*.*);;Pictures (*.jpg)"

                );
    ui->lineEdit->setText(src);
}


