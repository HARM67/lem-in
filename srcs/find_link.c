/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:57:36 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 15:11:12 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	fl_test(t_app *app, t_path *paths, unsigned int i)
{
	return (and_test(&app->mtrx.data[i * app->nbr_long],
					&app->identity.data[paths->unit * app->nbr_long],
					app->nbr_long) && (and_test(app->used,
					&app->identity.data[i * app->nbr_long], app->nbr_long) ==
					0 || i == app->out));
}

static void	fl_loop(t_app *app, t_path *paths)
{
	while (paths)
	{
		make_or(app->used, &app->identity.data[paths->unit * app->nbr_long],
				app->nbr_long);
		if (and_test(paths->content,
				&app->identity.data[app->in * app->nbr_long], app->nbr_long)
		&& and_test(paths->content,
				&app->identity.data[app->out * app->nbr_long], app->nbr_long))
		{
			is_solution(app, paths);
			paths = paths->next;
		}
		else
			paths = paths->next;
	}
}

void		find_link(t_app *app, unsigned int nbr)
{
	t_path			*paths;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	unsigned int	nbr_path;

	j = 0;
	app->current_iteration++;
	size = app->mtrx.size;
	paths = app->first_path;
	nbr_path = app->nbr_path;
	while (paths && j < nbr_path)
	{
		i = 0;
		while (i < size)
		{
			if (fl_test(app, paths, i))
				travel_path(app, paths->content, i);
			i++;
		}
		j++;
		paths = remove_path(app, paths);
	}
	fl_loop(app, paths);
}
