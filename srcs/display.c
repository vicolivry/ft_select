/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 18:56:33 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 19:04:48 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static int		get_col_nb(t_term *term)
{
	int	cols;

	cols = term->info.nb_elem / (term->info.nb_row - 1);
	cols = !cols ? 1 : cols;
	cols += cols * (term->info.nb_row) < term->info.nb_elem ? 1 : 0;
	return (cols);
}

static int		set_display(t_term *term, int col_pos, int i)
{
	int	j;

	j = 0;
	if (i != 0 && !(i % (term->info.nb_row)))
	{
		col_pos += (term->info.max_len);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	}
	while (j++ <= col_pos)
		tputs(tgetstr("nd", NULL), 1, ft_putchar_err);
	return (col_pos);
}

void	display(t_term *term)
{
	int		i;
	int		cols;
	int		col_pos;
	t_slct	*tmp;

	i = 1;
	cols = get_col_nb(term);
	ft_printf("rows : %d, cols : %d\n", term->info.nb_row, cols);
	col_pos = 0;
	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		col_pos = set_display(term, col_pos, i);
		ft_putendl(tmp->name);
		tmp = tmp->next;
		i++;
	}
}


