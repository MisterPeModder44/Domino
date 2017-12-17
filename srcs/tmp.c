/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:51:51 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 14:55:24 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include <stdlib.h>
#include <fcntl.h>

static void		do_print(t_list *lst)
{
	dprintf(g_lfd, "%d|%d ,", get_dnum_a(lst), get_dnum_b(lst));
}

void			print_lst(char *name, t_list *list)
{
	dprintf(g_lfd, "%s: ", name);
	ft_lstiter(list, &do_print);
}

void		get_logfile(void)
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
