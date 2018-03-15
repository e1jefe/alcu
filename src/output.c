/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:15:09 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/10 22:15:10 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../alcu.h"

void		error(void)
{
	write(2, "ERROR\n", 6);
}

int			nerror(void)
{
	error();
	return (-1);
}

static int	board_size(t_field *field)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (++i <= field->currow)
		res = ft_max(res, field->rows[i]);
	return (res);
}

static void	ft_putnsymb(char s, int n)
{
	char	str[n + 1];

	ft_memset(str, s, n);
	str[n] = 0;
	ft_putstr(str);
}

void		display_board(t_game game)
{
	t_iter	it;
	int		size;
	int		diff;

	it.i = -1;
	size = board_size(game.field);
	ft_putstr("\nTurn ");
	ft_putnbr(game.count);
	write(1, "\n", 1);
	while (++it.i <= game.field->currow)
	{
		it.j = -1;
		diff = (size - (game.field->rows[it.i] / 2 * 2)) / 2;
		ft_putnsymb(' ', diff);
		ft_putnsymb('|', game.field->rows[it.i]);
		write(1, "\n", 1);
	}
}
