#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char	c;
	char	*fei, *l, *tab;
	int		v = 0, soul = 1024, lim, dmt;

	if (ac != 2 || !av[1][0])
		return 1;
	lim = strlen(av[1]);
	fei = malloc(soul);
	if (!fei)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return 1;
	}
	while ((dmt = read(0, &c, 1)) > 0)
	{
		if (v >= soul - 1)
		{
			soul *= 2;
			fei = realloc(fei, soul);
			if (!fei)
			{
				fprintf(stderr, "Error: realloc failed\n");
				return 1;
			}
		}
		fei[v++] = c;
	}
	if (dmt < 0)
	{
		perror("Error");
		return 1;
	}
	fei[v] = 0;
	l = fei;
	while ((tab = memmem(l, strlen(l), av[1], lim)))
	{
		*tab = 0;
		printf("%s", l);

		for (int m = 0; m < lim; m++)
			printf("*");
		l = tab + lim;
	}
	printf("%s", l);
	free(fei);
	return 0;
}