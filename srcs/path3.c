/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:44:55 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 13:44:57 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
