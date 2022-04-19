#include "_text.h"

void set_cursor(text txt, size_t line, size_t position)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "There are no lines in the text!\n");
        return;
    } 

    if (line >= txt->length)
    {
        fprintf(stderr, "Cursor line out of bounds!\n");
        return;
    } 
    
    node *current = txt->begin;
    for (size_t i = 0; i < line; i++)
        current = current->next;

    if (position >= strlen(current->contents))
    {
        fprintf(stderr, "Cursor position out of bounds!\n");
        return;
    } 

    txt->cursor->line = current;
    txt->cursor->position = position;
}
