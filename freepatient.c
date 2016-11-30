#include "project.h"

static void	ft_freetab(char ***tab)
{
	size_t	i;

	if (!*tab || !**tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void		freepatient(t_ptnt **patient)
{
	free((*patient)->name);
	ft_freetab(&((*patient)->pres));
	ft_freetab(&((*patient)->cur_med));
	ft_freetab(&((*patient)->disease));
	free(*patient);
}
