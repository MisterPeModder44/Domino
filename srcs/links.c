/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:57:12 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 23:31:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static int			fwd_to_center(t_gamestate *s, t_place_data *d)
{
	int				ox;
	int				oy;

	if (!get_fwd(s, d))
		return (0);
	ox = d->x;
	oy = d->y;
	if (GRID(s, d) == '-' || GRID(s, d) == '|')
		return (1);
	else if (ft_isdigit(GRID(s, d)))
	{
		if (d->y < s->gheight - 1 && s->grid[d->x][d->y + 1] == '-')
			++d->y;
		else if (d->y > 0 && s->grid[d->x][d->y - 1] == '-')
			--d->y;
		else if (d->x < d->len - 1 && s->grid[d->x + 1][d->y] == '|')
			++d->x;
		else if (d->x > 0 && s->grid[d->x - 1][d->y] == '|')
			--d->x;
		return (ox != d->x || oy != d->y);
	}
	return (0);
}

static int			center_links(t_gamestate *s, t_place_data *d)
{
	int				links;

	links = 0;
	if (d->y > 0 && ft_isdigit(s->grid[d->x][d->y - 1]))
		++links;
	return (links);
}

static int			center_links_h(t_gamestate *s, t_place_data *d)

static int			count_links(t_gamestate *s, t_place_data *d)
{
	if (!fwd_to_center)
		return (0);

}

int					check_links(t_gamestate *state, t_place_data *d)
{
	int				ox;
	int				oy;
	int				ret;

	ox = d->x;
	oy = d->y;
	ret = count_links(state, d);
	d->x = ox;
	d->y = oy;
	return (ret);
}
