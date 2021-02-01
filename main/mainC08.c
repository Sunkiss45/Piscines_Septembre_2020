/* ===== EX04-05 ===== */

int	main(int ac, char **av)
{
	t_stock_str	*s_av;

	s_av = ft_strs_to_tab(ac, av);
	ft_show_tab(s_av);
	return (0);
}
