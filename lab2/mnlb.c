#include <stdio.h>
#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */
void mnlb(text txt)
{
	if (txt == NULL) {
        fprintf(stderr, "There are no lines in the text!\n");
        return;
    } 

	size_t line;
	get_cursor(txt, &line, NULL);
	set_cursor(txt, line + 1, 0);
}