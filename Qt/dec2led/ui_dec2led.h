/********************************************************************************
** Form generated from reading UI file 'dec2led.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEC2LED_H
#define UI_DEC2LED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dec2Led
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *bit3;
    QLabel *bit2;
    QLabel *bit1;
    QLabel *bit0;
    QHBoxLayout *horizontalLayout_2;
    QSlider *decimalValue;
    QLabel *showdec;

    void setupUi(QWidget *Dec2Led)
    {
        if (Dec2Led->objectName().isEmpty())
            Dec2Led->setObjectName(QStringLiteral("Dec2Led"));
        Dec2Led->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dec2Led);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bit3 = new QLabel(Dec2Led);
        bit3->setObjectName(QStringLiteral("bit3"));
        bit3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        bit3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(bit3);

        bit2 = new QLabel(Dec2Led);
        bit2->setObjectName(QStringLiteral("bit2"));
        bit2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        bit2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(bit2);

        bit1 = new QLabel(Dec2Led);
        bit1->setObjectName(QStringLiteral("bit1"));
        bit1->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        bit1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(bit1);

        bit0 = new QLabel(Dec2Led);
        bit0->setObjectName(QStringLiteral("bit0"));
        bit0->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        bit0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(bit0);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        decimalValue = new QSlider(Dec2Led);
        decimalValue->setObjectName(QStringLiteral("decimalValue"));
        decimalValue->setMaximum(15);
        decimalValue->setOrientation(Qt::Horizontal);
        decimalValue->setTickPosition(QSlider::TicksBothSides);

        horizontalLayout_2->addWidget(decimalValue);

        showdec = new QLabel(Dec2Led);
        showdec->setObjectName(QStringLiteral("showdec"));

        horizontalLayout_2->addWidget(showdec);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dec2Led);

        QMetaObject::connectSlotsByName(Dec2Led);
    } // setupUi

    void retranslateUi(QWidget *Dec2Led)
    {
        Dec2Led->setWindowTitle(QApplication::translate("Dec2Led", "Dec2Led", nullptr));
        bit3->setText(QApplication::translate("Dec2Led", "8", nullptr));
        bit2->setText(QApplication::translate("Dec2Led", "4", nullptr));
        bit1->setText(QApplication::translate("Dec2Led", "2", nullptr));
        bit0->setText(QApplication::translate("Dec2Led", "1", nullptr));
        showdec->setText(QApplication::translate("Dec2Led", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dec2Led: public Ui_Dec2Led {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEC2LED_H
