/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:09:47 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/10 16:43:59 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char ahpla;

	ahpla = 122;
	while (ahpla >= 97)
	{
		write(1, &ahpla, 1);
		ahpla--;
	}
}
