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

void	print_col(void)
{
	int i;

	i = 1;
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('<', 2);
	while (i < g_m.col - 1)
	{
		ft_putchar_fd('-', 2);
		i++;
	}
	ft_putchar_fd('>', 2);
}

void	print2(char **av, int *tab_int, t_print *p)
{
	p->tx++;
	ft_color(av[p->i], p, tab_int);
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
			if (p->x >= g_m.li - 3)
			{
				if ((p->res = tgetstr("cl", NULL)) == NULL)
					return ;
				tputs(p->res, 1, my_putchar);
				ft_putstr_fd("fenetre trop petit", 2);
				return ;
			}
			p->ty++;
			g_m.max = p->ty;
			if (g_m.max2 < p->tx)
				g_m.max2 = p->tx;
			p->tx = 0;
			g_m.max_der = 0;
			ft_putchar_fd('\n', 2);
			p->count = 0;
		}
		print2(av, tab_int, p);
	}
}

void	set_stru(t_print *p, char **av)
{
	p->count = 0;
	p->i = 1;
	p->max = ft_max(av);
	p->x = 0;
	p->ty = 0;
	p->tx = 0;
	g_m.oui = 0;
	g_m.max_der = 0;
	g_m.max2 = 0;
}

void	ft_print_tab(char **av, int *tab_int)
{
	t_print p;

	set_stru(&p, av);
	if (g_m.col <= p.max)
	{
		ft_putstr_fd("fenetre trop petit", 2);
		return ;
	}
	ft_putstr_fd("ft_select :", 2);
	print_col();
	while (av[p.i])
	{
		print3(av, tab_int, &p);
		p.i++;
	}
	print_col();
	g_m.max3 = p.ty;
	if (g_m.max2 == 0)
		g_m.max2 = p.tx;
	if (g_m.oui == 0)
	{
		tputs(tgetstr("ve", NULL), 1, my_putchar);
		exit(0);
	}
}
