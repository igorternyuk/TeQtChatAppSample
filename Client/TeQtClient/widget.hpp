#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class Widget;
}

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnSend_clicked();
    void on_btnConnect_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};

#endif // WIDGET_HPP
