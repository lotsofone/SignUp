#include "file_helper.h"

File_Helper::File_Helper()
{
    num_of_player=0;

}

Obj_Player* File_Helper::get_player(long i)
{
    return &players[i];
}

void File_Helper::add_player(Obj_Player &py)
{
    players[num_of_player]=py; num_of_player++;
}
