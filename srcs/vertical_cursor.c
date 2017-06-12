#include "select.h"

void	ft_cursor_down(int max, int *tab_int, int *tx, int *ty)
{
	int i;

	i = -1;
	while (++i < max)
	{
		if (tab_int[i] != 1 && tab_int[i] != 3 && tab_int[i] != -1 &&
			tab_int[i] != 2)
			tab_int[i] = 0;
	}
	i = 0;
	while (tab_int[i] != 1 && tab_int[i] != 3)
		i++;
	tx[0] = g_m.tab_x[i];
	ty[0] = g_m.tab_y[i];
	if (tab_int[i] == 1)
		tab_int[i] = 0;
	if (tab_int[i] == 3)
		tab_int[i] = 2;
}

int		*ft_tab_down(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
	i = max;
	if (ty == g_m.max)
		ty = -1;
	test = 0;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_y[i] != ty + 1 || g_m.tab_x[i] != tx -
			test || tab_int[i] == -1))
			i++;
		test++;
	}
	if (tab_int[i] == 0)
		tab_int[i] = 1;
	if (tab_int[i] == 2)
		tab_int[i] = 3;
	i = 0;
	return (tab_int);
}

int		*ft_tab_up(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
	if (ty == 0)
		ty = g_m.max + 1;
	test = 0;
	i = max;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_y[i] != ty - 1 || g_m.tab_x[i] != tx -
			test || tab_int[i] == -1))
			i++;
		test++;
	}
	if (tab_int[i] == 0)
		tab_int[i] = 1;
	if (tab_int[i] == 2)
		tab_int[i] = 3;
	return (tab_int);
}