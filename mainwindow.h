#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QVector>
#include <QTimer>
#include "qcustomplot.h"

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

    void addPoints();

private slots:
    void serialReceive();//получаем данные

    void on_pushButtonClear_clicked();

    void on_pushButtonConnect_clicked();

    void sendMessage();

    void updateGraph(int);
    void updateTimeTicks();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    bool portState = 0;//открыт или закрыт порт
//    QCustomPlot* plot = nullptr;

    void uiControlSetup();
    void SerialPortSetup();

    QVector<double> x,y;

    double timeTicks = 0.0;
    QTimer *updGraphTimer = nullptr;


};
#endif // MAINWINDOW_H
