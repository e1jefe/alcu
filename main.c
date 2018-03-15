/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:21:58 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/11 14:18:46 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static const t_ai	g_diff[] =
{
	{play_ai_easy},
	{play_ai_medium},
	{play_ai_hard}
};

t_field			*parse_field(t_info *info)
{
	t_field		*res;
	int			i;

	res = (t_field *)malloc(sizeof(t_field));
	res->rows = (int *)malloc(sizeof(int) * info->cursize);
	i = -1;
	res->currow = info->cursize - 1;
	while (++i < info->cursize)
		res->rows[i] = (int)ft_atoi(info->tab[i]);
	return (res);
}

static int		play_player(t_game game)
{
	char		*line;
	int			rm;

	line = (game.curplayer == PLAYER1) ? "Player1 turn.\nChoose how many "
	"matches to take from the last row(1-3)" : "Player2 turn.\nChoose how "
	"many matches to take from the last row(1-3)";
	color_putstr(line, "yellow");
	line = NULL;
	rm = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) != 1 || (rm = (int)ft_atoi(line)) > 3 || rm < 1)
			color_putstr("Input error, please try again", "red");
		else if (game.field->rows[game.field->currow] < rm)
			color_putstr("Input error, can not remove "
							"specified amount of matches", "red");
		else
		{
			game.field->rows[game.field->currow] -= rm;
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

void			play(t_game game)
{
	int		status;

	game.count = 1;
	status = 1;
	while (game.field->rows[0] != 0)
	{
		display_board(game);
		if (game.curplayer == PLAYER1 || game.mode == PVP)
			status = play_player(game);
		else if (game.curplayer == AIP2)
			g_diff[game.mode].diff(game);
		if (game.field->rows[game.field->currow] == 0)
			game.field->currow--;
		if (game.field->currow == -1 || status == 0)
		{
			ft_putstr("\nWinner is Player");
			ft_putstr((game.curplayer == PLAYER1) ? "2!\n" : "1!\n");
			return (color_putstr("\nGame over\n", "blue"));
		}
		game.curplayer ^= 1;
		game.count++;
	}
}

int				main(int argc, char **argv)
{
	int		fd;
	t_info	*info;
	t_game	game;

	(argc == 1) ? fd = 0 : -1;
	(argc == 2) ? fd = open(argv[1], O_RDONLY) : 1;
	if (argc > 2 || fd == -1)
		return (-1);
	info = init_info();
	(fd == 0) ? color_putstr("Enter board. Empty line signals"
		" end of board.", "green") : 1;
	if (read_info(fd, info) == -1)
		return (-1);
	if (info->cursize == 0 || !(game.field = parse_field(info)))
		return (nerror());
	choose_diff(&game);
	if (game.mode == -1)
		return (nerror());
	choose_start(&game);
	if (game.curplayer == -1)
		return (nerror());
	play(game);
}
