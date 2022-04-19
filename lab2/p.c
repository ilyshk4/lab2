#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

void p(text txt, size_t line, char* contents)
{
	insert_line(txt, line, contents);
}