#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 37
#endif

char	*findv(char *t)
{
	int fei = 0;

	while (t[fei])
		fei++;
	char *tab = (char *)malloc(fei + 1);
	if (!tab)
		return NULL;
	for (int v = 0; v <= fei; v++)
		tab[v] = t[v];
	return tab;
}

char	*get_next_line(int fd)
{
	static char	dmt[BUFFER_SIZE];
	static int	w = 0;
	static int	g = 0;
	char		fei[77777];
	int			v = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while (1)
	{
		if (w >= g)
		{
			g = read(fd, dmt, BUFFER_SIZE);
			w = 0;
			if (g <= 0)
				break;
		}
		fei[v] = dmt[w++];
		if (fei[v] == '\n')
		{
			v++;
			break;
		}
		v++;
	}
	fei[v] = '\0';
	if (v == 0)
		return NULL;
	return (findv(fei));
}