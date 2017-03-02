#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 4096
#define NORMAL_DOT_NB 12
#define NORMAL_HASH_NB 4
#define MIN_CHAR_NB 20
#define MAX_CHAR_NB 545

/*
** Ci dessous a virer une fois fini
*/

#include <stdio.h>

/*
** Ci dessus a virer une fois fini
*/


typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct 	s_tetrimino
{
	t_point ref_point;
	t_point hash[4];
	char lettre;
}				t_tetrimino;

typedef struct 	s_map
{
	int size;
	char **content;
}				t_map;



int		ft_floor_sqrt(int nb)
{
	int i;

	i = 2;	
	while (i * i <= nb)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*buf;
/*
**	Verifier si le nombre d'arguments est 2
*/
	if (argc != 2)
	{
		write(2, "Usage: ./fillit input_file\n", 27);
		return (0);
	}
/*
**	Ouvrir le fichier, le lire, le mettre dans un buffer puis fermer le fichier
*/
	buf = (char *)malloc(sizeof(char) * 10000);
	fd = open(argv[1], O_RDONLY);
	//printf("fd is %d\n", fd);
	//fd = -1;
	if (fd == -1)
	{
		write(2, "open() failed\n", 14);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	//printf("ret is %d\n", ret);
	//ret = -1;
	if (ret == -1)
	{
		write(2, "read() failed\n", 14);
		return (0);
	}
	buf[ret] = '\0';
	//printf("buf below\n%s\n", buf);
	if (close(fd) == -1)
	{
		write(2, "close() failed\n", 15);
		return (0);
	}
	printf("%s\n", buf);
/*
**	Afficher "error" si
**		le nombre de characteres est impossible
**		le nombre de # est impossible
**		le nombre de . est impossible
**		les \n ne sont pas au bon endroit
*/
	int		char_nb;
	int		hash_nb;
	int		dot_nb;
	int		border_nl_nb;
	int		between_nl_Nb;
	int		i;
	int		j;
	int		tetriminos_nb;

	char_nb = 0;
	hash_nb = 0;
	dot_nb = 0;
	border_nl_nb = 0;
	between_nl_Nb = 0;
	i = 0;
	j = 1;
	tetriminos_nb = 0;
	while (buf[i])
	{
		char_nb++;
		if (buf[i] == '#')
			hash_nb++;
		if (buf[i] == '.')
			dot_nb++;
		if ((j) % 5 == 0 && buf[i] == '\n')
			border_nl_nb++;
		if ((i + 1) % 21 == 0 && buf[i] == '\n')
		{
			between_nl_Nb++;
			j--;
		}
		i++;
		j++;
	}
	printf("char_nb\t%d\nhash_nb\t%d\ndot_nb\t%d\n", char_nb, hash_nb, dot_nb);
	printf("border_nl_nb\t%d\nbetween_nl_Nb \t%d\n", border_nl_nb, between_nl_Nb);
	if (char_nb < MIN_CHAR_NB || char_nb > MAX_CHAR_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if ((char_nb + 1) % (20 + 1) != 0)
	{
		write(2, "error\n", 6);
		return (0);
	}
	tetriminos_nb = (char_nb + 1) / 21;
	printf("tetriminos_nb\t%d\n", tetriminos_nb);
	if (hash_nb / tetriminos_nb != NORMAL_HASH_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (dot_nb / tetriminos_nb != NORMAL_DOT_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (border_nl_nb / tetriminos_nb != 4)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if ((between_nl_Nb + 1) / tetriminos_nb != 1)
	{
		write(2, "error\n", 6);
		return (0);
	}

/*
**	Verifier que les # ont tous au moin un voisin sinon retourner error
*/


	int nb_voisin_min;
	int index;
	
	nb_voisin_min = 0;
	index = 0;
	while (buf[index])
	{
		if (buf[index] == '#')
		{
			if (buf[index-1] == '#'
				|| buf[index+1] == '#'
				|| buf[index-5] == '#'
				|| buf[index+5] == '#')
			{
				nb_voisin_min++;
			}
		}
		index++;
	}
	printf("nb_voisin_min\t%d\n", nb_voisin_min);
	if (nb_voisin_min != hash_nb)
	{
		write(2, "error\n", 6);
		return (0);
	}

/*
**	En fonction du nombre de # du fichier de base calculer la taille minimale du nombre de caracteres du carre
*/
	int 	min_square_space;

	min_square_space = ft_floor_sqrt(hash_nb);
	printf("min_square_space\t%d\n", min_square_space);

/*
**	Decomposer en un tableau en 2D
*/



	char **tetris_table;
	tetris_table = ft_strsplit(buf, '\n');

	/*
	while (*tetris_table)
	{
		printf("%s\n", *tetris_table);
		tetris_table++;
	}
	*/

/*
**	Initialisation carre minimal
*/

	char **map;
	map = (char**)malloc(sizeof(char*) * (min_square_space + 1));
	int hauteur;
	hauteur = 0;
	int indexe;
	while(hauteur < min_square_space)
	{
		map[hauteur] = (char*)malloc(sizeof(char) * (min_square_space + 1));
		indexe = 0;
		while (indexe < min_square_space)
		{
			map[hauteur][indexe] = '.';
			indexe++;
		}
		map[hauteur][indexe] = '\0';
		hauteur++;
	}
	map[hauteur] = 0;
	/*

	printf("\n");
	while(*map)
	{
		printf("%s\n", *map);
		map++;
	}
	*/

/*
**	Recuperation des coordonnees des # dans une structure de tetrimino
*/

	t_tetrimino tetrimino[tetriminos_nb];

	int ligneuh;
	int ka;
	int tetris_iter;
	int hash_iter;

	ligneuh = 0;
	tetris_iter = -1;
	while (ligneuh < tetriminos_nb * 4)
	{
		if (((ligneuh) % 4) == 0)
		{
			tetris_iter++;
			hash_iter = 0;
		}
		ka = 0;
		
		while (tetris_table[ligneuh][ka])
		{
			if (tetris_table[ligneuh][ka] == '#')
			{
				printf("# repere %d\n", hash_iter);
				printf("tetris_iter %d\n", tetris_iter);
				tetrimino[tetris_iter].hash[hash_iter].x = ka % 4;
				printf("x %d\n", tetrimino[tetris_iter].hash[hash_iter].x);
				tetrimino[tetris_iter].hash[hash_iter].y = ligneuh % 4;
				printf("y %d\n", tetrimino[tetris_iter].hash[hash_iter].y);
				hash_iter++;
			}
			ka++;
		}
		ligneuh++;
	}

/*
**	Recuperation du point de reference de chaque tetrimino
*/

	int min_x;
	int min_y;
	tetris_iter = 0;
	while (tetris_iter < tetriminos_nb)
	{
		hash_iter = 0;
		min_x = 4;
		min_y = 4;
		while (hash_iter < 4)
		{
			if (tetrimino[tetris_iter].hash[hash_iter].x < min_x)
				min_x = tetrimino[tetris_iter].hash[hash_iter].x;
			if (tetrimino[tetris_iter].hash[hash_iter].y < min_y)
				min_y = tetrimino[tetris_iter].hash[hash_iter].y;
			hash_iter++;
		}
		tetrimino[tetris_iter].ref_point.x = min_x;
		tetrimino[tetris_iter].ref_point.y = min_y;
		printf("\nmin_x %d\nmin_y %d\n", tetrimino[tetris_iter].ref_point.x, tetrimino[tetris_iter].ref_point.y);
		tetris_iter++;
	}

/*
**	Assigner la lettre de chaque tetrimino
*/

	tetris_iter = 0;
	char charact = 'A';
	while (tetris_iter < tetriminos_nb)
	{
		tetrimino[tetris_iter].lettre = charact + tetris_iter;
		printf("%c\n", tetrimino[tetris_iter].lettre);
		tetris_iter++;
	}


/*
**	On verifie si on peut placer un tetrimino sur la map
**		S'il n'y a rien sur la map en dessous du tetrimino
**		Si le tetrimino rentre dans la map en largeur et hauteur
*/







	

/*
**	Recuperer min_x et min_y pour obtenir les coordonnees de reference
*/
/*
	int ligneuh;
	int min_x;
	int min_y;
	int ka;
	int iter_tetris;

	iter_tetris = 0;
	ligneuh = 0;
	min_y = 4;
	min_x = 4;
	while (iter_tetris < tetriminos_nb)
	{
		

		while (ligneuh < (iter_tetris + 1) * 4)
		{ 
			ka = 0;
			while (tetris_table[ligneuh][ka])
			{
				if (tetris_table[ligneuh][ka] == '#')
				{
					if (ka < min_x)
						min_x = ka;
					if (ligneuh < min_y)
						min_y = ligneuh;
				}
				ka++;
			}
			ligneuh++;
		}
		printf("min_x %d\nmin_y %d\n", min_x, min_y);
		ligneuh = ligneuh + 4;
		min_x = min_x + 4;
		min_y = min_y + 4;
		iter_tetris++;
	}
*/

/*
**	Transformer les 4 premiers # en A les 4 suivants en B et ainsi de suite
*/

	/*
		i = 0;
		char le_char = 'A';
		while (buf[i])
		{
			if (buf[i] == '#')
				buf[i] = le_char;
			if (i !=0 && (i+1) % 21 == 0)
				le_char++;
			i++;
		}
		printf("%s\n", buf);
	*/

/*
**	Verifier recursivement s'il est possible de poser tous les tetrimino dans le carre minimal l'augmenter juqu'a ce que ca fonctionne.
**	Afficher le carre resolu
*/

/*
**	Afficher le carre resolu et optimise
*/

	return (0);
}
