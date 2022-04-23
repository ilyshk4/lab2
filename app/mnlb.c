#include <stdio.h>
#include "common.h"
#include "text.h"

/**
 * Загружает содержимое указанного файла
 */
void mnlb(text txt)
{
	size_t line, position;
	get_cursor(txt, &line, &position);
	set_cursor(txt, line + 1, 0);
}