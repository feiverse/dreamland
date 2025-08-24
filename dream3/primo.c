#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	acid(int *psy, int good, int tab, char *trip)
{
	int v;

	if (tab == good)
	{
		trip[good] = '\0';
		puts(trip);
		return;
	}
	for (v = 0; v < 256; ++v)
		if (psy[v])
		{
			trip[tab] = (char)v;
			--psy[v];
			acid(psy, good, tab + 1, trip);
			++psy[v];
		}
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int fei[256] = {0};
		int tab = strlen(av[1]);
		char *trip = malloc(tab + 1);

		for (int v = 0; v < tab; ++v)
			++fei[(unsigned char)av[1][v]];
		acid(fei, tab, 0, trip);
		free(trip);
	}
	return 0;
}