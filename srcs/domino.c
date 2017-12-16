/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:27:14 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 16:02:13 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_list		*make_domino_pool(void)
{
	int			a;
	int			b;
	t_list		*pool;
	t_list		*nlst;
	t_domino	dom;

	a = 0;
	pool = NULL;
	while (a <= 6)
	{
		b = a;
		while (b <= 6)
		{
			dom.num1 = a;
			dom.num2 = b;
			nlst = ft_lstnew(&dom, sizeof(t_domino));
			ft_lstadd(&pool, nlst);
			++b;
		}
		++a;
	}
	return (pool);
}

int			get_dnum_1(t_list *domino)
{
	return (((t_domino *)domino->content)->num1);
}

int			get_dnum_2(t_list *domino)
{
	return (((t_domino *)domino->content)->num2);
}
