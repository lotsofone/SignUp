#include "mainwindow.h"
#include "grade_test.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    //grade_test w;//测试Obj_Grade类所用的程序


    w.show();

    return a.exec();
}
/**/
