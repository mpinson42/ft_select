/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:55:35 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 13:55:38 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_color(char *str, t_print *p, int *tab_int)
{
	struct stat	s;

	if (lstat(str, &s) == -1)
		return ;
	if (S_ISREG(s.st_mode) && s.st_mode & S_IXUSR &&
		s.st_mode & S_IXGRP && s.st_mode & S_IXOTH)
		write(2, "\e[0;31m", 8);
	else if (S_ISDIR(s.st_mode))
		write(2, "\e[1;36m", 8);
	else if (S_ISLNK(s.st_mode))
		write(2, "\e[0;35m", 8);
	else if (S_ISBLK(s.st_mode))
		write(2, "\e[0;34m", 8);
	else if (S_ISCHR(s.st_mode))
		write(2, "\e[1;33m", 8);
	if (tab_int[p->i - 1] == 3)
	{
		tputs(tgetstr("mr", NULL), 1, my_putchar);
		tputs(tgetstr("us", NULL), 1, my_putchar);
	}
	else if (tab_int[p->i - 1] == 2)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	else if (tab_int[p->i - 1] == 1)
		tputs(tgetstr("us", NULL), 1, my_putchar);
}

int		set_signial(char **av, int ac, char *name_term)
{
	if (ac == 1)
		return (-1);
	g_m.av = av;
	signal(SIGWINCH, ft_signe);
	signal(SIGTSTP, ft_signe);
	signal(SIGCONT, ft_signe);
	signal(SIGQUIT, ft_signe);
	signal(SIGINT, ft_signe);
	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr("attention pas d environment");
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	*name_term;
	char	*res;

	name_term = NULL;
	if (set_signial(av, ac, name_term) == -1)
		return (0);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &g_m.term) == -1)
		return (-1);
	g_m.term.c_lflag &= ~(ICANON);
	g_m.term.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &g_m.term) == -1)
		return (-1);
	voir_touche(av, g_m.tab_int);
	if ((res = tgetstr("ve", NULL)) == NULL)
		return (-1);
	tputs(res, 1, my_putchar);
	g_m.term.c_lflag |= ICANON;
	g_m.term.c_lflag |= ECHO;
	if (tcsetattr(0, 0, &g_m.term) == -1)
		return (-1);
	return (0);
}
