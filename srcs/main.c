/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 17:50:41 by volivry     ###    #+. /#+    ###.fr     */
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

int		main(int argc, const char **argv)
{
	t_term	term;

	if (argc <= 1)
	{
		ft_putendl_fd("Not enough arguments", 2);
		return (0);
	}
	term.slct = init_slct(argv);
	init_term(&term);
	get_info(&term);
	display(&term);
	rehab_term(&term);
	free_slct(term.slct);
	return (0);
}
