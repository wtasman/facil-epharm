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
	t_drug	*newdrug;

	newdrug = (t_drug*)malloc(sizeof(newdrug));
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	newdrug->name = ft_strdup(str);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	newdrug->ins = ft_strdup(str);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(newdrug->drugi = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (newdrug->drugi[++i])
		if (!(newdrug->drugi[i] = ft_strtrim(newdrug->drugi[i])))
			return (NULL);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(newdrug->diseasei = ft_strsplit(str, ',')))
		return (NULL);
	ft_putstr(newdrug->name);	//this prints the drug name correctly
	i = -1;
	while (newdrug->diseasei[++i])
		if(!(newdrug->diseasei[i] = ft_strtrim(newdrug->diseasei[i])))
			return (NULL);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!(str = rmv_title(str)))
		return (NULL);
	if (!(newdrug->se = ft_strsplit(str, ',')))
		return (NULL);
	ft_putstr(newdrug->name);	//this prints gibberish instead of the drug name
	i = -1;
	while (newdrug->se[++i])
	{
		if (!(newdrug->se[i] = ft_strtrim(newdrug->se[i])))
			return (NULL);
	}
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
