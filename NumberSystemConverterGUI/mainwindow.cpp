#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    in.open("History.txt");
    if (!getline(in, historyNum)){
        historyNum = "1";
        out.open("History.txt");
        out << "0 Conversions Performed" << endl;
        in.close();
        out.close();
    }
    else{
        in.close();
        in.open("History.txt");
        in >> historyNum;
        historyNum = num.string_plus(historyNum, "1");
        in.close();
    }
    out.open("History.txt", ios :: app);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Conversion_currentIndexChanged(int index)
{
    if(index ==0){
        num.number = ui->InputNum->text().toStdString();
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            cout << "Entered Value is not a Decimal Number...!" << endl;
        }
        else{
            num.dtob();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
}
