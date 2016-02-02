#include "lem_in.h"

void	remove_inout(t_app *app)
{
	t_path			*tmp;
	unsigned int	i;

	tmp = app->full_first;
	i = 0;
	while (tmp && i < app->nbr_full)
	{
		make_and(tmp->content, app->solution, app->nbr_long);
		tmp = tmp->next;
	}
}

void	choose_path(t_app *app)
{
			
}
