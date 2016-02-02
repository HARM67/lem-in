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
	//	ft_printf("\n\n%064b\n%064b\n", d1[i], d2[i]);
		if (d1[i] & d2[i])
		{
	//		ft_printf("je return 1\n\n");
			return (1);
			}
		i++;
	}
	//ft_printf("je return 0\n\n");
	return (0);
}

