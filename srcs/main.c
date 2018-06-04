/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:17:27 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"



void	key_input(t_term *term)
{
	char	buff[5];
	int		nb_cols;

	nb_cols = get_col_nb(term);
	ft_bzero(buff, 5);
	if ((read(0, buff, 4) < 0))
		clean_exit("read");
	if (*(int*)buff == UP)
		up_key(term);
	if (*(int*)buff == DOWN)
		down_key(term);
	if (*(int*)buff == RIGHT)
		nb_cols == 1 ? down_key(term) : right_key(term);
	if (*(int*)buff == LEFT)
		nb_cols == 1 ? up_key(term) : left_key(term);
	if (*(int*)buff == SP)
		sp_key(term);
	if (*(int*)buff == DEL || *(int*)buff == BCK_SP)
		del_key(term);
	if (*(int*)buff == ESC)
		exit(0);
	if (*(int*)buff == RET)
		rc_key(term);
}

static void	infinite_loop(t_term *term)
{
	while ("infinite loop")
	{
		update_index(term->slct);
		get_info(term);
			key_input(term);
			tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
			tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
			display(term);
	}
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
	term.slct->next->current = 1;
	update_index(term.slct);
	display(&term);
	infinite_loop(&term);
	rehab_term(&term);
	return (0);
}
