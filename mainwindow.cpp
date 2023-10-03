#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete order;
    order=nullptr;
}


void MainWindow::on_pushButtonCriar_clicked()
{
    try {
        order = new adf::Ordenar(ui->lineEditTamanho->text().toInt());
        ui->lineEditVetor->setText(order->accessVector());

    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }

}


void MainWindow::on_pushButtonOrder_clicked()
{
    try {
        if(ui->comboBox->currentIndex()==0){
            order->OrdenarCrescente();
        }else{
            order->OrdenarDecrescente();
        }
        ui->textEditSaida->setText(order->accessVector());
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
}

