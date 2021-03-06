/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:25:25 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 15:43:53 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	what_id(t_app *app, unsigned long *data)
{
	unsigned int	i;

	i = 0;
	while (i < app->size)
	{
		if (and_test(data, &app->identity.data[i * app->nbr_long],
					app->nbr_long))
			return (i);
		i++;
	}
	return (-1);
}

static void			make_end_path_array(t_app *app, unsigned id)
{
	unsigned int	i;
	unsigned int	current;
	unsigned long	*tmp;

	i = 0;
	current = app->in;
	tmp = (unsigned long*)ft_memalloc(sizeof(unsigned long) * app->nbr_long);
	if (tmp == 0)
		put_error("Error malloc");
	app->firsts_end[id] = (t_end_path*)ft_memalloc(sizeof(t_end_path) *
		app->path_selected[id]->size);
	if (app->firsts_end[id] == 0)
		put_error("Error malloc");
	while (i < app->path_selected[id]->size)
	{
		make_cpy(tmp, app->path_selected[id]->content, app->nbr_long);
		make_and(tmp, &app->mtrx.data[current * app->nbr_long], app->nbr_long);
		current = what_id(app, tmp);
		app->firsts_end[id][i].id_block = current;
		make_and_reverse(app->path_selected[id]->content, tmp, app->nbr_long);
		i++;
	}
	free(tmp);
}

void				make_end_paths_array(t_app *app)
{
	unsigned int	i;

	i = 0;
	app->firsts_end = (t_end_path**)ft_memalloc(sizeof(t_end_path*) *
		app->best_size);
	if (app->firsts_end == 0)
		put_error("Error malloc");
	while (i < app->best_size)
	{
		make_end_path_array(app, i);
		i++;
	}
}
