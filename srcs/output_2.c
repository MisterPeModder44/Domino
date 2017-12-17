/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:37:48 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 17:34:01 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include "tmp.h"

int					cmd_sulk(void)
{
	char			*cmd;

	cmd = "sulk";
	return (output_cmd(&cmd, 1));
}

int					cmd_draw(void)
{
	char			*cmd;

	cmd = "draw";
	return (output_cmd(&cmd, 1));
}

int					cmd_ko(void)
{
	char			*cmd;

	cmd = "ko";
	output_cmd(&cmd, 1);
	return (1);
}
