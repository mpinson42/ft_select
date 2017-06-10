#include "libft.h"
#include <curses.h> 
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "mini.h"

int col;
int li;
char  **g_av;
int fd;
t_main m;

int	my_putchar(int c)
{
	write(1, &c, 1);
	return(0);
}

int ft_max(char **av)
{
	int i;
	int y;

	y = 1;
	i = 0;
	while(av[y])
	{
		//ft_putendl(av[0][y]);
		if(i < ft_strlen(av[y]))
			i = ft_strlen(av[y]);
		y++;
	}
	return(i);
}

void ft_print_tab(char **av, int *tab_int)
{
	int i;
	int y;
	int x;
	int max;
	int count;
	char *res;

	count = 0;
	i = 1;
	max = ft_max(av);
	x = 0;
	if(col <= max)
	{
	 	ft_putstr("fenetre trop petit");
	 	return ;
	}
	while(av[i])
	{
		if(tab_int[i - 1] != -1)
		{
			if(count + ft_strlen(av[i]) >= col)
			{
				x++;
				if(x >= li)
				{
					if ((res = tgetstr("cl", NULL)) == NULL)
						return ;
					tputs(res, 0, my_putchar);
					ft_putstr("fenetre trop petit");
					return;
				}

				ft_putchar('\n');
				count = 0;
			}
			
			
			if(tab_int[i - 1] == 3)
				write(1,"\033[45m\033[4m" ,10);
			else if(tab_int[i - 1] == 2)
				write(1,"\033[45m" ,6);
			else if(tab_int[i - 1] == 1)
				write(1,"\033[4m" ,5);
			ft_putstr(av[i]);
			//ft_putnbr(tab_int[i - 1]);
			write(1,"\033[0m" ,5);
		
			count += ft_strlen(av[i]);
			y = 0;
			while(count < col && y < max - ft_strlen(av[i]) + 1)
			{
				count++;
				ft_putchar(' ');
				y++;
			}
		}
		i++;
	}
}

void ft_signe(int signial)
{
	struct winsize        win;
	char *res;
 
  	ioctl(0, TIOCGWINSZ, &win); 
  	col = win.ws_col;
  	li = win.ws_row;
  	if ((res = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(res, 0, my_putchar);
	ft_print_tab(g_av, m.tab_int);

  	//printf("coll = %d   li == %d\n", col, li);
		
}

int ft_strlen_tab(char **av)
{
	int i;

	i = 0;
	while(av[i])
		i++;
	return(i);
}

int *ft_tab_ymor(int *tab_int, int max)
{
	int i;
	int y = 0;

	i = 0;
	while(i < max)
	{
		if(tab_int[i] == 1 || tab_int[i] == 3)
		{
			if(tab_int[i] == 1)
				tab_int[i] = 0;
			if(tab_int[i] == 3)
				tab_int[i] = 2;
			if(i + 2 == max)
			{
				while(tab_int[y] && tab_int[y] == -1)
					y++;
				if(tab_int[y] == 2)
					tab_int[y] = 3;
				else
					tab_int[y] = 1;
			}
			else
			{
				while(tab_int[i + 1] && tab_int[i + 1] == -1)
					i++;
				if(tab_int[i] == -1 && i + 2 == max )
				{
					i = 0;
					while(tab_int[i] && tab_int[i] == -1)
						i++;
					i -= 1;
					
				}
				if(tab_int[i + 1] == 2)
					tab_int[i + 1] = 3;
				else
				tab_int[i + 1] = 1;
			}
			break;
		}
		i++;
	}
	return(tab_int);
}

int *ft_tab_yneg(int *tab_int, int max)
{
	int i;
	int save;

	i = 0;
	while(i < max)
	{
		if(tab_int[i] == 1 || tab_int[i] == 3)
		{
			if(tab_int[i] == 1)
				tab_int[i] = 0;
			if(tab_int[i] == 3)
				tab_int[i] = 2;
			if(i == 0)
			{
				while(max - 2 > 0 && tab_int[max - 2] == -1)
					max--;
				if(tab_int[max - 2] == 2)
					tab_int[max - 2] = 3;
				else
					tab_int[max - 2] = 1;
			}
			else
			{
				save = i;
				while(i - 1 >= 0 && tab_int[i - 1] == -1)
					i--;
				if(i - 1 == -1 && tab_int[i] == -1)
				{
					i = max - 1;
					while(i - 1 >= 0 && tab_int[i - 1] == -1)
					{
						i--;
					}

				}
				if(tab_int[i - 1] == 2)
					tab_int[i - 1] = 3;
				else
					tab_int[i - 1] = 1;
			}
			break;
		}
		i++;
	}
	return(tab_int);
}

int ft_chr(int *tab_int, int max)
{
	int i;

	i = 0;
	while(i < max)
	{
		if(tab_int[i] == 1)
			return(i);
		i++;
	}
	return (0);
}

int ft_chr3(int *tab_int, int max)
{
	int i;

	i = 0;
	while(i < max)
	{
		if(tab_int[i] == 3)
			return(i);
		i++;
	}
	return (-1);
}

int ft_check_nul(int *tab_int, int max)
{
	int i;

	while(i < max - 2)
	{
		if(tab_int[i] != -1)
			return(1);
		i++;
	}
	return(-1);

}

void ft_cp(int *tab_int, int max)
{
	int i = 0;

	while(i < max)
	{
		m.tab_int[i] = tab_int[i];
		i++;
	}

}

void ft_retrun(char **av, int *tab_int)
{
	int i = 1;

	while(av[i])
	{
		if(tab_int[i - 1] == 2 || tab_int[i - 1] == 3)
		{
			ft_putstr(av[i]);
			ft_putchar(' ');
		}
		i++;
	}
}


int     voir_touche(char **av, int *tab_int)
{
	char     buffer[3];
	char    *res;
	int x = 0;
	int y = 0;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, my_putchar);

	ft_signe(1);
	while (1)
	{
		res = NULL;
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		ft_cp(tab_int, ft_strlen_tab(av));
		signal(SIGWINCH, ft_signe);
		if(ft_check_nul(tab_int, ft_strlen_tab(av)) == -1)
			return (0);
		
		if (buffer[0] == 27 && buffer[1] != 0)
		{

			if(buffer[2] ==68 && y >= 0)
			{
				tab_int = ft_tab_yneg(tab_int, ft_strlen_tab(av));
			}
			if(buffer[2] ==67 && y < col)
			{
				tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
			}
		}
		else if (buffer[0] == 27 && buffer[1] == 0)
			return (0);
		else if(buffer[0] == 32 && buffer[1] == 0)
		{
			if((y = ft_chr3(tab_int, ft_strlen_tab(av))) != -1)
				tab_int[y] = 1;
			else
			{
				y = ft_chr(tab_int, ft_strlen_tab(av));
				tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
				tab_int[y] = 2;
			}

		}
		else if ((buffer[0] == 127 || buffer[0] == 126) && buffer[1] == 0)
		{
			if((y = ft_chr3(tab_int, ft_strlen_tab(av))) != -1)
			{
				printf("oui\n");
				tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
				tab_int[y] = -1;
			}
			else
			{
				y = ft_chr(tab_int, ft_strlen_tab(av));
				//printf("%d\n", y);
				tab_int = ft_tab_ymor(tab_int, ft_strlen_tab(av));
				tab_int[y] = -1;
			}
		}
		else if(buffer[0] == 10 && buffer[1] == 0)
		{
			ft_retrun(av, tab_int);
			return(0);
		}
		
			if ((res = tgetstr("cl", NULL)) == NULL)
				return (-1);
			tputs(res, 0, my_putchar);
			ft_print_tab(av, tab_int);

	}
	return (0);
}

int              main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios term;
	int tab_int[ft_strlen_tab(av) + 1];
	g_av = av;
	ft_bzero(tab_int, ft_strlen_tab(av) + 1);
	tab_int[0] = 1;
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON | ECHO | ISIG); // Met le terminal en mode canonique.
	//term.c_lflag = ECHO; // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);


	voir_touche(av, tab_int);

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

