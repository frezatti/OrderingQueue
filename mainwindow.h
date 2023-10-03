#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Ordenar.h"
#include <QMainWindow>
#include<QString>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCriar_clicked();

    void on_pushButtonOrder_clicked();

private:
    Ui::MainWindow *ui;
    adf::Ordenar* order;
};
#endif // MAINWINDOW_H
