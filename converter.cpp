#include "converter.h"
#include "ui_converter.h"
#include "QtGui"

converter::converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::converter)
{
    ui->setupUi(this);
    ui->comboBox1->addItem(" Dollar ");
    ui->comboBox2->addItem(" Dollar ");
    ui->comboBox1->addItem(" Indian ");
    ui->comboBox2->addItem(" Indian ");
    ui->comboBox1->addItem(" Euro ");
    ui->comboBox2->addItem(" Euro ");
    ui->comboBox1->addItem(" Rupee ");
    ui->comboBox2->addItem(" Rupee ");

}

converter::~converter()
{
    delete ui;
}


void converter::on_convert_clicked()
{
    double solution;
    QString val = ui->lineEdit1->text();
    double calcVal = val.toDouble();
    QString conversion = ui->comboBox1->currentText();
    QString conversion2= ui->comboBox2->currentText();

 if (QString::compare(conversion, " Rupee ",Qt::CaseInsensitive)==0){
           if (QString::compare(conversion2, " Dollar ",Qt::CaseInsensitive)==0)
           {
               ui->lineEdit1->setText('nrs'+val);
               solution = calcVal/110.61;
               ui->lineEdit2->setText('$'+QString::number(solution));
           }}
 if (QString::compare(conversion, " Dollar ",Qt::CaseInsensitive)==0 ){
        if (QString::compare(conversion2, " Rupee ",Qt::CaseInsensitive)==0)
        {
            ui->lineEdit1->setText('$'+val);
            solution = calcVal*110.61;
            ui->lineEdit2->setText("nrs "+QString::number(solution));
        }}

 if (QString::compare(conversion, " Indian ",Qt::CaseInsensitive)==0){
    if (QString::compare(conversion2, " Rupee ",Qt::CaseInsensitive)==0)
 {
        ui->lineEdit1->setText('IC '+val);
        solution = calcVal*1.62;
        ui->lineEdit2->setText("nrs "+QString::number(solution));
 }}
 if (QString::compare(conversion, " Rupee ",Qt::CaseInsensitive)==0){
 if (QString::compare(conversion2, " Indian ",Qt::CaseInsensitive)==0)
 {
     ui->lineEdit1->setText('nrs'+val);
     solution = calcVal/1.62;
     ui->lineEdit2->setText('IC'+QString::number(solution));
 }}
}
