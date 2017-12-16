/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:51:29 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 20:00:10 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "domino_exp.h"

#define SPLIT_CHAR ':'

static void		get_logfile(void)
{
	char	*str;
	char	*tmp;
	int		ret;
	int		att;

	ret = 1;
	att = 1;
	while (ret)
	{
		tmp = ft_itoa(att);
		str = ft_strjoin("log_", tmp);
		free(tmp);
		tmp = ft_strjoin(str, ".txt");
		free(str);
		ret = open(tmp, O_CREAT | O_WRONLY | O_EXCL, 0640);
		free(tmp);
		++att;
		if (ret > 0)
			break;
	}
	g_lfd = ret;
	dprintf(g_lfd, "== LOGFILE %d ==\n", att - 1);
}

static int		proc_cmd(t_gamestate *state,char **cmd)
{

	if (ft_strequ(*cmd, "player") && *(cmd[1]) == 'n'
			&& !(state = init_gamestate(cmd)))
		return (1);
	else if (ft_strequ(*cmd, "board") && make_grid(cmd, state))
		return (1);
	return (0);
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
			cmd = ft_strsplit(line, SPLIT_CHAR);
			if (proc_cmd(state, cmd))
			{
				ft_strtabdel(&cmd);
				return (-1);
			}
			ft_strtabdel(&cmd);
		}
		free(line);
	}
	close(g_lfd);
	return (0);
}
