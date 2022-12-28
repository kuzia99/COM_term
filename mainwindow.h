#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QVector>
#include <QTimer>
#include "qcustomplot.h"
#include "datamanager_t.h"

#define Open true
#define Closed false

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addPoints(double value);

    void sendPacket(QByteArray packet);

private slots:
    void serialReceive();//получаем данные

    void on_pushButtonClear_clicked();

    void on_pushButtonConnect_clicked();
    void sendMessage();

    void updateGraph(int);
    void updateTimeTicks();

    void on_checkBox_clicked(bool checked);

    void sendRequest();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;

    void uiControlSetup();
    void SerialPortSetup();
    void PlotSetup();
    void StartUpdateGraphTimer();
    void ConnectControlButton();
    void PrintInputMessage();
    void UpdateCOMList();
    void SetPortSettings();

    QVector<double> x,y;

    double timeTicks = 0.0;
    QTimer *updGraphTimer = nullptr;
    DataManager_t* DataManager = nullptr;
    QTimer *SerialResponseTimer = nullptr;

    QByteArray serialData;
    QString serialText;
};
#endif // MAINWINDOW_H
