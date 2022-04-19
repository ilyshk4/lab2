#include "_text.h"

void insert_line(text txt, size_t line, const char *contents)
{
	if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are no lines in the text!\n");
        return;
    } 
	
	if (line >= txt->length) {
        fprintf(stderr, "Line out of bounds!\n");
        return;
    } 
	
	if (contents == NULL) {
        fprintf(stderr, "Null contents!\n");
        return;
    } 
	
	node *current = txt->begin;
	
	for (size_t i = 0; i < line; i++)
		current = current->next;
	
	node *next = current->next;
	
	current->next = create_node(contents);
	current->next->previous = current;
	current->next->next = next;
	
	if (next != NULL)
		next->previous = current;
	
	txt->length++;         
    
    
    /* Устанавливаем курсор в конец добавленной строки */
    txt->cursor->line = current;
    txt->cursor->position = strlen(current->contents);
}
