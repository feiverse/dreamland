#include <stdio.h>
#include <stdlib.h>

typedef unsigned long mask;

void	lim(int *w, int g)
{
	for (int v = 0; v < g; ++v)
	{
		if (v)
			printf(" ");
		printf("%d", w[v]);
	}
	printf("\n");
}

void	dmt(int peru, int mex, int *bra, mask sha, mask man, mask ism)
{
	if (mex == peru)
	{
		lim(bra, peru);
		return;
	}
	for (int v = 0; v < peru; ++v)
	{
		mask aya = 1UL << v;
		mask hua = 1UL << (mex + v); 
		mask sca = 1UL << (v - mex + peru);
		
		if (!(sha & aya) && !(man & hua) && !(ism & sca))
		{
			bra[mex] = v;
			dmt(peru, mex + 1, bra, sha | aya, man | hua, ism | sca);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int v = atoi(av[1]);
	int w[32];
	dmt(v, 0, w, 0, 0, 0);
	return 0;
}