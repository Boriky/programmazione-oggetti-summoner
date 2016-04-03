#include "article.h"

/* IMPLEMENTATION OF ARTICLE */

Article::Article(const QString &i, const QString& titleP, const QString& genreP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    id(i), title(titleP), genre(genreP), date(dateP), author(authorP), comments(commentsV) {}

QString Article::getID() const { return id; }

QString Article::getTitle() const { return title; }

QString Article::getGenre() const { return genre; }

QVector<Comment*> Article::getComments() const { return comments; }

void Article::loadComments(QVector<Comment*> cmmt) { comments=cmmt; }

QString Article::getDate() const { return date; }

QString Article::getAuthor() const { return author; }

/* IMPLEMENTATION OF NEWS */

News::News(const QString &i, const QString& titleP, const QString& genreP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    Article(i, titleP, genreP, dateP, authorP, commentsV) {}

QString News::getCategory() const { return "news"; }

/* IMPLEMENTATION OF FEATURES */

Features::Features(const QString &i, const QString& titleP, const QString& genreP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    Article(i, titleP, genreP, dateP, authorP, commentsV) {}

QString Features::getCategory() const { return "features"; }

/* IMPLEMENTATION OF OPINION */

Opinion::Opinion(const QString& i, const QString& titleP, const QString& genreP, const QString& summaryP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    Article(i, titleP, genreP, dateP, authorP, commentsV), summary(summaryP) {}

QString Opinion::getSummary() const { return summary; }

QString Opinion::getCategory() const { return "opinion"; }

/* IMPLEMENTATION OF REVIEW */

Review::Review(const QString &i, const QString& titleP, const QString& genreP, int scoreP, const QString& summaryP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    Opinion(i, titleP, genreP, summaryP, dateP, authorP, commentsV), score(scoreP) {}

double Review::getScore() const { return score; }

QString Review::getCategory() const { return "review"; }

/* IMPLEMENTATION OF HANDSON */

HandsOn::HandsOn(const QString& i, const QString& titleP, const QString& genreP, const QString& summaryP, const QString& dateP, const QString& authorP, QVector<Comment*> commentsV) :
    Opinion(i, titleP, genreP, summaryP, dateP, authorP, commentsV) {}

QString HandsOn::getCategory() const { return "handson"; }
