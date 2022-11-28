/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:10:37 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/26 03:12:22 by mbazirea         ###   ########.fr       */
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
		printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, test);
		signal(SIGUSR2, test);
		pause ();
	}
	return (0);
}
