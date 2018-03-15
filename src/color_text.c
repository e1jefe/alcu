/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:19:57 by dsheptun          #+#    #+#             */
/*   Updated: 2018/03/11 14:21:18 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../alcu.h"

void		color_putstr(char *str, char *color)
{
	if (ft_strcmp(color, "yellow") == 0)
		ft_putstr(YELLOW_FONT);
	else if (ft_strcmp(color, "red") == 0)
		ft_putstr(RED_FONT);
	else if (ft_strcmp(color, "green") == 0)
		ft_putstr(GREEN_FONT);
	else if (ft_strcmp(color, "blue") == 0)
		ft_putstr(BLUE_FONT);
	ft_putendl(str);
	ft_putstr(COLOR_OFF);
}
