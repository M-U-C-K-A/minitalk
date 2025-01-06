/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:00:42 by hdelacou          #+#    #+#             */
/*   Updated: 2025/01/07 00:37:05 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * Processes server signals.
 * @param sig Signal number received.
 * @param info Signal info structure.
 * @param context Signal context.
 * @details
 * Accumulates bits to form bytes and prints characters.
 */
static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

/**
 * Main entry point of the server program.
 * @details
 * Displays logo and PID, then waits for SIGUSR1/2
 * to receive and print a string from client.
 * @returns 0 on success, 1 on failure.
 */
int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("\033[H\033[2J\033[34m", 1);
	ft_putstr_fd(" ██████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n", 1);
	ft_putstr_fd("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n", 1);
	ft_putstr_fd("╚█████╗ █████╗  ██████╔╝╚██╗ ██╔╝█████╗  ██████╔╝\n", 1);
	ft_putstr_fd(" ╚═══██╗██╔══╝  ██╔══██╗ ╚████╔╝ ██╔══╝  ██╔══██╗\n", 1);
	ft_putstr_fd("██████╔╝███████╗██║  ██║  ╚██╔╝  ███████╗██║  ██║\n", 1);
	ft_putstr_fd("╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n", 1);
	ft_putstr_fd("\033[0m\033[1m Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
