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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::performConversion(){
    if(ui->Conversion->currentIndex() == 0){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
        }
        else{
            num.dtob();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 1){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
        }
        else{
            num.dtoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 2){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
        }
        else{
            num.dtoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 3){
        num.numbercopy = num.number;
        if (num.is_binary() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
        }
        else{
            num.btod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 4){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
        }
        else{
            num.otod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 5){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
        }
        else{
            num.htod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 6){
        num.numbercopy = num.number;
        if (num.is_binary()== false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
        }
        else{
            num.btoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 7){
        num.numbercopy = num.number;
        if (num.is_binary() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
        }
        else{
            num.btoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 8){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
        }
        else{
            num.otob();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 9){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
        }
        else{
            num.otoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 10){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
        }
        else{
            num.htoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
    else if(ui->Conversion->currentIndex() == 11){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
        }
        else{
            num.htob();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
        out.close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    out.open("History.txt", ios :: app);
    num.number = ui->InputNum->text().toStdString();
    performConversion();
    historyNum = num.string_plus(historyNum, "1");
}

