#include <vector>
#include "ContratException.h"


namespace labParcoursArbre {

// À compléter ...

template<typename E>
Arbre<E>::Arbre(const std::vector<E> & p_visiteSymetrique, const std::vector<E>& p_visitePere) {
	m_racine = _auxPereSym(p_visiteSymetrique.begin(), p_visiteSymetrique.end(), p_visitePere.begin(), p_visitePere.end());
}


template<typename E>
typename Arbre<E>::Noeud*
Arbre<E>::_auxPereSym(constVecItr& p_debutS, constVecItr& p_finS, constVecItr& p_debutP, constVecItr& p_finP) {

	PRECONDITION(std::distance(p_debutS, p_finS) == std::distance(p_debutP, p_finP));

	// Condition d'arret
	if (p_debutS == p_finS)
		return NULL;

	// Le premier element de tabP est la racine de l'arbre
	Noeud* nouveau = new Noeud(*p_debutP);

	// Recherche de la racine de l'arbre dans tabS. Apres cette boucle:
	// - iterS pointe sur la racine de l'arbre dans tabS;
	// - iterP pointe sur la racine du fils droit dans tabP;
	vecItr iterS = p_debutS;
	vecItr iterP = p_debutP + 1;
	while (*iterS != *p_debutP && iterS != p_finS) {
		++iterS;
		++iterP;
	}

	// Construction recursives des sous-arbres gauche et droit
	nouveau->m_gauche = _auxPereSym(p_debutS, iterS, p_debutP + 1, iterP);
	nouveau->m_droite = _auxPereSym(iterS + 1, p_finS, iterP, p_finP);

	return nouveau;
}

    template<typename E>
    Arbre<E>::Arbre()
    {

    }

    template<typename E>
    Arbre<E>::Arbre(E * parcoursSymetrique, int begin, int end, E ** parcoursPreOrdre)
    {
        this->m_racine = _auxPereSym(parcoursSymetrique, begin, end, parcoursPreOrdre);
    }

    template<typename E>
    Arbre<E>::Arbre(const std::vector<E> &, const std::vector<E> &)
    {

    }

    template<typename E>
    Arbre<E>::Arbre(const Arbre &)
    {

    }

    template<typename E>
    Arbre<E>::~Arbre()
    {

    }

    template<typename E>
    const Arbre &Arbre<E>::operator=(const Arbre &)
    {
        return <#initializer#>;
    }

    template<typename E>
    std::vector<E> Arbre<E>::listerPreOrdre() const
    {
        return _listerPreOrdre(this->m_racine);
    }

    template<typename E>
    std::vector<E> Arbre<E>::listerEnOrdre() const
    {
        return _listerEnOrdre(this->m_racine);
    }

    template<typename E>
    std::vector<E> Arbre<E>::listerPostOrdre() const
    {
        return _listerPostOrdre(this->m_racine);
    }

    template<typename E>
    std::vector<E> Arbre<E>::listerParNiveau() const
    {
        std::vector<E> data;
        std::queue<Noeud*> visitedNodes;
        visitedNodes.push(this-m_racine);
        while (!visitedNodes.empty())
        {
            Noeud * sentinelle = visitedNodes.front();
            visitedNotes.pop();
            if (sentinelle != nullptr)
            {
                data.push_back(sentinelle->m_data);
                visitedNotes.push(sentinelle->m_gauche);
                visitedNotes.push(sentinelle->m_droite);
            }
        }
        return data;
    }

    template<typename E>
    void Arbre<E>::verifieInvariant() const
    {

    }

    template<typename E>
    Arbre::Noeud *Arbre<E>::_auxPereSym(
    <unknown> &, <unknown> &, <unknown> &, <unknown> &)
{
    return nullptr;
}

template<typename E>
Arbre::Noeud *Arbre<E>::_auxPereSym(E * parcoursSymetrique, int begin, int end, E ** parcoursPreOrdre) const
{
    Arbre::Noeue * seed = nullptr;
    if (begin <= end)
    {
        E seedData = **parcoursPreOrdre;
        seed = new Noeud(seedData);
        int seedPosition = getSeedPosition(parcoursSymetrique, seedData);
        (*parcoursPreOrdre)++;
        seed->m_gauche = _auxPereSym(parcoursSymetrique, begin, seedPosition - 1, parcoursPreOrdre);
        seed->m_droite = _auxPereSym(parcoursSymetrique, seedPosition + 1, end, parcoursPreOrdre);
    }
    return seed;
}

template<typename E>
int Arbre<E>::getSeedPosition(E * parcoursSymetrique, const E & seed) const
{
    int position = 0;
    while (parcoursSymetrique[position] != seed)
    {
        position++;
    }
    return position;
}

template<typename E>
std::vector<E> Arbre<E>::_listerEnOrdre(Arbre::Noeud * node) const
{
    std::vector<E> nodeData;
    if (node != nullptr)
    {
        std::vector<E> leftNodeData = _listerPreOrdre(node->m_gauche);
        nodeData.insert(nodeData.cend(), leftNodeData.cbegin(), leftNodeData.cend());
        nodeData.push_back(node->m_data);
        std::vector<E> RightNodeData = _listerPreOrdre(node->m_droite);
        nodeData.insert(nodeData.cend(), RightNodeData.cbegin(), RightNodeData.cend());
    }
    return nodeData;
}

template<typename E>
std::vector<E> Arbre<E>::_listerPreOrdre(Arbre::Noeud * node) const
{
    std::vector<E> nodeData;
    if (node != nullptr)
    {
        nodeData.push_back(node->m_data);
        std::vector<E> leftNodeData = _listerPreOrdre(node->m_gauche);
        nodeData.insert(nodeData.cend(), leftNodeData.cbegin(), leftNodeData.cend());
        std::vector<E> RightNodeData = _listerPreOrdre(node->m_droite);
        nodeData.insert(nodeData.cend(), RightNodeData.cbegin(), RightNodeData.cend());
    }
    return nodeData;
}

template<typename E>
std::vector<E> Arbre<E>::_listerPostOrdre(Arbre::Noeud *) const
{
    std::vector<E> nodeData;
    if (node != nullptr)
    {
        std::vector<E> leftNodeData = _listerPreOrdre(node->m_gauche);
        nodeData.insert(nodeData.cend(), leftNodeData.cbegin(), leftNodeData.cend());
        std::vector<E> RightNodeData = _listerPreOrdre(node->m_droite);
        nodeData.insert(nodeData.cend(), RightNodeData.cbegin(), RightNodeData.cend());
        nodeData.push_back(node->m_data);
    }
    return nodeData;
}

}            //Fin du namespace
