#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void save_line(int index, char *contents, int cursor, void *data);

void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "a")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    process_forward(txt, save_line, f);

    fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    
    /* Выводим строку на экран */
    fputs(contents, data);
    fputs("\n", data);
}
