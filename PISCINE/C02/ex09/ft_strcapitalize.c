/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:32:49 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/16 18:08:43 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*changeonlow(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	changeonlow(str);
	while (str[i])
	{
		if ((i == 0 || (str[i - 1] >= 0 && str[i - 1] <= 47)
			|| (str[i - 1] >= 58 && str[i - 1] <= 64)
			|| (str[i - 1] >= 91 && str[i - 1] <= 96)
			|| str[i - 1] >= 123)
			&& (str[i] >= 97 && str[i] <= 122))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
