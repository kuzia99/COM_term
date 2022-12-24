#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    uiControlSetup();
    SerialPortSetup();

    for(int i = 0; i < 200; ++i)
    {
        x.push_back(i);
        y.push_back(rand() & 150);
    }

    ui->widget->xAxis->setRange(0,200);
    ui->widget->yAxis->setRange(0, 155);

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,y);

    ui->widget->replot();
//    ui->widget->setInteraction(QCP::iRangeZoom, true);
//    ui->widget->setInteraction(QCP::iRangeDrag, true);

    updGraphTimer = new QTimer();
    connect(updGraphTimer, SIGNAL(timeout()), this, SLOT(updateTimeTicks()));
    updGraphTimer->start(10);



    connect(ui->spinBox_y_lower, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
    connect(ui->spinBox_y_upper, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
    connect(ui->spinBox_time, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
}

MainWindow::~MainWindow()
{
    delete ui;

    //закрываем соединение при выходе
    serial->close();
    delete serial;
    delete updGraphTimer;
}

void MainWindow::updateGraph(int)
{
    int timeInGraph = ui->spinBox_time->value();
    ui->widget->xAxis->setRange(timeTicks - timeInGraph, timeTicks);
    ui->widget->yAxis->setRange(ui->spinBox_y_lower->value(), ui->spinBox_y_upper->value());
    ui->widget->replot();
}

void MainWindow::updateTimeTicks()
{
    timeTicks += 0.01;
    updateGraph(0);
}
void MainWindow::addPoints()
{

}

void MainWindow::serialReceive()//получаем данные
{
    QByteArray ba;//создаем пустой массив байт
    ba = serial->readAll();//читаем все
    ui->textBrowserRX->insertPlainText(ba);
}

void MainWindow::uiControlSetup()
{
    ui->setupUi(this);
    /* свяжем сигналы кнопок отправки */
    connect(ui->pushButtonSend,SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->lineEditTX, SIGNAL(editingFinished()), this, SLOT(sendMessage()));
}

void MainWindow::SerialPortSetup()
{

    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialReceive()));//соединяем чтение-прием данных

    ui->comboBoxCOM->clear();/* получим список доступных в системе com портов при помощи QSerialPortInfo */
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QSerialPort port;
        port.setPort(info);
        if (port.open(QIODevice::ReadWrite)) {
            qDebug() << "Название: " + info.portName() + " " + info.description() + info.manufacturer();
            ui->comboBoxCOM->addItem(port.portName());/* добавим порт в выпадающий списочек*/
        }
    }
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->textBrowserRX->clear();
}


void MainWindow::on_pushButtonConnect_clicked()
{
    if(portState == Closed)
    {//если порт не открыт

        /* меняем состояние кнопки */
        ui->pushButtonConnect->setText("Отключиться!");

        /* открываем порт */
        serial->setPortName(ui->comboBoxCOM->currentText());
        serial->setBaudRate(ui->comboBoxSPEED->currentText().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        serial->open(QIODevice::ReadWrite);//открыли порт

        portState = Open;
    }
    else
    {//если порт открыт
        /* меняем состояние кнопки */
        ui->pushButtonConnect->setText("Подключиться!");

        /* закрываем порт */
        serial->close();


        /* Обновим список COM портов */
        ui->comboBoxCOM->clear();
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            QSerialPort port;
            port.setPort(info);
            if(port.open(QIODevice::ReadWrite))
            {
                qDebug() << "Название: " + info.portName() + " " + info.description() + info.manufacturer();

                /* добавим порт в выпадающий списочек*/
                ui->comboBoxCOM->addItem(port.portName());
            }
        }

        portState = Closed;
    }

}

void MainWindow::sendMessage()
{
    QByteArray packet;
    packet = ui->lineEditTX->text().toUtf8();
    serial->write(packet);

    /* очистим виджет ввода */
    ui->lineEditTX->clear();
}
