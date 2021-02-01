/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:42:46 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/23 15:07:37 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		error(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_long;
	int		i;

	if (error(base) == 1)
		return ;
	i = ft_strlen(base);
	nbr_long = nbr;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long *= -1;
	}
	if (nbr_long > i - 1)
	{
		ft_putnbr_base(nbr_long / i, base);
		nbr_long = nbr_long % i;
	}
	ft_putchar(base[nbr_long % i]);
}
