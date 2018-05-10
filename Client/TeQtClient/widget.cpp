#include "widget.hpp"
#include "ui_widget.h"
#include "connectiondialog.hpp"
#include <QTextStream>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream stream(mSocket);
        auto msg = stream.readAll();
        ui->listWidget->addItem(msg);
        mSocket->flush();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnSend_clicked()
{
    if(mSocket)
    {
        QTextStream stream(mSocket);
        stream << ui->txtNickname->text() << ": " << ui->txtMessage->text();
        mSocket->flush();
        ui->txtMessage->clear();
    }
}

void Widget::on_btnConnect_clicked()
{
    ConnectionDialog dialog;
    if(dialog.exec() == ConnectionDialog::Accepted)
    {
        auto hostname = dialog.hostname();
        quint16 port = dialog.port();
        mSocket->connectToHost(hostname, port);
    }
}
