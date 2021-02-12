#include "ContratException.h"


namespace lab04 {

template<typename U>
std::ostream& operator <<(std::ostream& p_out, const File<U>& p_source) 
{
	p_out << "[";
	for (int i = 0; i < p_source.taille(); ++i) 
	{
		p_out << p_source[i] << ",";
	}
	p_out << "]";
	return p_out;
}

/**
 * Ce constructeur construit une file vide de la taille passee en parametre.
 * @tparam T est le type d'elements contenus dans la file.
 * @param queueSize est la taille de la nouvelle file.
 */
template<typename T>
File<T>::File(const int queueSize): m_tete{0},
                                    m_queue{0},
                                    m_tailleMax{queueSize},
                                    m_cardinalite{0}
{
    PRECONDITION(queueSize >= 0);

    this->m_tab = new T[queueSize];

    POSTCONDITION(m_tete == 0); // faire la meme chose pour les autres.

    INVARIANTS();
}

template<typename T>
File<T>::~File()
{
    delete[] m_tab;
}

template<typename T>
File<T>::File(const File<T> & queueToCopy)
{
    destruct();
    copy(queueToCopy);
}

template<typename T>
void File<T>::destruct()
{
    delete[] m_tab;
}

template<typename T>
void File<T>::copy(const File<T> & queueToCopy)
{
    this->m_tete = queueToCopy.m_tete;
    this->m_queue = queueToCopy.m_queue;
    this->m_tailleMax = queueToCopy.m_tailleMax;
    this->m_cardinalite = queueToCopy.m_cardinalite;
    this->m_tab = new T[queueToCopy.m_tailleMax];
    for (int i = 0; i < queueToCopy.m_tailleMax; i++)
    {
        this->m_tab[i] = queueToCopy.m_tab[i];
    }
}

template<typename T>
const File<T> &File<T>::operator=(const File<T> & queueToCopy)
{
    if (this != &queueToCopy)
    {
        destruct();
        copy(queueToCopy);
    }
    return *this;
}

template<typename T>
void File<T>::enfiler(const T & newElement)
{
    PRECONDITON(this->m_cardinalite < this->m_tailleMax);

    this->m_tab[this->m_queue] = newElement;
    this->m_queue = (this -> m_queue + 1) % this->m_tailleMax;
    this->m_cardinalite++;

    //postcondition
    INVARIANTS();
}

template<typename T>
T File<T>::defiler()
{
    PRECONDITION(this->m_cardinalite > 0);

    T topElement = this->m_tab[this->m_tete];
    this->m_tete = (this->m_tete + 1) % this->m_tailleMax;
    this->m_cardinalite--;

    //Post

    INVARIANTS();

    return topElement;
}

template<typename T>
int File<T>::taille() const
{
    return this->m_cardinalite;
}

template<typename T>
bool File<T>::estVide() const
{
    return this->m_cardinalite == 0;
}

template<typename T>
bool File<T>::estPleine() const
{
    return this->m_cardinalite == this->m_tailleMax;
}

template<typename T>
const T &File<T>::premier() const
{
    PRECONDITION(this->m_cardinalite > 0);
    return this->m_tab[this->m_tete];
}

template<typename T>
const T &File<T>::dernier() const
{
    PRECONDITION(this->m_cardinalite > 0);
    int lastElementIndex = (this->m_tete + this->m_cardinalite - 1) % this->m_tailleMax;
    return this->m_tab[lastElementIndex];
}

template<typename T>
T File<T>::operator[](const int & index) const
{
    PRECONDITION(index >= 0);
    PRECONDITION(index < this->m_tailleMax);

    return this->m_tab[index];
}

template<typename T>
void File<T>::verifieInvariant() const
{
    INVARIANT(this->m_tete >= 0);
    INVARIANT(this->m_tete < this->m_tailleMax); // faire ca pour les autres.
}

} //Fin du namespace
