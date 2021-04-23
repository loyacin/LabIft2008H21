/**
 *
 * Les gaps choisis sont 2^k - 1 :
 * [1, 3, 7, 15, 31, 63, ... , 2^floor(log(N)/log(2)) - 1]
 *
 * Ces gaps donnent une complexité de O(N^1.5).
 *
 * REMARQUE
 *
 * Lorsque gap = 1, le tri shell devient exactement le tri insertion!
 */
#include <vector>
#include <cmath>

namespace labTris {

    template<typename E>
    void triShell(std::vector<E> & p_v) {
        auto gaps = createGaps(p_v.size());
        for (auto gap : gaps)
        {
            for (size_t i = gap; i < p_v.size(); i ++)
            {
                E temp = p_v[i];
                size_t j;
                for (j = i; j >= gap && p_v[j - gap] > temp; j -= gap)
                {
                    std::swap(p_v[j], p_v[j - gap]);
                }
                std::swap(p_v[j], p_v[i]);
            }
        }
    }

    std::vector<size_t> createGaps(size_t maximum)
    {
        auto gaps;
        for (size_t k = 1; k <= std::floor(std::log(maximum) / std::log(2)); k++) // log _2 n = log n / log 2 et a ^ (log _a b) = b
        {
            gaps.push_back(std::pow(2, k) - 1);
        }
        return gaps;
    }

} // Fin namespace
