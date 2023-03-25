#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
int i;
long int n1 = 1, n2 = 2, next;
printf("%ld, %ld", n1, n2);
for (i = 2; i < 50; i++)
{
next = n1 + n2;
printf(", %ld", next);
n1 = n2;
n2 = next;
}
printf("\n");
return (0);
}
