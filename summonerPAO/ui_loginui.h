/********************************************************************************
** Form generated from reading UI file 'loginui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

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

class Ui_LoginUI
{
public:
    QLabel *lblResult;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_username;
    QLabel *label_username;
    QLineEdit *textUser;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_password;
    QLabel *label_password;
    QLineEdit *textPassword;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_buttons;
    QPushButton *buttonLogin;
    QPushButton *buttonClear;

    void setupUi(QWidget *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QStringLiteral("LoginUI"));
        LoginUI->resize(321, 121);
        LoginUI->setAutoFillBackground(true);
        lblResult = new QLabel(LoginUI);
        lblResult->setObjectName(QStringLiteral("lblResult"));
        lblResult->setGeometry(QRect(23, 81, 281, 21));
        layoutWidget = new QWidget(LoginUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 21, 189, 22));
        horizontalLayout_username = new QHBoxLayout(layoutWidget);
        horizontalLayout_username->setObjectName(QStringLiteral("horizontalLayout_username"));
        horizontalLayout_username->setContentsMargins(0, 0, 0, 0);
        label_username = new QLabel(layoutWidget);
        label_username->setObjectName(QStringLiteral("label_username"));

        horizontalLayout_username->addWidget(label_username);

        textUser = new QLineEdit(layoutWidget);
        textUser->setObjectName(QStringLiteral("textUser"));

        horizontalLayout_username->addWidget(textUser);

        layoutWidget_2 = new QWidget(LoginUI);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(23, 49, 190, 22));
        horizontalLayout_password = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_password->setObjectName(QStringLiteral("horizontalLayout_password"));
        horizontalLayout_password->setContentsMargins(0, 0, 0, 0);
        label_password = new QLabel(layoutWidget_2);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_password->addWidget(label_password);

        textPassword = new QLineEdit(layoutWidget_2);
        textPassword->setObjectName(QStringLiteral("textPassword"));
        textPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_password->addWidget(textPassword);

        layoutWidget_3 = new QWidget(LoginUI);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(220, 20, 77, 54));
        verticalLayout_buttons = new QVBoxLayout(layoutWidget_3);
        verticalLayout_buttons->setObjectName(QStringLiteral("verticalLayout_buttons"));
        verticalLayout_buttons->setContentsMargins(0, 0, 0, 0);
        buttonLogin = new QPushButton(layoutWidget_3);
        buttonLogin->setObjectName(QStringLiteral("buttonLogin"));

        verticalLayout_buttons->addWidget(buttonLogin);

        buttonClear = new QPushButton(layoutWidget_3);
        buttonClear->setObjectName(QStringLiteral("buttonClear"));

        verticalLayout_buttons->addWidget(buttonClear);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QWidget *LoginUI)
    {
        LoginUI->setWindowTitle(QApplication::translate("LoginUI", "Login", 0));
        lblResult->setText(QApplication::translate("LoginUI", "Login Result", 0));
        label_username->setText(QApplication::translate("LoginUI", "Username", 0));
        label_password->setText(QApplication::translate("LoginUI", "Password ", 0));
        buttonLogin->setText(QApplication::translate("LoginUI", "Login", 0));
        buttonClear->setText(QApplication::translate("LoginUI", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
