/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое указанного файла
 */
void save(text txt, char *filename);

/**
 * Ставит курсор на позицию
 */
void m(text txt, size_t line, size_t position);
void show_rev_even(text txt);
void mnlb(text txt);
void p(text txt, size_t line, char* contents);

#endif
