/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:13:10 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/22 15:15:10 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int res;

	i = 0;
	if (nb == 1)
		return (1);
	while (i < nb && i <= 46340)
	{
		res = i * i;
		if (res == nb)
			return (i);
		i++;
	}
	return (0);
}
