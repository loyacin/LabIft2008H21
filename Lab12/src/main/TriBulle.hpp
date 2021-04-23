#include <vector>
#include <cstddef>

namespace labTris {

    template<typename E>
    bool shakeStartEnd(const std::vector<E> &p_v);

    template<typename E>
    bool shakeEndStart(const std::vector<E> &p_v);

    template<typename E>
    void triBulle(std::vector<E> & p_v) {
        bool swapped;
        do
        {
            swapped = shakeStartEnd(p_v);
            if (!swapped) {
                break;
            }
            swapped = shakeEndStart(p_v);
        } while (swapped);
    }

    template<typename E>
    bool shakeEndStart(const std::vector<E> &p_v)
    {
        bool swapped = false;
        for (size_t i = p_v.size() - 2; i >= 0; i--)
        {
            if (p_v[i] > p_v[i + 1])
            {
                std::swap(p_v[i], p_v[i + 1]);
                swapped = true;
            }
        }
        return swapped;
    }

    template<typename E>
    bool shakeStartEnd(const std::vector<E> &p_v)
    {
        bool swapped = false;
        for (size_t i = 0; i < p_v.size() - 2; i++)
        {
            if (p_v[i] > p_v[i + 1])
            {
                std::swap(p_v[i], p_v[i + 1]);
                swapped = true;
            }
        }
        return swapped;
    }

} // Fin namespace
