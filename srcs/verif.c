/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:12:55 by mfroehly          #+#    #+#             */
/*   Updated: 2016/03/04 14:12:56 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	verif_number(char *nbr)
{
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			return (0);
		nbr++;
	}
	return (1);
}
