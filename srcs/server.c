/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:48:08 by jules             #+#    #+#             */
/*   Updated: 2024/02/17 17:33:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h> // replace with ft_printf

#define WAIT_TIME 50

void	listen(int signal)
{
	static int	i = 0;
	static char	c = 0;

	c <<= 1;
	i += 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (i == 8)
	{
		printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	printf("Server ID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, listen);
		signal(SIGUSR2, listen);
		pause ();
	}
	return (0);
}
