/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:48:08 by jules             #+#    #+#             */
/*   Updated: 2024/02/23 14:39:06 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	listen(int signo, siginfo_t *info, void *content)
{
	static int	i = 0;
	static int	c = 0;

	(void) content;
	c = c << 1;
	i++;
	if (signo == SIGUSR2)
		c |= 1;
	if (i >= 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction sig;

	ft_printf("Server ID : %d\n", getpid());
	sig.sa_sigaction = listen;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = (sigset_t){0};
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
