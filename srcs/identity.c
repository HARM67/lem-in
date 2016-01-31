/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 06:34:43 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 06:50:42 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_mtrx_identity(t_mtrx *mtrx)
{
	unsigned int	i;
	unsigned long	nbr;
	unsigned int	size;

	i = 0;
	nbr = 1;
	size = mtrx->size;
	while (i < size)
	{
		mtrx->data[i] = nbr;
		nbr <<= 1;
		i++;
	}
}
