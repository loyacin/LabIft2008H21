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

    }

    template<typename T>
    void Pile<T>::empiler(const T &)
    {

    }

    template<typename T>
    T Pile<T>::depiler()
    {
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
    T Pile<T>::operator[](const int &) const
    {
        return nullptr;
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
