#include <QDateTime>
#include <QDesktopWidget>
#include "newarticle.h"
#include "ui_newarticle.h"

newArticle::newArticle(Database *d, User *u, QWidget *parent) :
    QWidget(parent),
    db(d), loginSession(u),
    ui(new Ui::newArticle)
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
}

newArticle::~newArticle()
{
    delete ui;
}

void newArticle::on_pushButton_clicked()
{
    QString id = ui->lineEditNameOfFile->text();
    QString title = ui->lineEditTitle->text();
    QString html = ui->textEditHTML->toHtml();
    QString category = ui->boxCategory->currentText();
    QString genre = ui->boxGenre->currentText();
    QString date = QDateTime::currentDateTimeUtc().date().toString();
    QString author = loginSession->getLogin()->getUsername();
    QString summary = ui->textEditSummary->toPlainText();
    QVector<Comment*> cmmt;
    bool okSCORE;
    int score = (ui->lineEditScore->text()).toInt(&okSCORE, 10);
    if(!okSCORE && category=="Review") {
        QWidget* errorScore = new QWidget;
        errorScore->setMinimumSize(150,150);
        QVBoxLayout* layout_errorScore = new QVBoxLayout;
        errorScore->setLayout(layout_errorScore);
        QLabel* errorText = new QLabel;
        errorText->setText("ERRORE PUNTEGGIO VALUTAZIONE: inserire un valore da 0 a 10 intero!");
        layout_errorScore->addWidget(errorText);
        errorScore->show();
    }
    else {
        if(category == "News")
        {
            Article* t = new News(id, title, genre, date, author, cmmt);
            db->insertArticle(t);
        }
        else if(category == "Features")
        {
            Article* t = new Features(id, title, genre, date, author, cmmt);
            db->insertArticle(t);
        }
        else if(category == "Recensione")
        {
            Opinion* t = new Review(id, title, genre, score, summary, date, author, cmmt);
            qDebug() << t->getTitle();
            db->insertArticle(t);
        }
        else if(category == "Hands-On")
        {
            Opinion* t = new HandsOn(id, title, genre, summary, date, author, cmmt);
            db->insertArticle(t);
        }
        db->saveArticles();

        QFile file( "html/" + id + ".html" );
        if( !file.open( QIODevice::WriteOnly ) )
            qDebug() << "ERROR: Cannot open file "+ id + ".html for writing!";
        QTextStream ts( &file );
        ts << html;
        file.close();

        delete this;
    }
}
