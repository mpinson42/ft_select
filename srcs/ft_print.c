/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:55:26 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 14:51:18 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	print2(char **av, int *tab_int, t_print *p)
{
	p->tx++;
	if (tab_int[p->i - 1] == 3)
		write(2, "\033[45m\033[4m", 10);
	else if (tab_int[p->i - 1] == 2)
		write(2, "\033[45m", 6);
	else if (tab_int[p->i - 1] == 1)
		write(2, "\033[4m", 5);
	g_m.tab_x[p->i - 1] = p->tx;
	g_m.tab_y[p->i - 1] = p->ty;
	g_m.oui++;
	g_m.max_der++;
	ft_putstr_fd(av[p->i], 2);
	write(2, "\033[0m", 5);
	p->count += ft_strlen(av[p->i]);
	p->y = 0;
	while (p->count < g_m.col && p->y < p->max -
			(int)ft_strlen(av[p->i]) + 1)
	{
		p->count++;
		ft_putchar_fd(' ', 2);
		p->y++;
	}
}

void	print3(char **av, int *tab_int, t_print *p)
{
	if (tab_int[p->i - 1] != -1)
	{
		if (p->count + p->max >= g_m.col)
		{
			p->x++;
			if (p->x >= g_m.li)
			{
				if ((p->res = tgetstr("cl", NULL)) == NULL)
					return ;
				tputs(p->res, 1, my_putchar);
				ft_putstr_fd("fenetre trop petit", 2);
				return ;
			}
			p->ty++;
			g_m.max = p->ty;
			if(g_m.max2 < p->tx)
				g_m.max2 = p->tx;
			p->tx = 0;
			g_m.max_der = 0;
			ft_putchar_fd('\n', 2);
			p->count = 0;
		}
		print2(av, tab_int, p);
	}
}

void	ft_print_tab(char **av, int *tab_int)
{
	t_print p;

	p.count = 0;
	p.i = 1;
	p.max = ft_max(av);
	p.x = 0;
	p.ty = 0;
	g_m.oui = 0;
	p.tx = 0;
	g_m.max_der = 0;
	g_m.max2 = 0;
	if (g_m.col <= p.max)
	{
		ft_putstr_fd("fenetre trop petit", 2);
		return ;
	}
	while (av[p.i])
	{
		print3(av, tab_int, &p);
		p.i++;
	}
	if(g_m.max2 == 0)
		g_m.max2 = p.tx;
	if(g_m.oui == 0)
		exit(0);
}
