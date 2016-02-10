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
	app->current_ant = 1;

	app->nbr_ant = 10;
}

unsigned int	what_id(t_app *app, unsigned long *data)
{
	unsigned int 	i;

	i = 0;
	while (i < app->size)
	{
		if (and_test(data, &app->identity.data[i], app->nbr_long))
			return (i);
			i++;
	}
	return (-1);
}

void	print_selected(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->best_size)
	{
		ft_printf("Nb_ant:%3u Size:%3u Stroke:%3u => ",
		app->path_selected[i]->ant_use, app->path_selected[i]->size,
			app->path_selected[i]->stroke);
		print_data(app->path_selected[i]->content, app->nbr_long);
		i++;
	}
}

void	print_array(t_app *app)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < app->best_size)
	{
		while (j < app->path_selected[i]->size)
		{
			ft_putendl(ft_itoa(app->firsts_end[i][j].id_block));
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	make_end_path_array(t_app *app, unsigned id)
{
	unsigned int	i;
	unsigned int	current;
	unsigned long	*tmp;

	i = 0;
	current = app->in;
	tmp = (unsigned long*)ft_memalloc(sizeof(unsigned long) * app->nbr_long);
	if (tmp == 0)
		exit(1);
	app->firsts_end[id] = (t_end_path*)ft_memalloc(sizeof(t_end_path) * app->path_selected[id]->size);
	if (app->firsts_end[id] == 0)
		exit(1);
	while (i < app->path_selected[id]->size)
	{
		make_cpy(tmp, app->path_selected[id]->content, app->nbr_long);
		make_and(tmp, &app->mtrx.data[current], app->nbr_long);
		current = what_id(app, tmp);
		app->firsts_end[id][i].id_block = current;
		make_and_reverse(app->path_selected[id]->content, tmp, app->nbr_long);
		i++;
	}
	free(tmp);
}

void	make_end_paths_array(t_app *app)
{
	unsigned int	i;

	i = 0;
	app->firsts_end = (t_end_path**)ft_memalloc(sizeof(t_end_path*) * app->best_size);
	if (app->firsts_end == 0)
		exit(1);
	while (i < app->best_size)
	{
		make_end_path_array(app, i);
		i++;
	}
}

void	insert_out(t_app *app)
{
	unsigned int	i;

	i = 0;
	while (i < app->best_size)
	{
		make_or(app->path_selected[i]->content, &app->identity.data[app->out], app->nbr_long);
		i++;
	}
}

void	calc_stroke(t_app *app)
{
	unsigned int	i;
	t_path			*tmp;

	i = 0;
	while (i < app->best_size)
	{
		tmp = app->path_selected[i];
		tmp->stroke = tmp->size + tmp->ant_use - 1;
		if (tmp->stroke > app->max_stroke)
			app->max_stroke = tmp->stroke;
		i++;
	}
}

void	move_ant(t_app *app, unsigned int id, unsigned int iteration)
{
	int	i;

	i = (int)app->path_selected[id]->size - 1;
	if (iteration >= app->path_selected[id]->stroke)
		return ;
	while (i >= 0)
	{
		if (app->firsts_end[id][i].current_ant != 0)
		{
			if (i == (int)app->path_selected[id]->size - 1)
			{
				i--;
				continue ;
			}
			if (app->temoin)
				ft_putchar(' ');
			app->firsts_end[id][i + 1].current_ant = app->firsts_end[id][i].current_ant;
			app->firsts_end[id][i].current_ant = 0;
			ft_printf("L%u-%s", app->firsts_end[id][i + 1].current_ant, app->block_array[app->firsts_end[id][i + 1].id_block]->name);
			app->temoin = 1;
		}
		if (iteration < app->path_selected[id]->ant_use && i == 0)
		{
			if (app->temoin)
				ft_putchar(' ');
			app->firsts_end[id][i].current_ant = app->current_ant;
			ft_printf("L%u-%s", app->firsts_end[id][i].current_ant, app->block_array[app->firsts_end[id][i].id_block]->name);
			app->current_ant++;
			app->temoin = 1;
		}
		i--;
	}
}

void	move_ants(t_app *app)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < app->max_stroke)
	{
		app->temoin = 0;
		while (j < app->best_size)
		{
			move_ant(app, j, i);
			j++;
		}
		j = 0;
		ft_putchar('\n');
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
	choose_rec(app, app->full_first, 0);
	calc_stroke(app);
	insert_out(app);
	make_end_paths_array(app);
	move_ants(app);
}
