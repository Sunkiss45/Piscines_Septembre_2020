/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:31:29 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/22 15:51:37 by ebarguil         ###   ########.fr       */
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
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < argc / 2)
	{
		tmp = argv[j];
		argv[j] = argv[argc - j - 1];
		argv[argc - j - 1] = tmp;
		j++;
	}
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != argv[argc - 1])
			converssion(argv[i]);
		i++;
	}
}
