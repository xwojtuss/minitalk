/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:13:02 by wkornato          #+#    #+#             */
/*   Updated: 2024/06/11 15:13:03 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

void	get_data(int signum, siginfo_t *info, void *context)
{
	static unsigned int	character = 0;
	static int			bit_count = 7;

	(void)context;
	if (signum == SIGUSR2 && bit_count > -1)
		character |= (1 << bit_count);
	bit_count--;
	if (character == 0 && bit_count == -1)
	{
		ft_printf("\nMessage fully received!\n");
		kill(info->si_pid, SIGUSR2);
		character = 0;
		bit_count = 7;
		return ;
	}
	else if (bit_count == -1)
	{
		ft_putchar(character);
		character = 0;
		bit_count = 7;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = get_data;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		usleep(1);
	return (0);
}
