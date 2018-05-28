/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_select.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 11:15:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 18:16:39 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./libft/libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
# include <curses.h>
/*
** KEYBOARD INPUTS
*/

# define RIGHT 4414235
# define LEFT 4479771
# define UP 4283163
# define DOWN 4348699
# define BCK_SP 127
# define RET 10
# define ESC 27
# define SP 32
# define DEL 2117294875

/*
** PRINT COLORS
*/

# define BLACK "\033[30m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define YELLOW "\033[33m"

# define RESET "\033[00m"

typedef struct			s_slct
{
	int					pos;
	int					len;
	int					select;
	char				*name;
	struct s_slct		*next;
	struct s_slct		*prev;
}						t_slct;

typedef struct winsize	t_wndw;
typedef struct termios	t_termios;

typedef struct			s_info
{
	int					nb_elem;
	int					max_len;
	int					nb_col;
	int					nb_row;
}						t_info;

typedef struct			s_term
{
	int					fd;
	t_wndw				wndw;
	t_slct				*slct;
	t_info				info;
	t_termios			termios;
}						t_term;

void	add_after_lst(t_slct *elem, const char *name, int pos);
void	add_before_lst(t_slct *elem, const char *name, int pos);
void	add_queue(t_slct *root, const char *name, int pos);
void	add_head(t_slct *root, const char *name, int pos);
void	remove_elem(t_slct *elem);

#endif
