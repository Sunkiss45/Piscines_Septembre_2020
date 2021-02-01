/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:26:41 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/15 18:03:24 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		nb_long = nb_long * (-1);
		ft_putchar('-');
	}
	if (nb_long >= 0 && nb_long <= 9)
	{
		ft_putchar(nb_long + '0');
	}
	if (nb_long > 9)
	{
		ft_putnbr(nb_long / 10);
		ft_putnbr(nb_long % 10);
	}
}
