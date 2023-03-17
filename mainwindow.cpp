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
    //ui->swapButton->setStyleSheet("border-image: url(:/resources/img/swap.png);");
    on_InputNumComboBox_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    out.open("History.txt", ios :: app);
    num.number = ui->InputNum->text().toStdString();
    performConversion();
    out.close();
}


void MainWindow::on_InputNum_returnPressed()
{
    on_convertButton_clicked();
}

void MainWindow::on_ResultComboBox_currentIndexChanged(int index)
{
    on_convertButton_clicked();
}

void MainWindow::on_aboutButton_clicked()
{
    QMessageBox aboutDev(QMessageBox::NoIcon,"About Developer","This app is developed by Nazakat Umrani (21SW49)\nFor More information visit my Github Account\nGithub: github.com/nazakatumrani",QMessageBox::Close);
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

void MainWindow::on_InputNumComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        ui->ResultComboBox->setItemText(0, "Octal");
        ui->ResultComboBox->setItemText(1, "Decimal");
        ui->ResultComboBox->setItemText(2, "Hexadecimal");
    }
    else if(index == 1){
        ui->ResultComboBox->setItemText(0, "Binary");
        ui->ResultComboBox->setItemText(1, "Decimal");
        ui->ResultComboBox->setItemText(2, "Hexadecimal");
    }
    else if(index == 2){
        ui->ResultComboBox->setItemText(0, "Binary");
        ui->ResultComboBox->setItemText(1, "Octal");
        ui->ResultComboBox->setItemText(2, "Hexadecimal");
    }
    else if(index == 3){
        ui->ResultComboBox->setItemText(0, "Binary");
        ui->ResultComboBox->setItemText(1, "Octal");
        ui->ResultComboBox->setItemText(2, "Decimal");
    }
    on_convertButton_clicked();
}

void MainWindow::on_swapButton_clicked()
{
    QString tempStr = ui->InputNum->text();
    ui->InputNum->setText(ui->Result->text());
    ui->Result->setText(tempStr);
    int tempBox;
    tempBox = ui->InputNumComboBox->currentIndex();
    tempStr = ui->ResultComboBox->itemText(ui->ResultComboBox->currentIndex());
    if(tempStr == "Binary"){
        ui->InputNumComboBox->setCurrentIndex(0);
    }
    else if(tempStr == "Octal"){
        ui->InputNumComboBox->setCurrentIndex(1);
    }
    else if(tempStr == "Decimal"){
        ui->InputNumComboBox->setCurrentIndex(2);
    }
    else if(tempStr == "Hexadecimal"){
        ui->InputNumComboBox->setCurrentIndex(3);
    }
    if(tempBox == 0){
        ui->ResultComboBox->setCurrentIndex(ui->ResultComboBox->findText(QString::fromStdString("Binary")));
    }
    else if(tempBox == 1){
        ui->ResultComboBox->setCurrentIndex(ui->ResultComboBox->findText(QString::fromStdString("Octal")));
    }
    else if(tempBox == 2){
        ui->ResultComboBox->setCurrentIndex(ui->ResultComboBox->findText(QString::fromStdString("Decimal")));
    }
    else if(tempBox == 3){
        ui->ResultComboBox->setCurrentIndex(ui->ResultComboBox->findText(QString::fromStdString("Hexadecimal")));
    }
    //deletePreviousConversion(historyNum);
}

void MainWindow::performConversion(){
    if(ui->InputNumComboBox->currentIndex() == 0){
        if(ui->ResultComboBox->currentIndex() == 0){
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
        else if(ui->ResultComboBox->currentIndex() == 1){
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
        else if(ui->ResultComboBox->currentIndex() == 2){
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
    }
    else if(ui->InputNumComboBox->currentIndex() == 1){
        if(ui->ResultComboBox->currentIndex() == 0){
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
        else if(ui->ResultComboBox->currentIndex() == 1){
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
        else if(ui->ResultComboBox->currentIndex() == 2){
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
    }
    else if(ui->InputNumComboBox->currentIndex() == 2){
        if(ui->ResultComboBox->currentIndex() == 0){
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
        else if(ui->ResultComboBox->currentIndex() == 1){
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
        else if(ui->ResultComboBox->currentIndex() == 2){
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
    }
    else if(ui->InputNumComboBox->currentIndex() == 3){
        if(ui->ResultComboBox->currentIndex() == 0){
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
        else if(ui->ResultComboBox->currentIndex() == 1){
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
        else if(ui->ResultComboBox->currentIndex() == 2){
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
    }
    historyNum = num.string_plus(historyNum, "1");
}
