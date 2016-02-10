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
	if (rt == 0)
		exit (1);
	rt->content = (unsigned long*)ft_memalloc(sizeof(unsigned long) * size_data);
	if (rt->content == 0)
		exit (1);
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
	make_or(app->last_path->content, &app->identity.data[unit], app->nbr_long);
	app->nbr_path++;
}

void			travel_path(t_app *app, unsigned long *old, unsigned int unit)
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
	make_or(app->last_path->content, old, app->nbr_long);
	make_or(app->last_path->content, &app->identity.data[unit], app->nbr_long);
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
	app->nbr_path--;
}

void			is_solution(t_app *app, t_path *path)
{
	path->size = app->current_iteration;
	if (app->first_path == path)
		app->first_path = path->next;
	if (app->last_path == path)
		app->last_path = path->previous;
	if (path->previous)
		path->previous->next = path->next;
	if (path->next)
		path->next->previous = path->previous;
	if (app->full_first == 0 && app->nbr_full == 0)
	{
		app->full_first = path;
		app->full_last = path;
	}
	else
	{
		app->full_last->next = path;
		app->full_last->next->previous = app->full_last;
		app->full_last = app->full_last->next;
	}
	app->full_last->next = 0;
	app->nbr_path--;
	app->nbr_full++;
}

void			print_full(t_app *app)
{
	unsigned int	i;
	unsigned int	nbr_full;
	t_path			*tmp;

	tmp = app->full_first;
	i = 0;
	nbr_full = app->nbr_full;
	while (i < nbr_full && tmp)
	{
		ft_printf("%3u : ", tmp->size);
		print_data(tmp->content, app->nbr_long);
		tmp = tmp->next;
		i++;
	}
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
		ft_printf("%3u : ", tmp->unit);
		print_data(tmp->content, app->nbr_long);
		tmp = tmp->next;
		i++;
	}
}
