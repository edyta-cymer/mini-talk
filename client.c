/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:40:35 by ecymer            #+#    #+#             */
/*   Updated: 2024/08/28 21:40:41 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char message)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < 8)
	{
		if (((message >> bit_position) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_position++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("%s\n", "wrong count of arguments");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_message(pid, *str);
		str++;
	}
	return (0);
}
