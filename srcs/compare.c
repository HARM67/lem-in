/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:01:20 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 07:13:11 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		and_test(unsigned long *d1, unsigned long *d2, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		if (d1[i] & d2[i])
			return (1);
		i++;
	}
	return (0);
}
