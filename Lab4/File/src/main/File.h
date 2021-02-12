/**
 * \file File.h
 * \brief Classe définissant le type abstrait file
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \author Abder
 * \version 0.3
 * \date Mai 2014 et Septembre 2019
 *
 * Representation dans un tableau dynamique.
 */

#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <stdexcept>

namespace lab04 {
/**
 * \class File
 *
 * \brief classe générique représentant une File
 *
 *  La classe gère une file générique. L'implémentation
 *  se fait dans un tableau dynamique.
 */
template<typename T>
class File 
{
public:
	File(const int = MAX_FILE);
	~File();

	File(const File<T> &);
	const File<T> & operator =(const File<T> &);

	void enfiler(const T &);
	T defiler();

	int taille() const;
	bool estVide() const;
	bool estPleine() const;

	const T & premier() const;
	const T & dernier() const;

	T operator [](const int &) const;

	void verifieInvariant() const;

private:
	T *m_tab; /*!< Tableau contenant la file*/;
	int m_tete; /*!< Tete de la file*/
	int m_queue; /*!< Queue de la file (sur la position après le dernier élément)*/
	int m_tailleMax; /*!< Capacité courante de la file*/
	int m_cardinalite; /*!< Nombre d'éléments effectifs dans la file*/
	static const int MAX_FILE = 100; /*!< Capacité de la file par défaut*/
    void destruct();
};
} //Fin du namespace

#include "File.hpp"

#endif
