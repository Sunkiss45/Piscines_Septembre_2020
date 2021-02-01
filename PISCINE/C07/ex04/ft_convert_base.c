/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:21:09 by ebarguil          #+#    #+#             */
/*   Updated: 2021/01/06 10:16:38 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int nbr, char *base, int len, int neg);

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

int		char_val(char n, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (n == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		base_len(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi_base(char *nbr, char *base)
{
	int i;
	int neg;
	int res;
	int val;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	neg = 0;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			neg++;
		i++;
	}
	res = 0;
	while ((val = char_val(nbr[i], base)) > -1)
	{
		res = res * base_len(base) + val;
		i++;
	}
	if (neg % 2 == 1)
		res *= -1;
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		neg;
	int		semi_nbr;
	char	*final_nbr;

	neg = 0;
	if (error(base_from) == 1 || error(base_to) == 1)
		return (0);
	semi_nbr = ft_atoi_base(nbr, base_from);
	if (semi_nbr < 0)
		neg = 1;
	final_nbr = ft_itoa_base(semi_nbr, base_to, base_len(base_to), neg);
	return (final_nbr);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char *str;

	if (argc != 4)
		return(0);
	str = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", str);
	free(str);
	return (0);
}
