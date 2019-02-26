#include "any.h"

int any(const char *str1, const char *str2)
{
	if (str1[0] == str2[0])
		return 0;
	for(int i = 1; i < sizeof(str1) - 1; i++)
	{
		if (str1[i] == str2[0])
			return i;
	}
	if (str1[0] != str2[0] && str2[1] == '\0')
		return -1;
	return any(str1, ++str2);
}
