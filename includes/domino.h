/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcirlig <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:24:21 by dcirlig           #+#    #+#             */
/*   Updated: 2017/12/16 18:41:02 by dcirlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H

# define DOMINO_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_domino
{
	int			first;
	int			second;
	int			used;
}				s_domino;

typedef struct	s_board
{
	char	*value;
	int		c;
	int		l;
}				s_board;

typedef struct	s_pieces
{
	char	*value;
	int		first;
	int		second;
}				s_pieces;

typedef struct	s_end
{
	char	*value;
	int		winner;
	int		score;
}				s_end;

typedef struct	s_operation
{
	char	p;
	int		*winner;
	char	*operation;
}				s_operation;

int ft_count_word(char const *s, char c);
#endif
