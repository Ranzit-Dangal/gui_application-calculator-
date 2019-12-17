#include "mainwindow.h"
#include "ui_mainwindow.h"

static double calcVal = 0.0;
static bool divTrigger = false;
static bool multTrigger = false;
static bool addTrigger = false;
static bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button0,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button1,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button2,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button3,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button4,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button5,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button6,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button7,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button8,SIGNAL(clicked()),this,SLOT(NumPressed()));
    connect(ui->Button9,SIGNAL(clicked()),this,SLOT(NumPressed()));


    ui->lineEdit->setText(QString::number(calcVal));

    connect(ui->add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->division, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayVal = ui->lineEdit->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->lineEdit->setText(butval);
    } else {
        QString newVal = displayVal + butval;
        double dblNewVal = newVal.toDouble();
        ui->lineEdit->setText(QString::number(dblNewVal, 'g', 16));
    }

}
void MainWindow::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->lineEdit->text();
    calcVal = displayVal.toDouble();
    QPushButton * button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
       } else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0) {
        multTrigger = true;
}   else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0) {
        addTrigger =true;
    }   else {
            subTrigger = true;
    }
    ui->lineEdit->setText("");
 }


void MainWindow::on_equalsto_clicked()
{
    double solution = 0.0;
    QString displayVal = ui->lineEdit->text();
    double dbDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multTrigger || divTrigger){
        if(addTrigger){
            solution = calcVal + dbDisplayVal;
        }else if (subTrigger) {
            solution = calcVal - dbDisplayVal;
        }else if (multTrigger) {
            solution = calcVal * dbDisplayVal;
        }else{
            solution = calcVal / dbDisplayVal;

        }
    }
    ui->lineEdit->setText(QString::number(solution));
}


void MainWindow::on_clear_clicked()
{
    ui->lineEdit->setText("0.0");
}

void MainWindow::on_backspace_clicked()
{
    QString item = ui->lineEdit->text();
    item.remove(item.size()-1,item.size()-1);
    ui->lineEdit->setText(item);
}

void MainWindow::on_sign_change_clicked()
{
    QString displayVal = ui->lineEdit->text();
    QRegExp reg("[-]?[0-9.]*");
            if(reg.exactMatch(displayVal)){
        double dbDisplayVal = displayVal.toDouble();
        double dbDisplayValSign = -1 * dbDisplayVal;
        ui->lineEdit->setText((QString::number(dbDisplayValSign)));
}
}




void MainWindow::on_decimal_clicked()
{
    QString a = ui->lineEdit->text();
    ui->lineEdit->setText(a+".");
}


void MainWindow::on_converter_clicked()
{
    ci = new converter(this);
    ci->show();
}
