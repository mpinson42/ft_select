/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:55:47 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 13:55:48 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static	void			handle_sigtstp(void)
{
	char	cp[2];
	char	*res;

	cp[0] = g_m.term.c_cc[VSUSP];
	cp[1] = 0;
	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 1, my_putchar);
	ft_putstr_fd("Stopping...\n", 2);
	if ((res = tgetstr("ve", NULL)) == NULL)
		return ;
	tputs(res, 1, my_putchar);
	g_m.term.c_lflag |= ICANON;
	g_m.term.c_lflag |= ECHO;
	if (tcsetattr(0, 0, &g_m.term) == -1)
		return ;
	tputs(res, 1, my_putchar);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static	void			handle_sigcont(void)
{
	char	*res;

	g_m.term.c_lflag &= ~(ICANON);
	g_m.term.c_lflag &= ~(ECHO);
	if (tcsetattr(0, 0, &g_m.term) == -1)
		return ;
	signal(SIGTSTP, ft_signe);
	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 1, my_putchar);
	if ((res = tgetstr("vi", NULL)) == NULL)
		return ;
	tputs(res, 1, my_putchar);
	ft_print_tab(g_m.av, g_m.tab_int);
}

void					ft_signe(int signial)
{
	struct winsize	win;
	char			*res;

	if (signial == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &win);
		g_m.col = win.ws_col;
		g_m.li = win.ws_row;
		if ((res = tgetstr("cl", NULL)) == NULL)
			return ;
		tputs(res, 1, my_putchar);
		ft_print_tab(g_m.av, g_m.tab_int);
	}
	else if (signial == SIGTSTP)
		handle_sigtstp();
	else if (signial == SIGCONT)
		handle_sigcont();
	else if (signial == SIGQUIT || signial == SIGINT)
	{
		if ((res = tgetstr("ve", NULL)) == NULL)
			return ;
		tputs(res, 1, my_putchar);
		exit(0);
	}
}
