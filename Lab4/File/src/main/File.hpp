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

} //Fin du namespace
