#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T09:27:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    obj_grade.cpp \
    obj_player.cpp \
    obj_teamrun.cpp \
    grade_test.cpp \
    single_game.cpp \
    aao_copy.cpp \
    aao_school.cpp \
    sports_meeting.cpp \
    file_helper.cpp \
    schools_generator.cpp \
    students_generator.cpp

HEADERS  += mainwindow.h \
    obj_grade.h \
    obj_player.h \
    grade_test.h \
    single_game.h \
    obj_teamrun.h \
    aao_copy.h \
    aao_school.h \
    sports_meeting.h \
    file_helper.h

FORMS    += mainwindow.ui \
    grade_test.ui

DISTFILES +=
