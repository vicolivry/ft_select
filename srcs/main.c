/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:06:58 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_term		*memorize_term(t_term *term, int mode)
{
	static t_term	*tmp = NULL;

	if (!mode)
		tmp = term;
	return (tmp);
}

static void	infinite_loop(t_term *term)
{
	term = memorize_term(term, 0);
	get_signals();
	while ("infinite loop")
	{
		update_index(term->slct);
		get_info(term);
		key_input(term);
		display(term);
	}
}

int			main(int argc, const char **argv)
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
	term.slct->next->current = 1;
	update_index(term.slct);
	display(&term);
	infinite_loop(&term);
	return (0);
}
