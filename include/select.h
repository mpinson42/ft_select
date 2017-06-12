/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:11:33 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/12 16:11:36 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>

typedef struct	s_main
{
	int				tab_int[5000];
	int				tab_x[5000];
	int				tab_y[5000];
	int				max;
	int 			max2;
	int 			delet;
	int				col;
	int				li;
		int 	oui;
		int 	max_der;
	char			**av;
	struct termios	term;
}				t_main;

typedef struct	s_print
{
	int		i;
	int		y;
	int		x;
	int		tx;
	int		ty;
	int		max;
	int		count;
	char	*res;
}				t_print;

void			ft_cursor_down(int max, int *tab_int, int *tx, int *ty);
void			ft_cursor(int max, int *tab_int, int *tx, int *ty);
int				ct_1(int *tab_int, int max);
int				*ft_tab_ymor(int *tab_int, int max);
int				*ft_tab_yneg(int *tab_int, int max);
int				*ft_tab_down(int *tab_int, int max);
int				*ft_tab_up(int *tab_int, int max);
int				voir_touche(char **av, int *tab_int);
void			ft_signe(int signial);
int				my_putchar(int c);
void			ft_print_tab(char **av, int *tab_int);
int				ft_max(char **av);
int				ft_strlen_tab(char **av);
int				ft_chr(int *tab_int, int max);
int				ft_chr3(int *tab_int, int max);
int				ft_check_nul(int *tab_int, int max);
void			ft_cp(int *tab_int, int max);
void			ft_retrun(char **av, int *tab_int);

t_main g_m;

#endif
