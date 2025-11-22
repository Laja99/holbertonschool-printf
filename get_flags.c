#include "main.h"

int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char flags_CH[] = {'+', ' ', '#', '\0'};
	const int flags_ARR[] = {F_PLUS, F_SPACE, F_HASH, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; flags_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == flags_CH[j])
			{
				flags |= flags_ARR[j];
				break;
			}
		}
		if (flags_CH[j] == '\0')
			break;
	}
	*i = curr_i - 1;
	return (flags);
}
