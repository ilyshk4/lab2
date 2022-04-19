#include "_text.h"

void get_cursor(text txt, size_t *line, size_t *position)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are no lines in the text!\n");
        return;
    } 

	node *current = txt->begin;
	int i = 0;
	while (current != txt->cursor->line)
	{
		current = current->next;
		i++;
	}
	
	if (line != NULL)
		*line = i;
	
	if (position != NULL)
		*position = txt->cursor->position;
}
