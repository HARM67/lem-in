/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:15:58 by mfroehly          #+#    #+#             */
/*   Updated: 2016/01/31 08:06:02 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	t_app app;
	
	ft_bzero(&app, sizeof(t_app));
	app.ac = ac;
	app.av = av;
	init_app(&app);
	run_app(&app);
	return (0);
}
