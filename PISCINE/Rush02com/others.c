/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 08:07:52 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 22:14:34 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

// FONCTION D'INITIALISATION DE NOTRE STRUCTURE T_FILE.
// LE NOM DU FICHIER SERA, S'IL N'Y A PAS DE DICTIONNAIRE DECLARE, LE DICTIONNAIRE PAR DEFAUT 
// (VOIR DEFINE), SINON CELUI QUE L'UTILISATEUR DU PROGRAMME AURA DONNE EN PARAMETRE.
// ON RECUPERE LA TAILLE DU FICHIER AVEC GET_FILE_SIZE.
// ON INITIALISE MUST_FREE A FALSE PAR DEFAUT
t_file	init_file(int argc, char **argv)
{
	t_file	file;

	file.name = argc == 3 ? argv[1] : DICT;
	file.size = get_file_size(file.name);
	file.must_free = FALSE;
	return (file);
}

// FONCTION QUI VA INITIALISER NOTRE TABLEAU DE T_NUM A -1 PARTOUT PAR DEFAUT
// TAB ETANT LE TABLEAU ET SIZE ETANT LA TAILLE DE CELUI-CI
t_num	*init_num(t_num *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab[i].hund = -1;
		tab[i].tens = -1;
		tab[i].unit = -1;
		i++;
	}
	return (tab);
}

// FONCTION QUI VA RECUPERER LE NOMBRE SUR L'ENTREE STANDARD LORSQU'IL N'Y A PAS D'ARGUMENT RECU
// EN PARAMETRE DU PROGRAMME.
// ON UTILISE READ ET, A LA PLACE D'UN FILE DESCRIPTEUR POUR LIRE DANS UN FICHIER, ON LI SUR 0
// QUI CORRESPONT A L'ENTREE STANDARD.
// ON STOCK CECI DANS UNE CHAINE DE CARACTERE (BUFF), ON VERIFIE LE NOMBRE, ON RETIRE LES 0
// AU DEBUT ET ON ALLOUE UNE NOUVELLE CHAINE DE CARACTERE (NUMBER), PUIS ON LA REMPLIE AVEC LE NOMBRE COMPRIS DANS BUFF.
// POURQUOI NE PAS AVOIR RENVOYE BUFF DIRECTEMENT ? CAR UNE VARIABLE DECLARE SUR LA STACK (SANS MALLOC QUI DECLARE SUR LA
// HEAP) SERA SUPPRIMEE EN SORTIE DE FONCTION DONC CELA NE COMPILERA PAS.
char	*get_nbr_stdin(void)
{
	char		buff[BUFF_SIZE];
	ssize_t		bytes;
	char		*number;
	static int	i = 0;
	static int	j = 0;

	bytes = read(0, buff, BUFF_SIZE - 1);
	buff[bytes - 1] = 0;
	if (check_nbr(buff) == FALSE)
		return (0);
	if (ft_strlen(buff) > 1)
	{
		while (buff[i] == 48 && buff[i + 1])
			i++;
	}
	if (!(number = malloc(sizeof(char) * (ft_strlen(buff + i) + 1))))
		return (0);
	while (buff[i])
	{
		number[j] = buff[i];
		i++;
		j++;
	}
	number[i] = 0;
	return (number);
}

// FONCTION QUI VA RECUPERER UNE CHAINE DE CARACTERE CORRESPONDANT A UN NOMBRE.
// ON ELIMINE LES 0 DE LA CHAINE RECUE EN PARAMETRE ET ON RENVOI CELLE-CI + I.
// I CORRESPONDERA DU COUP AU NOMBRE DE 0 QUE L'ON A ELIMINE.
// STR[I + 1] CAR SI L'ON A QUE DES 0 ON VEUT QUAND MEME EN GARDER UN POUR AFFICHER ZERO
char	*get_nbr(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1)
	{
		while (str[i] == 48 && str[i + 1])
			i++;
	}
	return (str + i);
}

// FONCTION QUI VA DETERMINE S'IL RESTE D'AUTRES CARACTERES QUE DES ESPACES SUR LA LIGNE
// CETTE FONCTION PERMET DE TRIMER LES ESPACES DE FIN LORS DU PARSING DU DICTIONNAIRE.
short	is_last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 && str[i])
		i++;
	return (str[i] == 10 ? TRUE : FALSE);
}
