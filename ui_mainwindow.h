/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *s0widget;
    QLineEdit *s0lineEdit;
    QLabel *label_3;
    QPushButton *s0add_player;
    QPushButton *s0addgame;
    QPushButton *s0delete_player;
    QListWidget *playerlist;
    QPushButton *s0deletegame;
    QPushButton *s0output_check;
    QComboBox *s0comboBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *s0num_per_pre;
    QLineEdit *s0num_per_final;
    QPushButton *s0app;
    QLineEdit *s0student_id;
    QLabel *label_8;
    QPushButton *s0_lock;
    QPushButton *save_button;
    QListWidget *gamelist;
    QLabel *label;
    QWidget *s1widget;
    QListWidget *pre_log_list;
    QPushButton *s1_log_pre_bt;
    QPushButton *s1_log_final_bt;
    QListWidget *final_log_list;
    QPushButton *s1print_all;
    QListWidget *final_rank;
    QListWidget *school_rank;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *line_grade;
    QLabel *label_drug;
    QPushButton *log_grade_button;
    QPushButton *log_drug_button;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *drug_box;
    QLabel *s1get_id;
    QPushButton *button_enter_final;
    QPushButton *s1reset;
    QMenuBar *s1menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(933, 510);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        s0widget = new QWidget(centralWidget);
        s0widget->setObjectName(QStringLiteral("s0widget"));
        s0widget->setEnabled(true);
        s0widget->setGeometry(QRect(-10, -70, 861, 511));
        s0lineEdit = new QLineEdit(s0widget);
        s0lineEdit->setObjectName(QStringLiteral("s0lineEdit"));
        s0lineEdit->setGeometry(QRect(20, 390, 311, 21));
        label_3 = new QLabel(s0widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 80, 101, 16));
        s0add_player = new QPushButton(s0widget);
        s0add_player->setObjectName(QStringLiteral("s0add_player"));
        s0add_player->setGeometry(QRect(740, 370, 93, 28));
        s0addgame = new QPushButton(s0widget);
        s0addgame->setObjectName(QStringLiteral("s0addgame"));
        s0addgame->setGeometry(QRect(30, 480, 71, 28));
        s0delete_player = new QPushButton(s0widget);
        s0delete_player->setObjectName(QStringLiteral("s0delete_player"));
        s0delete_player->setGeometry(QRect(740, 410, 93, 28));
        playerlist = new QListWidget(s0widget);
        playerlist->setObjectName(QStringLiteral("playerlist"));
        playerlist->setEnabled(true);
        playerlist->setGeometry(QRect(380, 100, 351, 361));
        s0deletegame = new QPushButton(s0widget);
        s0deletegame->setObjectName(QStringLiteral("s0deletegame"));
        s0deletegame->setGeometry(QRect(110, 480, 71, 28));
        s0output_check = new QPushButton(s0widget);
        s0output_check->setObjectName(QStringLiteral("s0output_check"));
        s0output_check->setGeometry(QRect(370, 470, 181, 41));
        s0comboBox = new QComboBox(s0widget);
        s0comboBox->setObjectName(QStringLiteral("s0comboBox"));
        s0comboBox->setGeometry(QRect(110, 420, 81, 22));
        label_5 = new QLabel(s0widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 420, 72, 21));
        label_6 = new QLabel(s0widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 450, 91, 21));
        label_7 = new QLabel(s0widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 450, 121, 21));
        s0num_per_pre = new QLineEdit(s0widget);
        s0num_per_pre->setObjectName(QStringLiteral("s0num_per_pre"));
        s0num_per_pre->setGeometry(QRect(110, 450, 71, 21));
        s0num_per_final = new QLineEdit(s0widget);
        s0num_per_final->setObjectName(QStringLiteral("s0num_per_final"));
        s0num_per_final->setGeometry(QRect(260, 450, 71, 21));
        s0app = new QPushButton(s0widget);
        s0app->setObjectName(QStringLiteral("s0app"));
        s0app->setGeometry(QRect(220, 480, 71, 28));
        s0student_id = new QLineEdit(s0widget);
        s0student_id->setObjectName(QStringLiteral("s0student_id"));
        s0student_id->setGeometry(QRect(740, 340, 91, 21));
        label_8 = new QLabel(s0widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(740, 310, 72, 21));
        s0_lock = new QPushButton(s0widget);
        s0_lock->setObjectName(QStringLiteral("s0_lock"));
        s0_lock->setGeometry(QRect(740, 470, 81, 41));
        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(830, 400, 81, 41));
        gamelist = new QListWidget(centralWidget);
        gamelist->setObjectName(QStringLiteral("gamelist"));
        gamelist->setGeometry(QRect(10, 30, 251, 281));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 72, 15));
        s1widget = new QWidget(centralWidget);
        s1widget->setObjectName(QStringLiteral("s1widget"));
        s1widget->setGeometry(QRect(-1, 0, 1001, 441));
        pre_log_list = new QListWidget(s1widget);
        pre_log_list->setObjectName(QStringLiteral("pre_log_list"));
        pre_log_list->setGeometry(QRect(270, 30, 301, 361));
        s1_log_pre_bt = new QPushButton(s1widget);
        s1_log_pre_bt->setObjectName(QStringLiteral("s1_log_pre_bt"));
        s1_log_pre_bt->setGeometry(QRect(270, 0, 93, 28));
        s1_log_final_bt = new QPushButton(s1widget);
        s1_log_final_bt->setObjectName(QStringLiteral("s1_log_final_bt"));
        s1_log_final_bt->setGeometry(QRect(370, 0, 93, 28));
        final_log_list = new QListWidget(s1widget);
        final_log_list->setObjectName(QStringLiteral("final_log_list"));
        final_log_list->setGeometry(QRect(270, 30, 301, 361));
        s1print_all = new QPushButton(s1widget);
        s1print_all->setObjectName(QStringLiteral("s1print_all"));
        s1print_all->setGeometry(QRect(480, 400, 201, 41));
        final_rank = new QListWidget(s1widget);
        final_rank->setObjectName(QStringLiteral("final_rank"));
        final_rank->setGeometry(QRect(600, 30, 301, 171));
        school_rank = new QListWidget(s1widget);
        school_rank->setObjectName(QStringLiteral("school_rank"));
        school_rank->setGeometry(QRect(600, 230, 301, 161));
        label_2 = new QLabel(s1widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 320, 72, 21));
        label_4 = new QLabel(s1widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 320, 72, 21));
        label_9 = new QLabel(s1widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 350, 72, 21));
        line_grade = new QLineEdit(s1widget);
        line_grade->setObjectName(QStringLiteral("line_grade"));
        line_grade->setGeometry(QRect(80, 350, 101, 21));
        label_drug = new QLabel(s1widget);
        label_drug->setObjectName(QStringLiteral("label_drug"));
        label_drug->setGeometry(QRect(30, 380, 72, 21));
        log_grade_button = new QPushButton(s1widget);
        log_grade_button->setObjectName(QStringLiteral("log_grade_button"));
        log_grade_button->setGeometry(QRect(190, 350, 71, 28));
        log_drug_button = new QPushButton(s1widget);
        log_drug_button->setObjectName(QStringLiteral("log_drug_button"));
        log_drug_button->setGeometry(QRect(190, 380, 71, 28));
        label_10 = new QLabel(s1widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(600, 10, 72, 21));
        label_11 = new QLabel(s1widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(600, 210, 72, 21));
        drug_box = new QComboBox(s1widget);
        drug_box->setObjectName(QStringLiteral("drug_box"));
        drug_box->setGeometry(QRect(80, 380, 101, 22));
        s1get_id = new QLabel(s1widget);
        s1get_id->setObjectName(QStringLiteral("s1get_id"));
        s1get_id->setGeometry(QRect(100, 320, 72, 21));
        button_enter_final = new QPushButton(s1widget);
        button_enter_final->setObjectName(QStringLiteral("button_enter_final"));
        button_enter_final->setGeometry(QRect(350, 400, 101, 28));
        s1reset = new QPushButton(s1widget);
        s1reset->setObjectName(QStringLiteral("s1reset"));
        s1reset->setGeometry(QRect(730, 400, 91, 41));
        MainWindow->setCentralWidget(centralWidget);
        s0widget->raise();
        label->raise();
        s1widget->raise();
        gamelist->raise();
        save_button->raise();
        s1menuBar = new QMenuBar(MainWindow);
        s1menuBar->setObjectName(QStringLiteral("s1menuBar"));
        s1menuBar->setGeometry(QRect(0, 0, 933, 26));
        MainWindow->setMenuBar(s1menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\345\221\230\345\220\215\345\215\225", Q_NULLPTR));
        s0add_player->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\277\220\345\212\250\345\221\230", Q_NULLPTR));
        s0addgame->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271\347\233\256", Q_NULLPTR));
        s0delete_player->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\277\220\345\212\250\345\221\230", Q_NULLPTR));
        s0deletegame->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\351\241\271\347\233\256", Q_NULLPTR));
        s0output_check->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\256\214\346\225\264\346\240\270\345\257\271\350\241\250", Q_NULLPTR));
        s0comboBox->clear();
        s0comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\224\260\350\265\233(\347\261\263)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\276\204\350\265\233(\347\247\222)", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251\347\261\273\345\236\213", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\260\217\347\273\204\350\265\233\344\272\272\346\225\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\206\263\350\265\233\344\272\272\346\225\260", Q_NULLPTR));
        s0app->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\233\264\346\224\271", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\255\246\345\217\267", Q_NULLPTR));
        s0_lock->setText(QApplication::translate("MainWindow", "\346\212\245\345\220\215\351\224\201\345\256\232", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\345\210\227\350\241\250", Q_NULLPTR));
        s1_log_pre_bt->setText(QApplication::translate("MainWindow", "\345\260\217\347\273\204\350\265\233", Q_NULLPTR));
        s1_log_final_bt->setText(QApplication::translate("MainWindow", "\345\206\263\350\265\233", Q_NULLPTR));
        s1print_all->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\350\277\220\345\212\250\344\274\232\346\216\222\350\241\214\346\200\273\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\217\267\347\240\201\347\211\214", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<==", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251", Q_NULLPTR));
        label_drug->setText(QApplication::translate("MainWindow", "\350\215\257\346\243\200", Q_NULLPTR));
        log_grade_button->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245==>", Q_NULLPTR));
        log_drug_button->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245==>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\346\216\222\345\220\215", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\255\246\351\231\242\346\216\222\345\220\215", Q_NULLPTR));
        drug_box->clear();
        drug_box->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\230\264\346\200\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\230\263\346\200\247", Q_NULLPTR)
        );
        s1get_id->setText(QString());
        button_enter_final->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\345\206\263\350\265\233", Q_NULLPTR));
        s1reset->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\351\207\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
