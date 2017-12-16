/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcirlig <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:53:27 by dcirlig           #+#    #+#             */
/*   Updated: 2017/12/16 18:46:40 by dcirlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "domino.h"
#include <stdio.h>

#define BUF_SIZE 4096

void	ft_open_filed(int file_des)
{
	if (file_des == -1)
		write(2, "open failed\n", 12);
}

void	ft_close_filed(int file_des)
{
	if (file_des == -1)
		write(2, "close failed\n", 13);
}

s_domino	*lst_domino(char *s)
{
	s_domino	*domino;
	int			i;
	char		**tab;
	char		**tab1;
	int			j;

	i = 0;
	j = 0;
	domino = malloc(sizeof(domino));

	while (i < ft_count_word(s, '\n'))
	{
		tab1 = ft_strsplit(tab[i], ':');
		domino[j].first = ft_atoi(tab1[1]);
		domino[j].second = ft_atoi(tab1[2]);
		domino[j].used = 0;
		j++;
		i++;
	}
	return (domino);
}

int	ChainExist(s_domino *domino, int start, int end)
{
	int	chainExist;
	int	i;

	i = 0;
	chainExist = 0;
	if (start == end)
		return (1);
//	while (i < domino.size())
	{
		if (!domino[i].used)
		{
			domino[i].used = 1;
			chainExist = 0;
			if (domino[i].first == start)
				chainExist = ChainExist(domino, domino[i].second, end);
			else if (domino[i].second == start)
				chainExist = ChainExist(domino, domino[i].first, end);
			domino[i].used = 0;
			if (chainExist)
				return (1);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;
	int		i;
	char	**tab1;
	int		j;
	char	*line;
	s_domino *domino;
	i = 0;
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		ft_open_filed(fd);
		//while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		//{
		//	buf[ret] = '\0';
		//}
		while (get_next_line(fd, &line))
		{
			printf("%s\n", line);
		}
		ft_close_filed(fd);
	}
	return (0);
}
