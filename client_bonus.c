/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:14:12 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/04 19:14:15 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	s_send(int pid, char *str)
{
	int	i;

	while (1)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		if (!(*str))
			break ;
		str++;
	}
}

static void	c_receive(int signo)
{
	static int	bytes = 0;

	if (signo == SIGUSR1)
		bytes++;
	else if (signo == SIGUSR2)
	{
		write("receive bytes : ", 16);
		ft_putnbr_fd(bytes, 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	write(1, "Client PID : ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	write(1, "send	bytes : ", 13);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, c_receive);
	signal(SIGUSR2, c_receive);
	s_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
