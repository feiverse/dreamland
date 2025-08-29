#include <stdio.h>

int avic(char *tim)
{
    int v = 0;
    while (*tim)
    {
        if (*tim == '(') v++;
        if (*tim == ')') v--;
        if (v < 0) return 0;
        tim++;
    }
    return v == 0;
}

void rave(char *a, int v, int acid, int trap)
{
    if (!acid && !trap)
	{
		if (avic(a))
			puts(a);
			return;
	}
    for (; a[v]; v++)
    {
        if (a[v] == '(' && acid)
        {
            a[v] = ' ';
            rave(a, v + 1, acid - 1, trap);
            a[v] = '(';
        }
        if (a[v] == ')' && trap)
        {
            a[v] = ' ';
            rave(a, v + 1, acid, trap - 1);
            a[v] = ')';
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int l = 0, s = 0, tab = 0;
        char *soul = av[1];
        for (int v = 0; soul[v]; v++)
            if (soul[v] == '(') tab++;
            else if (soul[v] == ')') (tab ? tab-- : s++);
        l = tab;
        rave(soul, 0, l, s);
    }
    return 0;
}