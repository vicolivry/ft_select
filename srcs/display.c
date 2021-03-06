/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 18:56:33 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 11:29:24 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		set_cols(t_term *term, int col_pos, int i)
{
	int	j;

	j = 0;
	if (i != 0 && (i % (term->info.nb_row) == 0))
	{
		col_pos += (term->info.max_len + 2);
		tputs(tgetstr("rc", NULL), term->fd, ft_putchar_err);
	}
	while (j < col_pos)
	{
		tputs(tgetstr("nd", NULL), term->fd, ft_putchar_err);
		j++;
	}
	return (col_pos);
}

static void		display2(t_term *term, int col_pos, t_slct *tmp)
{
	int	i;

	i = 0;
	while (tmp != term->slct)
	{
		col_pos = set_cols(term, col_pos, i);
		print_arg(tmp, term);
		if ((i + 1) % (term->info.nb_row) || !i)
			ft_putchar_fd(10, term->fd);
		tmp = tmp->next;
		i++;
	}
}

void			display(t_term *term)
{
	int		i;
	int		cols;
	int		col_pos;
	t_slct	*tmp;

	i = 0;
	get_info(term);
	cols = get_col_nb(term);
	col_pos = 0;
	tmp = first_elem(term->slct);
	tputs(tgetstr("cl", NULL), term->fd, ft_putchar_err);
	if (cols * term->info.max_len > term->info.nb_col - 1)
	{
		ft_putstr_fd("Window size too small", term->fd);
		return ;
	}
	else
		display2(term, col_pos, tmp);
}
