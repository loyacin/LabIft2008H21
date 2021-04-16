#include <vector>

namespace labTris {

    template<typename E>
    void triSelection(std::vector<E> & p_v)
    {
        for (size_t i = 0; i < p_v.size(); i++)
        {
            size_t minimumPosition = i;
            for (size_t j = minimumPosition + 1; j < p_v.size(); j++)
            {
                if (p_v[minimumPosition] > p_v[j])
                {
                    minimumPosition = j;
                }
            }
            std::swap(p_v[i], p_v[minimumPosition]);
        }
    }

} // Fin namespace

