/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:14:07 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 15:51:51 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_app(t_app *app)
{
	app->read_mode = 9;
	read_file(app);
	app->used = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
	app->solution = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
	if (!app->used || !app->solution)
		put_error("Error malloc");
	make_or(app->solution, &app->identity.data[app->in * app->nbr_long],
			app->nbr_long);
	make_or(app->solution, &app->identity.data[app->out * app->nbr_long],
			app->nbr_long);
	make_reverse(app->solution, app->nbr_long);
	push_path(app, app->in);
	app->best_comb = 0xffffffff;
	app->current_ant = 1;
}

void	run_app(t_app *app)
{
	t_mtrx	*identity;

	identity = &app->identity;
	make_or(app->used, &identity->data[app->first_path->unit * app->nbr_long],
			app->nbr_long);
	while (app->first_path)
		find_link(app);
	if (!app->nbr_full)
		put_error("Pas trouve de chemin valide");
	app->path_selected = (t_path**)ft_memalloc(sizeof(t_path*) *
			app->nbr_full);
	app->path_selected_temp = (t_path**)ft_memalloc(sizeof(t_path*) *
			app->nbr_full);
	if (!app->path_selected || !app->path_selected_temp)
		put_error("Error malloc");
	remove_inout(app);
	choose_rec(app, app->full_first, 0);
	calc_stroke(app);
	insert_out(app);
	make_end_paths_array(app);
	move_ants(app);
}
