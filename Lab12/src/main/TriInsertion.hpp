#include <vector>

namespace labTris {

    template<typename E>
    void triInsertion(std::vector<E> & p_v)
    {
        for (int i = 1; i < p_v.size(); ++i)
        {
            int j = i;
            while (j > 0 && p_v[j - 1] > p_v[j])
            {
                std::swap(p_v[j - 1], p_v[j]);
                j--;
            }
        }
    }

} // Fin namespace
