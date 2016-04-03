/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHome;
    QAction *actionNews;
    QAction *actionOpinioni;
    QAction *actionFeatures;
    QAction *actionLogIn;
    QAction *actionNuovoArticolo;
    QAction *actionLogo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayoutSearch_2;
    QLineEdit *searchBox;
    QPushButton *searchButton;
    QStackedWidget *stackedWidget;
    QWidget *homePage;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelHome;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_Featured_2;
    QLabel *label_Featured_2;
    QPushButton *pushButton_TitleFeatured;
    QTextBrowser *textBrowser_Featured_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_News_2;
    QHBoxLayout *horizontalLayout_News_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_Opinions_2;
    QHBoxLayout *horizontalLayout_Opinions_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_Features_2;
    QHBoxLayout *horizontalLayout_Features_2;
    QWidget *newsPage;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_newsPage;
    QVBoxLayout *verticalLayout_NewsPage;
    QWidget *opinionsPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_opinionsPage;
    QVBoxLayout *verticalLayout_OpinionsPage;
    QWidget *featuresPage;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_featuresPage;
    QVBoxLayout *verticalLayout_FeaturesPage;
    QWidget *searchResultsPage;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_searchResults;
    QVBoxLayout *verticalLayout_SearchResults;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(969, 781);
        MainWindow->setMinimumSize(QSize(881, 538));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        MainWindow->setFont(font);
        actionHome = new QAction(MainWindow);
        actionHome->setObjectName(QStringLiteral("actionHome"));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/monument46.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHome->setIcon(icon);
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        actionHome->setFont(font1);
        actionHome->setVisible(true);
        actionHome->setIconVisibleInMenu(true);
        actionNews = new QAction(MainWindow);
        actionNews->setObjectName(QStringLiteral("actionNews"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/diploma.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNews->setIcon(icon1);
        actionOpinioni = new QAction(MainWindow);
        actionOpinioni->setObjectName(QStringLiteral("actionOpinioni"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/poetry.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpinioni->setIcon(icon2);
        actionFeatures = new QAction(MainWindow);
        actionFeatures->setObjectName(QStringLiteral("actionFeatures"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/message53.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFeatures->setIcon(icon3);
        actionLogIn = new QAction(MainWindow);
        actionLogIn->setObjectName(QStringLiteral("actionLogIn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/login17.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogIn->setIcon(icon4);
        actionNuovoArticolo = new QAction(MainWindow);
        actionNuovoArticolo->setObjectName(QStringLiteral("actionNuovoArticolo"));
        actionNuovoArticolo->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/add139.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNuovoArticolo->setIcon(icon5);
        actionLogo = new QAction(MainWindow);
        actionLogo->setObjectName(QStringLiteral("actionLogo"));
        actionLogo->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/logo_summoner_app.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogo->setIcon(icon6);
        QFont font2;
        font2.setPointSize(8);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        actionLogo->setFont(font2);
        actionLogo->setAutoRepeat(true);
        actionLogo->setVisible(true);
        actionLogo->setIconVisibleInMenu(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayoutSearch_2 = new QHBoxLayout();
        horizontalLayoutSearch_2->setSpacing(6);
        horizontalLayoutSearch_2->setObjectName(QStringLiteral("horizontalLayoutSearch_2"));
        searchBox = new QLineEdit(centralWidget);
        searchBox->setObjectName(QStringLiteral("searchBox"));

        horizontalLayoutSearch_2->addWidget(searchBox);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayoutSearch_2->addWidget(searchButton);


        verticalLayout_3->addLayout(horizontalLayoutSearch_2);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        homePage = new QWidget();
        homePage->setObjectName(QStringLiteral("homePage"));
        verticalLayout_4 = new QVBoxLayout(homePage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelHome = new QLabel(homePage);
        labelHome->setObjectName(QStringLiteral("labelHome"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        labelHome->setFont(font3);

        verticalLayout_4->addWidget(labelHome);

        scrollArea = new QScrollArea(homePage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 914, 603));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_Featured_2 = new QVBoxLayout();
        verticalLayout_Featured_2->setSpacing(6);
        verticalLayout_Featured_2->setObjectName(QStringLiteral("verticalLayout_Featured_2"));
        verticalLayout_Featured_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_Featured_2 = new QLabel(scrollAreaWidgetContents_2);
        label_Featured_2->setObjectName(QStringLiteral("label_Featured_2"));
        label_Featured_2->setFont(font3);

        verticalLayout_Featured_2->addWidget(label_Featured_2);

        pushButton_TitleFeatured = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_TitleFeatured->setObjectName(QStringLiteral("pushButton_TitleFeatured"));
        QFont font4;
        font4.setFamily(QStringLiteral("Verdana"));
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_TitleFeatured->setFont(font4);

        verticalLayout_Featured_2->addWidget(pushButton_TitleFeatured);

        textBrowser_Featured_2 = new QTextBrowser(scrollAreaWidgetContents_2);
        textBrowser_Featured_2->setObjectName(QStringLiteral("textBrowser_Featured_2"));
        textBrowser_Featured_2->setEnabled(true);
        textBrowser_Featured_2->setMinimumSize(QSize(0, 400));
        textBrowser_Featured_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser_Featured_2->setOpenExternalLinks(true);

        verticalLayout_Featured_2->addWidget(textBrowser_Featured_2);


        verticalLayout_2->addLayout(verticalLayout_Featured_2);

        verticalSpacer_4 = new QSpacerItem(0, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_News_2 = new QLabel(scrollAreaWidgetContents_2);
        label_News_2->setObjectName(QStringLiteral("label_News_2"));
        label_News_2->setFont(font3);

        verticalLayout_2->addWidget(label_News_2);

        horizontalLayout_News_2 = new QHBoxLayout();
        horizontalLayout_News_2->setSpacing(6);
        horizontalLayout_News_2->setObjectName(QStringLiteral("horizontalLayout_News_2"));

        verticalLayout_2->addLayout(horizontalLayout_News_2);

        verticalSpacer_5 = new QSpacerItem(0, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_Opinions_2 = new QLabel(scrollAreaWidgetContents_2);
        label_Opinions_2->setObjectName(QStringLiteral("label_Opinions_2"));
        label_Opinions_2->setFont(font3);

        verticalLayout_2->addWidget(label_Opinions_2);

        horizontalLayout_Opinions_2 = new QHBoxLayout();
        horizontalLayout_Opinions_2->setSpacing(6);
        horizontalLayout_Opinions_2->setObjectName(QStringLiteral("horizontalLayout_Opinions_2"));

        verticalLayout_2->addLayout(horizontalLayout_Opinions_2);

        verticalSpacer_6 = new QSpacerItem(0, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        label_Features_2 = new QLabel(scrollAreaWidgetContents_2);
        label_Features_2->setObjectName(QStringLiteral("label_Features_2"));
        label_Features_2->setFont(font3);

        verticalLayout_2->addWidget(label_Features_2);

        horizontalLayout_Features_2 = new QHBoxLayout();
        horizontalLayout_Features_2->setSpacing(6);
        horizontalLayout_Features_2->setObjectName(QStringLiteral("horizontalLayout_Features_2"));

        verticalLayout_2->addLayout(horizontalLayout_Features_2);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea);

        stackedWidget->addWidget(homePage);
        newsPage = new QWidget();
        newsPage->setObjectName(QStringLiteral("newsPage"));
        verticalLayout_5 = new QVBoxLayout(newsPage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_newsPage = new QLabel(newsPage);
        label_newsPage->setObjectName(QStringLiteral("label_newsPage"));
        label_newsPage->setFont(font3);

        verticalLayout_5->addWidget(label_newsPage);

        verticalLayout_NewsPage = new QVBoxLayout();
        verticalLayout_NewsPage->setSpacing(6);
        verticalLayout_NewsPage->setObjectName(QStringLiteral("verticalLayout_NewsPage"));

        verticalLayout_5->addLayout(verticalLayout_NewsPage);

        stackedWidget->addWidget(newsPage);
        opinionsPage = new QWidget();
        opinionsPage->setObjectName(QStringLiteral("opinionsPage"));
        verticalLayout_6 = new QVBoxLayout(opinionsPage);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_opinionsPage = new QLabel(opinionsPage);
        label_opinionsPage->setObjectName(QStringLiteral("label_opinionsPage"));
        label_opinionsPage->setFont(font3);

        verticalLayout_6->addWidget(label_opinionsPage);

        verticalLayout_OpinionsPage = new QVBoxLayout();
        verticalLayout_OpinionsPage->setSpacing(6);
        verticalLayout_OpinionsPage->setObjectName(QStringLiteral("verticalLayout_OpinionsPage"));

        verticalLayout_6->addLayout(verticalLayout_OpinionsPage);

        stackedWidget->addWidget(opinionsPage);
        featuresPage = new QWidget();
        featuresPage->setObjectName(QStringLiteral("featuresPage"));
        verticalLayout_7 = new QVBoxLayout(featuresPage);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_featuresPage = new QLabel(featuresPage);
        label_featuresPage->setObjectName(QStringLiteral("label_featuresPage"));
        label_featuresPage->setFont(font3);

        verticalLayout_7->addWidget(label_featuresPage);

        verticalLayout_FeaturesPage = new QVBoxLayout();
        verticalLayout_FeaturesPage->setSpacing(6);
        verticalLayout_FeaturesPage->setObjectName(QStringLiteral("verticalLayout_FeaturesPage"));

        verticalLayout_7->addLayout(verticalLayout_FeaturesPage);

        stackedWidget->addWidget(featuresPage);
        searchResultsPage = new QWidget();
        searchResultsPage->setObjectName(QStringLiteral("searchResultsPage"));
        verticalLayout_9 = new QVBoxLayout(searchResultsPage);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_searchResults = new QLabel(searchResultsPage);
        label_searchResults->setObjectName(QStringLiteral("label_searchResults"));
        label_searchResults->setFont(font3);

        verticalLayout_9->addWidget(label_searchResults);

        verticalLayout_SearchResults = new QVBoxLayout();
        verticalLayout_SearchResults->setSpacing(6);
        verticalLayout_SearchResults->setObjectName(QStringLiteral("verticalLayout_SearchResults"));

        verticalLayout_9->addLayout(verticalLayout_SearchResults);

        stackedWidget->addWidget(searchResultsPage);

        verticalLayout_3->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setFont(font3);
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(111, 49));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionLogo);
        mainToolBar->addAction(actionHome);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNews);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionOpinioni);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFeatures);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLogIn);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNuovoArticolo);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "suMMOner", 0));
        actionHome->setText(QApplication::translate("MainWindow", "Home", 0));
        actionHome->setIconText(QApplication::translate("MainWindow", "HOME", 0));
#ifndef QT_NO_TOOLTIP
        actionHome->setToolTip(QApplication::translate("MainWindow", "Go back to Home", 0));
#endif // QT_NO_TOOLTIP
        actionNews->setText(QApplication::translate("MainWindow", "News", 0));
        actionNews->setIconText(QApplication::translate("MainWindow", "NEWS", 0));
#ifndef QT_NO_TOOLTIP
        actionNews->setToolTip(QApplication::translate("MainWindow", "Go to the News section", 0));
#endif // QT_NO_TOOLTIP
        actionOpinioni->setText(QApplication::translate("MainWindow", "Opinioni", 0));
        actionOpinioni->setIconText(QApplication::translate("MainWindow", "OPINIONI", 0));
#ifndef QT_NO_TOOLTIP
        actionOpinioni->setToolTip(QApplication::translate("MainWindow", "Go to the Opinion section", 0));
#endif // QT_NO_TOOLTIP
        actionFeatures->setText(QApplication::translate("MainWindow", "Features", 0));
        actionFeatures->setIconText(QApplication::translate("MainWindow", "FEATURES", 0));
#ifndef QT_NO_TOOLTIP
        actionFeatures->setToolTip(QApplication::translate("MainWindow", "Go to the Features list section", 0));
#endif // QT_NO_TOOLTIP
        actionLogIn->setText(QApplication::translate("MainWindow", "logIn", 0));
        actionLogIn->setIconText(QApplication::translate("MainWindow", "LOGIN", 0));
#ifndef QT_NO_TOOLTIP
        actionLogIn->setToolTip(QApplication::translate("MainWindow", "Login in to leave comments", 0));
#endif // QT_NO_TOOLTIP
        actionNuovoArticolo->setText(QApplication::translate("MainWindow", "NUOVO ARTICOLO", 0));
        actionLogo->setText(QApplication::translate("MainWindow", "suMMOner.it", 0));
#ifndef QT_NO_TOOLTIP
        actionLogo->setToolTip(QApplication::translate("MainWindow", "Apri www.suMMOner.it nel browser", 0));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("MainWindow", "Cerca", 0));
        labelHome->setText(QApplication::translate("MainWindow", "HOME", 0));
        label_Featured_2->setText(QApplication::translate("MainWindow", "IN EVIDENZA", 0));
        pushButton_TitleFeatured->setText(QString());
        textBrowser_Featured_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        label_News_2->setText(QApplication::translate("MainWindow", "NEWS", 0));
        label_Opinions_2->setText(QApplication::translate("MainWindow", "OPINIONI", 0));
        label_Features_2->setText(QApplication::translate("MainWindow", "FEATURES", 0));
        label_newsPage->setText(QApplication::translate("MainWindow", "ARCHIVIO NEWS", 0));
        label_opinionsPage->setText(QApplication::translate("MainWindow", "ARCHIVIO OPINIONI", 0));
        label_featuresPage->setText(QApplication::translate("MainWindow", "ARCHIVIO FEATURES", 0));
        label_searchResults->setText(QApplication::translate("MainWindow", "RISULTATI DELLA RICERCA", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
