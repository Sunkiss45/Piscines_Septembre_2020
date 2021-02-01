/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:03:28 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 21:20:39 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

// FONCTION DE VERIFICATION DU FICHIER RECU
// ON PREND UN POINTEUR SUR UNE STRUCTURE T_FILE EN PARAMETRE. CETTE STRUCTURE CONTIENDRA
// DANS SON BUFFER LA TOTALITE DU FICHIER QUE L'ON AURA LU AU PREALABLE
// LA FONCTION VA VERFIER, LIGNE PAR LIGNE, SI LE FICHIER RESPECTE BIEN LES REGLES
// DE SYNTAXE DECRITE DANS LE SUJET.
// LA FONCTION EST RECURSIVE TANT QUE LA CHAINNE DE CARACTERE BUFF N'EST PAS ARRIVEE A 
// LA FIN.
// ON DECLARE UNE VARIABLE STATIQUE PAR MANQUE DE LIGNE. LA NORME DEFINIE QU'UNE VARIABLE
// STATIQUE PEUT ETRE PEUT ETRE DEFINIE SUR LA MEME LIGNE QUE SA DECLARATION, CONTRAIREMENT
// A UNE VARAIBLE CLASSIQUE
short	check_buff(t_file *file)
{
	static unsigned long	i = 0;

	while (file->buff[i] == 10 && file->buff[i])
		i++;
	if ((file->buff[i] < '0' || file->buff[i] > '9') && file->buff[i])
		return (FALSE);
	while ((file->buff[i] > 47 && file->buff[i] < 58) && file->buff[i])
		i++;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	if (file->buff[i] != ':' && file->buff[i])
		return (FALSE);
	else if (file->buff[i])
		i++;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	if ((file->buff[i] < 33 || file->buff[i] > 126) && file->buff[i])
		return (FALSE);
	while (file->buff[i] > 31 && file->buff[i] < 127 && file->buff[i])
		i++;
	if (file->buff[i] != 10 && file->buff[i])
		return (FALSE);
	return (file->buff[i] ? check_buff(file) : TRUE);
}

// FONCTION QUI VA OUVRIR LE FICHIER DICTIONNAIRE ET STOCKER L'ENSEMBLE DE CE FICHIER DANS
// LA CHAINE DE CARACTERE BUFFER DE NOTRE STRUCTURE T_FILE
// OPEN RENVOI UN DESCRIPTEUR DE FICHIER (FD). C'EST AVEC CE DESCRIPTEUR QUE L'ON VA POUVOIR
// LIRE DANS LE FICHIER AVEC READ.
// SI OPEN RENVOIE UNE VALEURE NEGATIVE, C'EST QU'ELLE N'A PAS REUSSI A OUVRIR LE FICHIER,
// DANS CE CAS ON QUITTE.
// ON ALLOUE ENSUITE LA CHAINE DE CARACTERE BUFF DE NOTRE T_FILE DE LA TAILLE DE NOTRE FICHIER
// (FILE->SIZE QUE L'ON AURA DETERMINE AU PREALABLE)
// UNE CHAINE DE CARACTERE AYANT ETE ALLOUEE AVEC MALLOC, ON SE DOIT DE LA FREE, DONC ON INITIALISE
// FILE->MUST_FREE A TRUE AFIN DE S'EN RAPPELER PLUS LOIN
// PAR LA SUITE, ON LIT DANS LE FICHIER AVEC READ TANT QU'IL RESTE QUELQUE CHOSE A LIRE.
// UNE FOIS LA LECTURE TERMINEE, READ RENVERRA 0 ET ON QUITTERA LE WHILE, SINON, LE NOMBRE D'OCTET LU
// A CHAQUE TOUR DE BOUCLE EST STOCKE DANS FILE->BYTES.
// SI READ RENVOI UNE VALEURE NEGATIVE, C'EST UNE ERREUR DE LECTURE ET ON QUITTE LE PROGRAMME.
// SINON, ON CONTINUE DE REMPLIR NOTRE FILE->BUFF
// UNE FOIS LA LECTURE TERMINEE, ON FERME LE FICHIER AVEC CLOSE ET ON METS UN 0 A LA FIN DE LA CHAINE
// FILE->BUFF.
// ON RETOURNE ENSUITE LA VALEUR DE RETOUR DE LA FONCTION CHECK_BUFF CI DESSUS QUE L'ON APPELLE 
// DONC A CE MOMENT LA.
short	check_file(t_file *file)
{
	unsigned long	index;

	index = 0;
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
		return (FALSE);
	if (!(file->buff = malloc(sizeof(char) * file->size)))
		return (FALSE);
	file->must_free = TRUE;
	while ((file->bytes = read(file->fd, file->buff + index, BUFF_SIZE)))
	{
		if (file->bytes < 0)
		{
			close(file->fd);
			return (FALSE);
		}
		index += file->bytes;
	}
	close(file->fd);
	file->buff[index - 1] = 0;
	return (check_buff(file));
}

// FONCTION QUI VA DETERMINE LA VALIDITE DU NOMBRE RECU EN PARAMETRE DU PROGRAMME
// SI LE NOMBRE CONTIENT AUTRE CHOSE QUE DES CHIFFRES, ON RENVOI FALSE
short	check_nbr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// FONCTION QUI VA VERIFIER LA VALIDITE DE NOTRE DICTIONNAIREQUE L'ON AURA PARSE AU PREALABLE
// SI UNE CLE OU UNE VALEURE EST MANQUANTE OU SI LE DICTIONNAIRE CONTIENT DEUX FOIS LA MEME CLE
// , LE DICTIONNAIRE N'EST PAS VALIDE
short	check_dict(t_dict *list, int size)
{
	int i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (!(list[i].key) || !(list[i].val))
			return (FALSE);
		while (j < size)
		{
			if (ft_strcmp(list[i].key, list[j].key) == 0)
				return (FALSE);
			j++;
		}
		i++;
	}
	if (!(list[i].key) || !(list[i].val))
		return (FALSE);
	return (TRUE);
}

// FONCTION QUI VA VERIFIER SI LE DICTIONNAIRE QUE L'ON AURA PARSE AU PREALABLE
// CONTIENT BIEN AU MOINS TOUTE LES CLES DU DICTIONNAIRE STANDARD
// ON DECLARE ICI CES CLES A LA MAIN DANS UNE VARIABLE STATIQUE QUI NOUS PERMET DE FAIRE 
// LA DECLARATION SUR LA MEME LIGNE QUE L'INITIALISATION
// SI UNE DE CES CLES N'EXISTE PAS DANS NOTRE DICTIONNAIRE, CE DERNIER N'EST PAS VAIDE.
short	check_keys(t_dict *list, int size)
{
	static char	tab[41][37] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
	, "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30"
	, "40", "50", "60", "70", "80", "90", "100", "1000", "1000000"
	, "1000000000", "1000000000000", "1000000000000000", "1000000000000000000"
	, "1000000000000000000000", "1000000000000000000000000"
	, "1000000000000000000000000000", "1000000000000000000000000000000"
	, "1000000000000000000000000000000000"
	, "1000000000000000000000000000000000000"};
	int			i;

	i = 0;
	if (size < 41)
		return (FALSE);
	while (i < 41)
	{
		if (is_key(tab[i], list, size) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
