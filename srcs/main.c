/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:51:29 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 19:08:31 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/* === TEMPORARY ===*/
int				g_lfd;

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

int				main(void)
{
	get_logfile();
	dprintf(g_lfd, "starting program...\n");
	close(g_lfd);
	return (0);
}
