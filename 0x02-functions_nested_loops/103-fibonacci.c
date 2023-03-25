#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
int first_num = 1;
int second_num = 2;
int next_num = 0;
int sum = 2;
while (next_num <= 4000000)
{
next_num = first_num + second_num;
first_num = second_num;
second_num = next_num;
if (next_num % 2 == 0 && next_num <= 4000000)
sum += next_num;
}
printf("%d\n", sum);
return (0);
}
