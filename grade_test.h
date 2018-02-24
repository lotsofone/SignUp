#ifndef GRADE_TEST_H
#define GRADE_TEST_H

#include <QWidget>
#include "obj_grade.h"
#include <QListWidget>
#include <sstream>

namespace Ui {
class grade_test;
}

class grade_test : public QWidget
{
    Q_OBJECT

public:
    explicit grade_test(QWidget *parent = 0);
    ~grade_test();
    void refresh_debug_window();

private slots:

    void on_buff1c_clicked();

    void on_rst1c_clicked();

    void on_int1c_clicked();

    void on_str1c_clicked();

    void on_ttc_clicked();

    void on_rvc_clicked();

    void on_sftc_clicked();

    void on_unc_clicked();

    void on_buff2c_clicked();

    void on_int2c_clicked();

    void on_str2c_clicked();

    void on_rst2c_clicked();

private:
    Ui::grade_test *ui;
};

#endif // GRADE_TEST_H
