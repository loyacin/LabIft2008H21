#include <vector>

namespace labTris {

    template<typename E>
    void triFusion(std::vector<E> & p_v)
    {
        if (p_v.size() <= 1)
        {
            return;
        }
        std:vector<E> temp(p_v.size());
        mergeSort(p_v, temp, 0, p_v.size() - 1);
    }

    template<typename E>
    void mergeSort(std::vector<E> & originalElements, std::vector<E> & tempElements, size_t left, size_t right)
    {
        if (left < right)
        {
            size_t center = (left + right) / 2;
            mergeSort(originalElements, tempElements, left, center);
            mergeSort(originalElements, tempElements, center + 1, right);
            merge(originalElements, tempElements, left, center + 1, right);
        }
    }

    template<typename E>
    void merge(std::vector<E> & originalElements,
               std::vector<E> & tempElements,
               size_t leftStart,
               size_t rightStart,
               size_t end)
    {
        size_t leftEnd = rightStart - 1;
        size_t insertionPosition = leftStart;
        size_t nbElements = end - leftStart + 1;
        while (leftStart <= leftEnd && rightStart <= end)
        {
            if (originalElements[leftStart] <= originalElements[rightStart])
            {
                tempElements[insertionPosition++] = originalElements[leftStart++];
            }
            else
            {
                tempElements[insertionPosition++] = originalElements[rightStart++];
            }
        }
        while (leftStart <= leftEnd)
        {
            tempElements[insertionPosition++] = originalElements[leftStart++];
        }
        while (rightStart <= end)
        {
            tempElements[insertionPosition++] = originalElements[rightStart++];
        }
        for (size_t i = 0; i < nbElements; i++, end--)
        {
            originalElements[end] = tempElements[end];
        }
    }

} // Fin namespace
