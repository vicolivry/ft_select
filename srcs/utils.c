/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 13:55:04 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/29 13:55:59 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	clean_exit(const char *error)
{
	ft_putendl_fd("ft_select: error: ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

int		ft_putchar_err(int c)
{
	return (write(2, &c, 1));
}
