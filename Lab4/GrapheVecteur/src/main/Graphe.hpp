#include <iostream>
#include <algorithm>
#include "ContratException.h"
#include "Graphe.h"


namespace labGrapheListes {

// TODO: À compléter...

    template <typename T>
    void Graphe<T>::affiche() const {

        for (unsigned int i = 0; i < m_nbSommets; ++i) {
            std::cout << "Sommet " << i << ": ";

            for (std::list<unsigned int>::const_iterator it = m_listesAdj[i].begin(); it != m_listesAdj[i].end(); ++it) {
                std::cout << i << "->" << *it << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }

    template<typename T>
    Graphe<T>::Graphe(size_t graphSize): m_nbSommets(graphSize)
    {
        m_noms.resize(graphSize);
        m_listesAdj.resize(graphSize);

        //post veerifier les tailles.

        INVARIANTS();
    }

    template<typename T>
    Graphe<T>::~Graphe()
    {
        m_nbSommets = 0;
        m_noms.clear();
        m_listesAdj.clear();

        INVARIANTS();
    }

    template<typename T>
    void Graphe<T>::nommer(unsigned int vertexNumber, const T & name)
    {
        PRECONDITION(isVertexNumberValid(vertexNumber));
        PRECONDITION(name != NULL);

        this->m_noms[vertexNumber] = name;

        // post vrifier le nom

        INVARIANTS();
    }

    template<typename T>
    bool Graphe<T>::isVertexNumberValid(unsigned int vertexNumber) const
    {
        return vertexNumber < m_nbSommets;
    }

    template<typename T>
    void Graphe<T>::ajouterArc(unsigned int origin, unsigned int destination)
    {
        PRECONDITION(!arcExiste(origin, destination));

        this->m_listesAdj[origin].insert(destination);

        // post verifier arcExiste

        INVARIANTS();
    }

    template<typename T>
    void Graphe<T>::enleverArc(unsigned int origin, unsigned int destination)
    {
        PRECONDITION(arcExiste(origin, destination));

        this->m_listesAdj[origin].remove(destination);

        // post arc nexiste pas

        INVARIANTS();
    }

    template<typename T>
    T Graphe<T>::reqNom(unsigned int) const
    {
        return nullptr;
    }

    template<typename T>
    bool Graphe<T>::arcExiste(unsigned int, unsigned int) const
    {
        PRECONDITION(origin);
        PRECONDITION(destination);
        return false;
    }

    template<typename T>
    size_t Graphe<T>::reqNbSommets() const
    {
        return 0;
    }

    template<typename T>
    std::vector<unsigned int> Graphe<T>::listerSommetsAdjacents(unsigned int) const
    {
        return std::vector<unsigned int>();
    }

    template<typename T>
    unsigned int Graphe<T>::ordreEntreeSommet(unsigned int) const
    {
        return 0;
    }

    template<typename T>
    unsigned int Graphe<T>::ordreSortieSommet(unsigned int) const
    {
        return 0;
    }

    template<typename T>
    void Graphe<T>::verifieInvariant() const
    {

    }

} //Fin du namespace
