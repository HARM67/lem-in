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
	app->nbr_long = app->mtrx.nbr_long;
	app->used = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
	app->solution = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
}

void	run_app(t_app *app)
{
	t_mtrx *mtrx;
	t_mtrx *identity;

	print_mtrx(&app->mtrx);
	ft_putchar('\n');
	//print_mtrx(&app->identity);
	//print_block(app);
	make_or(app->solution, &app->identity.data[app->in], app->nbr_long);
	make_or(app->solution, &app->identity.data[app->out], app->nbr_long);
	print_data(app->solution, app->nbr_long);
	push_path(app, app->in);
	//print_paths(app);
	/*
	mtrx = &app->mtrx;
	identity = &app->identity;
	mtrx->data[0] = 0x802;
	mtrx->data[1] = 0x5;
	mtrx->data[2] = 0x20a;
	mtrx->data[3] = 0x14;
	mtrx->data[4] = 0x28;
	mtrx->data[5] = 0x50;
	mtrx->data[6] = 0x2a0;
	mtrx->data[7] = 0x140;
	mtrx->data[8] = 0x480;
	mtrx->data[9] = 0x444;
	mtrx->data[10] = 0xb00;
	mtrx->data[11] = 0x401;
	print_mtrx(mtrx);
	ft_putchar('\n');
	//print_mtrx(identity);

	make_or(app->used, &identity->data[app->first_path->unit], app->nbr_long);
	find_link(app, 0);
	find_link(app, 0);
	find_link(app, 0);
	find_link(app, 0);
	find_link(app, 0);
	find_link(app, 0);
	find_link(app, 0);
	print_full(app);*/
}
