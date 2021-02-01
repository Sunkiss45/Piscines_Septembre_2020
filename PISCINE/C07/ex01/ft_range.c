/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:42:28 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/29 19:26:54 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*res;
	int		i;
	long	len;

	if (min >= max)
		return (NULL);
	i = 0;
	len = max - min;
	if (!(res = malloc(sizeof(int) * len)))
		return (0);
	while (i < len)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
