/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/29 18:04:16 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

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

void	get_info(t_term *term)
{
	t_slct	*tmp;

	term->info.nb_elem = 0;
	term->info.nb_col = 0;
	term->info.nb_row = 0;
	term->info.max_len = 0;
	tmp = first_elem(term->slct);
	ioctl(0, TIOCGWINSZ, &(term->wndw));
	term->info.nb_row = term->wndw.ws_row;
	term->info.nb_col = term->wndw.ws_col;
	while (tmp != term->slct)
	{
		if (ft_strlen(tmp->name) > term->info.max_len)
			term->info.max_len = ft_strlen(tmp->name);
		term->info.nb_elem++;
		tmp = tmp->next;
	}
}

int		main(int argc, const char **argv)
{
	t_slct	*tmp;
	t_term	term;

	if (argc <= 1)
	{
		ft_putendl_fd("Not enough arguments", 2);
		return (0);
	}
	term.slct = init_slct(argv);
	tmp = first_elem(term.slct);
	init_term(&term);
	get_info(&term);
	while (tmp != term.slct)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("ROWS : %d, COLMNS : %d\n", term.info.nb_row, term.info.nb_col);
	ft_printf("MAXLEN: %d, nb elem: %d\n", term.info.max_len, term.info.nb_elem);
	rehab_term(&term);
	free_slct(term.slct);
	return (0);
}
