#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include <QToolBar>
#include "database.h"

namespace Ui {
class LoginUI;
}

class LoginUI : public QWidget
{
    Q_OBJECT

public:
    explicit LoginUI(Database* d, User* u, QAction* act, QWidget *parent = 0);
    ~LoginUI();

private slots:
    void on_buttonClear_clicked();

    void on_buttonLogin_clicked();

private:
    Ui::LoginUI *ui;

    Database* db;
    User* loginSession;
    QAction* actionNuovoArticolo;
};

#endif // LOGINUI_H
