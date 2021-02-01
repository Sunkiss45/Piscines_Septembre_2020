#include <stdio.h>

char	vis_col_up(char **tab, int col)
{
	int		i;
	char	max_so_far;
	char	vis_so_far;

	i = 0;
	max_so_far = '0';
	vis_so_far = '0';
	while (i < 4)
	{
		if (tab[i][col] > max_so_far)
		{
			max_so_far = tab[i][col];
			vis_so_far += 1;
		}
		i++;
	}
	return (vis_so_far);
}

char	vis_col_down(char **tab, int col)
{
	int		i;
	char	max_so_far;
	char	vis_so_far;

	i = 3;
	max_so_far = '0';
	vis_so_far = '0';
	while (i >= 0)
	{
		if (tab[i][col] > max_so_far)
		{
			max_so_far = tab[i][col];
			vis_so_far += 1;
		}
		i--;
	}
	return (vis_so_far);
}

char	vis_row_left(char **tab, int row)
{
	int		i;
	char	max_so_far;
	char	vis_so_far;

	i = 0;
	max_so_far = '0';
	vis_so_far = '0';
	while (i < 4)
	{
		if (tab[row][i] > max_so_far)
		{
			max_so_far = tab[row][i];
			vis_so_far += 1;
		}
		i++;
	}
	return (vis_so_far);
}

char	vis_row_right(char **tab, int row)
{
	int		i;
	char	max_so_far;
	char	vis_so_far;

	i = 3;
	max_so_far = '0';
	vis_so_far = '0';
	while (i >= 0)
	{
		if (tab[row][i] > max_so_far)
		{
			max_so_far = tab[row][i];
			vis_so_far += 1;
		}
		i--;
	}
	return (vis_so_far);
}
