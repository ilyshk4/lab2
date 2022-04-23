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
	append_line.c \
	insert_line.c \
	create_text.c \
	process_forward.c \
	process_backward.c \
	remove_all.c \
	set_cursor.c \
	get_cursor.c 

HEADERS += \
    common.h \
    _text.h \
    text.h 

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
