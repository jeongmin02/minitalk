/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:13:53 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/04 19:16:09 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	s_receive_send(int signo, siginfo_t *info, void *none)
{
	static int	i = 0;
	static char	c = 0;

	if (signo == SIGUSR1)
		c = c | 1;
	if (i++ == 7)
	{
		i = 0;
		if (!c)
		{
			write(1, &c, 1);
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sig_act;

	write(1, "Server PID : ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = s_receive_send;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
