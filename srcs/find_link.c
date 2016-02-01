/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:57:36 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 08:32:40 by mfroehly         ###   ########.fr       */
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

	i = 0;
	j = 0;
	temoin = 0;
	size = app->mtrx.size;
	paths = app->first_path;
	nbr_path = app->nbr_path;
	while (paths && j < nbr_path)
	{
		while (i < size)
		{
			if (and_test(&app->mtrx.data[i], &app->identity.data[paths->unit], app->nbr_long) &&
			(and_test(app->used, &app->identity.data[i], app->nbr_long) == 0 || i == app->out))
			{
//				ft_printf("%u est lie a %u\n", paths->unit, i);
				travel_path(app, paths->content, i);
			}
			i++;
		}
		i = 0;
		j++;
		last = paths;
		remove_path(app, last);
		paths = paths->next;
	}
	while (paths)
	{
		make_or(app->used, &app->identity.data[paths->unit], app->nbr_long);
		if (and_test(paths->content, &app->identity.data[app->in], app->nbr_long)
		&& and_test(paths->content, &app->identity.data[app->out], app->nbr_long))
		{
			last = paths;
//			ft_printf("J'ai trouve %u est lie a %u\n", paths->unit, i);
			is_solution(app, paths);
			paths = last->next;
		}
		else
			paths = paths->next;
	}
}
