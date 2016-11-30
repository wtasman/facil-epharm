#include "project.h"

char	*rmv_title(char *str)
{
	int 	i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			tmp = ft_strsub(str, (i + 2), (ft_strlen(str) - (i + 1)));
			return (tmp);
		}
		i++;
	}
	return (str);
}
