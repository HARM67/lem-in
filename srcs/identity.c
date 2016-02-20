/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:34:43 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/20 16:10:14 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_mtrx_identity(t_mtrx *mtrx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned long	nbr;
	unsigned long	nbr_long;
	unsigned int	size;

	i = 0;
	nbr = 1;
	nbr_long = mtrx->nbr_long;
	size = mtrx->size;
	j = 0;
	while (i < size)
	{
		mtrx->data[(i * nbr_long) + j] = nbr;
		nbr <<= 1;
		i++;
		if ((i % 64) == 0)
		{
			nbr = 1;
			j++;
		}
	}
}
