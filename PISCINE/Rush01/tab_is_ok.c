#include <unistd.h>

int		vis_col_up(char **tab, int row);

int		vis_col_down(char **tab, int row);

int		vis_row_left(char **tab, int col);

int		vis_row_right(char **tab, int col);

void	ft_print(char **tab)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			write(1, &tab[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int		tab_is_ok(char **tab_res, char **tab_arg)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab_arg[0][i] != vis_col_up(tab_res, i))
			return (0);
		if (tab_arg[1][i] != vis_col_down(tab_res, i))
			return (0);
		if (tab_arg[2][i] != vis_row_left(tab_res, i))
			return (0);
		if (tab_arg[3][i] != vis_row_right(tab_res, i))
			return (0);
		i++;
	}
	ft_print(tab_res);
	return (1);
}
