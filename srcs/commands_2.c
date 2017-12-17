/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:04:21 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 19:00:34 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "domino.h"
#include "libft_base/base.h"


static void			grid_put(char **cmd, t_gamestate *state, int a, int b)
{
	int				infos[4];
	int				x;
	int				y;

	infos[0] = ft_atoi(cmd[3]);
	infos[1] = ft_atoi(cmd[4]);
	infos[2] = ft_atoi(cmd[5]);
	infos[3] = ft_atoi(cmd[6]);
	state->grid[infos[1]][infos[0]] = b + '0';
	if (infos[2] == 1)
	{
		x = 0;
		y = infos[3] == 1 ? -1 : 1;
	}
	else
	{
		y = 0;
		x = infos[3] == 1 ? -1 : 1;
	}
	state->grid[infos[1] + y][infos[0] + x] = infos[2] == 1 ? '-' : '|';
	state->grid[infos[1] + y * 2][infos[0] + x * 2] = a + '0';
}


int					on_piece_placed(char **cmd, t_gamestate *state)
{
	t_list			*dom;
	int				a;
	int				b;

	if (state->score <= INITAL_SCORE)
		state->score = 0;
	a = ft_atoi(cmd[1]);
	b = ft_atoi(cmd[2]);
	dom = search_and_extract(&state->placed, a, b);
	if (!dom)
	{
		dom = search_and_extract(&state->pool, a, b);
		if (!dom)
			return (1);
	}
	ft_lstadd(&state->placed, dom);
	grid_put(cmd, state, a, b);
	a = -1;
	while (++a < 42)
		dprintf(g_lfd, "%d: |%s|\n", a, state->grid[a]);
	return (0);
}
