/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text.h"

/**
 * Загружает содержимое указанного файла
 */
void m(text txt, size_t line, size_t position)
{
	set_cursor(txt, line, position);
}