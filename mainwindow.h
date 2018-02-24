#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <queue>
#include <QMainWindow>
#include "sports_meeting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //std::queue<Single_Game*> got_games;
    bool log_final_switch;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refresh_game_list();
    void show_info_in_lineedit(int row);
    void save_data();
    void refresh_player_list();
    void switch_execute();
    void refresh_log_list();
    void refresh_game_ranklist();
    void refresh_school_ranklist();

private slots:

    void on_s0addgame_clicked();

    void on_gamelist_currentRowChanged(int currentRow);

    void on_s0app_clicked();

    void on_s0deletegame_clicked();

    void on_save_button_clicked();

    void on_s0add_player_clicked();

    void on_s0delete_player_clicked();

    void on_s0output_check_clicked();

    void on_s0_lock_clicked();

    void on_log_grade_button_clicked();

    void on_log_drug_button_clicked();

    void on_final_log_list_currentRowChanged(int currentRow);

    void on_pre_log_list_currentRowChanged(int currentRow);

    void on_s1print_all_clicked();

    void on_s1_log_pre_bt_clicked();

    void on_s1_log_final_bt_clicked();

    void on_button_enter_final_clicked();

    void on_s1reset_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
