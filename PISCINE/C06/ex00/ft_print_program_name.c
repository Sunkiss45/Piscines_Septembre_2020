/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:42:26 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/22 15:48:35 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*argv2;

	(void)argc;
	argv2 = argv[0];
	i = 0;
	while (argv2[i] != '\0')
	{
		ft_putchar(argv2[i]);
		i++;
	}
	ft_putchar('\n');
}
