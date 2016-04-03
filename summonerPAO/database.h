#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QFile>          // the QFile class provides an interface for reading from and writing to files.
#include <QIODevice>
#include <QDomDocument>

#include "container.h"  // article.h included in container.h
#include "user.h"
#include "comment.h"

class Database {
public:
    void loadArticles();    // load from local_db.xml file
    void loadUsers();       // load from users.xml file
    void loadComments();    // load from comments.xml file
    void saveArticles();    // save on file articles.xml -> needed for updating the comments list & for adding new articles

    void insertArticle(Article*);   // add an article to the main articles container

    // SEARCH METODS
    // return a list of articles
    Container searchArticles(const QString&) const;
    // return a single article
    Article* searchArticle(const QString&) const;

    Container getArticlesDB() const;
    QVector<User*> getUsersDB() const;
private:
    Container artc;   // custom container for articles...
    QVector<User*> usr;
};

#endif // DATABASE_H
