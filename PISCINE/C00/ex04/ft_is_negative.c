/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:09:44 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/29 22:33:41 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	if (n >= 0)
	{
		write(1, "P", 1);
	}
}

//#include <>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_is_negative(atoi(argv[1]));
	return (0);
}
