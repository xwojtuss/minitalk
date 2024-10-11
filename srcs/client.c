/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:12:57 by wkornato          #+#    #+#             */
/*   Updated: 2024/06/11 15:12:59 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

volatile int	g_received = 0;

void	confirmation_handler(int signum)
{
	if (signum == SIGUSR1)
		g_received = 1;
}

void	acknowledgement_handler(int signum)
{
	if (signum == SIGUSR2)
		g_received = 42;
}

void	send_char(int octan, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		signal(SIGUSR1, confirmation_handler);
		signal(SIGUSR2, acknowledgement_handler);
		g_received = 0;
		if (((octan & (1 << i)) > 0) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_received == 0)
			usleep(1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	unsigned char	*string;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	string = (unsigned char *)argv[2];
	while (*string)
	{
		send_char(*string, server_pid);
		string++;
	}
	send_char(0, server_pid);
	if (g_received == 42)
		ft_printf("Message fully received!\n");
	return (0);
}
