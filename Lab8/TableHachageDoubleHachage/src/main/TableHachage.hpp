#include <cmath>
#include "ContratException.h"
#include "TableHachage.h"


namespace labTableHachage {

template<typename TypeClef, typename TypeElement, class FoncteurHachage1,
		class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::afficher(
		std::ostream & p_out) const {
	p_out << "{";
	for (size_t i = 0; i < m_tab.size(); ++i) {
		if (m_tab[i].m_info == OCCUPE) {
			p_out << m_tab[i] << ",";
		}
	}
	p_out << "}";
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1,
		class FoncteurHachage2>
int TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_prochainPremier(
		int p_entier) const {
	if (p_entier % 2 == 0) {
		p_entier++;
	}
	while (!_estPremier(p_entier)) {
		p_entier += 2;
	}
	return p_entier;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1,
		class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_estPremier(
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

template<typename TClef, typename TElement, class FHachage1, class FHachage2>
std::ostream& operator<<(std::ostream& p_out,
		const TableHachage<TClef, TElement, FHachage1, FHachage2> & p_source) {
	p_source.afficher(p_out);
	return p_out;
}

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::TableHachage(size_t size):
        m_tab(this->_prochainPremier(size)), m_cardinalite(0), m_nInsertions(0), m_nCollisions(0)
    {
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::inserer(const TypeClef & key,
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

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::enlever(const TypeClef & key)
    {
        PRECONDITION(contient(key));
        size_t position = _trouverPositionClef(key);
        this-m_tab[position].m_info = EFFACE;
        this->m_cardinalite--;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::contient(const TypeClef & key) const
    {
        size_t position = _trouverPositionClef(key);
        EtatEntree state = this->m_tab[position].m_info;
        return state == OCCUPE;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    TypeElement TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::element(const TypeClef & key) const
    {
        PRECONDITION(contient(key));
        size_t position = _trouverPositionClef(key);
        return this->m_tab[position].m_el;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::rehacher()
    {
        std::vector<EntreeHachage> existingEntries = getEntries();
        this->m_tab.resize(_prochainPremier(2 * this->m_tab.size()));
        this->vider();
        inserer(existingEntries);
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::vider()
    {
        for (auto & entry : this->m_tab)
        {
            entry.m_info = VACANT;
        }
        this->m_cardinalite = 0;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    int TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::taille() const
    {
        return this->m_cardinalite;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    double TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::statistiques() const
    {
        double stat = 0;
        if (this->m_nInsertions > 0)
        {
            stat = (double) this->m_nCollisions / (double) this->m_nInsertions;
        }
        return stat;
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    size_t
    TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_trouverPositionLibre(const TypeClef & key)
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

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_trouverPositionClef(
            const TypeClef & key) const
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

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::hashKeyWithCollisions(const TypeClef & key, long numberOfCollisions)
    {
        size_t secondHash = this->m_hachage2(key);
        if (secondHash == 0)
        {
            secondHash = 1;
        }
        return (this->m_hachage1(key) + numberOfCollisions * secondHash) % this->m_tab.size();
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::mustRehash()
    {
        /*
         * cardi / taille >= 50%
         * cardi / taille >= 0.5
         * cardi / taille >= 50 / 100
         * cardi / taille >= TAUX_MAX / 100
         * 100 * cardi / taille >= TAUX_MAX
         * 100 * cardi >= TAUX_MAX * taille
         */
        return 100 * this->m_cardinalite >= TAUX_MAX * this->m_tab.size();
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    void
    TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::inserer(const std::vector<EntreeHachage> & entries)
    {
        for (auto & entry : entries)
        {
            inserer(entry.m_clef, entry.m_el);
        }
    }

    template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
    std::vector<EntreeHachage> TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::getEntries()
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

