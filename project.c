#include "project.h"

int	main(int arc, char **arv)
{
	int		fd;
	t_ptnt	*patient;
	t_drug	*presc;

	if (arc != 2 || !arv[1])
		return (1);
	fd = open(arv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	patient = mk_ptnt(fd);
	if (!patient)
		return (1);
	presc = ft_drugparse(patient);
	if (!presc)
		return (1);
	dis_se_cmp(presc, patient);
	freepatient(&patient);
//	ft_drugdel(&presc);
	return (0);
}
