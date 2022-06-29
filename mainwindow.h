#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>

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

private slots:
    void serialReceive();//получаем данные

    void on_pushButtonClear_clicked();

    void on_pushButtonConnect_clicked();

    void sendMessage();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    bool portState = 0;//открыт или закрыт порт

};
#endif // MAINWINDOW_H
