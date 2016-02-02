/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:14:07 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 08:31:38 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_app(t_app *app)
{
	read_file(app);
	app->used = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
	app->solution = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
	make_or(app->solution, &app->identity.data[app->in], app->nbr_long);
	make_or(app->solution, &app->identity.data[app->out], app->nbr_long);
	make_reverse(app->solution, app->nbr_long);
	push_path(app, app->in);
}

void	run_app(t_app *app)
{
	t_mtrx *mtrx;
	t_mtrx *identity;

	identity = &app->identity;
	make_or(app->used, &identity->data[app->first_path->unit], app->nbr_long);
	while (app->first_path)
	{
		find_link(app, 0);
	}
	remove_inout(app);
	print_full(app);
}
