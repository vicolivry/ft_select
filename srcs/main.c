/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 18:45:31 by volivry     ###    #+. /#+    ###.fr     */
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

void	key_input(t_term *term)
{
	char	buff[5];

	ft_bzero(buff, 5);
	if ((read(0, buff, 4) < 0))
		clean_exit("read");
	if (*(int*)buff == UP)
		up_key(term);
	if (*(int*)buff == DOWN)
		down_key(term);
	if (*(int*)buff == RIGHT)
		right_key(term);
	if (*(int*)buff == LEFT)
		left_key(term);
	if (*(int*)buff == SP)
		sp_key(term);
	if (*(int*)buff == DEL || *(int*)buff == BCK_SP)
		del_key(term);
	if (*(int*)buff == ESC)
		exit(0);
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
	display(&term);
	while ("infinite loop")
	{
		key_input(&term);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
		tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
		display(&term);
	}
	free_slct(term.slct);
	rehab_term(&term);
	return (0);
}
