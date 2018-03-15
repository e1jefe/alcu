/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:11:59 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/10 22:12:00 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../alcu.h"
#include <time.h>

void	ai_remove(int matches)
{
	ft_putstr("AI removed ");
	ft_putnbr(matches);
	ft_putstr(" match(es)\n");
}

void	play_ai_easy(t_game game)
{
	game.field->rows[game.field->currow] -= 1;
	ai_remove(1);
}

void	play_ai_medium(t_game game)
{
	int am;

	srand(time(NULL));
	am = -1;
	while (am == -1 || am > game.field->rows[game.field->currow])
		am = rand() % 3 + 1;
	game.field->rows[game.field->currow] -= am;
	ai_remove(am);
}

void	play_ai_hard(t_game game)
{
	int		wl;
	int		i;

	wl = 0;
	i = -1;
	while (++i < game.field->currow)
		if (wl == 0 && game.field->rows[i] % 4 == 1)
			wl ^= 1;
		else if (wl == 1 && game.field->rows[i] % 4 != 0)
			wl ^= 1;
	i = game.field->rows[game.field->currow];
	if (wl == 0)
	{
		if (i % 4 != 1 && i % 4 != 0)
			game.field->rows[game.field->currow] -= i % 4 - 1;
		else
			game.field->rows[game.field->currow] -= (i % 4 == 0) ? 3 : 1;
	}
	else
		game.field->rows[game.field->currow] -= (i % 4 != 0) ? i % 4 : 1;
	ai_remove(i - game.field->rows[game.field->currow]);
}
