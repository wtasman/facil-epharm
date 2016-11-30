#include "fcntl.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include "project.h"

t_drug		*ft_drugnew(int fd)
{
	char	*str;
	int		i;
	t_drug	*newdrug;

	get_next_line(fd, &str);
	//dash trim
	newdrug->name = ft_strdup(str);
	get_next_line(fd, &str);
	//dash trim
	newdrug->ins = ft_strdup(str);
	get_next_line(fd, &str);
	//dash trim
	newdrug->drugi = ft_strsplit(str, ',');
	i = -1;
	while (newdrug->drugi[++i])
		newdrug->drugi[i] = ft_strtrim(newdrug->drugi[i]);
	get_next_line(fd, &str);
	//dash trim
	newdrug->diseasei = ft_strsplit(str, ',');
	i = -1;
	while (newdrug->diseasei[++i])
		newdrug->diseasei[i] = ft_strtrim(newdrug->diseasei[i]);
	get_next_line(fd, &str);
	//dash trim
	newdrug->se = ft_strsplit(str, ',');
	i = -1;
	while (newdrug->se[++i])
		newdrug->se[i] = ft_strtrim(newdrug->se[i]);
	while (get_next_line(fd, &str))
		;
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
		fd = open(patientfile->pres[i], O_RDONLY);
		ft_drugadd(&druglist, ft_drugnew(fd));
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
