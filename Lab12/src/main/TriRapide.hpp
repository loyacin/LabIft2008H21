#include <vector>

namespace labTris {

    template<typename E>
    void triRapide(std::vector<E> & p_v)
    {
        _quickSort(p_v, 0, p_v.size() - 1);
    }

    template<typename E>
    void _quickSort(std::vector<E> & elements, size_t start, size_t end)
    {
        if (start < end)
        {
            size_t positionPivot = partition(elements, start, end);
            _quickSort(elements, start, positionPivot - 1);
            _quickSort(elements, positionPivot + 1, end);
        }
    }

    template<typename E>
    size_t partition(std::vector<E> & elements, size_t start, size_t end)
    {
        E pivot = elements[end];
        size_t pivotPosition = start;
        for (size_t j = start; j < end; j++)
        {
            if (elements[j] < pivot)
            {
                std::swap(elements[pivotPosition], elements[j]);
                pivotPosition++;
            }
        }
        std::swap(elements[pivotPosition], elements[end]);
        return pivotPosition;
    }

} // Fin namespace
