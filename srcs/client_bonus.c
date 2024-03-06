/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:48:04 by jules             #+#    #+#             */
/*   Updated: 2024/03/07 00:48:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_waiting_for_response = 0;

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
		g_waiting_for_response = 0;
	}
}

void	ft_send(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (g_waiting_for_response == 0)
		{
			g_waiting_for_response = 1;
			if (c & (0x80 >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
		}
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	if (kill(pid, 0) < 0)
	{
		ft_printf("ERROR : cant send sig to pid : %d\n", pid);
		return (1);
	}
	i = 0;
	signal(SIGUSR2, listen_for_response);
	i = 0;
	while (argv[2][i])
		ft_send(pid, argv[2][i++]);
	ft_send(pid, 0);
	usleep(WAIT_TIME);
	if (!g_waiting_for_response)
		ft_printf("Message envoye et recu avec succes\n");
}
