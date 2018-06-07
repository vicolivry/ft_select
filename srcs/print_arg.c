/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 11:59:58 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 14:02:33 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	print_cur(t_slct *slct, t_term *term)
{
	tputs(tgetstr("us", NULL), term->fd, ft_putchar_err);
	slct->index % 2 ? ft_putstr_fd(YELLOW, term->fd) :
		ft_putstr_fd(GREEN, term->fd);
	ft_putstr_fd(slct->name, term->fd);
	ft_putstr_fd(RESET, term->fd);
	tputs(tgetstr("ue", NULL), term->fd, ft_putchar_err);
}

static void	print_cur_slct(t_slct *slct, t_term *term)
{
	tputs(tgetstr("so", NULL), term->fd, ft_putchar_err);
	tputs(tgetstr("us", NULL), term->fd, ft_putchar_err);
	slct->index % 2 ? ft_putstr_fd(YELLOW, term->fd) :
		ft_putstr_fd(GREEN, term->fd);
	ft_putstr_fd(slct->name, term->fd);
	ft_putstr_fd(RESET, term->fd);
	tputs(tgetstr("ue", NULL), term->fd, ft_putchar_err);
	tputs(tgetstr("se", NULL), term->fd, ft_putchar_err);
}

static void	print_slct(t_slct *slct, t_term *term)
{
	tputs(tgetstr("so", NULL), term->fd, ft_putchar_err);
	slct->index % 2 ? ft_putstr_fd(YELLOW, term->fd) :
		ft_putstr_fd(GREEN, term->fd);
	ft_putstr_fd(slct->name, term->fd);
	ft_putstr_fd(RESET, term->fd);
	tputs(tgetstr("se", NULL), term->fd, ft_putchar_err);
}

void		print_arg(t_slct *slct, t_term *term)
{
	if (slct->current)
	{
		if (slct->select == 1)
			print_cur_slct(slct, term);
		else
			print_cur(slct, term);
	}
	else if (slct->select)
		print_slct(slct, term);
	else
	{
		slct->index % 2 ? ft_putstr_fd(YELLOW, term->fd) :
			ft_putstr_fd(GREEN, term->fd);
		ft_putstr_fd(slct->name, term->fd);
		ft_putstr_fd(RESET, term->fd);
	}
}
