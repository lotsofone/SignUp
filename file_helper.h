#ifndef FILE_HELPER_H
#define FILE_HELPER_H
#include <vector>
#include <obj_player.h>

class File_Helper
{
public:
    File_Helper();
    Obj_Player players[30000];
    Obj_Player* get_player(long i);
    long num_of_player;
    void add_player(Obj_Player &py);
};

#endif // FILE_HELPER_H
