/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:10:37 by mbazirea          #+#    #+#             */
/*   Updated: 2022/12/01 08:17:26 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test(int sig)
{
	static int	c;
	static int	i;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*test2;

	pid = getpid();
	test2 = ft_itoa(pid);
	ft_putstr_fd(test2, 1);
	free(test2);
	while (1)
	{
		signal(SIGUSR1, test);
		signal(SIGUSR2, test);
		pause ();
	}
	return (0);
}
