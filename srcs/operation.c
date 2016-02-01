#include "lem_in.h"

void	make_or(unsigned long *d1, unsigned long *d2, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		d1[i] |= d2[i];
		i++;
	}
}

unsigned long	*make_reverse_and_out(unsigned long *d1, unsigned long *d2,
						unsigned int nbr_long)
{
	unsigned long	*out;
	unsigned int	i;

	i = 0;
	out = (unsigned long*)ft_memalloc(sizeof(unsigned long) * nbr_long);
	while (i < nbr_long)
	{
		d1[i] & d2[i];
		i++;
	}
}
