/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:33:05 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 15:39:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H
# define DOMINO_H

#include "libft.h"

typedef struct		s_domino
{
	int				num1;
	int				num2;
}					t_domino;

t_list				*make_domino_pool(void);
int					get_dnum_1(t_list *domino);
int					get_dnum_2(t_list *domino);

#endif
