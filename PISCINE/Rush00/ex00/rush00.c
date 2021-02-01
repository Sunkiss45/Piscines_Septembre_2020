/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocraulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:48:40 by ocraulin          #+#    #+#             */
/*   Updated: 2020/09/12 16:46:59 by ocraulin         ###   ########.fr       */
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
			ft_putchar('o');
		}
		i++;
		while (i < x - 1)
		{
			ft_putchar('-');
			i++;
		}
		i++;
		if (i == x && j == 0)
		{
			ft_putchar('o');
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
			ft_putchar('|');
		j++;
		while (j < x - 1)
		{
			ft_putchar(' ');
			j++;
		}
		j++;
		if (j == x)
			ft_putchar('|');
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
			ft_putchar('o');
		}
		i++;
		while (i < x - 1)
		{
			ft_putchar('-');
			i++;
		}
		i++;
		if (i == x && j == y)
		{
			ft_putchar('o');
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
