/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:02:46 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/13 13:02:49 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ty == g_m.max - 1 && tx > g_m.max_der)
		ty = -1;
	else if (ty == g_m.max)
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
	tab_int[i] == 0 ? tab_int[i] = 1 : 0;
	tab_int[i] == 2 ? tab_int[i] = 3 : 0;
	i = 0;
	return (tab_int);
}

void	extand_up(int *tx, int *ty)
{
	if (tx[0] > g_m.max_der)
		ty[0] = g_m.max;
	else
		ty[0] = g_m.max + 1;
}

int		*ft_tab_up(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
	if (ty == 0)
		extand_up(&tx, &ty);
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
	tab_int[i] == 0 ? tab_int[i] = 1 : 0;
	tab_int[i] == 2 ? tab_int[i] = 3 : 0;
	return (tab_int);
}
