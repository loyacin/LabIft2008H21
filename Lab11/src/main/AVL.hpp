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
		m_racine(nullptr), m_cardinalite(0) {
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
    _auxDetruire(this->m_racine);
    this->m_cardinalite = 0;
}
/**
 * \brief Détruire un sous-arbre. Fonction récursive auxiliaire pour le destructeur
 * \post Le sous-arbre est détruit
 * \param[in] p_arb Le sous-arbre à détruire
 */
template<typename T>
void Arbre<T>::_auxDetruire(Noeud *& p_arb) {
    if (p_arb != nullptr)
    {
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
    INVARIANT(this->estAVL());
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
    _insererAVL(this->racine, data);
}

/**
 * \brief Fonction récursive pour insérer un élément en gardant l'arbre AVL
 * \param[in] p_arb Le sous arbre actuel
 * \param[in] p_data L'élément à ajouter
 * \post L'élément est ajouté
 */
template<typename E>
void Arbre<E>::_insererAVL(Noeud *& p_arb, const E & p_data) {
    if (p_arb == nullptr)
    {
        p_arb = new Noeud(p_data);
        this->m_cardinalite++;
    }
    else
    {
        if (p_data < p_arb->m_data)
        {
            _insererAVL(p_arb->m_gauche, p_data);
        }
        else if (p_data > p_arb->m_data)
        {
            _insererAVL(p_arb->m_droite, p_data);
        }
        else
        {
            throw std::logic_error("Les duplicats sont interdits.")
        }
        balancer(p_arb);
        mettreAjourHauteur(p_arb);
    }
}

template<typename E>
void Arbre<E>::balancer(Noeud *& p_arb)
{
    if (estDebalanceGauche(p_arb))
    {
        if (estPencheADroite(p_arb->m_gauche))
        {
            zigZagGauche(p_arb);
        }
        else
        {
            zigZigGauche(p_arb);
        }
    }
    else if (estDelanceDroite(p_arb))
    {
        if (estPencheAGauche(p_arb->m_droite))
        {
            zigZagDroit(p_arb);
        }
        else
        {
            zigZigDroit(p_arb);
        }
    }
}

template<typename E>
bool Arbre<E>::estDebalanceGauche(const Noeud *& p_arb) const
{
    return p_arb != nullptr && 1 < hauteur(p_arb->m_gauche) - hauteur(p_arb->m_droite);
}

template<typename E>
int Arbre<E>::hauteur(const Noeud *& p_arb) const
{
    return (p_arb == nullptr) ? -1 : p_arb->m_hauteur;
}

template<typename E>
bool Arbre<E>::estDebalanceDroite(const Noeud *& p_arb) const
{
    return p_arb != nullptr && 1 < hauteur(p_arb->m_droite) - hauteur(p_arb->m_gauche);
}

template<typename E>
bool Arbre<E>::estPencheADroite(const Noeud *& p_arb) const
{
    return p_arb != nullptr && hauteur(p_arb->m_gauche) < hauteur(p_arb->m_droite);
}

template<typename E>
bool Arbre<E>::estPencheAGauche(const Noeud *& p_arb) const
{
    return p_arb != nullptr && hauteur(p_arb->m_droite) < hauteur(p_arb->m_gauche);
}

template<typename E>
void Arbre<E>::mettreAjourHauteur(Noeud *& p_arb)
{
    if (p_arb != nullptr)
    {
        p_arb->m_hauteur = 1 + std::max(hauteur(p_arb->m_gauche), hauteur(p_arb->m_droite));
    }
}

template<typename E>
void Arbre<E>::zigZigDroit(Noeud *& p_arb)
{
    Noeud* sentinelle = p_arb->m_droite;
    p_arb->m_droite = sentinelle->m_gauche;
    sentinelle->m_gauche = p_arb;
    mettreAjourHauteur(p_arb);
    mettreAjourHauteur(sentinelle);
    p_arb = sentinelle;
}

template<typename E>
void Arbre<E>::zigZigGauche(Noeud *& p_arb)
{
    Noeud* sentinelle = p_arb->m_gauche;
    p_arb->m_gauche = sentinelle->m_droite;
    sentinelle->m_droite = p_arb;
    mettreAjourHauteur(p_arb);
    mettreAjourHauteur(sentinelle);
    p_arb = sentinelle;
}

template<typename E>
void Arbre<E>::zigZagDroit(Noeud *& p_arb)
{
    zigZigGauche(p_arb->m_droite);
    zigZigDroit(p_arb);
}

template<typename E>
void Arbre<E>::zigZagGauche(Noeud *& p_arb)
{
    zigZigDroit(p_arb->gauche);
    zigZigGauche(p_arb);
}

/**
 * \brief Enlever un élément en gardant l'arbre AVL
 * \param[in] p_data L'élément à enlever
 * \pre L'élément est dans l'arbre
 * \post L'élément est enlevé
 */
template<typename E>
void Arbre<E>::enleverAVL(const E & p_data) {
    _enleverAVL(this->m_racine, p_data);
}

/**
 * \brief Fonction récursive pour enlever un élément en gardant l'arbre AVL
 * \param[in] p_arb Le sous arbre de la récursion
 * \param[in] p_data L'élément à enlever
 * \post L'élément est enlevé
 */
template<typename E>
void Arbre<E>::_enleverAVL(Noeud *& p_arb, const E& p_data) {
    if (p_arb = nullptr)
    {
        std::logic_error("Tentative d'enlever une donnée absente.");
    }
    if (p_data < p_arb->m_data)
    {
        _enleverAVL(p_arb->m_gauche, p_data);
    }
    else if (p_data > p_arb->m_data)
    {
        _enleverAVL(p_arb->m_droite, p_data);
    }
    else if (p_arb->m_gauche != nullptr && p_arb->m_droite != nullptr)
    {
        enleverSuccMinDroite(p_arb);
    }
    else
    {
        Noeud* sentinelle = p_arb;
        p_arb = (p_arb->m_gauche == nullptr) ? p_arb->m_droite : p_arb->m_gauche;
        delete sentinelle;
        this->m_cardinalite--;
    }
    balancer(p_arb);
    miseAJourHauteur(p_arb);
}

template<typename E>
void Arbre<E>::enleverSuccMinDroite(Noeud *& p_arb)
{
    Noeud * minimum = p_arb->m_droite;
    while (minimum->gauche != nullptr)
    {
        minimum = minimum->m_gauche;
    }
    p_arb->m_data = minimum->m_data;
    _enleverAVL(&minimum, minimum->data);
}

/**
 * \brief Indique si l'arbre est AVL
 * \post L'arbre est inchangé
 * \return Bool indiquant si l'arbre est AVL
 */
template<typename E>
bool Arbre<E>::estAVL() const {
    return _estAVL(this->m_racine);
}

template<typename E>
bool Arbre<E>::estAVL(const Noeud *& p_arb) const {
    bool estAVL = p_arb == nullptr;
    if (!estAVL)
    {
        estAVL = std::abs(hauteur(p_arb->m_gauche) - hauteur(p_arb->droite)) <= 1
                 && estAVL(p_arb->m_gauche)
                 && estAVL(p_arb->m_droite);
    }
    return estAVL;
}

} //Fin du namespace
