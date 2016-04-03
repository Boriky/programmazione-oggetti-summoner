#include "loginui.h"
#include "ui_loginui.h"
#include <QDesktopWidget>

LoginUI::LoginUI(Database* d, User* u, QAction* act, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginUI),
    db(d), loginSession(u), actionNuovoArticolo(act)
{
    ui->setupUi(this);
    // force the interface in the center of the screen
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    db->loadUsers();
}

LoginUI::~LoginUI()
{
    delete ui;
}

void LoginUI::on_buttonClear_clicked()
{
    ui->textPassword->setText("");
    ui->textUser->setText("");
    ui->lblResult->hide();
}

void LoginUI::on_buttonLogin_clicked()
{
    QString username, password;
    username = ui->textUser->text();
    password = ui->textPassword->text();
    bool found = false;

    QVector<User*> users = db->getUsersDB();

    // check the login
    for(int i=0; !found && i < users.size(); ++i)
    {
        if(username == users[i]->getLogin()->getUsername() && password == users[i]->getLogin()->getPassword())
        {
            found = true;
            *loginSession = *users[i];
            ui->lblResult->setText("Valid Username and Password!");
            if(loginSession->isMod()) {
                actionNuovoArticolo->setVisible(true);
            }
            this->close();
        }
        else
        {
            ui->lblResult->show();
            ui->lblResult->setText("Wrong Username or Password!");
        }
    }
}

