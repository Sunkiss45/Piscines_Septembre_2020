/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:08:53 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/21 18:26:32 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = 0;
	x = ft_strlen(src);
	y = ft_strlen(dest);
	if (size <= y)
		return (size + x);
	i = 0;
	while (size && (size - y - 1) && src[i])
	{
		dest[y + i] = src[i];
		i++;
		size--;
	}
	dest[y + i] = '\0';
	return (x + y);
}
