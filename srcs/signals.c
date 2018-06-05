/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signals.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 15:34:35 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 15:57:46 by volivry     ###    #+. /#+    ###.fr     */
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
	tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
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
}
