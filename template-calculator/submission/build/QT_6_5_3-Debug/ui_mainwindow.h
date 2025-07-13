/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btn_mem_get;
    QPushButton *btn_clear;
    QPushButton *btn_reverse;
    QPushButton *btn_mem_clear;
    QPushButton *btn_7;
    QPushButton *btn_mem_save;
    QPushButton *btn_1;
    QPushButton *btn_4;
    QPushButton *tb_extra;
    QPushButton *btn_8;
    QPushButton *btn_5;
    QPushButton *btn_2;
    QPushButton *btn_0;
    QPushButton *btn_9;
    QPushButton *btn_6;
    QPushButton *btn_3;
    QPushButton *btn_backspace;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;
    QLabel *l_formula;
    QGridLayout *gridLayout_3;
    QPushButton *btn_minus;
    QPushButton *btn_div;
    QPushButton *btn_pow;
    QPushButton *btn_plus;
    QPushButton *btn_mult;
    QPushButton *btn_count;
    QComboBox *cmb_controller;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(484, 362);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(11);
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(0, -1, -1, -1);
        btn_mem_get = new QPushButton(centralwidget);
        btn_mem_get->setObjectName("btn_mem_get");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_mem_get->sizePolicy().hasHeightForWidth());
        btn_mem_get->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_mem_get, 0, 1, 1, 1);

        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName("btn_clear");
        sizePolicy1.setHeightForWidth(btn_clear->sizePolicy().hasHeightForWidth());
        btn_clear->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_clear, 1, 0, 1, 2);

        btn_reverse = new QPushButton(centralwidget);
        btn_reverse->setObjectName("btn_reverse");
        sizePolicy1.setHeightForWidth(btn_reverse->sizePolicy().hasHeightForWidth());
        btn_reverse->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_reverse, 1, 2, 1, 1);

        btn_mem_clear = new QPushButton(centralwidget);
        btn_mem_clear->setObjectName("btn_mem_clear");
        sizePolicy1.setHeightForWidth(btn_mem_clear->sizePolicy().hasHeightForWidth());
        btn_mem_clear->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_mem_clear, 0, 0, 1, 1);

        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName("btn_7");
        sizePolicy1.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_7, 2, 0, 1, 1);

        btn_mem_save = new QPushButton(centralwidget);
        btn_mem_save->setObjectName("btn_mem_save");
        sizePolicy1.setHeightForWidth(btn_mem_save->sizePolicy().hasHeightForWidth());
        btn_mem_save->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_mem_save, 0, 2, 1, 1);

        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName("btn_1");
        sizePolicy1.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_1, 4, 0, 1, 1);

        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName("btn_4");
        sizePolicy1.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_4, 3, 0, 1, 1);

        tb_extra = new QPushButton(centralwidget);
        tb_extra->setObjectName("tb_extra");
        sizePolicy1.setHeightForWidth(tb_extra->sizePolicy().hasHeightForWidth());
        tb_extra->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tb_extra, 5, 0, 1, 1);

        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName("btn_8");
        sizePolicy1.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_8, 2, 1, 1, 1);

        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName("btn_5");
        sizePolicy1.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_5, 3, 1, 1, 1);

        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName("btn_2");
        sizePolicy1.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_2, 4, 1, 1, 1);

        btn_0 = new QPushButton(centralwidget);
        btn_0->setObjectName("btn_0");
        sizePolicy1.setHeightForWidth(btn_0->sizePolicy().hasHeightForWidth());
        btn_0->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_0, 5, 1, 1, 1);

        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName("btn_9");
        sizePolicy1.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_9, 2, 2, 1, 1);

        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName("btn_6");
        sizePolicy1.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_6, 3, 2, 1, 1);

        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName("btn_3");
        sizePolicy1.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_3, 4, 2, 1, 1);

        btn_backspace = new QPushButton(centralwidget);
        btn_backspace->setObjectName("btn_backspace");
        sizePolicy1.setHeightForWidth(btn_backspace->sizePolicy().hasHeightForWidth());
        btn_backspace->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(btn_backspace, 5, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        l_result->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(l_result);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        l_formula->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(l_formula, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(10);
        gridLayout_3->setObjectName("gridLayout_3");
        btn_minus = new QPushButton(centralwidget);
        btn_minus->setObjectName("btn_minus");
        sizePolicy1.setHeightForWidth(btn_minus->sizePolicy().hasHeightForWidth());
        btn_minus->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(btn_minus, 3, 0, 1, 1);

        btn_div = new QPushButton(centralwidget);
        btn_div->setObjectName("btn_div");
        sizePolicy1.setHeightForWidth(btn_div->sizePolicy().hasHeightForWidth());
        btn_div->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(btn_div, 1, 0, 1, 1);

        btn_pow = new QPushButton(centralwidget);
        btn_pow->setObjectName("btn_pow");
        sizePolicy1.setHeightForWidth(btn_pow->sizePolicy().hasHeightForWidth());
        btn_pow->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(btn_pow, 0, 0, 1, 1);

        btn_plus = new QPushButton(centralwidget);
        btn_plus->setObjectName("btn_plus");
        sizePolicy1.setHeightForWidth(btn_plus->sizePolicy().hasHeightForWidth());
        btn_plus->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(btn_plus, 4, 0, 1, 1);

        btn_mult = new QPushButton(centralwidget);
        btn_mult->setObjectName("btn_mult");
        sizePolicy1.setHeightForWidth(btn_mult->sizePolicy().hasHeightForWidth());
        btn_mult->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(btn_mult, 2, 0, 1, 1);

        btn_count = new QPushButton(centralwidget);
        btn_count->setObjectName("btn_count");

        gridLayout_3->addWidget(btn_count, 5, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 2, 1, 1, 1);

        cmb_controller = new QComboBox(centralwidget);
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->addItem(QString());
        cmb_controller->setObjectName("cmb_controller");

        gridLayout->addWidget(cmb_controller, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        btn_mem_get->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btn_reverse->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        btn_mem_clear->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        btn_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_mem_save->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        tb_extra->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btn_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn_backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        l_memory->setText(QCoreApplication::translate("MainWindow", "l_memory", nullptr));
        l_result->setText(QCoreApplication::translate("MainWindow", "l_result", nullptr));
        l_formula->setText(QCoreApplication::translate("MainWindow", "l_formula", nullptr));
        btn_minus->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        btn_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        btn_pow->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        btn_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_mult->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        btn_count->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        cmb_controller->setItemText(0, QCoreApplication::translate("MainWindow", "double", nullptr));
        cmb_controller->setItemText(1, QCoreApplication::translate("MainWindow", "float", nullptr));
        cmb_controller->setItemText(2, QCoreApplication::translate("MainWindow", "uint8_t", nullptr));
        cmb_controller->setItemText(3, QCoreApplication::translate("MainWindow", "int", nullptr));
        cmb_controller->setItemText(4, QCoreApplication::translate("MainWindow", "int64_t", nullptr));
        cmb_controller->setItemText(5, QCoreApplication::translate("MainWindow", "size_t", nullptr));
        cmb_controller->setItemText(6, QCoreApplication::translate("MainWindow", "Rational", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
