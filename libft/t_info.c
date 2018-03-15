/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:23:03 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/10 22:23:04 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_info		*init_info(void)
{
	t_info	*res;

	res = (t_info *)malloc(sizeof(t_info));
	res->cursize = 0;
	res->maxsize = 16;
	res->tab = (char **)malloc(sizeof(char *) * (res->maxsize + 1));
	res->tab[res->maxsize] = 0;
	return (res);
}

void		add_info(t_info *info, char *line)
{
	int		i;
	char	**newtab;

	if (info->cursize >= info->maxsize)
	{
		newtab = (char **)malloc(sizeof(char *) * (info->maxsize * 2 + 1));
		i = -1;
		while (++i < info->maxsize)
			newtab[i] = info->tab[i];
		free(info->tab);
		info->tab = newtab;
		info->maxsize *= 2;
		info->tab[info->maxsize] = 0;
	}
	info->tab[info->cursize] = line;
	info->cursize++;
}

void		free_info(t_info **info)
{
	int		i;

	i = -1;
	while (++i < (*info)->cursize)
		free((*info)->tab[i]);
	free((*info)->tab);
	free(*info);
	*info = NULL;
}
