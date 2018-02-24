#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

Sports_Meeting sports_meeting;
AAO_Copy aao_copy;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("运动会管理系统");
    ui->mainToolBar->hide();
    ui->s1widget->hide();//隐藏录成绩用的窗口
    log_final_switch = false;
    switch_execute();

    //读取数据
    std::ifstream iss;
    iss.open("SM_data.txt", std::ios::in);
    int state_load; iss>>state_load;
    sports_meeting.load_aao_backup();//在state_n==1时自己使用的数据副本
    if(state_load==0)
    {
        aao_copy.load_data();
        sports_meeting.set_up_aao_copy(&aao_copy);
        sports_meeting.copy_school();
    }
    int i,n;n=0;
    iss>>n;//目前有多少个比赛项目
    File_Helper file_helper;
    sports_meeting.set_up_file_helper(file_helper);
    qDebug()<<"读取的state_n="<<state_load;
    qDebug()<<"读取的项目数量="<<n;
    for(i=0;i<n;i++)
    {
        Single_Game* game = sports_meeting.add_game();
        game->load_data(iss, &file_helper);
    }
    iss.close();
    if(state_load==1)
    {
        sports_meeting.state_n=1;
        ui->s0widget->hide();
        ui->s1widget->show();
    }
    refresh_game_list();
    refresh_school_ranklist();
}

void MainWindow::save_data()
{
    /*int n,j;
    for(j=0;j<9;j++)
    {
        for(n=0;n<180;n++)
        sports_meeting.sign_up(j,aao_copy.get_student_id_randomly());
    }*/
    std::ofstream oss;
    oss.open("SM_data.txt");
    sports_meeting.save_aao_backup();
    oss<<sports_meeting.state()<<std::endl;
    oss<<sports_meeting.num_of_game()<<std::endl;
    int i;
    for(i=0;i<sports_meeting.num_of_game();i++)
    {
        sports_meeting.get_game(i)->save_data(oss);
    }
    oss.close();
    aao_copy.save_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh_game_list()
{
    ui->gamelist->clear();
    std::queue<Single_Game*> gms;
    sports_meeting.output_games(gms);
    while(!gms.empty())
    {
        ui->gamelist->addItem(QString::fromStdString(gms.front()->name));
        gms.pop();
    }
}

void MainWindow::show_info_in_lineedit(int row)
{
    QString qs;
    Single_Game* gm = sports_meeting.get_game(row);
    ui->s0lineEdit->setText(QString::fromStdString(gm->name));
    ui->s0num_per_pre->setText(qs.setNum(gm->get_num_per_team()));
    ui->s0num_per_final->setText(qs.setNum(gm->get_num_in_final()));
    ui->s0comboBox->setCurrentIndex(gm->get_time_type());
}


void MainWindow::on_s0addgame_clicked()
{
    Single_Game* game = sports_meeting.add_game();
    game->name = "未命名项目";
    game->set_unit("米");
    game->change_shift(2);
    game->set_reverse(0);
    game->set_time_type(0);
    refresh_game_list();
    if(ui->gamelist->count()!=0)ui->gamelist->setCurrentRow(sports_meeting.num_of_game()-1);
}

void MainWindow::on_gamelist_currentRowChanged(int currentRow)
{
    show_info_in_lineedit(currentRow);
    refresh_player_list();
    refresh_log_list();
    refresh_game_ranklist();
}

void MainWindow::on_s0app_clicked()
{
    int currentRow = ui->gamelist->currentRow();
    if(currentRow<0||currentRow>=sports_meeting.num_of_game())return;
    Single_Game* gm = sports_meeting.get_game(currentRow);
    gm->name = ui->s0lineEdit->text().toStdString();
    if(ui->s0comboBox->currentIndex()==0)
    {
        gm->set_time_type(0);
        gm->set_reverse(0);
    }
    else
    {
        gm->set_time_type(1);
        gm->set_reverse(1);
    }
    gm->set_num_per_team(ui->s0num_per_pre->text().toInt());
    gm->set_num_in_final(ui->s0num_per_final->text().toInt());
    refresh_game_list();
    ui->gamelist->setCurrentRow(currentRow);
}

void MainWindow::on_s0deletegame_clicked()
{
    int cr = ui->gamelist->currentRow();
    if(cr<0||cr>=sports_meeting.num_of_game())return;
    sports_meeting.delete_game(cr);
    refresh_game_list();
}

void MainWindow::on_save_button_clicked()
{
    save_data();
}

void MainWindow::refresh_player_list()
{
    ui->playerlist->clear();
    if(ui->gamelist->currentRow()<0||ui->gamelist->currentRow()>=sports_meeting.num_of_game())return;
    std::queue<Obj_Player*> pys;
    sports_meeting.get_game(ui->gamelist->currentRow())->output_signed_players(pys);

    QString qs,qs2;
    while(!pys.empty())
    {
        qs.setNum(pys.front()->id);
        while(qs.size()<4)qs.insert(0,'0');
        ui->playerlist->addItem(qs+" "+qs2.setNum(pys.front()->student_id)+" "
                                +QString::fromStdString(pys.front()->name));
        pys.pop();
    }
}

void MainWindow::on_s0add_player_clicked()
{
    if(ui->gamelist->currentRow()<0||ui->gamelist->currentRow()>=sports_meeting.num_of_game())return;
    if(ui->s0student_id->text().toLong()==0)return;
    sports_meeting.sign_up(ui->gamelist->currentRow(), ui->s0student_id->text().toLong());
    refresh_player_list();
    if(ui->playerlist->count()>0)ui->playerlist->setCurrentRow(ui->playerlist->count()-1);
    //ui->s0student_id->setText("");
}

void MainWindow::on_s0delete_player_clicked()
{
    if(ui->gamelist->currentRow()<0||ui->gamelist->currentRow()>=sports_meeting.num_of_game())return;
    int cr = ui->playerlist->currentRow();
    sports_meeting.get_game(ui->gamelist->currentRow())->delete_at(cr);
    refresh_player_list();
    if(ui->playerlist->count()>cr)
    {
        ui->playerlist->setCurrentRow(cr);
    }
    else if(cr>0)
    {
        ui->playerlist->setCurrentRow(cr-1);
    }
}

void MainWindow::on_s0output_check_clicked()
{
    sports_meeting.print_check();
}

void MainWindow::on_s0_lock_clicked()
{
    sports_meeting.push_state();
    ui->s0widget->hide();
    ui->s1widget->show();
    switch_execute();
}
void MainWindow::switch_execute()
{
    if(log_final_switch)
    {
        ui->drug_box->show();
        ui->final_log_list->show();
        ui->label_drug->show();
        ui->log_drug_button->show();
        ui->pre_log_list->hide();
    }
    else
    {
        ui->drug_box->hide();
        ui->final_log_list->hide();
        ui->label_drug->hide();
        ui->log_drug_button->hide();
        ui->pre_log_list->show();
    }
}

void MainWindow::refresh_log_list()
{
    ui->final_log_list->clear();
    ui->pre_log_list->clear();
    int cr = ui->gamelist->currentRow();
    if(cr<0||cr>=sports_meeting.num_of_game())return;//防止越界
    int i,j;
    Single_Game* game=sports_meeting.get_game(cr);
    std::queue<Obj_Player*> pys;
    std::queue<Obj_Grade*> gds;
    Obj_Player* py;
    QString qs,sn;
    //刷新小组赛录入列表
    for(i=0;i<game->get_pre_team_num();i++)
    {
        j=0;
        game->output_pre_list(pys, gds, i);
        while(!pys.empty())
        {
            py = pys.front();pys.pop();
            j++;
            qs="";
            qs.setNum(j);
            qs.append(" ");
            if(py->id<1000)qs.append("0");
            if(py->id<100)qs.append("0");
            if(py->id<10)qs.append("0");
            qs.append(sn.setNum(py->id));
            qs.append(" ");
            qs.append(QString::fromStdString(py->name));
            qs.append("     ");
            qs.append(QString::fromStdString(gds.front()->grade_string()));gds.pop();
            ui->pre_log_list->addItem(qs);
        }
    }
    //刷新决赛录入列表
    game->output_final_list(pys, gds);
    while(!pys.empty())
    {
        py = pys.front();pys.pop();
        qs = "";
        if(py->id<1000)qs.append("0");
        if(py->id<100)qs.append("0");
        if(py->id<10)qs.append("0");
        qs.append(sn.setNum(py->id));
        qs.append(" ");
        qs.append(QString::fromStdString(py->name));
        qs.append("     ");
        qs.append(QString::fromStdString(gds.front()->grade_string()));gds.pop();
        ui->final_log_list->addItem(qs);
    }
}

void MainWindow::refresh_game_ranklist()
{
    int crgm = ui->gamelist->currentRow();
    if(crgm<0||crgm>sports_meeting.num_of_game())return;
    Single_Game* game = sports_meeting.get_game(crgm);//取得项目
    ui->final_rank->clear();
    if(game->state()<2)return;//没到决赛阶段
    std::queue<Obj_Player*> pys;
    std::queue<Obj_Grade*> gds;
    Obj_Player* py;
    QString qs,sn;
    game->output_final_ranking(pys, gds);
    while(!pys.empty())
    {
        //if(gds.front()->grade_string()=="未参赛")break;
        py=pys.front();
        qs = "";
        if(py->id<1000)qs.append("0");
        if(py->id<100)qs.append("0");
        if(py->id<10)qs.append("0");
        qs.append(sn.setNum(py->id));
        qs.append(" ");
        qs.append(QString::fromStdString(py->name));
        qs.append("     ");
        qs.append(QString::fromStdString(gds.front()->grade_string()));
        //qDebug()<<gds.front()->get_value();
        pys.pop();gds.pop();
        ui->final_rank->addItem(qs);
    }
}

void MainWindow::refresh_school_ranklist()
{
    //qDebug()<<"tt";
    ui->school_rank->clear();
    std::priority_queue<AAO_School> pq;
    //qDebug()<<"tt";
    sports_meeting.count_points();
    //qDebug()<<"tt";
    int i;
    for(i=0;i<sports_meeting.num_of_school();i++)
    {
        pq.push(sports_meeting.schools[i]);
    }
    QString qs, ap;long n;
    for(i=0;i<sports_meeting.num_of_school();i++)
    {
        qs="";
        qs.append(ap.setNum(i+1));
        qs.append(" ");
        qs.append(QString::fromStdString(pq.top().name));
        qs.append(" 总分");
        n=(pq.top()).points_sum_male+(pq.top()).points_sum_female;
        qs.append(ap.setNum(n));
        qs.append(" 男");
        qs.append(ap.setNum(pq.top().points_sum_male));
        qs.append(" 女");
        qs.append(ap.setNum(pq.top().points_sum_female));
        ui->school_rank->addItem(qs);
        pq.pop();
    }
}

void MainWindow::on_log_grade_button_clicked()
{
    /*Single_Game* gm = sports_meeting.get_game(8);
    int s=0;
    for(int j=0;j<gm->get_pre_team_num();j++)
    {
        while(1){
            gm->get_pre_grade(s%gm->get_num_per_team(),j)->log_grade(24+21/32767.0*(float)rand());
            s++;
            if(s%gm->get_num_per_team()==0)break;
            if(s==gm->num_of_players()-1)break;
        }
        if(s==gm->num_of_players()-1)break;
    }
    /**/
    int savecr1 = ui->pre_log_list->currentRow();
    int savecr2 = ui->final_log_list->currentRow();
    int crgm = ui->gamelist->currentRow();
    int cr;
    if(crgm<0||crgm>sports_meeting.num_of_game())return;
    Single_Game* game = sports_meeting.get_game(crgm);//取得需要录入的项目

    Obj_Grade* gd;
    if(log_final_switch)//切到最后页面
    {
        cr = ui->final_log_list->currentRow();
        if(cr<0)return;
        gd = game->get_final_grade(cr);
    }
    else
    {
        if(game->state()==2)return;//决赛阶段不可以修改预赛成绩
        cr = ui->pre_log_list->currentRow();
        if(cr<0)return;
        int i = cr/game->get_num_per_team();
        gd = game->get_pre_grade(cr%game->get_num_per_team() ,i);
    }
    gd->log_grade(ui->line_grade->text().toStdString());
    //qDebug()<<QString::fromStdString(gd->grade_string());
    refresh_log_list();
    refresh_game_ranklist();
    refresh_school_ranklist();
    if(savecr1+1<ui->pre_log_list->count())ui->pre_log_list->setCurrentRow(savecr1+1);
    if(savecr2+1<ui->final_log_list->count())ui->final_log_list->setCurrentRow(savecr2+1);
}

void MainWindow::on_log_drug_button_clicked()
{
    int savecr1 = ui->pre_log_list->currentRow();
    int savecr2 = ui->final_log_list->currentRow();
    int crgm = ui->gamelist->currentRow();
    int cr;
    if(crgm<0||crgm>sports_meeting.num_of_game())return;
    Single_Game* game = sports_meeting.get_game(crgm);//取得需要录入的项目

    Obj_Grade* gd;
    if(!log_final_switch)return;//必须在决赛页面才能使用
    cr = ui->final_log_list->currentRow();
    if(cr<0)return;
    gd = game->get_final_grade(cr);
    if(ui->drug_box->currentIndex()==1)
    {
        gd->log_drug_test(true);
    }
    else
    {
        gd->log_drug_test(false);
    }
    //qDebug()<<QString::fromStdString(gd->grade_string());
    refresh_log_list();
    refresh_game_ranklist();
    refresh_school_ranklist();
    if(savecr1+1<ui->pre_log_list->count())ui->pre_log_list->setCurrentRow(savecr1+1);
    if(savecr2+1<ui->final_log_list->count())ui->final_log_list->setCurrentRow(savecr2+1);
}

void MainWindow::on_final_log_list_currentRowChanged(int currentRow)
{
    if(currentRow<0)return;
    int cr = ui->gamelist->currentRow();
    if(cr<0||cr>sports_meeting.num_of_game())return;
    QString qs;
    Single_Game* game = sports_meeting.get_game(cr);

    qs="";
    cr = game->get_final_player(currentRow)->id;
    //qDebug()<<cr;
    if(cr<1000)qs.append("0");
    if(cr<100)qs.append("0");
    if(cr<10)qs.append("0");
    QString qs2;
    qs.append(qs2.setNum(cr));
    ui->s1get_id->setText(qs);
}

void MainWindow::on_pre_log_list_currentRowChanged(int currentRow)
{
    if(currentRow<0)return;
    int cr = ui->gamelist->currentRow();
    if(cr<0||cr>sports_meeting.num_of_game())return;
    Single_Game* game = sports_meeting.get_game(cr);
    QString qs;

    int n = currentRow/game->get_num_per_team();
    currentRow%=game->get_num_per_team();

    qs="";
    cr = game->get_pre_player(currentRow, n)->id;
    if(cr<1000)qs.append("0");
    if(cr<100)qs.append("0");
    if(cr<10)qs.append("0");
    QString qs2;
    qs.append(qs2.setNum(cr));
    ui->s1get_id->setText(qs);
}

void MainWindow::on_s1print_all_clicked()
{
    std::ofstream oss;
    oss.open("output.txt");
    int i;
    oss<<"东北大学运动会总排名表"<<std::endl;
    Single_Game* game;
    std::queue<Obj_Player*> pys;
    std::queue<Obj_Grade*> gds;
    Obj_Player* py;
    Obj_Grade* gd;
    for(i=0;i<sports_meeting.num_of_game();i++)
    {
        game = sports_meeting.get_game(i);
        //oss<<i<<" ";
        oss<<game->name<<" "<<std::endl;
        oss<<"名次;学号;姓名;性别;学院;成绩;"<<std::endl;
        game->output_final_ranking(pys, gds);
        for(int j=1;;j++)
        {
            if(pys.empty())break;
            py=pys.front();pys.pop();
            gd=gds.front();gds.pop();
            oss<<j<<";";
            oss<<py->student_id<<";"<<py->name<<";";
            if(py->gender){oss<<"男;";}
                else{oss<<"女;";}
            oss<<sports_meeting.schools[py->school_id].name<<";"<<gd->grade_string();
            oss<<std::endl;
        }
    }
    oss.close();
}

void MainWindow::on_s1_log_pre_bt_clicked()
{
    log_final_switch=false;
    switch_execute();
}

void MainWindow::on_s1_log_final_bt_clicked()
{\
    log_final_switch=true;
    switch_execute();
}

void MainWindow::on_button_enter_final_clicked()
{
    int crgm = ui->gamelist->currentRow();
    if(crgm<0||crgm>sports_meeting.num_of_game())return;
    Single_Game* game = sports_meeting.get_game(crgm);
    qDebug()<<"MainWindow::on_button_enter_final_clicked()  try to push_state";
    game->push_state();
    qDebug()<<"MainWindow::on_button_enter_final_clicked() success";
    log_final_switch=true;
    switch_execute();
    refresh_log_list();
}

void MainWindow::on_s1reset_clicked()
{
    std::ifstream iss;
    std::ofstream oss;
    iss.open("AAO_Copy_Students_reset_backup.txt");
    oss.open("AAO_Copy_Students.txt");
    std::string st;
    iss>>st;oss<<st<<std::endl;
    long i=0;
    while(iss>>st)
    {
        oss<<st;
        i++;
        i%=8;
        if(i==0){oss<<std::endl;}
        else{oss<<" ";}
    }
    iss.close();
    oss.close();
    oss.open("SM_data.txt");
    oss<<0<<std::endl<<0;
    oss.close();
    oss.open("SM_Schools.txt");
    oss<<0;
    oss.close();
    oss.open("SM_Students.txt");
    oss<<0;
    oss.close();
}
