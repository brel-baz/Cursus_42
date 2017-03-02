while (tous_les_tetris_ne_sont_pas_poses_dans_la_carte())
{
	while (on_peut_deplacer_tetris_zero_soit_vers_la_droite_soit_vers_le_bas())
	{
		si (on_peut_pas_poser_tetris_i())
		{
			poser_tetris_i();
		}
	}
	augmenter_la_taille_de_la_carte();
}
afficher_la_carte_resolue();