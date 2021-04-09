/**
 * \file AVL.h
 * \brief Classe définissant un arbre avl
 * \author Ludovic Trottier
 * \author Jean-Francis Roy
 * \version 0.3
 * \date mai 2014
 *
 * Definition de la classe Arbre et de ses
 * fonctions membres. Représentation par chaînage
 *
 */

#ifndef _AVL_H
#define _AVL_H

#include <stdexcept>

#include <iostream>
#include <vector>
#include <queue>
#include <string>

namespace labArbreAVL {
/**
 * \class Arbe
 *
 * \brief classe générique représentant un arbre
 *
 *  La classe doit gérer un arbre avl générique. L'implémentation
 *  se fait par chaînage.
 */
template<typename E>
class Arbre {
public:
	Arbre();
	Arbre(const Arbre &);
	Arbre & operator =(const Arbre &);
	~Arbre();

	bool estAVL() const;
	bool estVide() const;
	bool appartient(const E &) const;
	void verifieInvariant() const;

	void insererAVL(const E &);
	void enleverAVL(const E &);

	std::vector<E> listerPreOrdre() const;
	std::vector<E> listerEnOrdre() const;
	std::vector<E> listerPostOrdre() const;
	std::vector<E> listerParNiveau() const;

private:
	/**
	 * \class Noeud
	 *
	 * \brief classe interne représentant un noeud typique de l'arbre
	 *
	 *  La classe représente un noeud typique
	 *  pour implémenter un arbre par chaînage.
	 */
	class Noeud {
	public:
		Noeud *m_gauche; /*!< Pointeur vers le fils gauche*/
		E m_data; /*!< La donnée dans l'arbre*/
		Noeud *m_droite; /*!< Pointeur vers le fils droit*/
		int m_hauteur; /*!< La hauteur d'un noeud, utile pour le critère de balancement*/
		/**
		 * \brief Constructeur de la classe Noeud
		 *
		 * \post un noeud typique est intialisé
		 *
		 */
		Noeud(const E & p_data) :
				m_gauche(nullptr), m_data(p_data), m_droite(nullptr), m_hauteur(0) {
		}
	};

	Noeud * m_racine; /*!< La racine de l'arbre*/
	long m_cardinalite; /*!< La cardinalité de l'arbre*/
};

} //Fin du namespace
#include "AVL.hpp"

#endif
