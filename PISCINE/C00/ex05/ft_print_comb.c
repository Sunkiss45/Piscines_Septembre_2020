/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:25:25 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/10 21:43:54 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char end)
{
	write(1, &end, 1);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_putchar(a + '0');
				ft_putchar(b + '0');
				ft_putchar(c + '0');
				if (a != 7)
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
