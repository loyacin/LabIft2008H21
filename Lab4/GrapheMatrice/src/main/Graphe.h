/**
 * \file Graphe.h
 * \brief Classe définissant le type abstrait Graphe.
 * \author Jean-Francis Roy
 * \version 0.1
 * \date Août 2016
 *
 * Définition de la classe Graphe et de ses fonctions membres.
 * Implémentation dans une matrice d'adjacence.
 */

#ifndef _GRAPHE_H
#define _GRAPHE_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

namespace labGrapheListes {
/**
 * \class Graphe
 *
 * \brief Classe générique représentant un graphe
 *
 *  La classe gère un graphe générique. L'implémentation
 *  se fait par des listes d'adjacence. Les numéros de
 *  sommets débutent à 0. Le type T correspond aux noms
 *  des sommets, qui peuvent être optionnellement intégrés.
 *
 */
template<typename T>
class Graphe {
public:
	Graphe(size_t = 10);
	~Graphe();

	void nommer(unsigned int, const T &);
	void ajouterArc(unsigned int, unsigned int);
	void enleverArc(unsigned int, unsigned int);

	T reqNom(unsigned int) const;
	bool arcExiste(unsigned int, unsigned int) const;
	size_t reqNbSommets() const;

	void affiche() const;
	std::vector<unsigned int> listerSommetsAdjacents(unsigned int) const;

	unsigned int ordreEntreeSommet(unsigned int) const;
	unsigned int ordreSortieSommet(unsigned int) const;

private:

	size_t m_nbSommets; /*!< le nombre de sommets */
	std::vector<T> m_noms; /*!< les noms des sommets */

	// Matrice d'adjacence, de m_nbSommets par m_nbSommets. Contient true s'il y a un arc
	// du sommet correspondant à la ligne, vers le sommet correspondant à la colonne.
	// La première dimension correspond aux lignes, et la seconde dimension correspond
	// aux colonnes.
	std::vector<std::vector<bool> > m_matriceAdj; /*!< la matrice d'adjacence */

	// Méthodes privées
	void verifieInvariant() const;

};

} //Fin du namespace

#include "Graphe.hpp"

#endif
