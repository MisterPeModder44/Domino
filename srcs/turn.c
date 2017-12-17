/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:07:26 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 19:48:27 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include "tmp.h"

static t_list		*get_double_in_hand(t_gamestate *state)
{
	t_list			*dom;
	int				i;

	i = 0;
	while (i <= 6)
	{
		if ((dom = search_and_extract(&state->hand, i, i)))
			return (dom);
		++i;
	}
	return (NULL);
}

static int			do_init_turns(t_gamestate *state)
{
	t_list			*dom;

	dprintf(g_lfd, "Inital turn: \n");
	if (state->score == INITAL_SCORE)
	{
		dprintf(g_lfd, "search result: \n===\n");
		if ((dom = get_double_in_hand(state)))
		{
			dprintf(g_lfd, "found it! trying to put in grid...\n===\n\n");
			state->score = 0;
			return (cmd_put_init(dom, state));
		}
		else
		{
			dprintf(g_lfd, "not found!\n===\n\n");
			--state->score;
			return (cmd_sulk());
		}
	}
	else if (state->score == INITAL_SCORE - 1)
	{
		dprintf(g_lfd, "drawing!\n");
		--state->score;
		return (cmd_draw());
	}
	return (0);
}

int					do_turn(t_gamestate *state)
{
	t_list			*dom;
	int				ret;

	dprintf(g_lfd, "\nThis is my turn now: score = %d!\n", state->score);
	if (state->score <= INITAL_SCORE)
		return (do_init_turns(state));
	else
	{
		dom = state->hand;
		while (dom)
		{
			dprintf(g_lfd, "trying to place %d|%d\n", get_dnum_a(dom), get_dnum_b(dom));
			if ((ret = try_place_piece(dom, state)) == 1)
				return (1);
			if (ret == 0)
			{
				ft_lstrem(&state->hand, dom);
				ft_lstdel(&dom, &delete_domino_piece);
				return (0);
			}
			dom = dom->next;
		}
	}
	return (0);
}
