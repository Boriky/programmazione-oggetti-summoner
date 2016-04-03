#ifndef COMMENT_H
#define COMMENT_H

#include <QString>

class Comment
{
public:
    Comment(const QString &usr, const QString &dt, const QString &txt);
    QString getUser() const;
    QString getDate() const;
    QString getText() const;
private:
    QString user;
    QString date;
    QString text;
};

#endif // COMMENT_H
