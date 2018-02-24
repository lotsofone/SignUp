
#include "grade_test.h"
#include "ui_grade_test.h"
#include <qstring.h>
#include <qdebug.h>
#include <QListWidget>
#include "obj_grade.h"

Obj_Grade g1,g2;
grade_test::grade_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grade_test)
{
    ui->setupUi(this);
    this->setWindowTitle("Obj_Grade类测试程序");
}

grade_test::~grade_test()
{
    delete ui;
}

void grade_test::refresh_debug_window()
{
    ui->u1_info->clear();
    /*long value;//成绩保存的值
    bool time_type;//成绩的类型是否为时间类。false为简单数值类，true为时间类
    bool reverse;//false表示值高的成绩好，否则值低的成绩好
    std::string unit;//成绩的单位
    int shift;//成绩小数点后保留多少位，从long value中截取后面几位
    int buff;//这次成绩的兴奋剂检查信息
    bool played;//是否已经参加了比赛*/
    QString qs;
    ui->u1_info->addItem("time_type=    "+qs.setNum(g1.get_time_type()));
    ui->u1_info->addItem("reverse=      "+qs.setNum(g1.get_reverse()));
    ui->u1_info->addItem("shift=        "+qs.setNum(g1.get_shift()));
    ui->u1_info->addItem("unit=         "+QString::fromStdString(g1.get_unit()));
    ui->u1_info->addItem("final string= "+QString::fromStdString(g1.grade_string()));

    ui->u2_info->clear();
    ui->u2_info->addItem("time_type=    "+qs.setNum(g2.get_time_type()));
    ui->u2_info->addItem("reverse=      "+qs.setNum(g2.get_reverse()));
    ui->u2_info->addItem("shift=        "+qs.setNum(g2.get_shift()));
    ui->u2_info->addItem("unit=         "+QString::fromStdString(g2.get_unit()));
    ui->u2_info->addItem("final string= "+QString::fromStdString(g2.grade_string()));

    qs.clear();
    ui->opt->clear();
    if(g1>g2)
    {
        qs.append(">");
    }
    if(g1==g2)
    {
        qs.append("==");
    }
    if(g1<g2)
    {
        qs.append("<");
    }
    ui->opt->setText(qs);
}

void grade_test::on_int1c_clicked()
{
    float ca = (ui->int1->text()).toFloat();
    g1.log_grade(ca);
    refresh_debug_window();
}

void grade_test::on_str1c_clicked()
{
    std::string ca = (ui->str1->text()).toStdString();
    g1.log_grade(ca);
    refresh_debug_window();
}

void grade_test::on_ttc_clicked()
{
    bool ca = (ui->tt->text()).toInt();
    g1.set_time_type(ca);
    g2.set_time_type(ca);
    refresh_debug_window();
}

void grade_test::on_rvc_clicked()
{
    bool ca = (ui->rv->text()).toInt();
    g1.set_reverse(ca);
    g2.set_reverse(ca);
    refresh_debug_window();
}

void grade_test::on_sftc_clicked()
{
    int ca = (ui->sft->text()).toInt();
    g1.change_shift(ca);
    g2.change_shift(ca);
    refresh_debug_window();
}

void grade_test::on_unc_clicked()
{
    std::string ca = (ui->un->text()).toStdString();
    g1.set_unit(ca);
    g2.set_unit(ca);
    refresh_debug_window();
}

void grade_test::on_buff1c_clicked()
{
    int ca = (ui->buff1->text()).toInt();
    g1.log_drug_test(ca);
    refresh_debug_window();
}

void grade_test::on_buff2c_clicked()
{
    int ca = (ui->buff2->text()).toInt();
    g2.log_drug_test(ca);
    refresh_debug_window();
}

void grade_test::on_int2c_clicked()
{
    float ca = (ui->int2->text()).toFloat();
    g2.log_grade(ca);
    refresh_debug_window();
}

void grade_test::on_str2c_clicked()
{
    std::string ca = (ui->str2->text()).toStdString();
    g2.log_grade(ca);
    refresh_debug_window();
}

void grade_test::on_rst1c_clicked()
{
    g1.reset_log();
    refresh_debug_window();
}

void grade_test::on_rst2c_clicked()
{
    g2.reset_log();
    refresh_debug_window();
}
