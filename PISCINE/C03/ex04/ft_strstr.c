/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:10:31 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/19 19:20:56 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int tmp;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			tmp = i;
			while (str[i] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (&str[tmp]);
				j++;
				i++;
			}
			i = tmp;
		}
		i++;
	}
	return (0);
}
