/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:44:17 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 14:58:28 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include "tmp.h"

static int			domino_cmp(void *a, void *b)
{
	t_domino		*dom1;
	t_domino		*dom2;

	dom1 = (t_domino *)a;
	dom2 = (t_domino *)b;
	if (dom1->a == dom2->a && dom1->b == dom2->b)
		return (0);
	else if (dom1->a == dom2->b && dom1->b == dom2->a)
		return (0);
	return (-1);
}

t_list				*search_and_extract(t_list **origin, int a, int b)
{
	t_domino		domino;

	domino.a = a;
	domino.b = b;
	print_lst("pool", *origin);
	dprintf(g_lfd, "\nsearching for %d|%d\n", a, b);
	return (ft_lstextract(origin, (void *)&domino, &domino_cmp));
}
