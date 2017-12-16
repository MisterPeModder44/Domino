/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino_exp.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:20:37 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/16 20:00:50 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_EXP_H
# define DOMINO_EXP_H

/* === TEMPORARY ===*/
int				g_lfd;

typedef enum		e_mode
{
	INIT,
	BOARD,

}					t_mode;

typedef struct		s_domino
{
	int				a;
	int				b;
}					t_domino;

typedef struct		s_gamestate
{
	int				player;
	t_list			*hand;
	char			**grid;
	int				score;
}					t_gamestate;

t_gamestate			*init_gamestate(char **cmd);
int					make_grid(char **cmd, t_gamestate *state);

#endif
