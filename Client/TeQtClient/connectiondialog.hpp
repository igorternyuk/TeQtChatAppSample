#ifndef CONNECTIONDIALOG_HPP
#define CONNECTIONDIALOG_HPP

#include <QDialog>

namespace Ui
{
    class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    QString hostname() const;
    quint16 port() const;

private slots:
    void on_btnAccept_clicked();

    void on_btnReject_clicked();

private:
    Ui::ConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};

#endif // CONNECTIONDIALOG_HPP
