/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:13:23 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:13:24 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_inout(t_app *app)
{
	t_path			*tmp;
	unsigned int	i;

	tmp = app->full_first;
	i = 0;
	while (tmp && i < app->nbr_full)
	{
		make_and(tmp->content, app->solution, app->nbr_long);
		tmp = tmp->next;
		i++;
	}
}
