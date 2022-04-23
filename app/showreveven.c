#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

static void show_line(int index, char *contents, int cursor, void *data);

void show_rev_even(text txt)
{
    process_backward(txt, show_line, NULL);
}

static void show_line(int index, char *contents, int cursor, void *data)
{
	if (index % 2 != 0)
		return;
	
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    /* Выводим строку на экран */
    char *i = contents;
    while (*i != 0) {
        if (i == contents + cursor)
            putchar('|');
        putchar(*i);
        i++;
    }
    putchar('\n');
}
