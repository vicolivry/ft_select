/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 13:06:18 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 18:30:01 by volivry     ###    #+. /#+    ###.fr     */
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

void free_slct(t_slct *lst)
{
	lst = lst->next;
	while (lst->next != lst)
	{
		remove_elem(lst);
		lst = lst->next;
	}
	ft_memdel((void**)&lst);
}

void	clean_exit(const char *error)
{
	ft_putendl_fd("ft_select: error: ", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

void	init_term(t_term *term)
{
	const char	*name_term;

	if (!isatty(0))
		clean_exit("isatty");
	if ((term->fd = open(ttyname(0), O_RDWR)) == -1)
		clean_exit("ttyname");
	if (!(name_term = getenv("TERM")))
		clean_exit("getenv");
	if (tgetent(NULL, name_term) < 1)
		clean_exit("tgetent");
	if (tcgetattr(term->fd, &(term->termios)) == -1)
		clean_exit("tcgetattr");
	term->termios.c_lflag &= ~(ICANON);
	term->termios.c_lflag &= ~(ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, TCSANOW, &(term->termios)) == -1)
			clean_exit("tcsetattr");
}

void	rehab_term(t_term *term)
{
	if (tcgetattr(term->fd, &(term->termios)) == -1)
		clean_exit("tcgetattr");
	term->termios.c_lflag = (ICANON | ECHO);
	if (tcsetattr(term->fd, 0, &(term->termios)) == -1)
		clean_exit("tcsetattr");
}

int		main(int argc, const char **argv)
{
	t_slct	*tmp;
	t_term	term;

	if (argc < 1)
	{
		ft_putendl_fd("Not enough arguments", 2);
		return (0);
	}
	term.slct = init_slct(argv);
	tmp = first_elem(term.slct);
	while (tmp->next != term.slct)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	init_term(&term);
	free_slct(term.slct);
	return (0);
}
