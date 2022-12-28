/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConnect;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBoxCOM;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxSPEED;
    QPushButton *pushButtonClear;
    QLabel *label_3;
    QTextBrowser *textBrowserRX;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditTX;
    QPushButton *pushButtonSend;
    QVBoxLayout *verticalLayout_6;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *scale_label;
    QSpinBox *spinBox_y_lower;
    QLabel *label_4;
    QSpinBox *spinBox_y_upper;
    QLabel *label_5;
    QSpinBox *spinBox_time;
    QCustomPlot *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCurrentValue;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox;
    QLabel *label_6;
    QSpinBox *spinBoxResponseTime;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *spinBoxId;
    QLabel *label_9;
    QSpinBox *spinBoxParameter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(0, 0, -1, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setEnabled(true);
        pushButtonConnect->setMinimumSize(QSize(70, 56));
        pushButtonConnect->setMaximumSize(QSize(128, 56));

        horizontalLayout->addWidget(pushButtonConnect);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        comboBoxCOM = new QComboBox(centralwidget);
        comboBoxCOM->setObjectName("comboBoxCOM");
        sizePolicy1.setHeightForWidth(comboBoxCOM->sizePolicy().hasHeightForWidth());
        comboBoxCOM->setSizePolicy(sizePolicy1);
        comboBoxCOM->setMinimumSize(QSize(170, 10));

        verticalLayout->addWidget(comboBoxCOM);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);

        comboBoxSPEED = new QComboBox(centralwidget);
        comboBoxSPEED->addItem(QString());
        comboBoxSPEED->addItem(QString());
        comboBoxSPEED->addItem(QString());
        comboBoxSPEED->setObjectName("comboBoxSPEED");
        sizePolicy1.setHeightForWidth(comboBoxSPEED->sizePolicy().hasHeightForWidth());
        comboBoxSPEED->setSizePolicy(sizePolicy1);
        comboBoxSPEED->setMinimumSize(QSize(80, 20));

        verticalLayout_2->addWidget(comboBoxSPEED);


        horizontalLayout_10->addLayout(verticalLayout_2);

        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName("pushButtonClear");
        sizePolicy1.setHeightForWidth(pushButtonClear->sizePolicy().hasHeightForWidth());
        pushButtonClear->setSizePolicy(sizePolicy1);
        pushButtonClear->setMinimumSize(QSize(150, 0));
        pushButtonClear->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_10->addWidget(pushButtonClear);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout_4->addLayout(verticalLayout_3);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        textBrowserRX = new QTextBrowser(centralwidget);
        textBrowserRX->setObjectName("textBrowserRX");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowserRX->sizePolicy().hasHeightForWidth());
        textBrowserRX->setSizePolicy(sizePolicy2);
        textBrowserRX->setMinimumSize(QSize(250, 0));

        verticalLayout_4->addWidget(textBrowserRX);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEditTX = new QLineEdit(centralwidget);
        lineEditTX->setObjectName("lineEditTX");
        sizePolicy1.setHeightForWidth(lineEditTX->sizePolicy().hasHeightForWidth());
        lineEditTX->setSizePolicy(sizePolicy1);
        lineEditTX->setMinimumSize(QSize(180, 0));

        horizontalLayout_2->addWidget(lineEditTX);

        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName("pushButtonSend");
        sizePolicy1.setHeightForWidth(pushButtonSend->sizePolicy().hasHeightForWidth());
        pushButtonSend->setSizePolicy(sizePolicy1);
        pushButtonSend->setMinimumSize(QSize(30, 0));

        horizontalLayout_2->addWidget(pushButtonSend);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setMinimumSize(QSize(350, 0));

        verticalLayout_6->addWidget(listWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(280, 0));

        verticalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_6->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        scale_label = new QLabel(centralwidget);
        scale_label->setObjectName("scale_label");
        scale_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(scale_label);

        spinBox_y_lower = new QSpinBox(centralwidget);
        spinBox_y_lower->setObjectName("spinBox_y_lower");
        spinBox_y_lower->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_y_lower->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_y_lower->setMinimum(-9999);
        spinBox_y_lower->setMaximum(9999);
        spinBox_y_lower->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_5->addWidget(spinBox_y_lower);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(30, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        spinBox_y_upper = new QSpinBox(centralwidget);
        spinBox_y_upper->setObjectName("spinBox_y_upper");
        spinBox_y_upper->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_y_upper->setMinimum(-9999);
        spinBox_y_upper->setMaximum(9999);
        spinBox_y_upper->setValue(100);

        horizontalLayout_5->addWidget(spinBox_y_upper);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        spinBox_time = new QSpinBox(centralwidget);
        spinBox_time->setObjectName("spinBox_time");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(spinBox_time->sizePolicy().hasHeightForWidth());
        spinBox_time->setSizePolicy(sizePolicy4);
        spinBox_time->setMinimumSize(QSize(50, 0));
        spinBox_time->setLayoutDirection(Qt::LeftToRight);
        spinBox_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_time->setMaximum(999);
        spinBox_time->setValue(8);
        spinBox_time->setDisplayIntegerBase(10);

        horizontalLayout_5->addWidget(spinBox_time);


        verticalLayout_7->addLayout(horizontalLayout_5);

        widget = new QCustomPlot(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        widget->setMinimumSize(QSize(100, 200));

        verticalLayout_7->addWidget(widget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelCurrentValue = new QLabel(centralwidget);
        labelCurrentValue->setObjectName("labelCurrentValue");
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(labelCurrentValue->sizePolicy().hasHeightForWidth());
        labelCurrentValue->setSizePolicy(sizePolicy6);
        labelCurrentValue->setMinimumSize(QSize(0, 0));
        labelCurrentValue->setStyleSheet(QString::fromUtf8("border:2px solid rgb(0, 0, 0);"));
        labelCurrentValue->setTextFormat(Qt::RichText);
        labelCurrentValue->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelCurrentValue);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setCheckable(true);
        checkBox->setChecked(false);

        horizontalLayout_6->addWidget(checkBox);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        spinBoxResponseTime = new QSpinBox(centralwidget);
        spinBoxResponseTime->setObjectName("spinBoxResponseTime");
        sizePolicy1.setHeightForWidth(spinBoxResponseTime->sizePolicy().hasHeightForWidth());
        spinBoxResponseTime->setSizePolicy(sizePolicy1);
        spinBoxResponseTime->setMinimumSize(QSize(60, 0));
        spinBoxResponseTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxResponseTime->setMinimum(1);
        spinBoxResponseTime->setMaximum(100000);
        spinBoxResponseTime->setValue(20);

        horizontalLayout_6->addWidget(spinBoxResponseTime);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        sizePolicy6.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy6);

        horizontalLayout_11->addWidget(label_8);


        horizontalLayout_8->addLayout(horizontalLayout_11);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_7);

        spinBoxId = new QSpinBox(centralwidget);
        spinBoxId->setObjectName("spinBoxId");
        sizePolicy1.setHeightForWidth(spinBoxId->sizePolicy().hasHeightForWidth());
        spinBoxId->setSizePolicy(sizePolicy1);
        spinBoxId->setMinimumSize(QSize(50, 0));
        spinBoxId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(spinBoxId);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_9);

        spinBoxParameter = new QSpinBox(centralwidget);
        spinBoxParameter->setObjectName("spinBoxParameter");
        sizePolicy1.setHeightForWidth(spinBoxParameter->sizePolicy().hasHeightForWidth());
        spinBoxParameter->setSizePolicy(sizePolicy1);
        spinBoxParameter->setMinimumSize(QSize(70, 0));
        spinBoxParameter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxParameter->setMaximum(65535);

        horizontalLayout_7->addWidget(spinBoxParameter);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(horizontalLayout_8);


        horizontalLayout_3->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270 \320\277\320\276\321\200\321\202:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214, \320\264\320\260?", nullptr));
        comboBoxSPEED->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBoxSPEED->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBoxSPEED->setItemText(2, QCoreApplication::translate("MainWindow", "115200", nullptr));

        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\276\320\272\320\275\320\276 \320\277\321\200\320\270\320\265\320\274\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276 \320\262\321\213\320\262\320\276\320\264\320\260:", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
        scale_label->setText(QCoreApplication::translate("MainWindow", "Y \321\210\320\272\320\260\320\273\320\260. \320\276\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\275\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\265, \321\201:", nullptr));
        labelCurrentValue->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\200\320\276\321\201", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264, \320\274\321\201", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\202\320\265\320\262\320\276\320\271 ID", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
