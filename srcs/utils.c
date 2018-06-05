/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 13:55:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 15:37:51 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	clean_exit(const char *error, t_term *term)
{
	free_slct(term->slct);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	rehab_term(term);
	ft_putstr_fd("ft_select: error: ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

int		get_col_nb(t_term *term)
{
	int	cols;

	cols = term->info.nb_elem / (term->info.nb_row);
	cols = !cols ? 1 : cols;
	cols += cols * (term->info.nb_row) < term->info.nb_elem ? 1 : 0;
	return (cols);
}

int		ft_putchar_err(int c)
{
	return (write(2, &c, 1));
}

void	free_slct(t_slct *lst)
{
	lst = lst->next;
	while (lst->next != lst)
	{
		remove_elem(lst);
		lst = lst->next;
	}
	ft_memdel((void**)&lst);
}

void	quit_ft_select(t_term *term)
{
	rehab_term(term);
	free_slct(term->slct);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
	exit(0);
}
