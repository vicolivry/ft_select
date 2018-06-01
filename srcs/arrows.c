/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrows.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 17:44:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 18:40:34 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	right_key(t_term *term)
{
	t_slct	*tmp;
	int		i;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			i = 0;
			while (++i <= term->info.nb_row)
			{
				i -= tmp == term->slct ? 1 : 0;
				tmp = tmp->next;
			}
			tmp->current = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	left_key(t_term *term)
{
	t_slct	*tmp;
	int		i;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			i = term->info.nb_row + 1;
			while (--i)
			{
				i += tmp == term->slct ? 1 : 0;
				tmp = tmp->next;
			}
			tmp->current = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	down_key(t_term *term)
{
	t_slct	*tmp;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			if (tmp->next == term->slct)
				tmp->next->next->current = 1;
			else
				tmp->next->current = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void	up_key(t_term *term)
{
	t_slct	*tmp;

	tmp = last_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			if (tmp->prev == term->slct)
				tmp->prev->prev->current = 1;
			else
				tmp->prev->current = 1;
			return ;
		}
		tmp = tmp->prev;
	}
}
