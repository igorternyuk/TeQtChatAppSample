#include "connectiondialog.hpp"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_btnAccept_clicked()
{
    mHostname = ui->txtHostname->text();
    mPort = ui->spinnerPort->value();
    this->accept();
}

void ConnectionDialog::on_btnReject_clicked()
{
    this->reject();
}

quint16 ConnectionDialog::port() const
{
    return mPort;
}

QString ConnectionDialog::hostname() const
{
    return mHostname;
}
