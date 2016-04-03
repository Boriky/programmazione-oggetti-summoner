#include "database.h"

/* IMPLEMENTATION OF DATABASE */

// load all articles from articles.xml

void Database::loadArticles()
{
    // store articles.xml in QFile file and check if the file has openened...
    QFile fileArticles("localDatabase/articles.xml");
    if (!fileArticles.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "ERROR: Cannot open file articles.xml for reading!";
    }
    // ... If an error occurred, show the "parse error" at "line" and "column"
    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;
    if (!doc.setContent(&fileArticles, false, &errorStr, &errorLine, &errorColumn))
    {
        qDebug() << "ERROR: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr);
    }

    QDomElement articles = doc.documentElement(); // return the root element <articles> of the xml

    QDomElement article = articles.firstChild().toElement(); // return the child element <article> from <articles>

    while(!article.isNull())
    {
        QString id = article.attribute("id");
        QString title = article.attribute("title");
        QString category = article.attribute("category");
        QString genre = article.attribute("genre");
        QString date = article.attribute("date");
        QString author = article.attribute("author");
        QString summary = article.attribute("summary");
        bool okSCORE;
        int score = article.attribute("score").toInt(&okSCORE, 10);

        QDomElement comments = article.firstChild().toElement();

        QVector<Comment*> cmmt;

        if(!comments.isNull())
        {
            QDomElement comment = comments.firstChild().toElement(); // return the child element <comments> from <comments>

            while(!comment.isNull())
            {
                QString user = comment.attribute("user");
                QString date = comment.attribute("date");
                QString text = comment.attribute("text");

                Comment* temp = new Comment(user,date,text);

                cmmt.push_back(temp);   // load the comment into the comments vector

                comment = comment.nextSibling().toElement();    // go to the next <comment> node!
            }
        }

        if(category == "news")
        {
            Article* t = new News(id, title, genre, date, author, cmmt);
            artc.insertBack(t);
        }
        else if(category == "features")
        {
            Article* t = new Features(id, title, genre, date, author, cmmt);
            artc.insertBack(t);
        }
        else if(category == "review")
        {
            Article* t = new Review(id, title, genre, score, summary, date, author, cmmt);
            artc.insertBack(t);
        }
        else if(category == "handson")
        {
            Article* t = new HandsOn(id, title, genre, summary, date, author, cmmt);
            artc.insertBack(t);
        }

        article = article.nextSibling().toElement();    // go to the next <article> node!
    }
}

// load all users from users.xml

void Database::loadUsers()
{
    // store users.xml in QFile file and check if the file has openened...
    QFile file("localDatabase/users.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "ERROR: Cannot open file users.xml for reading!";
    }
    // ... If an error occurred, show the "parse error" at "line" and "column"
    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        qDebug() << "ERROR: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr);
    }

    QDomElement users = doc.documentElement(); // returns the root element <users> of the xml

    QDomElement user = users.firstChild().toElement(); // return the child element <user> from <users>

    while(!user.isNull())
    {
        QString username = user.attribute("username");
        QString email = user.attribute("email");
        QString password = user.attribute("password");
        QString isMod = user.attribute("isMod");
        QString bio = user.attribute("bio");

        Login* log = new Login(username, email, password);
        Profile* prf = new Profile(bio);

        if(isMod == "true")
        {
            User* temp = new Moderator(log,prf);
            usr.push_back(temp);    // load the user into the database
        }
        else
        {
            User* temp = new Subscriber(log,prf);
            usr.push_back(temp);
        }

        user = user.nextSibling().toElement();    // go to the next <article> node!
    }
}

void Database::saveArticles()
{
    // CREATE NEW FILE
    // FILL NEW FILE WITH INFOS
    // OVERWRITE OLD FILE

    QDomDocument doc;
    QDomElement articles = doc.createElement("articles"); //root
    doc.appendChild(articles);

    for(Container::Iterator it=artc.begin(); it!=artc.end(); ++it)
    {
        QDomElement article = doc.createElement("article");
        articles.appendChild(article);

        QString id = artc[it]->getID();
        QString title = artc[it]->getTitle();
        QString category = artc[it]->getCategory();
        QString genre = artc[it]->getGenre();
        QString date = artc[it]->getDate();
        QString author = artc[it]->getAuthor();

        article.setAttribute("id", id);
        article.setAttribute("title", title);
        article.setAttribute("category", category);
        article.setAttribute("genre", genre);
        article.setAttribute("date", date);
        article.setAttribute("author", author);

        QString score;
        QString summary;

        Opinion* ptrOP = dynamic_cast<Opinion*>(artc[it]);
        if(ptrOP) {
            summary = ptrOP->getSummary();
            Review* ptrRW = dynamic_cast<Review*>(artc[it]);
            if(ptrRW)
                score = QString::number(ptrRW->getScore());
            else
                score="";
        }
        else {
            summary="";
            score="";
        }

        article.setAttribute("summary", summary);
        article.setAttribute("score", score);

        QDomElement comments = doc.createElement("comments");
        article.appendChild(comments);
        QVector<Comment*> cmtV = artc[it]->getComments();
        for(int i=0; i<cmtV.size(); ++i)
        {
            QDomElement comment = doc.createElement("comment");
            comments.appendChild(comment);

            QString user = cmtV[i]->getUser();
            QString dateC = cmtV[i]->getDate();
            QString text = cmtV[i]->getText();

            comment.setAttribute("user", user);
            comment.setAttribute("date", dateC);
            comment.setAttribute("text", text);
        }
    }

    QFile::copy("localDatabase/articles.xml", "localBase/articles_backup.xml");

    QFile file( "localDatabase/articles.xml" );
    if( !file.open( QIODevice::WriteOnly ) )
        qDebug() << "ERROR: Cannot open file articles.xml for writing!";

    QTextStream ts( &file );

    ts << doc.toString();

    file.close();
}

// search for a match in articles titles and return a single article
Article* Database::searchArticle(const QString& match) const {
    for(Container::Iterator it = artc.begin(); it!=artc.end() && match!=""; ++it)
    {
        QString temp = artc[it]->getTitle();
        qDebug() << artc[it]->getTitle();
        if(temp.contains(match, Qt::CaseInsensitive))
        {
            return artc[it];
        }
    }
    return 0;
}

// search for a match in articles titles and return a list of matching articles
Container Database::searchArticles(const QString & match) const
{
    Container ris;
    bool ok = false;
    for(Container::Iterator it = artc.begin(); it!=artc.end() && match!=""; ++it)
    {
        QString temp = artc[it]->getTitle();
        qDebug() << artc[it]->getTitle();
        if(temp.contains(match, Qt::CaseInsensitive))
        {
            ris.insertBack(artc[it]);
            ok = true;
        }
    }
    if(ok)
        return ris;
}

// insert on the head of the container
void Database::insertArticle(Article* art) { artc.insertHead(art); }

Container Database::getArticlesDB() const { return artc; }
QVector<User*> Database::getUsersDB() const { return usr; }
