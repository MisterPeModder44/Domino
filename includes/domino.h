/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:20:37 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/17 23:11:56 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H
# define DOMINO_H

# include <stdio.h>
# include "libft_base/base.h"

# define INITAL_SCORE -424242
# define CMD_PART(i, l) (i < l ? cmd[i] : "\n")
# define GRID(s, d) (s->grid[d->x][d->y])
# define GRIDT(s, d) (s->grid[d->tx][d->ty])

/* === TEMPORARY ===*/
int					g_lfd;

typedef struct		s_domino
{
	int				a;
	int				b;
}					t_domino;

typedef struct		s_gamestate
{
	int				player;
	t_list			*pool;
	t_list			*hand;
	t_list			*placed;
	char			**grid;
	int				gheight;
	int				score;
	int				pieces;
}					t_gamestate;

typedef struct		s_place_data
{
	t_list			*to_place;
	int				len;
	int				tx;
	int				ty;
	int				x;
	int				y;
	int				o;
	int				d;
}					t_place_data;


t_gamestate			*init_gamestate(char **cmd);
int					make_grid(char **cmd, t_gamestate *state);
int					add_piece(char **cmd, t_gamestate *state);
int					do_turn(t_gamestate *state);
int					player_action(char **cmd, t_gamestate *state);
int					on_piece_placed(char **cmd, t_gamestate *state);

t_list				*make_domino(int a, int b);
int					get_dnum_a(t_list *domino);
int					get_dnum_b(t_list *domino);
void				delete_domino_list(t_list **list);
void				delete_domino_piece(void *dom, size_t size);
t_list				*search_and_extract(t_list **origin, int a, int b);
int					try_place_piece(t_list *dom, t_gamestate *state);
int					get_fwd(t_gamestate *state, t_place_data *d);
int					check_links(t_gamestate *state, t_place_data *d);

int					output_cmd(char **cmd, int len);
int					cmd_put_init(t_list *domino, t_gamestate *state);
int					cmd_put(t_list *domino, t_gamestate *state, int *args);
int					cmd_sulk(void);
int					cmd_draw(void);
int					cmd_ko(void);

#endif
