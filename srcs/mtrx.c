/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:16:34 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 15:50:32 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_mtrx(t_mtrx *mtrx, unsigned int size)
{
	mtrx->size = size;
	mtrx->nbr_long = size / 64;
	if (size % 64)
		mtrx->nbr_long++;
	mtrx->data = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
			mtrx->nbr_long * size);
	if (!mtrx->data)
		put_error("Error malloc");
}

void	print_mtrx(t_app *app, t_mtrx *mtrx)
{
	unsigned int	size;
	unsigned int	i;

	size = mtrx->size;
	i = 0;
	while (i < size)
	{
		if (i == app->in)
			ft_printf("{FG_GREEN}");
		else if (i == app->out)
			ft_printf("{FG_RED}");
		print_data(&mtrx->data[i * mtrx->nbr_long], mtrx->nbr_long);
		ft_printf("{EOC}");
		i++;
	}
}
