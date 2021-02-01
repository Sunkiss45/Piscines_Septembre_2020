/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 13:07:48 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/22 15:49:37 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	converssion(char *argv2)
{
	int i;

	i = 0;
	while (argv2[i] != '\0')
	{
		ft_putchar(argv2[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int i;

	(void)argc;
	i = 1;
	while (argv[i] != '\0')
	{
		converssion(argv[i]);
		i++;
	}
}
