/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:16:58 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 08:28:55 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*new_path(unsigned int size_data)
{
	t_path	*rt;

	rt = (t_path*)ft_memalloc(sizeof(t_path));
	rt->content = (unsigned long*)ft_memalloc(sizeof(unsigned long) * size_data);
	//rt->unit = (unsigned long*)ft_memalloc(sizeof(unsigned long) * size_data);
	return (rt);
}

void			push_path(t_app *app, unsigned int unit)
{
	if (app->first_path == 0 || app->nbr_path == 0)
	{
		app->first_path = new_path(app->nbr_long);
		app->last_path = app->first_path;
	}
	else
	{
		app->last_path->next = new_path(app->nbr_long);
		app->last_path->next->previous = app->last_path;
		app->last_path = app->last_path->next;
	}
	app->last_path->unit = unit;
	app->nbr_path++;
}

void			remove_path(t_app *app, t_path *path)
{
	if (app->first_path == path)
		app->first_path = path->next;
	if (app->last_path == path)
		app->last_path = path->previous;
	if (path->previous)
		path->previous->next = path->next;
	if (path->next)
		path->next->previous = path->previous;
	free(path->content);
	free(path);
}


void			print_paths(t_app *app)
{
	unsigned int	i;
	unsigned int	nbr_path;
	t_path			*tmp;

	tmp = app->first_path;
	i = 0;
	nbr_path = app->nbr_path;
	while (i < nbr_path && tmp)
	{
		ft_printf("%u : ", tmp->unit);
		print_data(&app->identity.data[tmp->unit], app->nbr_long);
		tmp = tmp->next;
		i++;
	}
}
