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

void	rip(char *tim, int berg, int bro, int sis, char *a, int v)
{
	if (bro < 0 || sis < 0)
		return;
	if (tim[berg] == '\0')
	{
		a[v] = '\0';
		if (avic(a))
			puts(a);
		return;
	}
	if (tim[berg] == '(' && bro > 0)
	{
 	   a[v] = ' ';
 	   rip(tim, berg + 1, bro - 1, sis, a, v + 1);
	}
	else if (tim[berg] == ')' && sis > 0) 
	{
 	   a[v] = ' ';
	    rip(tim, berg + 1, bro, sis - 1, a, v + 1);
	}
	a[v] = tim[berg];
	rip(tim, berg + 1, bro, sis, a, v + 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *tim = av[1];
	int	peace = 0, heaven = 0, v = 0;
	while (tim[v])
	{
		if (tim[v] == '(')
			peace++;
		else if (tim[v] == ')')
		{
			if (peace > 0)
				peace--;
			else
				heaven++;
		}
		v++;
	}
	char *soul = malloc(sizeof(char) * (v + 1));
	if (!soul)
		return 1;
	rip(tim, 0, peace, heaven, soul, 0);
	free(soul);
	return 0;
}
