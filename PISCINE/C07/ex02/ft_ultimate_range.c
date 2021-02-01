/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:29:14 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/29 19:27:05 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int len;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		return (-1);
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (i);
}
