#include <stdio.h>
#include <stdlib.h>

int	avic(char *tim)
{
	int a = 0;
	int v = 0;
	while (tim[v])
	{
		if (tim[v] == '(')
			a++;
		if (tim[v] == ')')
			a--;
		if (a < 0)
			return 0;
		v++;
	}
	return (a == 0);
}

void	rave(char *t, int w, int acid, int trap, char *beat, int v)
{
	if (acid < 0 || trap < 0)
		return;
	if (t[w] == '\0')
	{
		beat[v] = '\0';
		if (avic(beat))
			puts(beat);
		return;
	}
	if (t[w] == '(' && acid > 0)
	{
 		beat[v] = ' ';
 		rave(t, w + 1, acid - 1, trap, beat, v + 1);
	}
	else if (t[w] == ')' && trap > 0) 
	{
		beat[v] = ' ';
		rave(t, w + 1, acid, trap - 1, beat, v + 1);
	}
	beat[v] = t[w];
	rave(t, w + 1, acid, trap, beat, v + 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *soul = av[1];
	int	trance = 0, techno = 0, v = 0;
	while (soul[v])
	{
		if (soul[v] == '(')
			trance++;
		else if (soul[v] == ')')
		{
			if (trance > 0)
				trance--;
			else
				techno++;
		}
		v++;
	}
	char *fee = malloc(sizeof(char) * (v + 1));
	if (!fee)
		return 1;
	rave(soul, 0, trance, techno, fee, 0);
	free(fee);
	return 0;
}
