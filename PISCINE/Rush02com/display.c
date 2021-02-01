/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:05:02 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 21:54:35 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

// FONCTION QUI VA AFFICHER LE RANG DU NOMBRE
// EXEMPLE : THOUSAND MILLION BILLION ETC...
// LA FONCTION EST DIFFICILE A EXPLIQUER ICI, JE VOUS EXPLIQUERAIS IRL
void	display_rank(t_dict *dict, int d_size, int index, char *nbr)
{
	char	*str;
	int		nb_z;
	char	*val;
	int		i;

	nb_z = (ft_strlen(nbr) - 1) - (3 * index);
	while (nb_z % 3 != 0)
		nb_z--;
	i = 1;
	if (!(str = malloc(sizeof(char) * (nb_z + 20))))
		return ;
	str[0] = '1';
	while (i <= nb_z)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	val = get_val(dict, d_size, str);
	write(1, " ", 1);
	write(1, val, ft_strlen(val));
	free(str);
}

// FONCTION QUI VA AFFICHER LES UNITES.
// ON REMPLI UNE CHAINE DE CARACTERE AVEC LE NB RECU EN PARAMETREQUE L'ON VA CONVERTIR EN CARACTERE
// UNE FOIS CETTE CHAINE REMPLIE, ON RECUPERE LA VALEURE CORRESPONDANTE A CETTE CLE DANS LE DICTIONNAIRE ET ON
// AFFICHE CELLE CI.
// EXEMPLE POUR NB = 5 AVEC LE DICTIONNAIRE DE BASE, ON AFFICHE FIVE
void	display_unit(t_dict *dict, int d_size, short nb)
{
	char	unit[2];
	char	*val;

	unit[0] = nb + '0';
	unit[1] = 0;
	val = get_val(dict, d_size, unit);
	write(1, val, ft_strlen(val));
}

// FONCTION QUI VA AFFICHER TOUT LES NOMBRES COMPRIS ENTRE 10 ET 19 COMPRIS
// ON REMPLI UNE CHAINE DE CARACTERE AVEC LA DIZAINE ET L'UNITEE RECUES EN PARAMETRE.
// ON RECHERCHE ENSUITE CETTE CHAINE-CLE DANS LE DICTIONNAIRE ET ON AFFICHE LA VALEURE CORRESPONDANTE
// EXMPLE POUR NB = 19 AVEC LE DICTIONNAIRE DE BASE, ON AFFICHE NINETEEN
void	display_spec(t_dict *dict, int d_size, short tens, short unit)
{
	char	s_tens[3];
	char	*val;

	s_tens[0] = tens + '0';
	s_tens[1] = unit + '0';
	s_tens[2] = 0;
	val = get_val(dict, d_size, s_tens);
	write(1, val, ft_strlen(val));
}

// FONCTION QUI VA AFFICHER LES DIZAINES ENTRE 20 ET 90 COMPRIS
// ON REMPLI UNE CHAINE DE CARACTERE AVEC LA DIZAINE RECUE EN PARAMETRE
// ON RECHERCHE ENSUITE CETTE CHAINE-CLE DANS LE DICTIONNAIRE ET ON AFFICHE LA VALEURE CORRESPONDANTE
// EXMPLE POUR NB = 60 AVEC LE DICTIONNAIRE DE BASE, ON AFFICHE SIXTY
void	display_tens(t_dict *dict, int d_size, short tens)
{
	char	s_tens[3];
	char	*val;

	s_tens[0] = tens + '0';
	s_tens[1] = '0';
	s_tens[2] = 0;
	val = get_val(dict, d_size, s_tens);
	write(1, val, ft_strlen(val));
}

// FONCTION QUI VA GERE L'AFFICHAGE DU NOMBRE RECU EN ARGUMENT DU PROGRAMME
// ON AURA AU PREALABLE REPARTI CE NOMBRE EN UN TABLE DE STRUCTURE T_NUM REPRESENTANT,
// POUR CHAQUE CASE DE CE TABLEAU DES CENTAINES (HUND), DES DIZAINES (TENS) ET DES UNITES (UNIT)
// ON AFFICHE UN ESPACE UNIQUEMENT QUAND LES CONDITIONS SONT REMPLIE
// ON PROCEDE, DANS L'ORDE, PAR L'AFFICHAGE DES CENTAINES, DES DIZAINES, DES UNITES ET ENFIN DU 
// RANG CORRESPONDAND A L'INDEX DE NOTRE TABLEAU DE T_NUM.
// CETTE FONCTION EST RECURSIVE TANT QUE NOTRE TABLEAU DE T_NUM N'EST PAS FINI.
// ON CONNAIT LA FIN DE CE TABLEAU CAR UNIT DE LA DERNIERE CASE EST INITIALISEE A -1.
void	display(t_dict *dict, int d_size, t_num *num, char *nbr)
{
	static int	i = 0;
	char		*val;

	if (i > 0 && (num[i].unit > 0 || num[i].tens > 0 || num[i].hund > 0))
		write(1, " ", 1);
	if (num[i].hund > 0)
	{
		display_unit(dict, d_size, num[i].hund);
		write(1, " ", 1);
		val = get_val(dict, d_size, "100");
		write(1, val, ft_strlen(val));
		num[i].tens > 0 || num[i].unit > 0 ? write(1, " ", 1) : 0;
	}
	if (num[i].tens > 0)
	{
		num[i].tens == 1 ? display_spec(dict, d_size, num[i].tens
			, num[i].unit) : display_tens(dict, d_size, num[i].tens);
		num[i].unit > 0 && num[i].tens != 1 ? write(1, " ", 1) : 0;
	}
	if (num[i].unit > 0 && num[i].tens != 1)
		display_unit(dict, d_size, num[i].unit);
	if ((num[i].hund > 0 || num[i].tens > 0 || num[i].unit > 0)
		&& num[i + 1].unit != -1)
		display_rank(dict, d_size, i, nbr);
	return (num[i++].unit != -1 ? display(dict, d_size, num, nbr) : 0);
}
