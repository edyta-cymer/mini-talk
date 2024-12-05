/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:41:03 by ecymer            #+#    #+#             */
/*   Updated: 2024/08/28 21:41:06 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unixstd.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

void	handler(int num);
void	send_message(pid_t pid, char message);

#endif
