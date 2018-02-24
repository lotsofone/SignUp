/********************************************************************************
** Form generated from reading UI file 'teamrun_test.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMRUN_TEST_H
#define UI_TEAMRUN_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teamrun_test
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *addplayer;
    QLineEdit *xuesheng_id;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *gender;
    QLineEdit *xuewei;
    QLineEdit *years;
    QLineEdit *nianji;
    QLineEdit *xueyuan_number;
    QLineEdit *name;
    QLineEdit *lineEdit_9;
    QLineEdit *gid;
    QPushButton *deleteplayer;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *teamrun_test)
    {
        if (teamrun_test->objectName().isEmpty())
            teamrun_test->setObjectName(QStringLiteral("teamrun_test"));
        teamrun_test->resize(956, 600);
        centralwidget = new QWidget(teamrun_test);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 30, 281, 421));
        scrollArea->setMinimumSize(QSize(122, 122));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 255, 419));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollArea->setWidget(scrollAreaWidgetContents);
        addplayer = new QPushButton(centralwidget);
        addplayer->setObjectName(QStringLiteral("addplayer"));
        addplayer->setGeometry(QRect(710, 30, 93, 28));
        xuesheng_id = new QLineEdit(centralwidget);
        xuesheng_id->setObjectName(QStringLiteral("xuesheng_id"));
        xuesheng_id->setGeometry(QRect(820, 110, 113, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(700, 110, 113, 21));
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(700, 150, 113, 21));
        lineEdit_3->setFrame(false);
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(700, 190, 113, 21));
        lineEdit_4->setFrame(false);
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(700, 230, 113, 21));
        lineEdit_5->setFrame(false);
        lineEdit_5->setReadOnly(true);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(700, 270, 113, 21));
        lineEdit_6->setFrame(false);
        lineEdit_6->setReadOnly(true);
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(700, 350, 113, 21));
        lineEdit_7->setFrame(false);
        lineEdit_7->setReadOnly(true);
        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(700, 310, 113, 21));
        lineEdit_8->setFrame(false);
        lineEdit_8->setReadOnly(true);
        gender = new QLineEdit(centralwidget);
        gender->setObjectName(QStringLiteral("gender"));
        gender->setGeometry(QRect(820, 150, 113, 21));
        xuewei = new QLineEdit(centralwidget);
        xuewei->setObjectName(QStringLiteral("xuewei"));
        xuewei->setGeometry(QRect(820, 190, 113, 21));
        years = new QLineEdit(centralwidget);
        years->setObjectName(QStringLiteral("years"));
        years->setGeometry(QRect(820, 230, 113, 21));
        nianji = new QLineEdit(centralwidget);
        nianji->setObjectName(QStringLiteral("nianji"));
        nianji->setGeometry(QRect(820, 270, 113, 21));
        xueyuan_number = new QLineEdit(centralwidget);
        xueyuan_number->setObjectName(QStringLiteral("xueyuan_number"));
        xueyuan_number->setGeometry(QRect(820, 310, 113, 21));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(820, 350, 113, 21));
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(700, 70, 113, 21));
        lineEdit_9->setFrame(false);
        lineEdit_9->setReadOnly(true);
        gid = new QLineEdit(centralwidget);
        gid->setObjectName(QStringLiteral("gid"));
        gid->setGeometry(QRect(820, 70, 113, 21));
        deleteplayer = new QPushButton(centralwidget);
        deleteplayer->setObjectName(QStringLiteral("deleteplayer"));
        deleteplayer->setGeometry(QRect(820, 30, 93, 28));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(340, 31, 256, 421));
        teamrun_test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(teamrun_test);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 26));
        teamrun_test->setMenuBar(menubar);
        statusbar = new QStatusBar(teamrun_test);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        teamrun_test->setStatusBar(statusbar);

        retranslateUi(teamrun_test);

        QMetaObject::connectSlotsByName(teamrun_test);
    } // setupUi

    void retranslateUi(QMainWindow *teamrun_test)
    {
        teamrun_test->setWindowTitle(QApplication::translate("teamrun_test", "MainWindow", Q_NULLPTR));
        addplayer->setText(QApplication::translate("teamrun_test", "\346\267\273\345\212\240\350\277\220\345\212\250\345\221\230", Q_NULLPTR));
        xuesheng_id->setText(QApplication::translate("teamrun_test", "20150000", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("teamrun_test", "\345\255\246\345\217\267", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("teamrun_test", "\346\200\247\345\210\253", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("teamrun_test", "\345\255\246\344\275\215", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("teamrun_test", "\345\205\245\345\255\246\345\271\264\344\273\275", Q_NULLPTR));
        lineEdit_6->setText(QApplication::translate("teamrun_test", "\345\271\264\347\272\247", Q_NULLPTR));
        lineEdit_7->setText(QApplication::translate("teamrun_test", "\345\247\223\345\220\215", Q_NULLPTR));
        lineEdit_8->setText(QApplication::translate("teamrun_test", "\345\255\246\351\231\242\345\217\267", Q_NULLPTR));
        gender->setText(QApplication::translate("teamrun_test", "1", Q_NULLPTR));
        xuewei->setText(QApplication::translate("teamrun_test", "1", Q_NULLPTR));
        years->setText(QApplication::translate("teamrun_test", "2015", Q_NULLPTR));
        nianji->setText(QApplication::translate("teamrun_test", "2", Q_NULLPTR));
        xueyuan_number->setText(QApplication::translate("teamrun_test", "1", Q_NULLPTR));
        name->setText(QApplication::translate("teamrun_test", "\347\216\213\344\272\214", Q_NULLPTR));
        lineEdit_9->setText(QApplication::translate("teamrun_test", "id", Q_NULLPTR));
        gid->setText(QApplication::translate("teamrun_test", "0", Q_NULLPTR));
        deleteplayer->setText(QApplication::translate("teamrun_test", "\345\210\240\351\231\244\350\277\220\345\212\250\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class teamrun_test: public Ui_teamrun_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMRUN_TEST_H
