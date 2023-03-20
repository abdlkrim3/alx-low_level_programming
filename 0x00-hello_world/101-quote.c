#include <stdio.h>
#include <unistd.h>
/**
 * main - A c program that prists a line to the standard error
 *
 * Return 1 (Success)
 */

int main(void)
{
char quote[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
write(2, quote, sizeof(quote) - 1);
/*
 * Return failure status (nonzero)
 */
return (1);
}
