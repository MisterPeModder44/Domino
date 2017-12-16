/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:20:56 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 17:53:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "libft_base/base.h"

typedef struct		s_player_state
{
	int				player;
	int				score;
	t_list			*hand;
}					t_player_state;

int					ft_put_error(char *reason);
void				print_domino(t_list *domino);
void				put_player_color(int player);
void				do_training(int *options);
void				do_turn(char **grid,
		t_player_state *ps, t_list **pool, int first_turn);

#endif
