#include "fcntl.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include "project.h"

void		ft_drugdel(t_drug *druglist)
{
	int		i;

	free(druglist->name);
	free(druglist->ins);
	i = -1;
	while (druglist->drugi[++i])
		free(druglist->drugi[i]);
	i = -1;
	while (druglist->diseasei[++i])
		free(druglist->diseasei[++i]);
	i = -1;
	while (druglist->se[++i])
		free(druglist->se[i]);
	if (druglist->next != NULL)
		ft_drugdel(druglist->next);
	free (druglist);
}

t_drug		*ft_drugnew(int fd)
{
	char	*str;
	int		i;
	t_drug	*newdrug;

	if (!get_next_line(fd, &str))
		return (NULL);
	if (!rmv_title(str))
		return (NULL);
	newdrug->name = str;
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!rmv_title(str))
		return (NULL);
	newdrug->ins = str;
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!rmv_title(str))
		return (NULL);
	if (!(newdrug->drugi = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (newdrug->drugi[++i])
		if (!(newdrug->drugi[i] = ft_strtrim(newdrug->drugi[i])))
			return (NULL);
	free(str);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!rmv_title(str))
		return (NULL);
	if (!(newdrug->diseasei = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (newdrug->diseasei[++i])
		if(!(newdrug->diseasei[i] = ft_strtrim(newdrug->diseasei[i])))
			return (NULL);
	if (!get_next_line(fd, &str))
		return (NULL);
	if (!rmv_title(str))
		return (NULL);
	if (!(newdrug->se = ft_strsplit(str, ',')))
		return (NULL);
	i = -1;
	while (newdrug->se[++i])
		if (!(newdrug->se[i] = ft_strtrim(newdrug->se[i])))
			return (NULL);
	while ((i = get_next_line(fd, &str)))
			;
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
	char	*str;
	int		fd;
	int		i;
	t_drug	*druglist;

	i = -1;
	while (patientfile->pres[++i])
	{
		if (!(fd = open(patientfile->pres[i], O_RDONLY)))
			return (NULL);
		if (!(ft_drugadd(&druglist, ft_drugnew(fd))))
			return (NULL);
		close(fd);
	}
	return (druglist);
}

/*
#include <stdio.h>	//REMOVE
int		main(void)
{
	t_ptnt	*patientzero;
	t_drug	*cure;

	patientzero = (t_ptnt *)malloc(sizeof(t_ptnt));
	patientzero->name = "Bob Smith";
	patientzero->pres[1] = {"Accupril",};
	printf("hello world\n");
	patientzero->cur_med[1] = {"Eplerenone",};
	patientzero->disease[1] = {"heart disease",};
	printf("%s %s %s %s\n", patientzero->name, patientzero->pres[0], patientzero->cur_med[0], patientzero->disease[0]);
	cure = ft_drugparse(patientzero);
	printf("%s, %s, %s, %s %s %s %s\n", (cure->name), cure->ins, cure->drugi[0], cure->diseasei[0], cure->se[0], cure->se[1], cure->se[2]);
	return (0);
}
*/
