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

void	make_and_reverse(unsigned long *d1, unsigned long *d2, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		d1[i] &= ~d2[i];
		i++;
	}
}

void	make_and(unsigned long *d1, unsigned long *d2, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		d1[i] &= d2[i];
		i++;
	}
}

void	make_reverse(unsigned long *d, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		d[i] = ~d[i];
		i++;
	}
}

void	make_cpy(unsigned long *d1, unsigned long *d2, unsigned int nbr_long)
{
	unsigned int	i;

	i = 0;
	while (i < nbr_long)
	{
		d1[i] = 0;
		d1[i] = d2[i];
		i++;
	}
}
