/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:10:12 by udelorme          #+#    #+#             */
/*   Updated: 2016/03/24 19:41:35 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"
#include "toolkit.h"

int		main(int argc, char **argv, char **environ)
{
	(void)environ;
	t_all *global;
	char *res;

	if (argc < 2)
		return (1);
	global = t_all_new();
	init_env(global, argv);

	res = tgetstr("cl", NULL);
	tputs(res, 0, t_putchar);

	//ft_putstr("\033[?1049l");
	render_items(global);
	sleep(5);
	tputs("\033[?1049l", 0, t_putchar);
	tcsetattr(0, 0, &(global)->term);
	ft_putstr("/");
	return (0);
}
