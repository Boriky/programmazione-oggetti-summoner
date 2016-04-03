#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDirIterator>
#include <QDesktopServices>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    // force the interface in the center of the screen
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    loginSession = new User;    // initialize

    searchResults = 0;  // initialize

    ui->actionNuovoArticolo->setVisible(false); // hide the NewArticle QAction in QToolBar ... only visibile for mods after login

    // READ ME:
    // with the constructor of MainWindow the program loads and displays all the articles inside the local xml database
    // MainWindow is the main window of the program

    // OPEN THE HTML RESOURCE

    db = new Database;

    db->loadArticles();  // load all the articles into database object

    Container articles = db->getArticlesDB();    // get the articles custom container

    // GUI NEWS ARCHIVE
    QWidget* newsArchive = new QWidget;
    QVBoxLayout* layout_NewsArchive = new QVBoxLayout;
    newsArchive->setLayout(layout_NewsArchive);

    QScrollArea* scrollArea_NewsArchive = new QScrollArea;
    QVBoxLayout* layout_scrollArea_NewsArchive = new QVBoxLayout;
    QWidget* baseAreaNews = new QWidget;
    baseAreaNews->setLayout(layout_scrollArea_NewsArchive);
    scrollArea_NewsArchive->setWidget(baseAreaNews);
    scrollArea_NewsArchive->setWidgetResizable(true);
    layout_NewsArchive->addWidget(scrollArea_NewsArchive);

    ui->verticalLayout_NewsPage->addWidget(newsArchive);

    // GUI OPINIONS ARCHIVE
    QWidget* opinionsArchive = new QWidget;
    QVBoxLayout* layout_OpinionsArchive = new QVBoxLayout;
    opinionsArchive->setLayout(layout_OpinionsArchive);

    QScrollArea* scrollArea_OpinionsArchive = new QScrollArea;
    QVBoxLayout* layout_scrollArea_OpinionsArchive = new QVBoxLayout;
    QWidget* baseAreaOpinions = new QWidget;
    baseAreaOpinions->setLayout(layout_scrollArea_OpinionsArchive);
    scrollArea_OpinionsArchive->setWidget(baseAreaOpinions);
    scrollArea_OpinionsArchive->setWidgetResizable(true);
    layout_OpinionsArchive->addWidget(scrollArea_OpinionsArchive);

    ui->verticalLayout_OpinionsPage->addWidget(opinionsArchive);

    // GUI FEATURES ARCHIVE
    QWidget* featuresArchive = new QWidget;
    QVBoxLayout* layout_FeaturesArchive = new QVBoxLayout;
    featuresArchive->setLayout(layout_FeaturesArchive);

    QScrollArea* scrollArea_FeaturesArchive = new QScrollArea;
    QVBoxLayout* layout_scrollArea_FeaturesArchive = new QVBoxLayout;
    QWidget* baseAreaFeatures = new QWidget;
    baseAreaFeatures->setLayout(layout_scrollArea_FeaturesArchive);
    scrollArea_FeaturesArchive->setWidget(baseAreaFeatures);
    scrollArea_FeaturesArchive->setWidgetResizable(true);
    layout_FeaturesArchive->addWidget(scrollArea_FeaturesArchive);

    ui->verticalLayout_FeaturesPage->addWidget(featuresArchive);

    // controllers for "for cycles"
    bool articleFound = false;
    int cNews = 0;
    int cOpinions = 0;
    int cFeatures = 0;

    // start to cycle through all the articles
    for(Container::Iterator it = articles.begin(); it!=articles.end(); ++it)
    {
        // the "featured textBrowser" displays only the most recent review, aka the first in order of appearence
        if(articles[it]->getCategory() == "review" || articles[it]->getCategory() == "handson")
        {
            QString id = articles[it]->getID();
            QDirIterator dirIt("html",QDirIterator::Subdirectories);    // file iterator for html extension

            // cycle trough all the html files
            while (dirIt.hasNext())
            {
                dirIt.next();
                QFileInfo fileInfo(dirIt.filePath());

                if (fileInfo.isFile() && fileInfo.suffix() == "html" && fileInfo.fileName() == id+".html")
                {
                    QUrl* resource = new QUrl(dirIt.filePath());

                    // DA COMPATTARE QUESTO CON CATEGORIA OPINION!!!!!!!!!!!!!!!!!!!!!!

                    QTextBrowser* singleOpinion = new QTextBrowser;
                    singleOpinion->setOpenExternalLinks(true);
                    singleOpinion->setMinimumSize(600,400);
                    singleOpinion->setSource(*resource);
                    singleOpinion->setText( singleOpinion->toHtml().mid(0,1500) + " [...]" );
                    QPushButton* singleOpinion_Title = new QPushButton;
                    //singleOpinion_Title->setFlat(true);
                    singleOpinion_Title->setText(articles[it]->getTitle());
                    connect(singleOpinion_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                    QFont* titleFont = new QFont;
                    titleFont->setBold(true);
                    singleOpinion_Title->setFont(*titleFont);
                    QVBoxLayout* layout_singleOpinion = new QVBoxLayout;
                    layout_singleOpinion->addWidget(singleOpinion_Title);
                    layout_singleOpinion->addWidget(singleOpinion);
                    layout_scrollArea_OpinionsArchive->addLayout(layout_singleOpinion);

                    if(cOpinions<4) {
                        QTextBrowser* textBrowser_Opinions = new QTextBrowser;
                        textBrowser_Opinions->setMinimumSize(180,200);
                        textBrowser_Opinions->setSource(*resource);
                        QPushButton* homeOpinions_Title = new QPushButton;
                        homeOpinions_Title->setText(articles[it]->getTitle());
                        homeOpinions_Title->setMinimumWidth(195);
                        connect(homeOpinions_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                        QFont* titleFontH = new QFont;
                        titleFontH->setBold(true);

                        homeOpinions_Title->setFont(*titleFontH);
                        textBrowser_Opinions->setText(textBrowser_Opinions->toPlainText().mid(0,350) + " [...]");
                        QVBoxLayout* layout_homeOpinions = new QVBoxLayout;
                        layout_homeOpinions->addWidget(homeOpinions_Title);
                        layout_homeOpinions->addWidget(textBrowser_Opinions);
                        ui->horizontalLayout_Opinions_2->addLayout(layout_homeOpinions);
                        cOpinions++;
                    }

                    if(articles[it]->getCategory() == "review" && !articleFound)
                    {
                        ui->textBrowser_Featured_2->setSource(*resource);
                        ui->textBrowser_Featured_2->setText( ui->textBrowser_Featured_2->toHtml().mid(0,1500) + " [...]" );
                        ui->pushButton_TitleFeatured->setText(articles[it]->getTitle());
                        connect(ui->pushButton_TitleFeatured,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                        articleFound=true;  // most recent review displayed
                    }
                }
            }
        }
        // display only the first 4 most recent news!
        else if(articles[it]->getCategory() == "news")
        {
            QString id = articles[it]->getID();
            QDirIterator dirIt("html",QDirIterator::Subdirectories);    // file iterator for html extension
            // cycle trough all the html files
            while (dirIt.hasNext())
            {
                dirIt.next();
                QFileInfo fileInfo(dirIt.filePath());

                if (fileInfo.isFile() && fileInfo.suffix() == "html" && fileInfo.fileName() == id+".html")
                {
                    QUrl* resource = new QUrl(dirIt.filePath());

                    QTextBrowser* singleNews = new QTextBrowser;
                    singleNews->setOpenExternalLinks(true);
                    singleNews->setMinimumSize(600,400);
                    singleNews->setSource(*resource);
                    singleNews->setText( singleNews->toHtml().mid(0,1500) + " [...]" );
                    QPushButton* singleNews_Title = new QPushButton;
                    //singleNews_Title->setFlat(true);
                    singleNews_Title->setText(articles[it]->getTitle());
                    connect(singleNews_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                    QFont* titleFont = new QFont;
                    titleFont->setBold(true);
                    singleNews_Title->setFont(*titleFont);
                    QVBoxLayout* layout_singleNews = new QVBoxLayout;
                    layout_singleNews->addWidget(singleNews_Title);
                    layout_singleNews->addWidget(singleNews);
                    layout_scrollArea_NewsArchive->addLayout(layout_singleNews);

                    if(cNews<4)
                    {
                        QTextBrowser* textBrowser_News = new QTextBrowser;
                        textBrowser_News->setMinimumSize(180,200);
                        textBrowser_News->setSource(*resource);
                        QPushButton* homeNews_Title = new QPushButton;
                        homeNews_Title->setText(articles[it]->getTitle());
                        homeNews_Title->setMinimumWidth(195);
                        connect(homeNews_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                        QFont* titleFontH = new QFont;
                        titleFontH->setBold(true);

                        homeNews_Title->setFont(*titleFontH);
                        textBrowser_News->setText(textBrowser_News->toPlainText().mid(0,350) + " [...]");
                        QVBoxLayout* layout_homeNews = new QVBoxLayout;
                        layout_homeNews->addWidget(homeNews_Title);
                        layout_homeNews->addWidget(textBrowser_News);
                        ui->horizontalLayout_News_2->addLayout(layout_homeNews);
                        cNews++;
                    }
                }
            }
        }
        // display only the first 4 most recent features!
        else if(articles[it]->getCategory() == "features")
        {
            QString id = articles[it]->getID();
            QDirIterator dirIt("html",QDirIterator::Subdirectories);    // file iterator for html extension
            // cycle trough all the html files
            while (dirIt.hasNext())
            {
                dirIt.next();
                QFileInfo fileInfo(dirIt.filePath());

                if (fileInfo.isFile() && fileInfo.suffix() == "html" && fileInfo.fileName() == id+".html")
                {
                    QUrl* resource = new QUrl(dirIt.filePath());

                    QTextBrowser* singleFeatures = new QTextBrowser;
                    singleFeatures->setOpenExternalLinks(true);
                    singleFeatures->setMinimumSize(600,400);
                    singleFeatures->setSource(*resource);
                    singleFeatures->setText( singleFeatures->toHtml().mid(0,2000) + " [...]" );
                    QPushButton* singleFeatures_Title = new QPushButton;
                    //singleFeatures_Title->setFlat(true);
                    singleFeatures_Title->setText(articles[it]->getTitle());
                    connect(singleFeatures_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                    QFont* titleFont = new QFont;
                    titleFont->setBold(true);
                    singleFeatures_Title->setFont(*titleFont);
                    QVBoxLayout* layout_singleFeatures = new QVBoxLayout;
                    layout_singleFeatures->addWidget(singleFeatures_Title);
                    layout_singleFeatures->addWidget(singleFeatures);
                    layout_scrollArea_FeaturesArchive->addLayout(layout_singleFeatures);

                    if(cFeatures<4)
                    {
                        QTextBrowser* textBrowser_Features = new QTextBrowser;
                        textBrowser_Features->setMinimumSize(180,200);
                        textBrowser_Features->setSource(*resource);
                        QPushButton* homeFeatures_Title = new QPushButton;
                        homeFeatures_Title->setText(articles[it]->getTitle());
                        homeFeatures_Title->setMinimumWidth(195);
                        connect(homeFeatures_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                        QFont* titleFontH = new QFont;
                        titleFontH->setBold(true);

                        homeFeatures_Title->setFont(*titleFontH);
                        textBrowser_Features->setText(textBrowser_Features->toPlainText().mid(0,350) + " [...]");
                        QVBoxLayout* layout_homeFeatures = new QVBoxLayout;
                        layout_homeFeatures->addWidget(homeFeatures_Title);
                        layout_homeFeatures->addWidget(textBrowser_Features);
                        ui->horizontalLayout_Features_2->addLayout(layout_homeFeatures);
                        cFeatures++;
                    }
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    db->saveArticles();
}

// SLOT that OPENS www.summoner.it website on default browser :)

void MainWindow::on_actionLogo_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.summoner.it/"));
}

// SLOTS NEEDED TO CYCLE THROUGH ALL THE MAINWINDOW PAGES

void MainWindow::on_actionHome_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}

void MainWindow::on_actionNews_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->newsPage);
}

void MainWindow::on_actionOpinioni_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->opinionsPage);
}

void MainWindow::on_actionFeatures_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->featuresPage);
}

void MainWindow::on_actionLogIn_triggered()
{
    LoginUI* login_ui = new LoginUI(db, loginSession, ui->actionNuovoArticolo);
    login_ui->show();
}

// SEARCH FUNCTION

void MainWindow::on_searchButton_clicked()
{
    ui->label_searchResults->setText("RISULTATO DELLA RICERCA"); // reset the search result label feedback

    ui->stackedWidget->setCurrentIndex(4); // display the searchResults page

    QString match = ui->searchBox->text(); // store the input from the user

    Container temp = db->searchArticles(match); // get the group of articles containing the match of string

    if(!temp.isEmpty())
    {
        if(searchResults)
            delete searchResults;  // reset the windows content
        // GUI SEARCH RESULTS
        searchResults = new QWidget;
        QVBoxLayout* layout_searchResults = new QVBoxLayout;
        searchResults->setLayout(layout_searchResults);

        QScrollArea* scrollArea_searchResults = new QScrollArea;
        QVBoxLayout* layout_scrollArea_searchResults = new QVBoxLayout;
        QWidget* baseAreaSearchResults = new QWidget;
        baseAreaSearchResults->setLayout(layout_scrollArea_searchResults);
        scrollArea_searchResults->setWidget(baseAreaSearchResults);
        scrollArea_searchResults->setWidgetResizable(true);
        layout_searchResults->addWidget(scrollArea_searchResults);

        ui->verticalLayout_SearchResults->addWidget(searchResults);

        for(Container::Iterator it = temp.begin(); it!=temp.end(); ++it)  // if the article's been found...
        {

            QString id = temp[it]->getID();
            QDirIterator dirIt("html",QDirIterator::Subdirectories);    // file iterator for html extension
            // cycle trough all the html files
            while (dirIt.hasNext())
            {
                dirIt.next();
                QFileInfo fileInfo(dirIt.filePath());

                if (fileInfo.isFile() && fileInfo.suffix() == "html" && fileInfo.fileName() == id+".html")
                    {
                        QUrl* resource = new QUrl(dirIt.filePath());

                        QTextBrowser* textBrowser_searchResults = new QTextBrowser;
                        textBrowser_searchResults->setMinimumSize(600,450);
                        textBrowser_searchResults->setSource(*resource);
                        textBrowser_searchResults->setText( textBrowser_searchResults->toHtml().mid(0,1500) + " [...]" );
                        QPushButton* searchResults_Title = new QPushButton;
                        searchResults_Title->setText(temp[it]->getTitle());
                        QFont* titleFont = new QFont;
                        titleFont->setBold(true);
                        searchResults_Title->setFont(*titleFont);
                        connect(searchResults_Title,SIGNAL(clicked()),this,SLOT(on_dynamicTitle_clicked()));
                        QVBoxLayout* layout_searchResultsTEXT = new QVBoxLayout;
                        layout_searchResultsTEXT->addWidget(searchResults_Title);
                        layout_searchResultsTEXT->addWidget(textBrowser_searchResults);
                        layout_scrollArea_searchResults->addLayout(layout_searchResultsTEXT);
                    }
            }
        }
    }
    else
    {
        ui->label_searchResults->setText(ui->label_searchResults->text() + ": NESSUN RISULTATO TROVATO!");
    }
}

// INTERFACE FOR SINGLE ARTICLE + COMMENTS

void MainWindow::on_dynamicTitle_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString title = button->text();
    dynamicArticle = db->searchArticle(title);
    if(dynamicArticle)
    {
        QWidget* displayArticle = new QWidget;
        displayArticle->setMinimumSize(800,800);
        QVBoxLayout* layout_displayArticle = new QVBoxLayout;
        displayArticle->setLayout(layout_displayArticle);

        QScrollArea* scrollArea_displayArticle = new QScrollArea;
        QVBoxLayout* layout_scrollArea_displayArticle = new QVBoxLayout;
        QWidget* baseAreadisplayArticle = new QWidget;
        baseAreadisplayArticle->setLayout(layout_scrollArea_displayArticle);
        scrollArea_displayArticle->setWidget(baseAreadisplayArticle);
        scrollArea_displayArticle->setWidgetResizable(true);
        layout_displayArticle->addWidget(scrollArea_displayArticle);

        QString id = dynamicArticle->getID();
        QDirIterator dirIt("html",QDirIterator::Subdirectories);    // file iterator for html extension
        // cycle trough all the html files
        while (dirIt.hasNext())
        {
            dirIt.next();
            QFileInfo fileInfo(dirIt.filePath());

            if (fileInfo.isFile() && fileInfo.suffix() == "html" && fileInfo.fileName() == id+".html")
                {
                    QUrl* resource = new QUrl(dirIt.filePath());

                    QTextBrowser* textBrowser_displayArticle = new QTextBrowser;
                    textBrowser_displayArticle->setOpenExternalLinks(true);
                    textBrowser_displayArticle->setMinimumSize(0,450);
                    textBrowser_displayArticle->setSource(*resource);
                    QLabel* displayArticle_Title = new QLabel;
                    displayArticle_Title->setText(dynamicArticle->getTitle());
                    QFont* titleFont = new QFont;
                    titleFont->setBold(true);
                    displayArticle_Title->setFont(*titleFont);
                    QVBoxLayout* layout_displayArticleTEXT = new QVBoxLayout;
                    layout_displayArticleTEXT->addWidget(displayArticle_Title);
                    layout_displayArticleTEXT->addWidget(textBrowser_displayArticle);
                    layout_scrollArea_displayArticle->addLayout(layout_displayArticleTEXT);
                }
        }

        // Opinion box / Review box
        Opinion* ptrOP = dynamic_cast<Opinion*>(dynamicArticle);
        if(ptrOP) {
            QTextBrowser* textBrowser_OpinionBox = new QTextBrowser;
            textBrowser_OpinionBox->setMinimumSize(0,100);
            textBrowser_OpinionBox->setText(ptrOP->getSummary());
            QLabel* OpinionBox_Title = new QLabel;
            Review* ptrRW = dynamic_cast<Review*>(ptrOP);
            if(ptrRW)
                OpinionBox_Title->setText("Conclusione - Voto: " + QString::number(ptrRW->getScore()) + "/10");
            else
                OpinionBox_Title->setText("Conclusione");
            QFont* titleFont = new QFont;
            titleFont->setBold(true);
            OpinionBox_Title->setFont(*titleFont);
            QVBoxLayout* layout_OpinionBox = new QVBoxLayout;
            layout_OpinionBox->addWidget(OpinionBox_Title);
            layout_OpinionBox->addWidget(textBrowser_OpinionBox);
            layout_scrollArea_displayArticle->addLayout(layout_OpinionBox);
        }

        comments = dynamicArticle->getComments();

        textEdit_insertComment = new QTextEdit;
        QPushButton* button_insertComment = new QPushButton;
        button_insertComment->setText("Pubblica commento");
        connect(button_insertComment,SIGNAL(clicked()),this,SLOT(on_button_insertComment_clicked()));
        QHBoxLayout* layout_insertComment = new QHBoxLayout;
        layout_insertComment->addWidget(textEdit_insertComment);
        layout_insertComment->addWidget(button_insertComment);
        layout_scrollArea_displayArticle->addLayout(layout_insertComment);

        for(QVector<Comment*>::iterator it = comments.begin(); it!=comments.end(); ++it)
        {
            QTextBrowser* textBrowser_comment = new QTextBrowser;
            textBrowser_comment->setText((*it)->getText());
            QLabel* autorName = new QLabel;
            autorName->setText((*it)->getUser());
            QVBoxLayout* layout_comment = new QVBoxLayout;
            layout_comment->addWidget(autorName);
            layout_comment->addWidget(textBrowser_comment);
            layout_scrollArea_displayArticle->addLayout(layout_comment);

            if(loginSession->isMod())
            {
                CommentButton* button_deleteComment = new CommentButton(it,db,&comments,dynamicArticle,displayArticle);
                button_deleteComment->setText("Elimina commento ^");

                connect(button_deleteComment,SIGNAL(clicked()),button_deleteComment,SLOT(on_button_deleteComment_clicked()));

                layout_comment->addWidget(button_deleteComment);
            }
        }
        displayArticle->showMaximized();
    }
}

void MainWindow::on_button_insertComment_clicked()
{
    if(loginSession->getLogin())
    {
        QString temp = textEdit_insertComment->toPlainText();
        Comment* comment = new Comment(loginSession->getLogin()->getUsername(), "test", temp);

        comments.push_back(comment);

        dynamicArticle->loadComments(comments);

        for(int i=0; i<comments.size(); i++)
        {
            qDebug() << comments[i]->getText();
        }
    }
    else
    {
        LoginUI* login_ui = new LoginUI(db, loginSession, ui->actionNuovoArticolo);
        login_ui->show();
    }
}

void CommentButton::on_button_deleteComment_clicked()
{
    CommentButton* button = qobject_cast<CommentButton*>(sender());
    button->pV->erase(it);
    button->pda->loadComments(*pV);
    button->db->saveArticles();
    button->qw->close();
}

void MainWindow::on_actionNuovoArticolo_triggered()
{
    newArticle* newArticle_ui = new newArticle(db,loginSession);
    newArticle_ui->show();
}

// IMPLEMENTATION OF CLASS COMMENTBUTTON

CommentButton::CommentButton(QVector<Comment*>::iterator i, Database * d, QVector<Comment*>* v, Article* da, QWidget* w) : it(i), db(d), pV(v), pda(da), qw(w) {}
