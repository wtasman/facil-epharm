#include "project.h"

int	main(int arc, char **arv)
{
	int		fd;
	char	*store;
	t_ptnt	*patient;
	t_drug	*presc;

	if (arc != 2 || !arv[1])
		return (1);
	store = ft_strjoin(arv[1], ".txt");
	fd = open("patient1.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	patient = mk_ptnt(fd);
	if (!patient)
		return (1);
	presc = ft_drugparse(patient);
	if (!presc)
		return (1);
	dis_se_cmp(presc, patient);
	return (0);
}
