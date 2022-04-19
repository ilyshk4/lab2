TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
	load.c \
	m.c \
	save.c \
	show.c \
	showreveven.c \
    editor.c \
    mnlb.c \
    p.c \
	text/append_line.c \
	text/insert_line.c \
	text/create_text.c \
	text/process_forward.c \
	text/process_backward.c \
	text/remove_all.c \
	text/set_cursor.c \
	text/get_cursor.c 

HEADERS += \
    common.h \
    text/_text.h \
    text/text.h 

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
