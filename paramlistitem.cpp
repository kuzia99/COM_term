#include "paramlistitem.h"
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

ParamListItem::ParamListItem(QWidget *parent)
    : QWidget{parent}
{
    QLabel *label_1 = new QLabel(this);
    QLabel *label_2 = new QLabel(this);
    QSpinBox *spinBoxID = new QSpinBox(this);
    QSpinBox *spinBoxParameter = new QSpinBox(this);
    QCheckBox *checkBoxEnabled = new QCheckBox(this);
    QLabel *labelValue = new QLabel(this);

    label_1->setText("ID:");
    label_1->setGeometry(10, 0, 15, 20);
    spinBoxID->setGeometry( 30, 0, 40, 20);
    label_2->setText("Параметр: ");
    label_2->setGeometry(75, 0, 60, 20);
    spinBoxParameter->setGeometry( 145, 0, 60, 20);
    checkBoxEnabled->setText("Опрос");
    checkBoxEnabled->setGeometry( 215, 0, 60, 20);
    checkBoxEnabled->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
    labelValue->setText("Значение");
    labelValue->setGeometry(285, 0, 70, 20);
}
