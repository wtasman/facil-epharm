#include "project.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int fd;
	char *store;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while((get_next_line(fd, &store)) != 0)
		{
			ft_putstr(store);
			ft_putchar('\n');
		}
	}
	return (0);
}
