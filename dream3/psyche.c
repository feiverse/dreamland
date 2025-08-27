#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	int	psyc = 0;
	int	eros = ac - 2;
	int	true = atoi(av[1]);
	unsigned long g = 1UL << eros;

	for (unsigned long w = 0; w < g; ++w)    
	{
		int	love = 0;
		for (int v = 0; v < eros; ++v)
			if (w & (1UL << v))
				love += atoi(av[v + 2]);
		if (love == true)
		{
			int	gold = 1;
			for (int z = 0; z < eros; ++z)
				if (w & (1UL << z))
				{
					if (!gold)
						fprintf(stdout, " ");
					fprintf(stdout, "%s", av[z + 2]);
					gold = 0;
				}
			fprintf(stdout, "\n");
			psyc = 1;
		}
	}
	if (!psyc)
		fprintf(stdout, "\n");
	return 0;
}
