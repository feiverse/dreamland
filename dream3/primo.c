#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ams(int *psy, int room, int mush, char *good)
{
	int	v;

	if (mush == room)
	{
		good[room] = '\0';
		puts(good);
		return;
	}
	for (v = 0; v < 256; ++v)
		if (psy[v])
		{
			good[mush] = (char)v;
			--psy[v];
			ams(psy, room, mush + 1, good);
			++psy[v];
		}
}

int	main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int fei[256] = {0};
		int age = strlen(av[1]);
		char *god = malloc(age + 1);

		for (int v = 0; v < age; ++v)
			++fei[(unsigned char)av[1][v]];
		ams(fei, age, 0, god);
		free(god);
	}
	return 0;
}
