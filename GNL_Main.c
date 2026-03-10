#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	//fd = -1;
	fd = open("fichero.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("Linea %d: %s \n", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}