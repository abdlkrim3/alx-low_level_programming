#include <stdio.h> // add this line to declare _putchar

void print_times_table(void)
{
    int i, j, k;
    for (i = 0; i <= 100; i++)
    {
        for (j = 0; j <= 100; j++)
        {
            k = i * j;
            if (j == 0)
            {
                _putchar('0');
            }
            else if (k < 10)
            {
                _putchar(' ');
                _putchar(' ');
                _putchar(k + '0');
            }
            else if (k < 100)
            {
                _putchar(' ');
                _putchar(k / 10 + '0');
                _putchar(k % 10 + '0');
            }
            else
            {
                _putchar(k / 100 + '0');
                _putchar(k % 100 / 10 + '0');
                _putchar(k % 10 + '0');
            }
            if (j < 100)
            {
                _putchar(',');
                _putchar(' ');
            }
            else
            {
                _putchar('\n');
            }
        }
    }
}
