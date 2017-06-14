/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lateral_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:02:22 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 15:02:24 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	choise_mor(int *tx, int *ty)
{
	if (tx[0] == g_m.max_der && ty[0] == g_m.max)
	{
		tx[0] = 0;
		ty[0] = 0;
	}
	else if (tx[0] == g_m.max2)
	{
		if (ty[0] == g_m.max)
			ty[0] = 0;
		else
			ty[0]++;
		tx[0] = 0;
	}
}

int		*ft_tab_ymor(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
	choise_mor(&tx, &ty);
	test = 0;
	i = max;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_x[i] != tx + 1 ||
			g_m.tab_y[i] != ty - test || tab_int[i] == -1))
			i++;
		test++;
	}
	tab_int[i] == 0 ? tab_int[i] = 1 : 0;
	tab_int[i] == 2 ? tab_int[i] = 3 : 0;
	return (tab_int);
}

void	choise_neg(int *tx, int *ty)
{
	if (tx[0] == 1 && ty[0] == 0)
	{
		tx[0] = g_m.max_der + 1;
		ty[0] = g_m.max + 1;
	}
	else if (tx[0] == 1)
	{
		if (ty[0] == 0)
			ty[0] = g_m.max + 1;
		else
			ty[0]--;
		tx[0] = (g_m.max2 + 1);
	}
}

int		*ft_tab_yneg(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
	choise_neg(&tx, &ty);
	test = 0;
	i = max;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_x[i] != tx - 1 ||
			g_m.tab_y[i] != ty - test || tab_int[i] == -1))
			i++;
		test++;
	}
	tab_int[i] == 0 ? tab_int[i] = 1 : 0;
	tab_int[i] == 2 ? tab_int[i] = 3 : 0;
	return (tab_int);
}
