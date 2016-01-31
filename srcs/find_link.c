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
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = app->mtrx.size;
	paths = app->first_path;
	while (paths)
	{
		while (i < size)
		{
			if (and_test(&app->mtrx.data[i], &app->identity.data[paths->unit], app->nbr_long))
			{
				ft_printf("%u est lie a %u\n", paths->unit, i);
				push_path(app, i);
			}
			i++;
		}
		i = 0;
		last = paths;
		paths = paths->next;
		//remove_path(app, last);
	}
}
