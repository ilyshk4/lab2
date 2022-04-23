/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        if (fgets(cmdline, MAXLINE, stdin) == NULL) {
            fprintf(stderr, "Error reading line.");
            continue;
        }

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
		
		if (strcmp(cmd, "p") == 0) {
            char *str = NULL;
            if ((arg = strtok(NULL, " \n")) == NULL ||
                (str = strtok(NULL, " \n")) == NULL
            ) {
                fprintf(stderr, "Usage: p line text\n");
            } else {
                p(txt, atoi(arg), str);
            }
            continue;
        }
		
        if (strcmp(cmd, "m") == 0) {
            char *pos = NULL;
            if ((arg = strtok(NULL, " \n")) == NULL ||
                (pos = strtok(NULL, " \n")) == NULL
            ) {
                fprintf(stderr, "Usage: m line position\n");
            } else {
                m(txt, atoi(arg), atoi(pos));
            }
            continue;
        }
		
        if (strcmp(cmd, "mnlb") == 0) {
			mnlb(txt);
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;   
        }
		
        if (strcmp(cmd, "showreveven") == 0) {
            show_rev_even(txt);
            continue;   
        }
		
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
