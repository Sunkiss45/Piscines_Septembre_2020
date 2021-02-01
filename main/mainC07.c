/* ===== EX00 ===== */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char *src;
	src = argv[1];
	printf("%s\n", ft_strdup(src));
	return (0);
}

/* ===== EX01 ===== */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	long len = max - min;
	int *res = ft_range(min, max);
	int i = 0;

	while (i < len)
	{
		printf("%d\n", res[i]);
		i++;
	}
	return (0);
}

/* ===== EX02 ===== */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	int *res = NULL;
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int i = ft_ultimate_range(&res, min, max);

	printf("%d\n", i);
	return (0);
}

/* ===== EX03 ===== */

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

/* ===== EX04 ===== */

#include <stdio.h>

int	main(int argc, char **argv)
{
	char *str;

	if (argc != 4)
		return(0);
	str = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", str);
	free(str);
	return (0);
}

/* ===== EX05 ===== */

#include <stdio.h>

int	main(int argc, char **argv)
{
	char **tab = ft_split(argv[1], argv[2]);
	int i = 0;

	if (argc != 3)
		return (0);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
