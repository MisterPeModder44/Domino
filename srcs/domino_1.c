/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:56:41 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 19:49:07 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include <stdlib.h>

t_list				*make_domino(int a, int b)
{
	t_domino		domino;

	domino.a = a;
	domino.b = b;
	return (ft_lstnew(&domino, sizeof(t_domino)));
}

int					get_dnum_a(t_list *domino)
{
	return (((t_domino *)domino->content)->a);
}

int					get_dnum_b(t_list *domino)
{
	return (((t_domino *)domino->content)->b);
}

void			delete_domino_piece(void *dom, size_t size)
{
	size = 0;
	free(dom);
}

void				delete_domino_list(t_list **list)
{
	ft_lstdel(list, &delete_domino_piece);
}
