#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "database.h"
#include "loginui.h"
#include "newarticle.h"

namespace Ui {
class MainWindow;
}

// auxiliary specific Button for deleting comments
class CommentButton : public QPushButton {
    Q_OBJECT
public:
    ~CommentButton() {}
    CommentButton(const CommentButton& cb){}
    CommentButton(QVector<Comment*>::iterator i = 0, Database * d = 0, QVector<Comment*>* v = 0, Article* da = 0, QWidget* w =0);

private slots:
    void on_button_deleteComment_clicked();

private:
    QVector<Comment*>::iterator it;
    QVector<Comment*>* pV;
    Database* db;
    Article* pda;
    QWidget* qw;
};

Q_DECLARE_METATYPE(CommentButton);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Database* getDatabase() { return db; }

signals:

private slots:
    void on_actionHome_triggered();

    void on_actionNews_triggered();

    void on_actionOpinioni_triggered();

    void on_actionFeatures_triggered();

    void on_searchButton_clicked();

    void on_dynamicTitle_clicked();

    void on_button_insertComment_clicked();

    void on_actionLogIn_triggered();

    void on_actionNuovoArticolo_triggered();

    void on_actionLogo_triggered();

private:
    Ui::MainWindow *ui;

    Database* db;
    Article* dynamicArticle;
    User* loginSession;

    //GUI
    QWidget* searchResults;
    QVector<Comment*> comments;
    QTextEdit* textEdit_insertComment;
};

#endif // MAINWINDOW_H
