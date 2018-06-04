/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_info.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 12:07:02 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 12:53:49 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	get_info(t_term *term)
{
	t_slct	*tmp;

	term->info.nb_elem = 0;
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
