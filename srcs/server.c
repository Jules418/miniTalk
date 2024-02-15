#include <unistd.h>
#include <stdio.h> // replace with ft_printf

int	main()
{
	printf("Server ID : %d\n", getpid());
	return (0);
}