/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:15:42 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 17:39:40 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "domino.h"
#include "tmp.h"

int					output_cmd(char **cmd, int len)
{
	char			*to_put;
	char			*tmp;
	int				i;

	to_put = NULL;
	i = 0;
	while (i <= len)
	{
		if (to_put && i < len)
		{
			tmp = ft_strjoin(to_put, ":");
			free(to_put);
			to_put = tmp;
		}
		tmp = ft_strjoin(to_put, CMD_PART(i, len));
		if (to_put != NULL)
			free(to_put);
		to_put = ft_strequ(tmp, CMD_PART(i, len)) ? ft_strdup(tmp) : tmp;
		++i;
	}
	dprintf(g_lfd, "cmd = %s", to_put);
	i = write(1, to_put , ft_strlen(to_put));
	ft_strdel(&to_put);
	return (i == -1);
}

int					cmd_put_init(t_list *domino, t_gamestate *state)
{
	char			*cmd[3];
	char			*num;

	num = ft_itoa(get_dnum_a(domino));
	cmd[0] = "put";
	cmd[1] = num;
	cmd[2] = num;
	if (output_cmd(cmd, 3))
	{
		ft_strdel(&num);
		return (1);
	}
	print_lst("placed", state->placed);
	ft_lstadd(&state->placed, domino);
	state->score = 0;
	ft_strdel(&num);
	return (0);
}

static char			**get_nums(t_list *domino, int *args)
{
	char			**nums;
	int				i;

	if (!(nums = (char **)ft_memalloc(sizeof(char *) * 8)))
		return (NULL);
	nums[1] = ft_itoa(get_dnum_a(domino));
	nums[2] = ft_itoa(get_dnum_b(domino));
	i = 3;
	while (i < 8)
	{
		nums[i] = ft_itoa(args[i - 3]);
		++i;
	}
	i = 1;
	while (i < 8)
		if (!nums[++i])
			return (NULL);
	return (nums);
}

int					cmd_put(t_list *domino, t_gamestate *state, int *args)
{
	char			**cmd;

	if (!(cmd = get_nums(domino, args)))
		return (1);
	if (!(cmd[0] = ft_strdup("put")))
		return (1);
	if (output_cmd(cmd, 7))
	{
		ft_strtabdel(&cmd);
		return (1);
	}
	ft_lstadd(&state->placed, domino);
	ft_strtabdel(&cmd);
	print_lst("placed", state->placed);
	return (0);
}
