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

int		main(int ac, char **av)
{
	char	*name_term;
	int		tab_int[ft_strlen_tab(av) + 1];
	char *res;

	if (ac == 1)
		return (0);
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
