#include <cmath>
#include "ContratException.h"
#include "TableHachage.h"


namespace labTableHachage {


template<typename TypeClef, typename TypeElement, class FoncteurHachage>
void TableHachage<TypeClef, TypeElement, FoncteurHachage>::afficher(
		std::ostream & p_out) const {
	p_out << "{";
	for (size_t i = 0; i < m_tab.size(); ++i) {
		if (m_tab[i].m_info == OCCUPE) {
			p_out << m_tab[i] << ",";
		}
	}
	p_out << "}";
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage>
int TableHachage<TypeClef, TypeElement, FoncteurHachage>::_prochainPremier(
		int p_entier) const {
	if (p_entier % 2 == 0) {
		p_entier++;
	}
	while (!_estPremier(p_entier)) {
		p_entier += 2;
	}
	return p_entier;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage>::_estPremier(
		int p_entier) const {
	if (p_entier <= 1) {
		return false;
	}
	if (p_entier == 2) {             // le seul nombre premier pair
		return true;
	}
	if (p_entier % 2 == 0) {   // sinon, ce n'est pas un nombre premier
		return false;
	}

	int divisor = 3;
	int upperLimit = static_cast<int>(sqrt((float) p_entier) + 1);

	while (divisor <= upperLimit) {
		if (p_entier % divisor == 0) {
			return false;
		}
		divisor += 2;
	}
	return true;
}

template<typename TClef, typename TElement, class FHachage>
std::ostream& operator<<(std::ostream& p_out,
		const TableHachage<TClef, TElement, FHachage> & p_source) {
	p_source.afficher(p_out);
	return p_out;
}

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    TableHachage<TypeClef, TypeElement, FoncteurHachage>::TableHachage(size_t size) :
        m_tab(this->_prochainPremier(size)), m_cardinalite(0), m_nInsertions(0), m_nCollisions(0)
    {

    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage>::inserer(const TypeClef & key,
                                                                       const TypeElement & element)
    {
        PRECONDITION(!contient(key));
        size_t position = _trouverPositionLibre(key);
        EntreeHachage entry(key, element, OCCUPE);
        this->m_tab[position] = entry;
        this->m_nInsertions++;
        this->m_cardinalite++;
        if (mustRehash()) {
            this->rehacher();
        }
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage>::enlever(const TypeClef & key)
    {
        PRECONDITION(contient(key));
        size_t position = _trouverPositionClef(key);
        this-m_tab[position].m_info = EFFACE;
        this->m_cardinalite--;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    bool TableHachage<TypeClef, TypeElement, FoncteurHachage>::contient(const TypeClef & key) const
    {
        size_t position = _trouverPositionClef(key);
        EtatEntree state = this->m_tab[position].m_info;
        return state == OCCUPE;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    TypeElement TableHachage<TypeClef, TypeElement, FoncteurHachage>::element(const TypeClef &) const
    {
        return nullptr;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage>::rehacher()
    {

    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage>::vider()
    {

    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    int TableHachage<TypeClef, TypeElement, FoncteurHachage>::taille() const
    {
        return 0;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    double TableHachage<TypeClef, TypeElement, FoncteurHachage>::statistiques() const
    {
        return 0;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    bool TableHachage<TypeClef, TypeElement, FoncteurHachage>::mustRehash()
    {
        return 100 * this->m_cardinalite >= TAUX_MAX * this->m_tab.size();
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    size_t TableHachage<TypeClef, TypeElement, FoncteurHachage>::_trouverPositionLibre(const TypeClef & key)
    {
        long numberOfCollisions = 0;
        size_t position = hashKeyWithCollisions(key, numberOfCollisions);
        while(this->m_tab[position].m_info == OCCUPE)
        {
            numberOfCollisions++;
            position = hashKeyWithCollisions(key, numberOfCollisions);
        }
        this->m_nCollisions += numberOfCollisions;
        return position;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    size_t TableHachage<TypeClef, TypeElement, FoncteurHachage>::_trouverPositionClef(const TypeClef & key) const
    {
        long collisions = 0;
        size_t position = hashKeyWithCollisions(key, collisions);
        auto elem = this->m_tab[position];
        while(elem.m_info != VACANT && elem.m_clef != key)
        {
            collisions++;
            position = hashKeyWithCollisions(key, collisions);
            elem = this->m_tab[position];
        }
        return position;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    size_t TableHachage<TypeClef, TypeElement, FoncteurHachage>::hashKeyWithCollisions(const TypeClef &key,
                                                                                       long numberOfCollisions)
    {
        return (this->m_hachage1(key) + numberOfCollisions ** 2) % this->m_tab.size();
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage>::inserer(const std::vector<EntreeHachage> & entries)
    {
        for (auto & entry : entries)
        {
            inserer(entry.m_clef, entry.m_el);
        }
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage>
    std::vector<EntreeHachage> TableHachage<TypeClef, TypeElement, FoncteurHachage>::getEntries()
    {
        std::vector<EntreeHachage> existingEntries;
        for (auto & entry : this->m_tab)
        {
            if (entry.m_info == OCCUPE)
            {
                existingEntries.push_back(entry);
            }
        }
        return existingEntries;
    }

} //Fin du namespace

