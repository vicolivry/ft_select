/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arrows.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 17:44:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 13:15:29 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	right_key(t_term *term)
{
	t_slct	*tmp;
	int		pos;

	tmp = first_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			pos = (tmp->index % term->info.nb_row);
			tmp = tmp->next == term->slct ? tmp->next->next : tmp->next;
			while (tmp->index % term->info.nb_row != pos)
			{
				tmp = tmp->next == term->slct ? tmp->next : tmp;
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
	int		pos;

	tmp = last_elem(term->slct);
	while (tmp != term->slct)
	{
		if (tmp->current)
		{
			tmp->current = 0;
			pos = (tmp->index % term->info.nb_row);
			tmp = tmp->prev == term->slct ? tmp->prev->prev : tmp->prev;
			while (tmp->index % term->info.nb_row != pos)
			{
				tmp = tmp->prev == term->slct ? tmp->prev : tmp;
				tmp = tmp->prev;
			}
			tmp->current = 1;
			return ;
		}
		tmp = tmp->prev;
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
