/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *lblResult;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_username;
    QLineEdit *txtUser;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *txtPassword;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnLogin;
    QPushButton *btnClear;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(311, 110);
        lblResult = new QLabel(login);
        lblResult->setObjectName(QStringLiteral("lblResult"));
        lblResult->setGeometry(QRect(20, 80, 281, 21));
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 189, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_username = new QLabel(layoutWidget);
        label_username->setObjectName(QStringLiteral("label_username"));

        horizontalLayout->addWidget(label_username);

        txtUser = new QLineEdit(layoutWidget);
        txtUser->setObjectName(QStringLiteral("txtUser"));

        horizontalLayout->addWidget(txtUser);

        layoutWidget_2 = new QWidget(login);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 48, 190, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_password = new QLabel(layoutWidget_2);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_2->addWidget(label_password);

        txtPassword = new QLineEdit(layoutWidget_2);
        txtPassword->setObjectName(QStringLiteral("txtPassword"));
        txtPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtPassword);

        layoutWidget_3 = new QWidget(login);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(217, 19, 77, 54));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnLogin = new QPushButton(layoutWidget_3);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        verticalLayout_3->addWidget(btnLogin);

        btnClear = new QPushButton(layoutWidget_3);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        verticalLayout_3->addWidget(btnClear);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", 0));
        lblResult->setText(QApplication::translate("login", "Login Result", 0));
        label_username->setText(QApplication::translate("login", "Username", 0));
        label_password->setText(QApplication::translate("login", "Password ", 0));
        btnLogin->setText(QApplication::translate("login", "Login", 0));
        btnClear->setText(QApplication::translate("login", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
