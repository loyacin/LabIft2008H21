/**
 * \file AVL.hpp
 * \brief Le code des opérateurs d'un arbre AVL.
 * \author Ludovic Trottier
 * \author Jean-Francis Roy
 * \version 0.3
 * \date mai 2014
 *
 * Implémentation de la classe générique Arbre AVL par chaînage
 *
 */
#include <cmath>
#include <iostream>
#include "ContratException.h"

/**
 * \brief Namespace du laboratoire 8
 */
namespace labArbreAVL {
/**
 * \brief Constructeur par défaut
 * \post Une instance de la classe Arbre est initialisée
 */
template<typename E>
Arbre<E>::Arbre() :
		m_racine(nullptr), m_cardinalite(nullptr) {
}
/**
 * \brief Constructeur de copie
 *
 * \pre Il faut qu'il y ait suffisamment de mémoire
 * \post une copie profonde de l'arbre source est instanciée
 * \param[in] p_source L'arbre source à copier
 */
template<typename E>
Arbre<E>::Arbre(const Arbre& p_source) {
	_auxCopier(p_source.m_racine, m_racine);
	m_cardinalite = p_source.m_cardinalite;
}
/**
 * \brief Surcharger l'opérateur =
 *
 * \pre Il y a assez de mémoire pour l'opération
 * \post Une copie de l'arbre est effectuée
 * \param[in] p_source L'arbre source à copier
 * \return Une référence constante sur l'objet courant
 */
template<typename E>
Arbre<E>& Arbre<E>::operator =(const Arbre & p_source) {
	if (this != &p_source) {
		_auxDetruire(m_racine);
		_auxCopier(p_source.m_racine, m_racine);
		m_cardinalite = p_source.m_cardinalite;
	}

	return *this;
}
/**
 *  \brief Destructeur
 *  \post L'instance de Graphe est détruite
 */
template<typename E>
Arbre<E>::~Arbre() {
	_auxDetruire(m_racine);
}
/**
 * \brief Détruire un sous-arbre. Fonction récursive auxiliaire pour le destructeur
 * \post Le sous-arbre est détruit
 * \param[in] p_arb Le sous-arbre à détruire
 */
template<typename T>
void Arbre<T>::_auxDetruire(Noeud *& p_arb) {
	if (p_arb != nullptr) {
		_auxDetruire(p_arb->m_gauche);
		_auxDetruire(p_arb->m_droite);
		delete p_arb;
		p_arb = nullptr;
	}
}
/**
 * \brief Copier deux sous-arbres. Fonction récursive auxiliaire pour le constructeur de copie
 *
 * \pre Il y a assez de mémoire
 * \post Le sous-arbre source est copié sur la destination
 * \param[in] p_source Le sous-arbre à copier
 * \param[out] p_destination La destination où copier
 */
template<typename T>
void Arbre<T>::_auxCopier(Noeud * p_source, Noeud * & p_destination) {
	if (p_source == nullptr) {
		p_destination = nullptr;
		return;
	}

	p_destination = new Noeud(p_source->m_data);
	p_destination->m_hauteur = p_source->m_hauteur;
	_auxCopier(p_source->m_gauche, p_destination->m_gauche);
	_auxCopier(p_source->m_droite, p_destination->m_droite);
}
/**
 *  \brief Indiquer si l'arbre est vide
 *  \post L'arbre est inchangée
 *  \return Bool indiquant si l'arbre est vide
 */
template<typename E>
bool Arbre<E>::estVide() const {
	return m_cardinalite == 0;
}

/**
 * \brief Vérifier les invariant de la classe
 * \post La classe est inchangée.
 * \post L'arbre est inchangée
 */
template<typename E>
void Arbre<E>::verifieInvariant() const {
	INVARIANT(m_cardinalite >= 0);
}
/**
 * \brief Déterminer si un élément est dans l'arbre
 * \param[in] p_data L'élément à rechercher
 * \return Bool indiquant si l'élément est dans l'arbre
 * \post L'arbre est inchangée
 */
template<typename E>
bool Arbre<E>::appartient(const E & p_data) const {
	return (_appartient(m_racine, p_data) != nullptr);
}
/**
 * \brief Fonction récursive pour déterminer si un élément est dans l'arbre
 * \param[in] p_arb Le sous-arbre de la récursion
 * \param[in] p_data L'élément à rechercher
 * \return Pointeur sur le noeud contenant la donnée
 * \post L'arbre est inchangée
 */
template<typename E>
typename Arbre<E>::Noeud* Arbre<E>::_appartient(Noeud* const & p_arb,
		const E & p_data) const {
	if (p_arb == nullptr) {
		return nullptr;
	}
	if (p_arb->m_data == p_data) {
		return p_arb;
	}

	if (p_arb->m_data > p_data) {
		return _appartient(p_arb->m_gauche, p_data);
	} else {
		return _appartient(p_arb->m_droite, p_data);
	}
}
/**
 * \brief Effectuer un parcours pre-ordre sur l'arbre et lister la visite des noeuds.
 * \post L'arbre est inchangée
 * \return Vector contenant la visite des noeuds
 */
template<typename E>
std::vector<E> Arbre<E>::listerPreOrdre() const {
	std::vector<E> v;
	_listerPreOrdre(m_racine, v);
	return v;
}

/**
 * \brief Fonction auxiliaire récursive pour le parcours.
 * \post L'arbre est inchangée
 * \param[in] p_arb Racine du sous-arbre
 * \param[out] p_v Vector contenant la visite des noeuds
 */
template<typename E>
void Arbre<E>::_listerPreOrdre(Noeud * p_arb, std::vector<E> & p_v) const {
	if (p_arb != nullptr) {
		p_v.push_back(p_arb->m_data);
		_listerPreOrdre(p_arb->m_gauche, p_v);
		_listerPreOrdre(p_arb->m_droite, p_v);
	}
}
/**
 * \brief Effectuer un parcours en-ordre sur l'arbre et lister la visite des noeuds.
 * \post L'arbre est inchangée
 * \return Vector contenant la visite des noeuds
 */
template<typename E>
std::vector<E> Arbre<E>::listerEnOrdre() const {
	std::vector<E> v;
	_listerEnOrdre(m_racine, v);
	return v;
}
/**
 * \brief Fonction auxiliaire récursive pour le parcours.
 * \post L'arbre est inchangée
 * \param[in] p_arb Racine du sous-arbre
 * \param[out] p_v Vector contenant la visite des noeuds
 */
template<typename E>
void Arbre<E>::_listerEnOrdre(Noeud * p_arb, std::vector<E> & p_v) const {
	if (p_arb != nullptr) {
		_listerEnOrdre(p_arb->m_gauche, p_v);
		p_v.push_back(p_arb->m_data);
		_listerEnOrdre(p_arb->m_droite, p_v);
	}
}
/**
 * \brief Effectuer un parcours post-ordre sur l'arbre et lister la visite des noeuds.
 * \post L'arbre est inchangé
 * \return Vector contenant la visite des noeuds
 */
template<typename E>
std::vector<E> Arbre<E>::listerPostOrdre() const {
	std::vector<E> v;
	_listerPostOrdre(m_racine, v);
	return v;
}
/**
 * \brief Fonction auxiliaire récursive pour le parcours.
 * \post L'arbre est inchangée
 * \param[in] p_arb Racine du sous-arbre
 * \param[out] p_v Vector contenant la visite des noeuds
 */
template<typename E>
void Arbre<E>::_listerPostOrdre(Noeud * p_arb, std::vector<E> & p_v) const {
	if (p_arb != nullptr) {
		_listerPostOrdre(p_arb->m_gauche, p_v);
		_listerPostOrdre(p_arb->m_droite, p_v);
		p_v.push_back(p_arb->m_data);
	}
}
/**
 * \brief Effectuer un parcours par niveau sur l'arbre et lister la visite des noeuds.
 * \post L'arbre est inchangée
 * \return Vector contenant la visite des noeuds
 */
template<typename E>
std::vector<E> Arbre<E>::listerParNiveau() const {
	std::queue<Noeud*> file;
	Noeud * temp;
	std::vector<E> v;

	file.push(m_racine);
	while (!file.empty()) {
		temp = file.front();
		v.push_back(temp->m_data);
		file.pop();
		if (temp->m_gauche != 0) {
			file.push(temp->m_gauche);
		}
		if (temp->m_droite != 0) {
			file.push(temp->m_droite);
		}
	}
	return v;
}

/**
 * \brief Insérer un élément en gardant l'arbre AVL
 * \param[in] p_data L'élément à ajouter
 * \pre L'élément n'est pas dans l'arbre
 * \post L'élément est ajouté
 */
template<typename E>
void Arbre<E>::insererAVL(const E & p_data) {
}

/**
 * \brief Fonction récursive pour insérer un élément en gardant l'arbre AVL
 * \param[in] p_arb Le sous arbre actuel
 * \param[in] p_data L'élément à ajouter
 * \post L'élément est ajouté
 */
template<typename E>
void Arbre<E>::_insererAVL(Noeud *& p_arb, const E & p_data) {
}

/**
 * \brief Enlever un élément en gardant l'arbre AVL
 * \param[in] p_data L'élément à enlever
 * \pre L'élément est pas dans l'arbre
 * \post L'élément est enlevé
 */
template<typename E>
void Arbre<E>::enleverAVL(const E & p_data) {
}

/**
 * \brief Fonction récursive pour enlever un élément en gardant l'arbre AVL
 * \param[in] p_arb Le sous arbre de la récursion
 * \param[in] p_data L'élément à enlever
 * \post L'élément est enlevé
 */
template<typename E>
void Arbre<E>::_enleverAVL(Noeud *& p_arb, const E& p_data) {
}

/**
 * \brief Indique si l'arbre est AVL
 * \post L'arbre est inchangé
 * \return Bool indiquant si l'arbre est AVL
 */
template<typename E>
bool Arbre<E>::estAVL() const {
}

} //Fin du namespace
