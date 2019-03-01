
int my_strdiff(char *a, char *b)
{

	if (a[0] == '\0' || b[0] == '\0')
		return -1;

	if (a[0] == b[0])
		return 1 + my_strdiff(1 + a, 1 + b);

	if (a[0] != b[0])
		return 0;
}
