/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:43:10 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/11 21:43:12 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	itoc(int i)
{
	if (i >= 0 && i <= 9)
		return ((char)i + '0');
	return ((char)i + 'a' - 10);
}

static char	*r_uitoa(unsigned short int nb, char *tmp, int base)
{
	char	*rt;

	if (nb > (unsigned short int)base - 1)
	{
		rt = r_uitoa(nb / base, tmp, base);
		*rt = itoc(nb % base);
		return (rt + 1);
	}
	else if (nb > 0)
		*tmp = itoc(nb);
	return (tmp + 1);
}

char		*uitoa_base_2(unsigned short int n, int base)
{
	char tmp[21];
	char *rt;

	if (n == 0)
		return (ft_strdup("0"));
	ft_bzero(tmp, 21);
	r_uitoa(n, tmp, base);
	rt = ft_strdup(tmp);
	return (rt);
}
