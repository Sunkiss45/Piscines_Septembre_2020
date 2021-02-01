/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:33:07 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/16 17:01:14 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char g_base[16] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_putchar(g_base[(unsigned char)str[i] / 16]);
			ft_putchar(g_base[(unsigned char)str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
