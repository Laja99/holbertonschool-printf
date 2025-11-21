#include "main.h"
int _putchar(char c)
{
    return (write(1, &c, 1)); /* write(int __fd, const void *__buf, size_t __n) fd (1) = write*/
}
int print_string(char *str)
{
    int count = 0;
    if (!str) /*if null*/
    {
        str = "(null)";
    }
    while (*str) /*print it and return number of string*/
    {
        _putchar(*str);
        str++;
        count++;
    }
    return(count);
}
int print_number(int n)
{
    unsigned int n1 = 0;
    int count = 0;
    if (n < 0) /*if the number nigative make it positive*/ 
	{
		count += _putchar('-');
		n1 =(unsigned int)n;
	}
	else
	{
        
		n1 = n; /* copy */
	}

	if (n1 >= 10) /* more then one digit*/
    {
        count += print_number(n1 / 10); /*recursion to print left ot right and count all digitالعشرات
    }*/ 
	count += _putchar((n1 % 10) + '0'); /* transformation int to charالاحاد */ 
    }
    return (count);
}
