/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:39:12 by ebarguil          #+#    #+#             */
/*   Updated: 2021/01/07 10:44:22 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		count(int size, char **strs, char *sep)
{
	int dest_size;
	int sep_int;
	int s;

	dest_size = 1;
	s = 0;
	while (s < size)
	{
		dest_size += ft_strlen(strs[s]);
		s++;
	}
	sep_int = ft_strlen(sep);
	dest_size += sep_int * (size - 1);
	return (dest_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	if (size == 0)
	{
		if (!(dest = malloc(sizeof(char) * 1)))
			return (NULL);
		dest[0] = 0;
		return (dest);
	}
	if (!(dest = (char*)malloc(sizeof(char) * count(size, strs, sep))))
		return (NULL);
	dest[0] = 0;
	i = 0;
	while (i < size)
	{
		dest = ft_strcat(dest, strs[i]);
		if (i < (size - 1))
			dest = ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char *str;

	if (argc < 3)
		return (0);
	str = ft_strjoin(argc - 2, &argv[1] , argv[argc - 1]);
	printf("Chaine : %s\n", str);
	free(str);
	return (0);
}
