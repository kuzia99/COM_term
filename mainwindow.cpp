#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    uiControlSetup();
    SerialPortSetup();

    ui->widget->yAxis->setRange(0, 100);
    ui->widget->xAxis->setLabel("Time, s");
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,y);
    ui->widget->graph(0)->setPen(QPen(QColor(0, 0, 0), 3));
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 95))); // first graph will be filled with translucent blue

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

void MainWindow::addPoints(double value)
{
    x.push_back(timeTicks);
    y.push_back(value);

    ui->widget->graph(0)->setData(x,y);
    ui->widget->replot();
}

void MainWindow::serialReceive()//получаем данные
{
    if (serial->bytesAvailable() < 2)
        return;
    QByteArray ba;//создаем пустой массив байт

    ba = serial->readLine(4096);//читаем все

    QString in;
    for (int i = 0; i < ba.size(); ++i) {
        in += QString::number(ba.at(i), 16) + " ";
    }
    qDebug() << in + "\r\n";

    ui->textBrowserRX->insertPlainText(in);
    QScrollBar * sb = ui->textBrowserRX->verticalScrollBar();
    sb->setValue(sb-> maximum());

    double readedVal = DataManager->getParamValue(ba);
    if( readedVal > 1.0 && readedVal < 1000.0)
        addPoints(readedVal);
    QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendRequest()));
//    QString inputMessage = QString(ba);

//    if (inputMessage.contains("Temperature "))
//    {
//        inputMessage.remove("Temperature ");

//        QByteArray val = inputMessage.toLocal8Bit();

//        addPoints(strtod (val, nullptr)); // добавим точку на график
//    }
//    else
//    {
//        qDebug() << inputMessage;
//    }
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

    DataManager = new DataManager_t();
    SerialResponseTimer = new QTimer();
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
//        serial->setDataBits(QSerialPort::Data8);
//        serial->setParity(QSerialPort::NoParity);
//        serial->setStopBits(QSerialPort::OneStop);
//        serial->setFlowControl(QSerialPort::NoFlowControl);
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

void MainWindow::sendPacket(QByteArray packet)
{
    QString out;
    for (int i = 0; i < packet.length(); ++i) {
        out += QString::number(packet.at(i), 16) + " ";
    }
    qDebug() << out;

    serial->write(packet);
}


void MainWindow::sendMessage()
{
    QByteArray packet;
    packet = ui->lineEditTX->text().toUtf8();
    serial->write(packet);

    /* очистим виджет ввода */
    ui->lineEditTX->clear();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked)
    {
         QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendRequest()));

//        SerialResponseTimer->start(ui->spinBoxResponseTime->value());
//        connect(SerialResponseTimer, SIGNAL(timeout()), this, SLOT(sendRequest()));
    }
}

void MainWindow::sendRequest()
{
//    SerialResponseTimer->stop();// останавливаем таймер
    sendPacket(DataManager->AskPacket(ui->spinBoxId->value(), ui->spinBoxParameter->value())); // пора отправлять запрос
}

