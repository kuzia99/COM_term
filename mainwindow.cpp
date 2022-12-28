#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    uiControlSetup();
    SerialPortSetup();
    PlotSetup();
    StartUpdateGraphTimer();
    ConnectControlButton();
}

/// Методы инициализации

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
    UpdateCOMList();

    DataManager = new DataManager_t();
    SerialResponseTimer = new QTimer();
}

void MainWindow::PlotSetup()
{
    ui->widget->yAxis->setRange(0, 100);
    ui->widget->xAxis->setLabel("Time, s");
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,y);
    ui->widget->graph(0)->setPen(QPen(QColor(0, 0, 0), 3));
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 95))); // first graph will be filled with translucent blue

    ui->widget->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), 1));
    ui->widget->xAxis->grid()->setSubGridPen(QPen(QColor(0, 0, 0), 1));
    ui->widget->xAxis->grid()->setSubGridVisible(true);
    ui->widget->xAxis->grid()->setAntialiasedSubGrid(true);
    ui->widget->xAxis->grid()->setAntialiased(true);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), 1));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(0, 0, 0), 1));
    ui->widget->replot();
//    ui->widget->setInteraction(QCP::iRangeZoom, true);
//    ui->widget->setInteraction(QCP::iRangeDrag, true);
}

void MainWindow::StartUpdateGraphTimer()
{
    updGraphTimer = new QTimer();
    connect(updGraphTimer, SIGNAL(timeout()), this, SLOT(updateTimeTicks()));
    updGraphTimer->start(10);
}

void MainWindow::ConnectControlButton()
{
    connect(ui->spinBox_y_lower, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
    connect(ui->spinBox_y_upper, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
    connect(ui->spinBox_time, SIGNAL(valueChanged(int)), this, SLOT(updateGraph(int)));
}


MainWindow::~MainWindow()
{
    serial->close();//закрываем соединение при выходе
    delete ui;
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

    ui->widget->graph(0)->addData(timeTicks, value);
//    ui->widget->graph(0)->setData(x,y);
}

void MainWindow::serialReceive()//получаем данные
{
    serialData = serial->readAll();
    while (serial->waitForReadyRead(10)) {// таймаут по приему байт
        serialData += serial->readAll();//дочитываем остальное
    }
    PrintInputMessage();

    double readedVal = DataManager->getParamValue(serialData);
    addPoints(readedVal);
    ui->labelCurrentValue->setText(QString::number(readedVal));

    QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendRequest()));
}

void MainWindow::PrintInputMessage()
{
    serialText.clear();
    for (int i = 0; i < serialData.size(); ++i) {
        serialText += QString::number(serialData.at(i), 16) + " ";
    }
    qDebug() << serialText + "\r\n";

    ui->textBrowserRX->insertPlainText("<< " + serialText + "\r\n");
    QScrollBar * sb = ui->textBrowserRX->verticalScrollBar();
    sb->setValue(sb-> maximum());
}

void MainWindow::UpdateCOMList()
{
    ui->comboBoxCOM->clear();/* получим список доступных в системе com портов при помощи QSerialPortInfo */
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QSerialPort port;
        port.setPort(info);
        if (port.open(QIODevice::ReadWrite)) {
            qDebug() << "Название: " + info.portName() + " " + info.description() + info.manufacturer();
            ui->comboBoxCOM->addItem(port.portName() + " " + info.description());/* добавим порт в выпадающий списочек*/
        }
    }
}

void MainWindow::SetPortSettings()
{
    QString portName = ui->comboBoxCOM->currentText();
    serial->setPortName(portName.left(5));
    serial->setBaudRate(ui->comboBoxSPEED->currentText().toInt());
//        serial->setDataBits(QSerialPort::Data8);
//        serial->setParity(QSerialPort::NoParity);
//        serial->setStopBits(QSerialPort::OneStop);
//        serial->setFlowControl(QSerialPort::NoFlowControl);
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->textBrowserRX->clear();
}


void MainWindow::on_pushButtonConnect_clicked()
{
    if (!serial->isOpen())
    {
        SetPortSettings();
        serial->open(QIODevice::ReadWrite);/* открываем порт */
        ui->pushButtonConnect->setText("Отключиться!");/* меняем состояние кнопки */
    }
    else
    {//если порт открыт
        ui->pushButtonConnect->setText("Подключиться!");/* меняем состояние кнопки */
        serial->close();/* закрываем порт */
        UpdateCOMList();/* Обновим список COM портов */
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
    ui->lineEditTX->clear();/* очистим виджет ввода */
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked)
    {
         QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendRequest()));
    }
}

void MainWindow::sendRequest()
{
    if (ui->checkBox->checkState()) {
        sendPacket(DataManager->AskPacket(ui->spinBoxId->value(), ui->spinBoxParameter->value())); // пора отправлять запрос
    }
}

