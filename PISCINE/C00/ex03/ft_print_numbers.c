/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:55:37 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/10 17:03:17 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char end)
{
	write(1, &end, 1);
}

void	ft_print_numbers(void)
{
	int num;

	num = 0;
	while (num <= 9)
	{
		ft_putchar(num + '0');
		num++;
	}
}
