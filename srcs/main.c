/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:51:29 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 17:10:21 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft_base/base.h"
#include "get_next_line.h"
#include "domino.h"
#include "tmp.h"

#define SPLIT_CHAR ':'

static int		proc_cmd(t_gamestate **state,char **cmd)
{

	if (ft_strequ(*cmd, "player") && *(cmd[1]) == 'n'
			&& !(*state = init_gamestate(cmd)))
		return (1);
	else if (ft_strequ(*cmd, "board") && make_grid(cmd, *state))
		return (1);
	else if (ft_strequ(*cmd, "pieces") && *(cmd[1]) == 'n')
		(*state)->pieces = ft_atoi(cmd[2]);
	else if (ft_strequ(*cmd, "piece") && add_piece(cmd, *state))
		return (1);
	else if (ft_strequ(*cmd, "go") && do_turn(*state))
		return (1);
	else if (ft_strequ(*cmd, "p") && player_action(cmd, *state))
		return (1);
	else if (ft_strequ(*cmd, "new") && on_piece_placed(cmd, *state))
		return (1);
	return (0);
}

static void		huston_we_have_a_problem(t_gamestate **state)
{
	t_gamestate *s;

	s = *state;
	dprintf(g_lfd, "Huuuuuuuh... houston?\nWE HAVE A PROBLEM!!!!!!!!\n");
	if (s->pool)
		delete_domino_list(&s->pool);
	if (s->hand)
		delete_domino_list(&s->pool);
	if (s->placed)
		delete_domino_list(&s->pool);
	if (s->grid)
		ft_strtabdel(&s->grid);
}

int				main(void)
{
	char		*line;
	char		**cmd;
	t_gamestate	*state;

	get_logfile();
	dprintf(g_lfd, "starting program...\n");
	state = NULL;
	while (get_next_line(0, &line) >= 0)
	{
		if (line && *line)
		{
			dprintf(g_lfd, "Input: %s\n", line);
			cmd = ft_strsplit(line, SPLIT_CHAR);
			if (proc_cmd(&state, cmd))
			{
				ft_strtabdel(&cmd);
				if (state)
					huston_we_have_a_problem(&state);
				return (-1);
			}
			ft_strtabdel(&cmd);
		}
		if (line)
			ft_strdel(&line);
	}
	close(g_lfd);
	return (0);
}
