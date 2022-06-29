#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceive()));//соединяем чтение-прием данных

    /* получим список доступных в системе com портов при помощи QSerialPortInfo */
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort port;
        port.setPort(info);
        if(port.open(QIODevice::ReadWrite))
        {
            qDebug() << "Название: " + info.portName() + " " + info.description() + info.manufacturer();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;

    //закрываем соединение при выходе
    serial->close();
    delete serial;
}

void MainWindow::serialReceive()//получаем данные
{
    QByteArray ba;//создаем пустой массив байт
    ba = serial->readAll();//читаем все
    ui->textBrowserRX->append(ba);
}




void MainWindow::on_pushButtonClear_clicked()
{
    ui->textBrowserRX->clear();
}


void MainWindow::on_pushButtonConnect_clicked()
{
    serial->setPortName(ui->comboBoxCOM->currentText());
    serial->setBaudRate(ui->comboBoxSPEED->currentText().toInt());
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);//открыли порт
}

