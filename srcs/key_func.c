/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_func.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 17:49:20 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 15:33:00 by volivry     ###    #+. /#+    ###.fr     */
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
		clean_exit("read", term);
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		up_key(term);
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		down_key(term);
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		nb_cols == 1 ? down_key(term) : right_key(term);
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		nb_cols == 1 ? up_key(term) : left_key(term);
	if (*(int*)buff == 32)
		sp_key(term);
	if ((buff[0] == 27 && buff[1] == 91 && buff[2] == 51)|| *(int*)buff == 127)
		del_key(term);
	if (*(int*)buff == 27)
		quit_ft_select(term);
	if (*(int*)buff == 10)
		rc_key(term);
}

void	sp_key(t_term *term)
{
	t_slct	*tmp;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->select = tmp->select ? 0 : 1;
			down_key(term);
			return ;
		}
		tmp = tmp->next;
	}
}

void	del_key(t_term *term)
{
	t_slct	*tmp;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			if (tmp->next != term->slct)
				tmp->next->current = 1;
			else if (tmp->prev != term->slct)
				tmp->prev->current = 1;
			else
				quit_ft_select(term);
			remove_elem(tmp);
			update_index(term->slct);
			return ;
		}
		tmp = tmp->next;
	}
}

void	rc_key(t_term *term)
{
	t_slct	*tmp;

	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (!tmp->select)
			remove_elem(tmp);
		tmp = tmp->next;
	}
	tmp = first_elem(term->slct);
	if (tmp)
		while (tmp != term->slct)
		{
			ft_putstr_fd(tmp->name, 0);
			if (tmp->next != term->slct)
				ft_putstr_fd(" ", 0);
			tmp = tmp->next;
		}
	quit_ft_select(term);
}
