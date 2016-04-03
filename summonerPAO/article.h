#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QVector>
#include "user.h"
#include "comment.h"

class Article {
public:
    // an Article is made of Title, Genre, Date, Author, Comments and an unique ID.
    // the body of the Article is stored in a specific html file
    Article(const QString&, const QString&, const QString&, const QString&, const QString&, QVector<Comment*>);
    virtual ~Article() {}
    QString getID() const;
    QString getTitle() const;
    QString getGenre() const;
    QString getDate() const;                 // get the publication date of the article
    QString getAuthor() const;               // get the author that made the article
    QVector<Comment*> getComments() const;
    void loadComments(QVector<Comment*>);
    virtual QString getCategory() const = 0;

private:
    QString id;      // name of file
    QString title;
    QString genre;
    QString date;
    QString author;  // author that made the article
    QVector<Comment*> comments;
};

class News : public Article {
public:
    News(const QString&, const QString&, const QString&, const QString&, const QString&, QVector<Comment*>);

    virtual QString getCategory() const;
};


class Features : public Article {
public:
    Features(const QString&, const QString&, const QString&, const QString&, const QString&, QVector<Comment*>);

    virtual QString getCategory() const;
};


class Opinion : public Article {
public:
    Opinion(const QString &, const QString&, const QString&, const QString&, const QString&, const QString&, QVector<Comment*>);
    QString getSummary() const;

    virtual QString getCategory() const;

private:
    QString summary;
};


class Review : public Opinion {
public:
    Review(const QString&, const QString&, const QString&, int, const QString&, const QString&, const QString&, QVector<Comment*>);
    double getScore() const;

    virtual QString getCategory() const;

private:
    int score;
    // score format: .../100
};


class HandsOn : public Opinion {
public:
    HandsOn(const QString &, const QString&, const QString&, const QString&, const QString&, const QString&, QVector<Comment*>);

    virtual QString getCategory() const;
};

#endif // ARTICLE_H
