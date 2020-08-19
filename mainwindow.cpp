#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_ice,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_tea,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cake,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cola,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_coffe,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pizza,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_burger,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_panini,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cheesecake,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operation()));

    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button =(QPushButton *)sender();

    double all_numbers;
    QString new_label;
    all_numbers = (ui->result_show->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers,'g',15);

    ui->result_show->setText(new_label);
}
void MainWindow::math_operation()
{
     QPushButton *button =(QPushButton *)sender();

     num_first=ui->result_show->text().toDouble();
     ui->result_show->setText("");
     button->setChecked(true);

}
void MainWindow::on_pushButton_suma_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second=ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber=num_first + num_second;

        new_label = QString::number(labelNumber,'g',15);
         ui->result_show->setText(new_label);
         ui->pushButton_plus->setChecked(false);

    }else {}
}
