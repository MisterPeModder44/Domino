/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:52:56 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 16:36:24 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"
#include "domino.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int		get_size(int *options, char *arg)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(arg, ':');
	i = 0;
	while (tab[i])
		++i;
	if (i == 3 && ft_strequ(tab[0], "--size"))
	{
		i = 0;
		while (tab[1][i] && tab[1][i] >= '0' && tab[1][i] <= '9')
			++i;
		if (!tab[1][i])
		{
			i = 0;
			while (tab[2][i] && tab[2][i] >= '0' && tab[2][i] <= '9')
				++i;
			if (!tab[2][i])
			{
				options[1] = ft_atoi(tab[1]);
				options[2] = ft_atoi(tab[2]);
				ft_strtabdel(&tab);
				return (1);
			}
		}
	}
	ft_strtabdel(&tab);
	return (0);
}

int				main(int ac, char **av)
{
	int		options[3];

	options[0] = 0;
	if (ac == 2 || ac == 3)
	{
		options[0] = ft_strequ(av[1], "--training");
		if (!options[0] && ac == 2)
			return (ft_put_error("please select 2 AIs"));
		else if (ac == 2)
		{
			options[1] = 60;
			options[2] = 60;
		}
		else if (options[0] && ac == 3 && !get_size(options, av[2]))
			return (ft_put_error("bad size option, format: \"--size:w:h\""));
	}
	else
		return (ft_put_error("please select 2 AIs"));
	if (options[0])
		do_training(options);
	return (0);
}
