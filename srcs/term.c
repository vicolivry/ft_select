/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 14:21:59 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 14:43:40 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	init_term(t_term *term)
{
	const char	*name_term;

	if (!isatty(0))
		clean_exit("isatty", term);
	if ((term->fd = open(ttyname(0), O_RDWR)) == -1)
		clean_exit("ttyname", term);
	if (!(name_term = getenv("TERM")))
		clean_exit("getenv", term);
	if (tgetent(NULL, name_term) < 1)
		clean_exit("tgetent", term);
	if (tcgetattr(term->fd, &(term->termios)) == -1)
		clean_exit("tcgetattr", term);
	term->termios.c_lflag &= ~(ICANON);
	term->termios.c_lflag &= ~(ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, TCSANOW, &(term->termios)) == -1)
		clean_exit("tcsetattr", term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_err);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_err);
}

void	rehab_term(t_term *term)
{
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
	tputs(tgetstr("te", NULL), 1, ft_putchar_err);
	term->termios.c_lflag = (ICANON | ECHO);
}
