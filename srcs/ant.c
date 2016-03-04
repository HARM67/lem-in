/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:30:43 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:31:09 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	move_ant2(t_app *app, unsigned int id, unsigned int iteration,
		int i)
{
	if (iteration < app->path_selected[id]->ant_use && i == 0)
	{
		if (app->temoin)
			ft_putchar(' ');
		app->firsts_end[id][i].current_ant = app->current_ant;
		ft_printf("L%u-%s", app->firsts_end[id][i].current_ant,
			app->block_array[app->firsts_end[id][i].id_block]->name);
		app->current_ant++;
		app->temoin = 1;
		if (i == (int)app->path_selected[id]->size - 1)
		{
			app->firsts_end[id][i].current_ant = 0;
		}
	}
}

static void	move_ant(t_app *app, unsigned int id, unsigned int iteration)
{
	int	i;

	i = (int)app->path_selected[id]->size - 1;
	while (i >= 0)
	{
		if (app->firsts_end[id][i].current_ant != 0)
		{
			if (i == (int)app->path_selected[id]->size - 1)
			{
				app->firsts_end[id][i].current_ant = 0;
				i--;
				continue ;
			}
			if (app->temoin)
				ft_putchar(' ');
			app->firsts_end[id][i + 1].current_ant =
				app->firsts_end[id][i].current_ant;
			app->firsts_end[id][i].current_ant = 0;
			ft_printf("L%u-%s", app->firsts_end[id][i + 1].current_ant,
				app->block_array[app->firsts_end[id][i + 1].id_block]->name);
			app->temoin = 1;
		}
		move_ant2(app, id, iteration, i);
		i--;
	}
}

void		move_ants(t_app *app)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < app->max_stroke)
	{
		app->temoin = 0;
		while (j < app->best_size)
		{
			if (i < app->path_selected[j]->stroke)
				move_ant(app, j, i);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
