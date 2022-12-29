#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "paramlistitem.h"

#include <QList>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    uiControlSetup();
    SerialPortSetup();
    PlotSetup();
    StartUpdateGraphTimer();
    ConnectControlButton();
    CreateTable();
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
//    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 95))); // first graph will be filled with translucent blue

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

    ui->widget->graph(CurrentParam)->addData(timeTicks, value);
//    ui->widget->graph(0)->addData(timeTicks, value);
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
    ((QLabel*)(ui->tableWidget->cellWidget(CurrentParam, 4)))->setText(QString::number(readedVal));
//    ui->labelCurrentValue->setText(QString::number(readedVal));

    IncrementParamCounter();
    QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendNextRequest()));
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

void MainWindow::IncrementParamCounter()
{
    ++CurrentParam;
    if (CurrentParam >= ui->tableWidget->rowCount()) {
        CurrentParam = 0;
    }
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

void MainWindow::CreateTable()
{
    ui->tableWidget->setColumnCount(5);// Указываем число колонок
    ui->tableWidget->setShowGrid(true);// включаем отображение сетки
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);// Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);// Разрешаем выделение построчно
    QStringList headers = { "Опрос", "ID", "Параметр", "Цвет","Значение"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount());
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CreateItemTable(ui->tableWidget->rowCount());// метод добавления нового элемента в таблицу
}

void MainWindow::CreateItemTable(int row)
{
    ui->tableWidget->insertRow(row);

    QCheckBox *checkBoxEnabled = new QCheckBox();
    checkBoxEnabled->setStyleSheet("margin-left:10%; margin-right:90%;");
    ui->tableWidget->setCellWidget(row, 0, checkBoxEnabled);


    connect(checkBoxEnabled, SIGNAL(clicked(bool)), this, SLOT(sendRequest(bool)));



    QSpinBox *spinBoxId = new QSpinBox();
    spinBoxId->setValue(0);
    ui->tableWidget->setCellWidget(row, 1, spinBoxId);

    QSpinBox *spinBoxParameter = new QSpinBox();
    spinBoxParameter->setValue(0);
    ui->tableWidget->setCellWidget(row, 2, spinBoxParameter);

    QPushButton *pushButtonColor = new QPushButton();//тип тут лежит кнопка для редактирования цвета
    ui->tableWidget->setCellWidget(row, 3, pushButtonColor);

    QPalette pal = pushButtonColor->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    pushButtonColor->setAutoFillBackground(true);
    pushButtonColor->setPalette(pal);
    pushButtonColor->update();

    connect(pushButtonColor, &QPushButton::released, this, &MainWindow::changeColor);
    QLabel *labelValue = new QLabel();
    ui->tableWidget->setCellWidget(row, 4, labelValue);
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
    if (checked) {
         QTimer::singleShot(ui->spinBoxResponseTime->value(), this, SLOT(sendRequest()));
    }
}

void MainWindow::sendRequest(bool)
{
    QCheckBox *checkBox = static_cast<QCheckBox*>(ui->tableWidget->cellWidget(CurrentParam, 0));
    QSpinBox *spinBoxId = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(CurrentParam,1));
    QSpinBox *spinBoxParam = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(CurrentParam,2));

    if (checkBox->checkState()) {
        sendPacket(DataManager->AskPacket(spinBoxId->value(), spinBoxParam->value())); // пора отправлять запрос
    }
}


void MainWindow::on_pushButton_clicked()// добавить новый элемент в таблицу
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount());
    CreateItemTable(ui->tableWidget->rowCount());// метод добавления нового элемента в таблицу
    ui->widget->addGraph();//добавим новый график
}


void MainWindow::on_pushButton_2_clicked()//удалить текущий элемент из таблицы
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if (selectedRows.size()) {
        ui->tableWidget->removeRow(selectedRows[0].row());
    }
}

void MainWindow::changeColor()
{
    QColor color = QColorDialog::getColor(Qt::blue, this);

    QPushButton *button = static_cast<QPushButton*>(QObject::sender());

    QPalette pal = button->palette();
    pal.setColor(QPalette::Button, color);
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}

void MainWindow::sendNextRequest()
{
    sendRequest(true);
}

