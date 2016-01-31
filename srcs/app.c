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
	app->size = 4;
	init_mtrx(&app->mtrx, app->size);
	init_mtrx(&app->identity, app->size);
	init_mtrx_identity(&app->identity);
	app->nbr_long = app->mtrx.nbr_long;
	app->used = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			app->nbr_long);
}

void	run_app(t_app *app)
{
	t_mtrx *mtrx;
	t_mtrx *identity;

	app->in = 0;
	push_path(app, app->in);
	mtrx = &app->mtrx;
	identity = &app->identity;
	mtrx->data[0] = 0x6;
	mtrx->data[1] = 0x9;
	mtrx->data[2] = 0x9;
	mtrx->data[3] = 0x6;
	print_mtrx(mtrx);
	ft_putchar('\n');
	print_mtrx(identity);
	find_link(app, 0);
	ft_putchar('\n');
	print_paths(app);
	//find_link(app, 0);
	//ft_putchar('\n');
	//print_paths(app);
}
