/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:48:04 by jules             #+#    #+#             */
/*   Updated: 2024/02/23 14:32:06 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

int	waiting_for_response = 0;

int	ft_atoi(char *s)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	if (!s)
		return (-1);
	while (('0' <= s[i]) && (s[i] <= '9'))
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb);
}

void	listen_for_response(int signal)
{
	if (signal == SIGUSR2)
	{
		waiting_for_response = 0;
	}
}

void	ft_send(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (waiting_for_response == 0)
		{
			waiting_for_response = 1;
			if (c & (0x80 >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	i = 0;
	signal(SIGUSR2, listen_for_response);
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\n');
	usleep(WAIT_TIME);
	if (!waiting_for_response)
		ft_printf("Message envoye et recu avec succes\n");
}
