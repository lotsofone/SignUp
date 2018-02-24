#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class B;

class A
{
public:
    int aa(B* b)
    {
        b->bbb();
    }
    int aaa()
    {

    }
};
class B
{
    int bb(A* a)
    {
        a->aaa;
    }
    int bbb()
    {

    }
};


int main(int argc, char *argv[])
{
    return 0;
}
