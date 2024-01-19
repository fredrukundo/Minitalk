/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:27:51 by frukundo          #+#    #+#             */
/*   Updated: 2023/12/27 02:39:47 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_input(int ac, char **av)
{
	int	correct_input;

	correct_input = 0;
	if (ac != 3)
		ft_printf("%s\n", "Plz, verify the input → ./client <PID> <Message>");
	else if (!ft_isdigit_s(av[1]))
	{
		ft_printf("%s", "Please, verify the PID");
		ft_printf("%s\n", " → It should contain only numbers.");
	}
	else if (*av[2] == 0)
		ft_printf("%s\n", "Please, insert a non-empty message.");
	else
		correct_input = 1;
	return (correct_input);
}

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(800);
	}
}

void	handle_read_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received bit 1\n");
	else if (signal == SIGUSR2)
		ft_printf("Received bit 0\n");
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	if (check_input(argc, argv) != 1)
		return (0);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
