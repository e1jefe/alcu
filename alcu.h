/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:15:55 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/10 22:15:56 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft/libft.h"
# include <unistd.h>

# define PLAYER1 0
# define AIP2 1
# define EASY 0
# define MEDIUM 1
# define HARD 2
# define PVP 3
# define BLUE_FONT "\e[38;5;69m"
# define RED_FONT "\e[38;5;196m"
# define GREEN_FONT "\e[38;5;46m"
# define YELLOW_FONT "\e[38;5;226m"
# define COLOR_OFF "\e[0m"

typedef struct		s_field
{
	int				*rows;
	int				currow;
}					t_field;

typedef struct		s_game
{
	int				count;
	t_field			*field;
	int				curplayer;
	int				mode;
}					t_game;

typedef struct		s_ai
{
	void			(*diff)(t_game game);
}					t_ai;

void				error(void);
int					nerror(void);
void				display_board(t_game game);
void				play_ai_easy(t_game game);
void				play_ai_medium(t_game game);
void				play_ai_hard(t_game game);
void				choose_diff(t_game *game);
void				choose_start(t_game *game);
int					read_info(int fd, t_info *info);
void				color_putstr(char *str, char *color);
#endif
