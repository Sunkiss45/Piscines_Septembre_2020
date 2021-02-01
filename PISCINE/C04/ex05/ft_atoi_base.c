/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:54:16 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/23 15:08:05 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(char *base)
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

int	char_val(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	base_len(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, char *base)
{
	int i;
	int neg;
	int res;
	int val;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	res = 0;
	while ((val = char_val(str[i], base)) > -1)
	{
		res = res * base_len(base) + val;
		i++;
	}
	if (neg % 2 == 1)
		res *= -1;
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int res;

	if (error(base) == 1)
		return (0);
	res = ft_atoi(str, base);
	return (res);
}
