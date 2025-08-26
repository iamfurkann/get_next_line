#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;
	int fd = open("test.txt", O_RDONLY);
	int i = 0;

	while (i < 3 && (s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
		i++;
	}
	
	close(fd);
	get_next_line(-1);
	return (0);
}

