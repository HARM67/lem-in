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
	app->best_comb = 0xffffffff;

	app->nbr_ant = 15;
}

void	print_selected(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->best_size)
	{
		print_data(app->path_selected[i]->content, app->nbr_long);
		i++;
	}
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
	app->path_selected = (t_path**)ft_memalloc(sizeof(t_path*) * app->nbr_full);
	app->path_selected_temp = (t_path**)ft_memalloc(sizeof(t_path*) * app->nbr_full);
	remove_inout(app);

	print_full(app);
	choose_paths(app);
	print_selected(app);
/*
	app->selected_size = 3;
	app->path_selected[0] = app->full_first;
	app->path_selected[2] = app->full_first->next;
	app->path_selected[1] = app->full_first->next->next;
	calc_f_nums(app);
	ft_printf("%u %u %u\n", app->path_selected[0]->ant_use, app->path_selected[1]->ant_use, app->path_selected[2]->ant_use);
*/
/*
	print_mtrx(app, &app->mtrx);
	print_paths(app);
	*/
}
