/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *InputNum;
    QComboBox *Conversion;
    QLineEdit *Result;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(519, 266);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        InputNum = new QLineEdit(centralwidget);
        InputNum->setObjectName(QString::fromUtf8("InputNum"));

        verticalLayout->addWidget(InputNum);

        Conversion = new QComboBox(centralwidget);
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->addItem(QString());
        Conversion->setObjectName(QString::fromUtf8("Conversion"));

        verticalLayout->addWidget(Conversion);

        Result = new QLineEdit(centralwidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setReadOnly(true);

        verticalLayout->addWidget(Result);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 519, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        InputNum->setText(QString());
        Conversion->setItemText(0, QCoreApplication::translate("MainWindow", "Decimal to Binary", nullptr));
        Conversion->setItemText(1, QCoreApplication::translate("MainWindow", "Decimal to Octal", nullptr));
        Conversion->setItemText(2, QCoreApplication::translate("MainWindow", "Decimal to Hexadecimal", nullptr));
        Conversion->setItemText(3, QCoreApplication::translate("MainWindow", "Binary to Decimal", nullptr));
        Conversion->setItemText(4, QCoreApplication::translate("MainWindow", "Octal to Decimal", nullptr));
        Conversion->setItemText(5, QCoreApplication::translate("MainWindow", "Hexadecimal to Decimal", nullptr));
        Conversion->setItemText(6, QCoreApplication::translate("MainWindow", "Binary to Octal", nullptr));
        Conversion->setItemText(7, QCoreApplication::translate("MainWindow", "Binary to Hexadecimal", nullptr));
        Conversion->setItemText(8, QCoreApplication::translate("MainWindow", "Octal to Binary", nullptr));
        Conversion->setItemText(9, QCoreApplication::translate("MainWindow", "Octal to Hexadecimal", nullptr));
        Conversion->setItemText(10, QCoreApplication::translate("MainWindow", "Hexadecimal to Octal", nullptr));
        Conversion->setItemText(11, QCoreApplication::translate("MainWindow", "Hexadecimal to Binary", nullptr));

        Result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
