#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ams(int *box, int room, int mush, char *good)
{
	if (mush == room)
	{
		good[room] = '\0';
		puts(good);
		return;
	}
	for (int v = 0; v < 256; ++v)
		if (box[v])
		{
			good[mush] = (char)v;
			--box[v];
			ams(box, room, mush + 1, good);
			++box[v];
		}
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int fee[256] = {0};
		int age = strlen(av[1]);
		char *god = malloc(age + 1);

		for (int v = 0; v < age; ++v)
			++fee[(unsigned char)av[1][v]];
		ams(fee, age, 0, god);
		free(god);
	}
	return 0;
}