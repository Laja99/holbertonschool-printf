#include "main.h"

int handl_buf(char *buf, char c, unsigned int *ibuf)
{
	if (*ibuf == 1024)
	{
		write(1, buf, *ibuf);
		*ibuf = 0;
	}
	buf[*ibuf] = c;
	(*ibuf)++;
	return (1);
}
