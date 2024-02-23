/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:48:08 by jules             #+#    #+#             */
/*   Updated: 2024/02/23 12:44:20 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	listen(int signal)
{
	static int	i = 0;
	static char	c = 0;

	c = c << 1;
	i++;
	c |= (signal == SIGUSR2);
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Server ID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, listen);
		signal(SIGUSR2, listen);
		pause ();
	}
	return (0);
}
