#ifndef NEWARTICLE_H
#define NEWARTICLE_H

#include <QWidget>
#include "database.h"

namespace Ui {
class newArticle;
}

class newArticle : public QWidget
{
    Q_OBJECT

public:
    explicit newArticle(Database* d, User* u, QWidget *parent = 0);
    ~newArticle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newArticle *ui;

    Database* db;
    User* loginSession;
};

#endif // NEWARTICLE_H
