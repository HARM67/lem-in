/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:57:36 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:24:23 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_link(t_app *app, unsigned int nbr)
{
	t_path			*paths;
	t_path			*last;
	unsigned int	temoin;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	unsigned int	nbr_path;
	unsigned int	nbr_long;

	i = 0;
	j = 0;
	app->current_iteration++;
	temoin = 0;
	size = app->mtrx.size;
	paths = app->first_path;
	nbr_path = app->nbr_path;
	nbr_long = app->nbr_long;
	while (paths && j < nbr_path)
	{
		while (i < size)
		{
			if (and_test(&app->mtrx.data[i * nbr_long],
					&app->identity.data[paths->unit * nbr_long], nbr_long) &&
			(and_test(app->used, &app->identity.data[i * nbr_long], nbr_long) ==
				0 || i == app->out))
			{
				travel_path(app, paths->content, i);
			}
			i++;
		}
		i = 0;
		j++;
		last = paths;
		paths = paths->next;
		remove_path(app, last);
	}
	while (paths)
	{
		make_or(app->used, &app->identity.data[paths->unit * nbr_long],
				app->nbr_long);
		if (and_test(paths->content, &app->identity.data[app->in * nbr_long],
					app->nbr_long)
		&& and_test(paths->content, &app->identity.data[app->out * nbr_long],
			app->nbr_long))
		{
			last = paths;
			is_solution(app, paths);
			paths = last->next;
		}
		else
			paths = paths->next;
	}
}
