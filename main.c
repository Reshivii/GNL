#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}