/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:56:09 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 13:56:11 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_check_nul(int *tab_int, int max)
{
	int i;

	i = 0;
	while (i < max - 3)
	{
		if (tab_int[i] != -1)
			return (1);
		i++;
	}
	return (-1);
}

int		ct_1(int *tab_int, int max)
{
	int i;
	int ct;

	i = 0;
	ct = 0;
	while (i <= max)
	{
		if (tab_int[i] != -1)
			ct++;
		i++;
	}
	return (ct);
}

void	ft_cp(int *tab_int, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		g_m.tab_int[i] = tab_int[i];
		i++;
	}
}

void	ft_retrun(char **av, int *tab_int)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (tab_int[i - 1] == 2 || tab_int[i - 1] == 3)
		{
			ft_putstr(av[i]);
			ft_putchar(' ');
		}
		i++;
	}
}
