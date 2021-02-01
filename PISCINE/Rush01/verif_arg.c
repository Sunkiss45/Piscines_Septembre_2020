int	verif_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '1' && str[i] > '4') || (str[i + 1] != ' ' && i < 30))
			return (0);
		i += 2;
	}
	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	return (1);
}
