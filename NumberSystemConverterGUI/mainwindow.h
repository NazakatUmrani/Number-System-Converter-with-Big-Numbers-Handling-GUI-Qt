#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cliBigNumbersArithematic.hpp"
#include "cliNumberSystem.hpp"
#include "cliExtraFuncs.hpp"
#include <QMessageBox>

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
    void performConversion();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ifstream in;
    ofstream out;
    string historyNum;
    Number_System num;
};
#endif // MAINWINDOW_H
