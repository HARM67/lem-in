/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:27:14 by mfroehly          #+#    #+#             */
/*   Updated: 2016/02/20 12:09:11 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_data(unsigned long *data, unsigned int size)
{
	unsigned int i;

	i = size;
	while (i > 0)
	{
		ft_printf("%0*lb", sizeof(unsigned long) * 8, data[i - 1]);
		i--;
	}
	ft_putchar('\n');
}
