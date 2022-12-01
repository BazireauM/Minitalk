/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:31:03 by mbazirea          #+#    #+#             */
/*   Updated: 2022/12/01 08:18:11 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*malloc_final(int n, unsigned int n2, int *a)
{
	char			*final;

	*a = 0;
	while (n2 > 0)
	{
		n2 /= 10;
		*a = *a + 1;
	}
	if (n < 0)
	{
		final = malloc(sizeof(char) * *a + 2);
		if (!final)
			return (NULL);
		final[*a + 1] = '\0';
		final[0] = '-';
	}
	else
	{
		final = malloc(sizeof(char) * *a + 1);
		if (!final)
			return (NULL);
		final[*a] = '\0';
	}
	return (final);
}

void	zero(char *final)
{
	final[0] = '0';
	final[1] = '\0';
}

char	*ft_itoa_part2(int a, int n, char *final, unsigned int n2)
{
	while (a > 0 && n != 0)
	{
		if (n < 0)
			final[a] = '0' + n2 % 10;
		else
			final[a - 1] = '0' + n2 % 10;
		n2 /= 10;
		a--;
	}
	return (final);
}

char	*ft_itoa(int n)
{
	char			*final;
	unsigned int	n2;
	int				a;

	if (n == 0)
	{
		final = malloc(2);
		if (!final)
			return (NULL);
		zero(final);
		return (final);
	}
	else
	{
		if (n < 0)
			n2 = -n;
		else
			n2 = n;
		final = malloc_final(n, n2, &a);
		if (!final)
			return (NULL);
		ft_itoa_part2(a, n, final, n2);
		return (final);
	}
}
