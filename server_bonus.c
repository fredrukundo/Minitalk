/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:33:24 by frukundo          #+#    #+#             */
/*   Updated: 2023/12/14 02:25:18 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("SERVER PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
	while (1)
		pause();
	return (0);
}
