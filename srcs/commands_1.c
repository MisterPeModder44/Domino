/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:31:03 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 18:41:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "domino.h"
#include "libft_base/base.h"

static t_list		*make_pool_list(void)
{
	int				a;
	int				b;
	t_list			*pool;
	t_list			*nlist;

	a = 0;
	pool = NULL;
	while (a <= 6)
	{
		b = a;
		while (b <= 6)
		{
			if (!(nlist = make_domino(a, b)))
			{
				delete_domino_list(&pool);
				return (NULL);
			}
			ft_lstadd(&pool, nlist);
			++b;
		}
		++a;
	}
	dprintf(g_lfd, "Pool has been initialized!\n");
	return (pool);
}

t_gamestate			*init_gamestate(char **cmd)
{
	t_gamestate		*state;

	if (!(state = (t_gamestate *)malloc(sizeof(t_gamestate))))
		return (NULL);
	state->player = ft_atoi(cmd[2]);
	state->hand = NULL;
	state->placed = NULL;
	if (!(state->pool = make_pool_list()))
		return (NULL);
	state->score = INITAL_SCORE;
	state->pieces = 0;
	state->grid = NULL;
	dprintf(g_lfd, "I am player number %d!\n", state->player);
	return (state);
}

int					make_grid(char **cmd, t_gamestate *state)
{
	int				i;
	int				j;
	int				dim[2];

	dim[0] = ft_atoi(cmd[1]);
	dim[1] = ft_atoi(cmd[2]);
	dprintf(g_lfd, "Creating grid of dim [%d, %d]...\n", dim[0], dim[1]);
	if (!(state->grid = (char **)ft_memalloc(sizeof(char *) * (dim[1] + 1))))
		return (1);
	i = 0;
	while (i < dim[1])
	{
		if (!(state->grid[i] = ft_strnew(dim[0])))
		{
			j = 0;
			while (j < i)
				ft_strdel(&state->grid[j++]);
			ft_memdel((void **)state->grid);
			return (1);
		}
		ft_memset(state->grid[i], ' ', dim[0]);
		++i;
	}
	state->gheight = dim[0];
	dprintf(g_lfd, "Successfully created grid: i = %d!\n", i);
	return (0);
}


int					add_piece(char **cmd, t_gamestate *state)
{
	t_list			*piece;

	if (state->pieces <= 0)
		return (0);
	--state->pieces;
	piece = search_and_extract(&state->pool, ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	dprintf(g_lfd, "adding piece to list...\n");
	ft_lstadd(&state->hand, piece);
	dprintf(g_lfd, "moved domino %d|%d from pool to hand!\n", ft_atoi(cmd[1]), ft_atoi(cmd[2]));
	return (0);
}

int					player_action(char **cmd, t_gamestate *state)
{
	if (ft_atoi(cmd[1]) != state->player)
	{
		dprintf(g_lfd, "player %d: %s\n", ft_atoi(cmd[1]), cmd[2]);
		if (ft_strequ(cmd[2], "ko"))
			return (1);
		else
			dprintf(g_lfd, "player %d seems to be a little drunk...\n", ft_atoi(cmd[1]));
	}
	return (0);
}
