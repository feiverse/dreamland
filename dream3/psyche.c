#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	int	psyche = 0;
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
			for (int m = 0; m < eros; ++m)
				if (w & (1UL << m))
				{
					if (!gold)
						fprintf(stdout, " ");
					fprintf(stdout, "%s", av[m + 2]);
					gold = 0;
				}
			fprintf(stdout, "\n");
			psyche = 1;
		}
	}
	if (!psyche)
		fprintf(stdout, "\n");
	return 0;
}
