/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:17:58 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 17:59:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"
#include "domino.h"
#include <stdio.h>
#include <stdlib.h>

static void		free_pool(void *addr, size_t size)
{
	size = 0;
	free(addr);
}

void		print_domino(t_list *domino)
{
	ft_putstr("piece:");
	ft_putnbr(get_dnum_1(domino));
	ft_putchar(':');
	ft_putnbr(get_dnum_2(domino));
	ft_putchar('\n');
}

static t_list	*init(int player, int *options, t_list **pool)
{
	t_list	*domino;
	t_list	*hand;
	int		i;

	ft_putendl(player == 1 ? "\x1b[1;33mplayer:n:1" : "\x1b[1;34mplayer:n:2");
	ft_putstr("board:");
	ft_putnbr(options[1]);
	ft_putchar(':');
	ft_putnbr(options[2]);
	ft_putchar('\n');
	ft_putstr("pieces:n:7\n");
	i = 0;
	hand = NULL;
	while (i < 7)
	{
		domino = *pool;
		ft_lstrem(pool, domino);
		domino->next = NULL;
		ft_lstadd(&hand, domino);
		++i;
	}
	ft_lstiter(hand, &print_domino);
	ft_putchar('\n');
	return (hand);
}

static char	**make_grid(int *dim)
{
	char	**grid;
	int		i;

	if (!(grid = (char **)ft_memalloc(sizeof(char *) * (dim[1] + 1))))
		return (NULL);
	i = 0;
	while (i < dim[2])
	{
		if (!(grid[i] = ft_strnew(dim[2])))
			return (NULL);
		ft_memset((void *)grid[i], ' ', dim[2]);
		++i;
	}
	return (grid);
}

void		do_training(int *options)
{
	t_list			*pool;
	t_player_state	*p1;
	t_player_state	*p2;
	t_player_state	*player;
	char			**grid;
	int				first;

	if (!(pool = make_domino_pool()))
		return ;
	if (!(p1 = (t_player_state *)malloc(sizeof(t_player_state))))
		return ;
	if (!(p2 = (t_player_state *)malloc(sizeof(t_player_state))))
		return ;
	p1->hand = init(1, options, &pool);
	p2->hand = init(2, options, &pool);
	player = p1;
	grid = make_grid(options);
	first = 1;
	while (ft_lstlen(p1->hand) && ft_lstlen(p2->hand))
	{
		do_turn(grid, player == p1 ? p1 : p2, &pool, first);
		first = 0;
		player = player == p1 ? p2 : p1;
	}
	ft_lstdel(&p1->hand, &free_pool);
	ft_lstdel(&p2->hand, &free_pool);
	free(p1);
	free(p2);
	ft_lstdel(&pool, &free_pool);
}
