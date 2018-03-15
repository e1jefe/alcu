/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:25:14 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/10 22:35:08 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../alcu.h"

void			choose_diff(t_game *game)
{
	char	*line;
	int		n;

	game->mode = -1;
	while (game->mode == -1)
	{
		ft_putendl("Choose game mode: 1 - easy AI, 2 - medium AI, 3 - "
						"hard AI, 4 - 2-player mode");
		if (get_next_line(0, &line) <= 0)
			return ;
		if ((ft_strlen(line) == 1 && (n = (int)ft_atoi(line)) >= 1 && n <= 4))
			game->mode = n - 1;
		ft_strdel(&line);
	}
}

void			choose_start(t_game *game)
{
	char		*line;

	game->curplayer = -1;
	while (game->curplayer == -1)
	{
		ft_putendl("Choose starting player: 1 - Player1, 2 - AI/Player2");
		if (get_next_line(0, &line) <= 0)
			return ;
		(ft_strcmp(line, "1") == 0) ? game->curplayer = PLAYER1 : 1;
		(ft_strcmp(line, "2") == 0) ? game->curplayer = AIP2 : 1;
		ft_strdel(&line);
	}
}

int				is_valid(char *line)
{
	int			row;

	row = (int)ft_atoi(line);
	if (ft_strlen(line) > 5 || row < 1 || row > 10000 || !ft_isnumber(line))
		return (0);
	return (1);
}

int				read_info(int fd, t_info *info)
{
	char		*line;

	while (get_next_line(fd, &line) > 0 && (line[0] != 0 || fd != 0))
		if (is_valid(line) == 1)
			add_info(info, line);
		else
		{
			free_info(&info);
			return (nerror());
		}
	if (line[0] == 0)
		ft_strdel(&line);
	return (0);
}
