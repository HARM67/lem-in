/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:27:14 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 07:40:23 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_data(unsigned long *data, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%0*b", sizeof(unsigned long) * 8, data[i]);
		i++;
	}
	ft_putchar('\n');
}
