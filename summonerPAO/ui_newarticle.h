/********************************************************************************
** Form generated from reading UI file 'newarticle.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWARTICLE_H
#define UI_NEWARTICLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newArticle
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *labelNewArticle;
    QLabel *labelNameOfFile;
    QLineEdit *lineEditNameOfFile;
    QLabel *labelTitle;
    QLineEdit *lineEditTitle;
    QLabel *labelHTML;
    QTextEdit *textEditHTML;
    QLabel *labelCategory;
    QComboBox *boxCategory;
    QLabel *labelGenre;
    QComboBox *boxGenre;
    QLabel *labelSummary;
    QTextEdit *textEditSummary;
    QLabel *labelScore;
    QLineEdit *lineEditScore;
    QPushButton *pushButton;

    void setupUi(QWidget *newArticle)
    {
        if (newArticle->objectName().isEmpty())
            newArticle->setObjectName(QStringLiteral("newArticle"));
        newArticle->resize(800, 880);
        newArticle->setMinimumSize(QSize(650, 400));
        verticalLayout_2 = new QVBoxLayout(newArticle);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(newArticle);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 860));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelNewArticle = new QLabel(scrollAreaWidgetContents);
        labelNewArticle->setObjectName(QStringLiteral("labelNewArticle"));

        verticalLayout->addWidget(labelNewArticle, 0, Qt::AlignHCenter);

        labelNameOfFile = new QLabel(scrollAreaWidgetContents);
        labelNameOfFile->setObjectName(QStringLiteral("labelNameOfFile"));

        verticalLayout->addWidget(labelNameOfFile);

        lineEditNameOfFile = new QLineEdit(scrollAreaWidgetContents);
        lineEditNameOfFile->setObjectName(QStringLiteral("lineEditNameOfFile"));

        verticalLayout->addWidget(lineEditNameOfFile);

        labelTitle = new QLabel(scrollAreaWidgetContents);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        verticalLayout->addWidget(labelTitle);

        lineEditTitle = new QLineEdit(scrollAreaWidgetContents);
        lineEditTitle->setObjectName(QStringLiteral("lineEditTitle"));

        verticalLayout->addWidget(lineEditTitle);

        labelHTML = new QLabel(scrollAreaWidgetContents);
        labelHTML->setObjectName(QStringLiteral("labelHTML"));

        verticalLayout->addWidget(labelHTML, 0, Qt::AlignLeft);

        textEditHTML = new QTextEdit(scrollAreaWidgetContents);
        textEditHTML->setObjectName(QStringLiteral("textEditHTML"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEditHTML->sizePolicy().hasHeightForWidth());
        textEditHTML->setSizePolicy(sizePolicy);
        textEditHTML->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(textEditHTML);

        labelCategory = new QLabel(scrollAreaWidgetContents);
        labelCategory->setObjectName(QStringLiteral("labelCategory"));

        verticalLayout->addWidget(labelCategory);

        boxCategory = new QComboBox(scrollAreaWidgetContents);
        boxCategory->setObjectName(QStringLiteral("boxCategory"));

        verticalLayout->addWidget(boxCategory);

        labelGenre = new QLabel(scrollAreaWidgetContents);
        labelGenre->setObjectName(QStringLiteral("labelGenre"));

        verticalLayout->addWidget(labelGenre);

        boxGenre = new QComboBox(scrollAreaWidgetContents);
        boxGenre->setObjectName(QStringLiteral("boxGenre"));

        verticalLayout->addWidget(boxGenre);

        labelSummary = new QLabel(scrollAreaWidgetContents);
        labelSummary->setObjectName(QStringLiteral("labelSummary"));

        verticalLayout->addWidget(labelSummary);

        textEditSummary = new QTextEdit(scrollAreaWidgetContents);
        textEditSummary->setObjectName(QStringLiteral("textEditSummary"));
        sizePolicy.setHeightForWidth(textEditSummary->sizePolicy().hasHeightForWidth());
        textEditSummary->setSizePolicy(sizePolicy);
        textEditSummary->setMinimumSize(QSize(0, 150));

        verticalLayout->addWidget(textEditSummary);

        labelScore = new QLabel(scrollAreaWidgetContents);
        labelScore->setObjectName(QStringLiteral("labelScore"));

        verticalLayout->addWidget(labelScore);

        lineEditScore = new QLineEdit(scrollAreaWidgetContents);
        lineEditScore->setObjectName(QStringLiteral("lineEditScore"));

        verticalLayout->addWidget(lineEditScore);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(newArticle);

        QMetaObject::connectSlotsByName(newArticle);
    } // setupUi

    void retranslateUi(QWidget *newArticle)
    {
        newArticle->setWindowTitle(QApplication::translate("newArticle", "Form", 0));
        labelNewArticle->setText(QApplication::translate("newArticle", "Nuovo Articolo", 0));
        labelNameOfFile->setText(QApplication::translate("newArticle", "ID Nome File *", 0));
        labelTitle->setText(QApplication::translate("newArticle", "Titolo *", 0));
        labelHTML->setText(QApplication::translate("newArticle", "Inserire il codice HTML nel box di seguito *", 0));
        labelCategory->setText(QApplication::translate("newArticle", "Categoria", 0));
        boxCategory->clear();
        boxCategory->insertItems(0, QStringList()
         << QApplication::translate("newArticle", "News", 0)
         << QApplication::translate("newArticle", "Features", 0)
         << QApplication::translate("newArticle", "Recensione", 0)
         << QApplication::translate("newArticle", "Hands-On", 0)
        );
        labelGenre->setText(QApplication::translate("newArticle", "Genere", 0));
        boxGenre->clear();
        boxGenre->insertItems(0, QStringList()
         << QApplication::translate("newArticle", "MMO", 0)
         << QApplication::translate("newArticle", "MOBA", 0)
         << QApplication::translate("newArticle", "Survival", 0)
         << QApplication::translate("newArticle", "Coop", 0)
         << QApplication::translate("newArticle", "Competitive", 0)
         << QApplication::translate("newArticle", "a-RPG", 0)
         << QApplication::translate("newArticle", "e-Sport", 0)
         << QApplication::translate("newArticle", "Tech", 0)
        );
        labelSummary->setText(QApplication::translate("newArticle", "Riassunto (opzionale)", 0));
        labelScore->setText(QApplication::translate("newArticle", "Voto da 0 a 10 (opazionale)", 0));
        pushButton->setText(QApplication::translate("newArticle", "Pubblica Nuovo Articolo", 0));
    } // retranslateUi

};

namespace Ui {
    class newArticle: public Ui_newArticle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWARTICLE_H
