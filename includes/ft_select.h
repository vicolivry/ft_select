/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_select.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 11:15:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 14:04:52 by volivry     ###    #+. /#+    ###.fr     */
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
	int					current;
	int					len;
	int					select;
	char				*name;
	int					index;
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

void					add_after_lst(t_slct *elem, const char *name);
void					add_before_lst(t_slct *elem, const char *name);
void					add_queue(t_slct *root, const char *name);
void					add_head(t_slct *root, const char *name);
t_slct					*root_slct(void);
t_slct					*init_slct(const char **argv);
t_slct					*first_elem(t_slct *root);
t_slct					*last_elem(t_slct *root);
void					remove_elem(t_slct *elem);
void					clean_exit(const char *error, t_term *term);
int						ft_putchar_err(int c);
void					init_term(t_term *term);
void					rehab_term(t_term *term);
void					get_info(t_term *term);
void					display(t_term *term);
void					print_arg(t_slct *slct, t_term *term);
void					down_key(t_term *term);
void					up_key(t_term *term);
void					del_key(t_term *term);
void					sp_key(t_term *term);
int						get_col_nb(t_term *term);
void					right_key(t_term *term);
void					left_key(t_term *term);
void					update_index(t_slct *root);
void					rc_key(t_term *term);
void					quit_ft_select(t_term *term);
void					free_slct(t_slct *lst);
void					key_input(t_term *term);
void					get_signals(void);
t_term					*memorize_term(t_term *term, int mode);

#endif
