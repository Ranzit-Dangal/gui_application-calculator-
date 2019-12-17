#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <converter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    converter *ci;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void on_equalsto_clicked();
    void on_clear_clicked();
    void on_backspace_clicked();
    void on_sign_change_clicked();
    void on_decimal_clicked();
    void on_converter_clicked();
};

#endif MAINWINDOW_H
