#include "main.h"
/**
* positive_or_negative - Prints whether a given number is positive or negative.
* @i: The number to be checked.
*
* Return: If n is zero or greater, return 1 for positive.
*         If n is less than zero, return -1 for negative.
*/
void positive_or_negative(int i)
{
if (i == 0)
printf("%d is zero\n", i);
else if (i > 0)
printf("%d is positive\n", i);
else
printf("%d is negative\n", i);
}
