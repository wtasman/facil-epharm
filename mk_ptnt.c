#include "project.h"
#include "stdio.h"

int		ct_wrds(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 1;
	while (str[i])
	{
		if (str[i] == ',')
			cnt++;
		i++;
	}
	return (cnt);
}

int		find_comma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (i);
		i++;
	}
	return (i - 1);
}

t_ptnt	*mk_ptnt(int fd)
{
	char	*str;
	t_ptnt	*ptnt;
	char	**tab;
	int		i;

	if(!(ptnt = (t_ptnt*)malloc(sizeof(t_ptnt))))
		return (NULL);
	if (!(get_next_line(fd, &str)))
			return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(ptnt->name = ft_strdup(str)))
		return (NULL);
	if (!(get_next_line(fd, &str)))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);
	ptnt->pres = tab;
	if (!(get_next_line(fd, &str)))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);	
	ptnt->cur_med = tab;
	if (!(get_next_line(fd, &str)))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);	
	ptnt->disease = tab;
	return (ptnt);
}

/*int	 main()
{
	t_ptnt	*patient;
	int k;
	int fd;

	k = 0;
	fd = open("patient1.txt", O_RDONLY);
	patient = (t_ptnt *)malloc(sizeof(t_ptnt));
	patient = mk_ptnt(fd);
	ft_putstr(patient->name);
	ft_putchar('\n');
	while (patient->pres[k])
	{
		ft_putstr(patient->pres[k]);
		ft_putchar('\n');
		k++;
	}
	k = 0;
	while (patient->cur_med[k])
	{
		ft_putstr(patient->cur_med[k]);
		ft_putchar('\n');
		k++;
	}
	k = 0;
	while (patient->disease[k])
	{
		ft_putstr(patient->disease[k]);
		ft_putchar('\n');
		k++;
	}
	return (0);
}*/
