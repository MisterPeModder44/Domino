/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:49:08 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 23:12:01 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int			get_fwd(t_gamestate *state, t_place_data *d)
{
	if (d->o == 1)
		d->y = d->d == 1 ? d->y - 1 : d->y + 1;
	else
		d->x = d->d == 1 ? d->x - 1 : d->x + 1;
	return (d->x >= 0 && d->x < d->len && d->y >= 0 && d->y < state->gheight);
}

static int	check_tip(t_gamestate *state, t_place_data *d)
{
	char	c;

	if (!get_fwd(state, d) || GRID(state, d) == ' ')
		return (0);
	if (d->o == 2 && GRID(state, d) == '-' && d->y > 0 &&
			d->y < state->gheight - 1)
	{
		dprintf(g_lfd, "can place here 1\n");
		c = state->grid[d->x][d->y + 1];
		return (state->grid[d->x][d->y - 1] == c);
	}
	else if (d->o == 1 && GRID(state, d) == '|' && d->x > 0 &&
			d->x < d->len - 1)
	{
		dprintf(g_lfd, "can place here 2\n");
		c = state->grid[d->x + 1][d->y];
		return (state->grid[d->x - 1][d->y] == c);
	}
	else if (ft_isdigit(GRID(state, d)))
	{
		dprintf(g_lfd, "line: |%s|\n", state->grid[d->x]);
		dprintf(g_lfd, "can place here 3, x: %d, y: %d, o: %d, d: %d\n", d->x, d->y, d->o, d->d);
		return (check_links(state, d));
	}
	return (0);
}


static int	can_place_domino(t_gamestate *state, t_place_data *data)
{
	int		ret;

	if (GRIDT(state, data) != ' ')
		return (0);
	data->o = 0;
	while (++data->o < 3)
	{
		data->d = 0;
		while (++data->d < 3)
		{
			data->x = data->tx;
			data->y = data->ty;
			if (!get_fwd(state, data) || GRID(state, data) != ' ')
				continue;
			ret = get_fwd(state, data) && GRID(state, data) == ' ' &&
				check_tip(state, data);
			if (ret)
				return (1);
		}
	}
	return (0);
}

int			try_place_piece(t_list *dom, t_gamestate *state)
{
	t_place_data	data;
	int				args[4];

	data.len = ft_strlen(*state->grid);
	data.ty = -1;
	data.to_place = dom;
	while (++data.ty < state->gheight)
	{
		data.tx = -1;
		while (++data.tx < data.len)
		{
			if (can_place_domino(state, &data))
			{
				dprintf(g_lfd, "cool\n");
				data.len = -1;
				while (++data.len < 42)
					dprintf(g_lfd, "%d: |%s|\n", data.len, state->grid[data.len]);
				args[0] = data.tx;
				args[1] = data.ty;
				args[2] = data.o;
				args[3] = data.d;
				if (cmd_put(dom, state, args))
					return (cmd_ko());
				return (0);
			}
		}
	}
	return (2);
}
