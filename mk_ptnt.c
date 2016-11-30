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
	int		k;

	k = 0;
	str = rmv_title(str);
	ptnt = (t_ptnt*)malloc(sizeof(t_ptnt));
	get_next_line(fd, &str);
	str = rmv_title(str);
	ptnt->name = str;
	get_next_line(fd, &str);
	str = rmv_title(str);
	tab = ft_strsplit(str, ',');
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);	
	ptnt->pres = tab;
	get_next_line(fd, &str);
	str = rmv_title(str);
	tab = ft_strsplit(str, ',');
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);	
	ptnt->cur_med = tab;
	get_next_line(fd, &str);
	str = rmv_title(str);
	tab = ft_strsplit(str, ',');
	i = -1;
	while (tab[++i] != NULL)
	   tab[i] = ft_strtrim(tab[i]);	
	ptnt->disease = tab;
	return (ptnt);
}
