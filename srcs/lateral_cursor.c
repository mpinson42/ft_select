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

int		*ft_tab_ymor(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	ft_cursor_down(max, tab_int, &tx, &ty);
//	printf("-->%d  --  %d\n", g_m.max_der, g_m.max);
//	exit(0);
	if(tx == g_m.max_der && ty == g_m.max)
	{
		tx = 0;
		ty = 0;
	}
	else if (tx == g_m.max2)
	{
		if (ty == g_m.max)
			ty = 0; // chercher max der ligne
		else
			ty++;
		tx = 0;
	}
	test = 0;
	i = max;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_x[i] != tx + 1 || g_m.tab_y[i] != ty - test || tab_int[i] == -1))
			i++;
		test++;
	}
	if (tab_int[i] == 0)
		tab_int[i] = 1;
	if (tab_int[i] == 2)
		tab_int[i] = 3;
	return (tab_int);
}

int		*ft_tab_yneg(int *tab_int, int max)
{
	int i;
	int ty;
	int tx;
	int test;

	//max = g_m.max2;
	ft_cursor_down(max, tab_int, &tx, &ty);
	if(tx == 1 && ty == 0)
	{
		tx = g_m.max2;
		ty = g_m.max + 1;
	}
	else if (tx == 1)
	{
		if (ty == 0)
			ty = g_m.max + 1; // chercher max der ligne
		else
			ty--;
		tx = (g_m.max2 + 1);
	}
	test = 0;
	i = max;
	while (i == max)
	{
		i = 0;
		while (i < max && (g_m.tab_x[i] != tx - 1 || g_m.tab_y[i] != ty - test || tab_int[i] == -1))
			i++;
		test++;
	}
	if (tab_int[i] == 0)
		tab_int[i] = 1;
	if (tab_int[i] == 2)
		tab_int[i] = 3;
	return (tab_int);
}
