/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 15:58:55 by dmclaugh          #+#    #+#             */
/*   Updated: 2016/11/05 20:57:18 by dmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readfile(const int fd, char **mem, int status)
{
	char		*buf;
	char		*tmp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((status = read(fd, buf, BUFF_SIZE)))
	{
		if (status == -1 || status == 0)
			return (status);
		tmp = *mem;
		if (!(*mem = ft_strjoin(*mem, buf)))
			return (-1);
		ft_bzero(buf, BUFF_SIZE);
		free(tmp);
		if (ft_strchr(*mem, '\n') != NULL)
			break ;
	}
	free(buf);
	return (status);
}

int		seizeline(char **mem, char **line, int status)
{
	char		*tmp;

	tmp = *mem;
	while (**mem && **mem != '\n')
	{
		++*mem;
	}
	if (**mem == '\n')
	{
		**mem = '\0';
		++*mem;
		if (**mem)
			status = 1;
	}
	if (!(*line = ft_strdup(tmp)))
		return (-1);
	if (!(*mem = ft_strdup(*mem)))
		return (-1);
	free(tmp);
	return (status);
}

int		get_next_line(const int fd, char **line)
{
	static char	*mem;
	int			status;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	status = 1;
	if (!mem)
		if (!(mem = ft_strnew(0)))
			return (-1);
	if (ft_strchr(mem, '\n') == NULL)
	{
		status = readfile(fd, &mem, status);
		if (status == -1)
			return (-1);
		if (!*mem && status == 0)
			return (0);
	}
	status = seizeline(&mem, line, status);
	return (1);
}
