#include "project.h"

void		ft_drugdel(t_drug **druglist)
{
	int		i;

	free((*druglist)->name);
	free((*druglist)->ins);
	i = -1;
	while ((*druglist)->drugi[++i])
		free((*druglist)->drugi[i]);
	i = -1;
	while ((*druglist)->diseasei[++i])
		free((*druglist)->diseasei[i]);
	i = -1;
	while ((*druglist)->se[++i])
		free((*druglist)->se[i]);
	if ((*druglist)->next != NULL)
		ft_drugdel(&((*druglist)->next));
	free (*druglist);
}

t_drug		*ft_drugnew(int fd)
{
	char	*str;
	int		i;
	char	**tab;
	t_drug	*newdrug;

	newdrug = (t_drug*)malloc(sizeof(newdrug));
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	newdrug->name = ft_strdup(str);
	free(str);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	newdrug->ins = ft_strdup(str);
	free(str);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	free(str);
	i = -1;
	while (tab[++i])
		if (!(tab[i] = ft_strtrim(tab[i])))
			return (NULL);
	newdrug->drugi = tab;
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	free(str);
	i = -1;
	while (tab[++i])
		if(!(tab[i] = ft_strtrim(tab[i])))
			return (NULL);
	newdrug->diseasei = tab;
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(tab = ft_strsplit(str, ',')))
		return (NULL);
	free(str);
	i = -1;
	while (tab[++i])
	{
		if (!(tab[i] = ft_strtrim(tab[i])))
			return (NULL);
	}
//	newdrug->se = tab;
	if (i == -1)
		return (NULL);
	newdrug->next = NULL;
	return (newdrug);
}

void		ft_drugadd(t_drug **drug, t_drug *new)
{
	if (*drug)
		new->next = *drug;
	*drug = new;
}

t_drug		*ft_drugparse(t_ptnt *patientfile)
{
	int		fd;
	int		i;
	t_drug	*druglist;

	fd = open(ft_strjoin(patientfile->pres[0], ".txt"), O_RDONLY);
	if (fd == -1)
		return (NULL);
	druglist = ft_drugnew(fd);
	if (!druglist)
		return (NULL);
	close(fd);
	i = 0;
	while (patientfile->pres[++i])
	{
		ft_putstr("working\n");
		fd = open(ft_strjoin(patientfile->pres[i], ".txt"), O_RDONLY);
		if (fd == -1)
			return (NULL);
		ft_drugadd(&druglist, ft_drugnew(fd));
		close(fd);
	}
	return (druglist);
}
