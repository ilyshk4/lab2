include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS +=     \
    ../app/text.h \
    ../app/common.h \
    showreveven_tests.h

SOURCES +=     main.cpp \
    ../app/set_cursor.c \
    ../app/get_cursor.c \
    ../app/mnlb.c \
    ../app/p.c \
    ../app/show.c \
    ../app/load.c \
    ../app/remove_all.c \
    ../app/append_line.c \
    ../app/insert_line.c \
    ../app/process_backward.c \
    ../app/process_forward.c \
    ../app/showreveven.c \
    ../app/create_text.c

INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt