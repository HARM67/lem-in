/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:29:42 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:29:43 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		what_nbr(t_app *app, char *name)
{
	int	i;

	i = 0;
	while (i < app->size)
	{
		if (ft_strcmp(name, app->block_array[i]->name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

t_block	*new_block(char *name, int x, int y)
{
	t_block	*rt;

	rt = (t_block*)ft_memalloc(sizeof(t_block));
	rt->name = ft_strdup(name);
	rt->x = x;
	rt->y = y;
	return (rt);
}

void	insert_block(t_app *app, t_block *block)
{
	if (app->first_block == 0 || app->size == 0)
	{
		app->first_block = block;
		app->last_block = app->first_block;
	}
	else
	{
		app->last_block->next = block;
		block->previous = app->last_block;
		app->last_block = block;
	}
	app->size++;
}

void	print_block(t_app *app)
{
	unsigned int	i;
	t_block			**tmp;

	i = 0;
	tmp = app->block_array;
	ft_printf("There is %u blocks\n", app->size);
	while (i < app->size)
	{
		if (app->in == i)
			ft_putendl("##Start");
		else if (app->out == i)
			ft_putendl("##End");
		ft_printf("%u : %s, %d, %d\n", i, tmp[i]->name, tmp[i]->x, tmp[i]->y);
		i++;
	}
}
