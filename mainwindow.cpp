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
    out.open("History.txt", ios :: app);
    num.number = ui->InputNum->text().toStdString();
    if(ui->Conversion->currentIndex() == 0){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
            return;
        }
        else{
            num.dtob();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 1){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
            return;
        }
        else{
            num.dtoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 2){
        num.numbercopy = num.number;
        if (num.is_decimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Decimal Number!");
            return;
        }
        else{
            num.dtoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 3){
        num.numbercopy = num.number;
        if (num.is_binary() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
            return;
        }
        else{
            num.btod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 4){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
            return;
        }
        else{
            num.otod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 5){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
            return;
        }
        else{
            num.htod();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")10" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 6){
        num.numbercopy = num.number;
        if (num.is_binary()== false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
            return;
        }
        else{
            num.btoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 7){
        num.numbercopy = num.number;
        if (num.is_binary() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Binary Number!");
            return;
        }
        else{
            num.btoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 8){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
            return;
        }
        else{
            num.otob();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 9){
        num.numbercopy = num.number;
        if (num.is_octal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Octal Number!");
            return;
        }
        else{
            num.otoh();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")16" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 10){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
            return;
        }
        else{
            num.htoo();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")8" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    else if(ui->Conversion->currentIndex() == 11){
        num.numbercopy = num.number;
        if (num.is_hexadecimal() == false){
            QMessageBox::warning(this, "Wrong Input","Entered Number is not a Hexadecimal Number!");
            return;
        }
        else{
            num.htob();
            ui->Result->setText(QString::fromStdString(num.result));
            out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")2" << endl;
            updateConversionsPerformed(historyNum);
        }
    }
    historyNum = num.string_plus(historyNum, "1");
}

void MainWindow::on_convertButton_clicked()
{
    performConversion();
    out.close();
}


void MainWindow::on_InputNum_returnPressed()
{
    on_convertButton_clicked();
}

void MainWindow::on_aboutButton_clicked()
{
    QMessageBox aboutDev(QMessageBox::NoIcon,"About Developer","This app is developed by Nazakat Umrani (21SW49)\nFor More information visit my Github Account\nGithub: github.com/nazakatumrani",QMessageBox::Ok);
    QPixmap devPic(":/resources/img/devPic.png");
    aboutDev.setIconPixmap(devPic.scaled(100,100,Qt::KeepAspectRatio));
    aboutDev.exec();
}

void MainWindow::on_historyButton_clicked()
{
    histDialog = new HistoryDialog(this);
    histDialog->setWindowTitle("History");
    histDialog->show();
}

