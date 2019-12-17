#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMainWindow>

namespace Ui {
class converter;
}

class converter : public QMainWindow
{
    Q_OBJECT

public:
    explicit converter(QWidget *parent = nullptr);
    ~converter();

private slots:
    //void on_pushButton_clicked();

    void on_convert_clicked();

private:
    Ui::converter *ui;
};

#endif // CONVERTER_H
