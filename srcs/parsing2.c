/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:11:28 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 15:50:54 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	prepare_data(t_app *app)
{
	if (app->size < 1 || !app->have_start || !app->have_end)
		put_error("Error : map invalide");
	list_to_array(app);
	init_mtrx(&app->mtrx, app->size);
	app->nbr_long = app->mtrx.nbr_long;
	init_mtrx(&app->identity, app->size);
	init_mtrx_identity(&app->identity);
	app->read_mode = 4;
}

void	list_to_array(t_app *app)
{
	t_block			*tmp;
	unsigned int	i;

	i = 0;
	tmp = app->first_block;
	app->block_array = (t_block**)ft_memalloc(sizeof(t_block*) * app->size);
	if (!app->block_array)
		put_error("Error malloc");
	while (tmp && i < app->size)
	{
		app->block_array[i] = tmp;
		tmp = tmp->next;
		i++;
	}
}
