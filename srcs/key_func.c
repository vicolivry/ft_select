/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_func.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 17:49:20 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 17:59:49 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

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
				exit(1);
			remove_elem(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}
