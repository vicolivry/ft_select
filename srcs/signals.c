/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signals.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 15:34:35 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:27:53 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		resize_win(int sig)
{
	t_term	*term;

	(void)sig;
	term = NULL;
	term = memorize_term(term, 101);
	tputs(tgetstr("cl", NULL), term->fd, ft_putchar_err);
	display(term);
}

static void		stop(int sig)
{
	t_term	*term;
	char	s[2];

	(void)sig;
	term = NULL;
	term = memorize_term(term, 101);
	s[0] = term->termios.c_cc[VSUSP];
	s[1] = 0;
	rehab_term(term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, s);
}

static void		restart(int sig)
{
	t_term	*term;

	(void)sig;
	term = NULL;
	term = memorize_term(term, 101);
	signal(SIGTSTP, stop);
	init_term(term);
	display(term);
}

static void		quit(int sig)
{
	t_term	*term;

	(void)sig;
	term = NULL;
	term = memorize_term(term, 101);
	quit_ft_select(term);
}

void			get_signals(void)
{
	signal(SIGWINCH, resize_win);
	signal(SIGINT, quit);
	signal(SIGQUIT, quit);
	signal(SIGTERM, quit);
	signal(SIGTSTP, stop);
	signal(SIGCONT, restart);
}
