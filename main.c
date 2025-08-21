
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("satir: %s", s);
		free(s);
	}
	close(fd);
	return (0);
}
