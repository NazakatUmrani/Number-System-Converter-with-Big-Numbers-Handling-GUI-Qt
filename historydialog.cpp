#include "historydialog.h"
#include "ui_historydialog.h"
#include <QFile>
HistoryDialog::HistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryDialog)
{
    ui->setupUi(this);
    ifstream in2("History.txt");
    string line;
    string tempLine;
    do{
        getline(in2, line);
        ui->HistoryTextBox->setText(ui->HistoryTextBox->toPlainText()+QString::fromStdString(line+"\n"));
    }while(!in2.eof());
    in2.close();
}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}
