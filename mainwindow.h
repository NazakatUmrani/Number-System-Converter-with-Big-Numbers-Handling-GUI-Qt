#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cliBigNumbersArithematic.hpp"
#include "cliNumberSystem.hpp"
#include "cliExtraFuncs.hpp"
#include <QMessageBox>
#include <QPixmap>
#include "historydialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend void deletePreviousConversion(string &n);

private slots:
    void performConversion();

    void on_convertButton_clicked();

    void on_InputNum_returnPressed();

    void on_aboutButton_clicked();

    void on_historyButton_clicked();

    void on_InputNumComboBox_currentIndexChanged(int index);

    void on_swapButton_clicked();

private:
    Ui::MainWindow *ui;
    ifstream in;
    ofstream out;
    string historyNum;
    Number_System num;
    HistoryDialog *histDialog;
};
#endif // MAINWINDOW_H
