/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:03:01 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/12 17:03:07 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	firstline(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (y > 0)
	{
		if (i == 0 && j == 0)
		{
			ft_putchar('A');
		}
		i++;
		while (i < x - 1)
		{
			ft_putchar('B');
			i++;
		}
		i++;
		if (i == x && j == 0)
		{
			ft_putchar('C');
		}
		ft_putchar('\n');
	}
}

void	middle(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < y - 1)
	{
		if (j == 0)
			ft_putchar('B');
		j++;
		while (j < x - 1)
		{
			ft_putchar(' ');
			j++;
		}
		j++;
		if (j == x)
			ft_putchar('B');
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	lastline(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = y;
	if (y > 1)
	{
		if (i == 0 && j == y)
		{
			ft_putchar('A');
		}
		i++;
		while (i < x - 1)
		{
			ft_putchar('B');
			i++;
		}
		i++;
		if (i == x && j == y)
		{
			ft_putchar('C');
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || x > 2147483647 || y <= 0 || y > 2147483647)
		return ;
	firstline(x, y);
	middle(x, y);
	lastline(x, y);
}
