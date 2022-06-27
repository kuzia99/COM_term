#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSend_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBoxCOM->currentText());//задали порт
    serialPort.setBaudRate(ui->comboBoxSPEED->currentText().toInt());//задали скорость

    if(!serialPort.open(QIODevice::ReadWrite))/* пробуем подключиться */
    {
        QMessageBox::warning(this, "Ошибка подключения", "Не удалось подключиться к порту");
        return;
    }
    QString TX_str = ui->lineEditTX->text();
    QByteArray TX_bytearr = TX_str.toUtf8();

    serialPort.write(TX_bytearr);
    serialPort.waitForBytesWritten();//ждем пока дойдет

    while (serialPort.waitForReadyRead(10))
    {
        serialPort.readAll();
    }

    serialPort.close();

}

