#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_error()
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_error();
	ft_putstr(argv[1]);
}
