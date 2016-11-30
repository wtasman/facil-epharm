#include "project.h"
#include "stdio.h"

int	main(void)
{
	int fd;
	char *store;

	fd = open("patient1.txt", O_RDONLY);
	while((get_next_line(fd, &store)) != 0)
	{
		ft_putstr(store);
		ft_putchar('\n');
	}
	return (0);
}
