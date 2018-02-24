/********************************************************************************
** Form generated from reading UI file 'grade_test.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADE_TEST_H
#define UI_GRADE_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grade_test
{
public:
    QListWidget *u1_info;
    QLineEdit *lineEdit_11;
    QListWidget *u2_info;
    QLineEdit *opt;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *int1;
    QLineEdit *str1;
    QLineEdit *tt;
    QLineEdit *rv;
    QLineEdit *sft;
    QLineEdit *buff1;
    QPushButton *rst1c;
    QPushButton *int1c;
    QPushButton *str1c;
    QPushButton *ttc;
    QPushButton *rvc;
    QPushButton *sftc;
    QPushButton *buff1c;
    QPushButton *str2c;
    QLineEdit *buff2;
    QPushButton *int2c;
    QLineEdit *str2;
    QPushButton *buff2c;
    QLineEdit *int2;
    QPushButton *rst2c;
    QLineEdit *un;
    QLineEdit *lineEdit_18;
    QPushButton *unc;

    void setupUi(QWidget *grade_test)
    {
        if (grade_test->objectName().isEmpty())
            grade_test->setObjectName(QStringLiteral("grade_test"));
        grade_test->resize(645, 400);
        u1_info = new QListWidget(grade_test);
        u1_info->setObjectName(QStringLiteral("u1_info"));
        u1_info->setGeometry(QRect(10, 270, 281, 121));
        lineEdit_11 = new QLineEdit(grade_test);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setEnabled(true);
        lineEdit_11->setGeometry(QRect(20, 20, 81, 21));
        lineEdit_11->setFrame(false);
        lineEdit_11->setReadOnly(true);
        u2_info = new QListWidget(grade_test);
        u2_info->setObjectName(QStringLiteral("u2_info"));
        u2_info->setGeometry(QRect(360, 270, 261, 121));
        opt = new QLineEdit(grade_test);
        opt->setObjectName(QStringLiteral("opt"));
        opt->setGeometry(QRect(300, 320, 51, 21));
        opt->setFrame(true);
        opt->setReadOnly(true);
        lineEdit_12 = new QLineEdit(grade_test);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(true);
        lineEdit_12->setGeometry(QRect(20, 50, 81, 21));
        lineEdit_12->setFrame(false);
        lineEdit_12->setReadOnly(true);
        lineEdit_13 = new QLineEdit(grade_test);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setEnabled(true);
        lineEdit_13->setGeometry(QRect(20, 80, 81, 21));
        lineEdit_13->setFrame(false);
        lineEdit_13->setReadOnly(true);
        lineEdit_14 = new QLineEdit(grade_test);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setEnabled(true);
        lineEdit_14->setGeometry(QRect(20, 110, 81, 21));
        lineEdit_14->setFrame(false);
        lineEdit_14->setReadOnly(true);
        lineEdit_15 = new QLineEdit(grade_test);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setEnabled(true);
        lineEdit_15->setGeometry(QRect(20, 140, 81, 21));
        lineEdit_15->setFrame(false);
        lineEdit_15->setReadOnly(true);
        lineEdit_16 = new QLineEdit(grade_test);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setEnabled(true);
        lineEdit_16->setGeometry(QRect(20, 200, 81, 21));
        lineEdit_16->setFrame(false);
        lineEdit_16->setReadOnly(true);
        lineEdit_17 = new QLineEdit(grade_test);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setEnabled(true);
        lineEdit_17->setGeometry(QRect(20, 230, 81, 21));
        lineEdit_17->setFrame(false);
        lineEdit_17->setReadOnly(true);
        int1 = new QLineEdit(grade_test);
        int1->setObjectName(QStringLiteral("int1"));
        int1->setGeometry(QRect(120, 20, 91, 21));
        str1 = new QLineEdit(grade_test);
        str1->setObjectName(QStringLiteral("str1"));
        str1->setGeometry(QRect(120, 50, 91, 21));
        tt = new QLineEdit(grade_test);
        tt->setObjectName(QStringLiteral("tt"));
        tt->setGeometry(QRect(120, 80, 91, 21));
        rv = new QLineEdit(grade_test);
        rv->setObjectName(QStringLiteral("rv"));
        rv->setGeometry(QRect(120, 110, 91, 21));
        sft = new QLineEdit(grade_test);
        sft->setObjectName(QStringLiteral("sft"));
        sft->setGeometry(QRect(120, 140, 91, 21));
        buff1 = new QLineEdit(grade_test);
        buff1->setObjectName(QStringLiteral("buff1"));
        buff1->setGeometry(QRect(120, 200, 91, 21));
        rst1c = new QPushButton(grade_test);
        rst1c->setObjectName(QStringLiteral("rst1c"));
        rst1c->setGeometry(QRect(120, 230, 93, 28));
        int1c = new QPushButton(grade_test);
        int1c->setObjectName(QStringLiteral("int1c"));
        int1c->setGeometry(QRect(220, 20, 93, 28));
        str1c = new QPushButton(grade_test);
        str1c->setObjectName(QStringLiteral("str1c"));
        str1c->setGeometry(QRect(220, 50, 93, 28));
        ttc = new QPushButton(grade_test);
        ttc->setObjectName(QStringLiteral("ttc"));
        ttc->setGeometry(QRect(220, 80, 93, 28));
        rvc = new QPushButton(grade_test);
        rvc->setObjectName(QStringLiteral("rvc"));
        rvc->setGeometry(QRect(220, 110, 93, 28));
        sftc = new QPushButton(grade_test);
        sftc->setObjectName(QStringLiteral("sftc"));
        sftc->setGeometry(QRect(220, 140, 93, 28));
        buff1c = new QPushButton(grade_test);
        buff1c->setObjectName(QStringLiteral("buff1c"));
        buff1c->setGeometry(QRect(220, 200, 93, 28));
        str2c = new QPushButton(grade_test);
        str2c->setObjectName(QStringLiteral("str2c"));
        str2c->setGeometry(QRect(470, 50, 93, 28));
        buff2 = new QLineEdit(grade_test);
        buff2->setObjectName(QStringLiteral("buff2"));
        buff2->setGeometry(QRect(370, 200, 91, 21));
        int2c = new QPushButton(grade_test);
        int2c->setObjectName(QStringLiteral("int2c"));
        int2c->setGeometry(QRect(470, 20, 93, 28));
        str2 = new QLineEdit(grade_test);
        str2->setObjectName(QStringLiteral("str2"));
        str2->setGeometry(QRect(370, 50, 91, 21));
        buff2c = new QPushButton(grade_test);
        buff2c->setObjectName(QStringLiteral("buff2c"));
        buff2c->setGeometry(QRect(470, 200, 93, 28));
        int2 = new QLineEdit(grade_test);
        int2->setObjectName(QStringLiteral("int2"));
        int2->setGeometry(QRect(370, 20, 91, 21));
        rst2c = new QPushButton(grade_test);
        rst2c->setObjectName(QStringLiteral("rst2c"));
        rst2c->setGeometry(QRect(370, 230, 93, 28));
        un = new QLineEdit(grade_test);
        un->setObjectName(QStringLiteral("un"));
        un->setGeometry(QRect(120, 170, 91, 21));
        lineEdit_18 = new QLineEdit(grade_test);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setEnabled(true);
        lineEdit_18->setGeometry(QRect(20, 170, 81, 21));
        lineEdit_18->setFrame(false);
        lineEdit_18->setReadOnly(true);
        unc = new QPushButton(grade_test);
        unc->setObjectName(QStringLiteral("unc"));
        unc->setGeometry(QRect(220, 170, 93, 28));

        retranslateUi(grade_test);

        QMetaObject::connectSlotsByName(grade_test);
    } // setupUi

    void retranslateUi(QWidget *grade_test)
    {
        grade_test->setWindowTitle(QApplication::translate("grade_test", "Form", Q_NULLPTR));
        lineEdit_11->setText(QApplication::translate("grade_test", "\346\225\260\345\200\274\345\275\225\345\205\245", Q_NULLPTR));
        lineEdit_12->setText(QApplication::translate("grade_test", "\345\255\227\347\254\246\344\270\262\345\275\225\345\205\245", Q_NULLPTR));
        lineEdit_13->setText(QApplication::translate("grade_test", "\346\224\271\346\227\266\351\227\264\347\261\273\345\210\253", Q_NULLPTR));
        lineEdit_14->setText(QApplication::translate("grade_test", "\346\224\271\345\217\215\350\275\254", Q_NULLPTR));
        lineEdit_15->setText(QApplication::translate("grade_test", "\346\224\271\344\275\215\347\247\273", Q_NULLPTR));
        lineEdit_16->setText(QApplication::translate("grade_test", "\346\224\271\346\257\222\350\215\257", Q_NULLPTR));
        lineEdit_17->setText(QApplication::translate("grade_test", "\351\207\215\347\275\256", Q_NULLPTR));
        int1->setText(QApplication::translate("grade_test", "13289", Q_NULLPTR));
        str1->setText(QApplication::translate("grade_test", "132.89", Q_NULLPTR));
        tt->setText(QApplication::translate("grade_test", "0", Q_NULLPTR));
        rv->setText(QApplication::translate("grade_test", "0", Q_NULLPTR));
        sft->setText(QApplication::translate("grade_test", "2", Q_NULLPTR));
        buff1->setText(QApplication::translate("grade_test", "0", Q_NULLPTR));
        rst1c->setText(QApplication::translate("grade_test", "\351\207\215\347\275\256", Q_NULLPTR));
        int1c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        str1c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        ttc->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        rvc->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        sftc->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        buff1c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        str2c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        buff2->setText(QApplication::translate("grade_test", "0", Q_NULLPTR));
        int2c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        str2->setText(QApplication::translate("grade_test", "24.53", Q_NULLPTR));
        buff2c->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
        int2->setText(QApplication::translate("grade_test", "2453", Q_NULLPTR));
        rst2c->setText(QApplication::translate("grade_test", "\351\207\215\347\275\256", Q_NULLPTR));
        un->setText(QApplication::translate("grade_test", "\345\215\203\347\211\233", Q_NULLPTR));
        lineEdit_18->setText(QApplication::translate("grade_test", "\346\224\271\345\215\225\344\275\215", Q_NULLPTR));
        unc->setText(QApplication::translate("grade_test", "do", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class grade_test: public Ui_grade_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADE_TEST_H
