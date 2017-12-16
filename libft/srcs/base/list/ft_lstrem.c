/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:37:16 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 17:14:46 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_base/base.h"

void		ft_lstrem(t_list **beg, t_list *lst)
{
	t_list	*prev;

	if (!beg || !*beg || !lst)
		return ;
	if (lst == *beg)
		*beg = (*beg)->next;
	else
	{
		prev = *beg;
		while (prev->next)
		{
			if (prev->next == lst)
			{
				prev = prev->next->next;
				lst->next = NULL;
				return ;
			}
			else
				prev = prev->next;
		}
	}
}
