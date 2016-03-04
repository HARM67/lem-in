/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_f_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:29:10 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:30:24 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_f_num(t_app *app, t_path *path)
{
	long			rt;
	unsigned int	i;
	t_path			**tmp;

	i = 0;
	tmp = app->path_selected_temp;
	rt = app->nbr_ant;
	while (i < app->selected_size && i < rt)
	{
		rt += (long)tmp[i]->size - (long)path->size;
		i++;
	}
	if (rt < 0)
		rt = 0;
	path->ant_use = rt;
}

unsigned int	calc_f_nums(t_app *app)
{
	unsigned int	i;
	t_path			**tmp;
	unsigned int	max;

	i = 0;
	max = 0;
	tmp = app->path_selected_temp;
	while (i < app->selected_size && i < app->nbr_full)
	{
		calc_f_num(app, tmp[i]);
		if (i < tmp[i]->ant_use % app->selected_size)
		{
			tmp[i]->ant_use /= app->selected_size;
			tmp[i]->ant_use++;
		}
		else
			tmp[i]->ant_use /= app->selected_size;
		if (tmp[i]->ant_use > max)
			max = tmp[i]->ant_use;
		i++;
	}
	return (max);
}
