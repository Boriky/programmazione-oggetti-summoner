#include "mainwindow.h"
#include <QApplication>

#include "database.h"

#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // DEBUG DATABASE

    /*Database db;
    db.loadArticles();
    db.loadComments();
    db.loadUsers();

    Container articles = db.getArticlesDB();
    QVector<User*> users = db.getUsersDB();
    QVector<Comment*> comments = db.getCommentsDB();

    for(Container::Iterator it = articles.begin(); it!=articles.end(); ++it)
    {
       qDebug() << articles[it]->getTitle() << articles[it]->getCategory();
    }

    for(int i=0; i<comments.size(); ++i)
    {
        qDebug() << comments[i]->getUser() << comments[i]->getArticleTitle() << comments[i]->getDate() << comments[i]->getText();
    }

    for(int i=0; i<users.size(); ++i)
    {
       qDebug() << users[i]->getLogin()->getUsername() << users[i]->getLogin()->getEmail() << users[i]->getLogin()->getPassword();
    }*/

    // FINE DEBUG DB

    MainWindow w;
    w.show();

    return a.exec();
}
