/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_utils2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 13:57:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 17:25:27 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_slct	*root_slct(void)
{
	t_slct	*lst;

	lst = NULL;
	if (!(lst = malloc(sizeof(*lst))))
		return (NULL);
	lst->pos = 0;
	lst->len = 0;
	lst->select = 0;
	lst->name = NULL;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

t_slct	*init_slct(const char **argv)
{
	t_slct	*root;
	int		i;

	i = 1;
	if (!(root = root_slct()))
		return (NULL);
	while (argv[i])
	{
		add_queue(root, argv[i], i);
		i++;
	}
	return (root);
}

t_slct	*first_elem(t_slct *root)
{
	if (root->next != root)
		return (root->next);
	else
		return (NULL);
}
