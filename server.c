/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:40:53 by ecymer            #+#    #+#             */
/*   Updated: 2024/08/28 21:40:56 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	static int	bit_position;
	static int	character;

	if (num == SIGUSR1)
	{
		character |= (1 << bit_position);
		bit_position++;
	}
	else if (num == SIGUSR2)
	{
		character |= (0 << bit_position);
		bit_position++;
	}
	if (bit_position == 8)
	{
		ft_printf("%c", character);
		bit_position = 0;
		character = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	(void) argv;
	if (argc != 1)
		ft_printf("ERROR");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
	return (0);
}
