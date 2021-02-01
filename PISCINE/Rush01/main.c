#include <unistd.h>
#include <stdlib.h>

char	**fill_row(char **board, int row, char **tab_arg);

int		tab_is_ok(char **tab_res, char **tab_arg);

int		verif_arg(char *str);

void	ft_create_tab(char ***tab_res, char ***tab_arg)
{
	int i;

	i = -1;
	*tab_arg = (char **)malloc(sizeof(char *) * 4);
	*tab_res = (char **)malloc(sizeof(char *) * 4);
	while (++i < 4)
	{
		(*tab_arg)[i] = (char *)malloc(sizeof(char) * 4);
		(*tab_res)[i] = (char *)malloc(sizeof(char) * 4);
	}
}

char	**ft_fill_tab(char **tab, char **argv)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tab[i][j] = argv[1][k];
			k += 2;
		}
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	char **tab_arg;
	char **tab_res;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(verif_arg(argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_create_tab(&tab_res, &tab_arg);
	tab_arg = ft_fill_tab(tab_arg, argv);
	if (!(fill_row(tab_res, 0, tab_arg)))
		write(1, "Error\n", 6);
	free(tab_res);
	free(tab_arg);
	return (0);
}
