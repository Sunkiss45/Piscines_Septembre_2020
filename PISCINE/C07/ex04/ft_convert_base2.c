/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:02:44 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/30 19:01:47 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nbr_len(int nbr, int len, int neg)
{
	int		count;
	long	tmp;

	tmp = nbr;
	if (tmp == 0)
		return (1);
	if (neg == 1)
	{
		tmp *= -1;
		count = 1;
	}
	else
	{
		tmp = nbr;
		count = 0;
	}
	while (tmp > 0)
	{
		tmp = tmp / len;
		count++;
	}
	return (count);
}

int		base_len2(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

char	*is_neg(int nbr, char *base, char *res, int i)
{
	int		len;
	long	tmp;

	tmp = nbr;
	tmp *= -1;
	len = base_len2(base);
	res[0] = '-';
	while (i > 1)
	{
		res[--i] = base[tmp % len];
		tmp = tmp / len;
	}
	return (res);
}

char	*is_pos(int nbr, char *base, char *res, int i)
{
	int len;

	len = base_len2(base);
	while (i > 0)
	{
		res[--i] = base[nbr % len];
		nbr = nbr / len;
	}
	return (res);
}

char	*ft_itoa_base(int nbr, char *base, int len, int neg)
{
	char	*res;
	int		count;
	int		i;

	count = (nbr_len(nbr, len, neg) + 1);
	if (!(res = (char*)malloc(sizeof(char) * count)))
		return (0);
	i = count - 1;
	if (neg == 1)
		is_neg(nbr, base, res, i);
	else
		is_pos(nbr, base, res, i);
	res[count - 1] = '\0';
	return (res);
}
