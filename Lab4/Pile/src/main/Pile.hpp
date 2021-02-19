#include "ContratException.h"
#include "Pile.h"


namespace lab04 {

// À compléter ...

template<typename T>
std::ostream & operator <<(std::ostream & p_out, const Pile<T> & p_source) 
{
	typename Pile<T>::Noeud * tmp = p_source.m_sommet;
	p_out << "Pile: [";
	while (tmp != NULL) 
	{
		p_out << tmp->m_el;
		if (tmp->m_suivant != nullptr)
			p_out << ",";
		tmp = tmp->m_suivant;
	}
	p_out << "]";
	return p_out;
}

    template<typename T>
    int Pile<T>::taille() const
    {
        return 0;
    }

    template<typename T>
    Pile<T>::Pile()
    {

    }

    template<typename T>
    Pile<T>::Pile(const Pile &)
    {

    }

    template<typename T>
    Pile<T>::~Pile()
    {
        destruct(m_sommet)
    }

    if (sommet != m_sommet && sommet->suivant != nullptr)
        destruct(sommet -> suivant)
    ladestruction

    template<typename T>
    void Pile<T>::empiler(const T &)
    {

    }

    template<typename T>
    T Pile<T>::depiler()
    {
        /**
         * 1. retrouver l element du sommet
         * 2. creer une sentinelle sur le sommet
         * 3. sommet = sommet->m_suivant
         * 4. ladestruction(sentinelle)
         */
        return nullptr;
    }

    template<typename T>
    bool Pile<T>::estVide() const
    {
        return false;
    }

    template<typename T>
    const T &Pile<T>::top() const
    {
        return this->m_sommet->m_el;
    }

    template<typename T>
    T Pile<T>::operator[](const int & index) const
    {
        PRECONDITION(index >= 0);
        PRECONDITION(index < this->m_cardinalite);

        elem sentinelle = this->m_sommet;
        for (int i = 0; i < index; i++)
        {
            sentinelle = sentinelle->m_suivant;
        }
        return sentinelle->m_el;
    }

    template<typename T>
    const Pile <T> &Pile<T>::operator=(const Pile <T> &)
    {
        return Pile();
    }

    template<typename T>
    void Pile<T>::verifieInvariant() const
    {

    }

// Méthodes privées


} //Fin du namespace
