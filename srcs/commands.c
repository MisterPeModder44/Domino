/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:31:03 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 20:02:17 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "domino_exp.h"
#include "libft_base/base.h"

t_gamestate			*init_gamestate(char **cmd)
{
	t_gamestate		*state;

	if (!(state = (t_gamestate *)malloc(sizeof(t_gamestate))))
		return (NULL);
	state->player = ft_atoi(cmd[2]);
	state->hand = NULL;
	state->score = 0;
	state->grid = NULL;
	dprintf(g_lfd, "I am player number %d!\n", state->player);
}

int					make_grid(char **cmd, t_gamestate *state)
{
	int				i;
	int				j;
	int				dim;

	if (!(state->grid = (char **)malloc(sizeof(char *) * (cmd[2] + 1))))
		return (1);
	i = 0;
	while (i < cmd[2])
	{
		(!(state->grid[i] = ft_strnew(cmd[1])))
		{
			j = 0;
			while (j < i)
				ft_strdel(state->grid[j++]);
			ft_memdel((void **)state->grid);
			return (1);
		}
		ft_memset(state->grid[i], ' ', cmd[1]);
		++i;
	}
	return (0);
}
