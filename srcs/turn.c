/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:20:24 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 18:18:30 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"
#include "domino.h"
#include <stdio.h>

void			put_player_color(int player)
{
	ft_putstr(player == 1 ? "\x1b[1;33m": "\x1b[1;34m");
}

static void		write_prompt(int player)
{
	player = 0;
	ft_putstr("\n\x1b[1;97m> ");
}

static void		put_ko(int player)
{
	put_player_color(1);
	ft_putstr("\np:");
	ft_putnbr(player);
	ft_putendl(":ko");
	put_player_color(2);
	ft_putstr("\np:");
	ft_putnbr(player);
	ft_putendl(":ko");
	put_player_color(player);
}

/*
   static t_list	*get_domino(t_list *pool, int a, int b)
   {
   t_list		*tmp;

   tmp = pool;
   while (tmp)
   {
   if (get_dnum_1(tmp) == a && get_dnum_2(tmp) == b)
   return (tmp);
   tmp = tmp->next;
   }
   return (NULL);
   }*/

/*
   static int		put_domino_grid(char **grid, int a, int b, int c, int l, int o, int d)
   {
   if ((o == 1 && (d == 1 && !)))
   if (grid[l][c] == ' ')
   {
   ft_putendl("ko:there is already a domino there!");
   return (0);
   }
   else
   {
   grid[l][c] = (o == 1 ? '|' : '-');
   }
   }

   static void		print_domino_grid(char **grid)
   {

   }*/

void			do_turn(char **grid, t_player_state *ps, t_list **pool, int first_turn)
{
	char	*line;
	char	**cmd;
	int		turns;
	t_list	*domino;

	ft_putendl(ps->player == 1 ? "\x1b[1;33mplayer 1, go!":
			"\x1b[1;34mplayer 2, go!");
	grid = 0;
	turns = 3;
	ft_lstiter(ps->hand, &print_domino);
	write_prompt(ps->player);
	while (turns > 0 && get_next_line(0, &line) > 0)
	{
		put_player_color(ps->player);
		ft_putchar('\n');
		if (line && *line != 0)
		{
			cmd = ft_strsplit(line, ':');
			if (ft_strequ(*cmd, "sulk"))
			{
				--turns;
				if (turns > 0)
					ft_lstiter(ps->hand, &print_domino);
			}
			else if (ft_strequ(*cmd, "put"))
			{
				if (first_turn)
				{

				}
			}
			else if (ft_strequ(*cmd, "draw"))
			{
				put_player_color(ps->player);
				if (ft_lstlen(*pool) > 0)
				{
					ft_putendl("pieces:n:1");
					domino = *pool;
					print_domino(domino);
					ft_putchar('\n');
					ft_lstrem(pool, domino);
					domino->next = NULL;
					ft_lstadd(&ps->hand, domino);
					turns = 0;
				}
				else
				{
					ft_putendl("ko:empty stock");
					put_ko(ps->player);
					--turns;
				}
			}
			else
			{
				ft_putstr("ko:unknown command:\x1b[0m");
				ft_putendl(*cmd);
				put_ko(ps->player);
				ft_putchar('\n');
				--turns;
			}
			ft_strtabdel(&cmd);
		}
		ft_strdel(&line);
		if (turns > 0)
			write_prompt(ps->player);
	}
}
