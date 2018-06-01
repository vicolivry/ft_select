/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 11:59:58 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 18:01:19 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	print_cur(t_slct *slct)
{
	tputs(tgetstr("us", NULL), 1, ft_putchar_err);
	ft_putstr(slct->name);
	tputs(tgetstr("ue", NULL), 1, ft_putchar_err);
}

static void	print_cur_slct(t_slct *slct)
{
	tputs(tgetstr("so", NULL), 1, ft_putchar_err);
	tputs(tgetstr("us", NULL), 1, ft_putchar_err);
	ft_putstr(slct->name);
	tputs(tgetstr("ue", NULL), 1, ft_putchar_err);
	tputs(tgetstr("se", NULL), 1, ft_putchar_err);
}

static void	print_slct(t_slct *slct)
{
	tputs(tgetstr("so", NULL), 1, ft_putchar_err);
	ft_putstr(slct->name);
	tputs(tgetstr("se", NULL), 1, ft_putchar_err);
}

void		print_arg(t_slct *slct)
{
	if (slct->current)
	{
		if (slct->select == 1)
			print_cur_slct(slct);
		else
			print_cur(slct);
	}
	else if (slct->select)
		print_slct(slct);
	else
		ft_putstr(slct->name);
}
