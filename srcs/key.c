/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:36:17 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/13 13:17:45 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	touch3(int *tab_int, int y, char **av)
{
	if ((y = ft_chr3(tab_int, ft_strlen_tab(av))) != -1)
	{
		if (g_m.oui != 1)
			tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
		if (g_m.oui == 1)
			tab_int[y] = 1;
		else
			tab_int[y] = 0;
	}
	else
	{
		y = ft_chr(tab_int, ft_strlen_tab(av));
		if (g_m.oui != 1)
			tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
		if (g_m.oui == 1)
			tab_int[y] = 3;
		else
			tab_int[y] = 2;
	}
}

int		touch1(char *buffer, int *tab_int, int y, char **av)
{
	if (buffer[0] == 27 && buffer[1] != 0)
	{
		if (g_m.oui != 1)
		{
			if (buffer[2] == 68)
				tab_int = ft_tab_yneg(tab_int, ft_strlen_tab(av));
			if (buffer[2] == 67)
				tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
			if (buffer[2] == 65 && g_m.max3 > 0)
				tab_int = ft_tab_up(tab_int, ft_strlen_tab(av));
			if (buffer[2] == 66 && g_m.max3 > 0)
				tab_int = ft_tab_down(tab_int, ft_strlen_tab(av));
		}
	}
	else if ((buffer[0] == 27 && buffer[1] == 0))
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		return (-1);
	}
	else if (buffer[0] == 32 && buffer[1] == 0)
		touch3(tab_int, y, av);
	return (0);
}

int		toutch2(char *buffer, int y, int *tab_int, char **av)
{
	if ((buffer[0] == 127 || buffer[0] == 126) && buffer[1] == 0)
	{
		if ((y = ft_chr3(tab_int, ft_strlen_tab(av))) != -1)
		{
			tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
			tab_int[y] = -1;
		}
		else
		{
			y = ft_chr(tab_int, ft_strlen_tab(av));
			tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
			tab_int[y] = -1;
		}
		g_m.delet++;
	}
	else if (buffer[0] == 10 && buffer[1] == 0)
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		ft_retrun(av, tab_int);
		return (-1);
	}
	return (0);
}

int		voir_touche(char **av, int *tab_int)
{
	char	buffer[3];

	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	ft_memset(tab_int, 0, ft_strlen_tab(av) * 4);
	g_m.tab_int[0] = 1;
	tab_int[0] = 1;
	g_m.delet = 0;
	ft_signe(SIGWINCH);
	while (1)
	{
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		ft_cp(tab_int, ft_strlen_tab(av));
		if (touch1(buffer, tab_int, 0, av) == -1)
			return (0);
		else if (toutch2(buffer, 0, tab_int, av) == -1)
			return (0);
		if (ct_1(tab_int, ft_strlen_tab(av)) == 0)
			return (0);
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		ft_print_tab(av, tab_int);
	}
	return (0);
}
