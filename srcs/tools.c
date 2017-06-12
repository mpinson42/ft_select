/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:55:57 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 13:55:59 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		my_putchar(int c)
{
	write(2, &c, 1);
	return (0);
}

int		ft_max(char **av)
{
	int i;
	int y;

	y = 1;
	i = 0;
	while (av[y])
	{
		if (i < (int)ft_strlen(av[y]))
			i = ft_strlen(av[y]);
		y++;
	}
	return (i);
}

int		ft_strlen_tab(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int		ft_chr(int *tab_int, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (tab_int[i] == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_chr3(int *tab_int, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (tab_int[i] == 3)
			return (i);
		i++;
	}
	return (-1);
}
