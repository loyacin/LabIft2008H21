namespace heapSort
{

    size_t leftChild(size_t parent)
    {
        return 2 * parent + 1;
    }

    template<typename E>
    size_t getGreatestChildPosition(const std::vector<E> &elements, size_t parentPosition, size_t elementsSize)
    {
        size_t leftChildPosition = leftChild(parentPosition);
        if (leftChildPosition < elementsSize - 1
            && elements[leftChildPosition] < elements[leftChildPosition + 1])
        {
            leftChildPosition++;
        }
        return leftChildPosition;
    }

    template <typename  E>
    void percDown(std::vector<E> & elements, size_t parentPosition, size_t elementsSize)
    {
        while (leftChild(parentPosition) < elementsSize)
        {
            size_t childPosition = getGreatestChildPosition(elements, parentPosition, elementsSize);
            if (elements[parentPosition] < elements[childPosition])
            {
                std::swap(elements[parentPosition], elements[childPosition]);
                parentPosition = childPosition;
            }
            else
            {
                break;
            }
        }
    }

    template <typename E>
    std::vector<E> constructHeap(const std::vector<E> & elements)
    {
        std::vector<E> heap(elements);
        if (!heap.empty())
        {
            size_t heapSize = heap.size();
            size_t lastParent = heapSize / 2 - 1;
            for (size_t i = lastParent; ; i--)
            {
                percDown(heap, i, heapSize);
                if (i == 0)
                {
                    break;
                }
            }
        }
        return heap;
    }

    template <typename E>
    void _heapSort(std::vector<E> & elementsToSort)
    {
        if (elementsToSort.empty())
        {
            return;
        }
        for (size_t i = elementsToSort.size() - 1; i > 0; i--)
        {
            std::swap(elementsToSort[0], elementsToSort[i]); // propriété tas: racine est le plus grand élément.
            percDown(elementsToSort, 0, i); // reconstruire un monceau en ignorant l'ancien plus grand élément.
        }
    }

    template <typename E>
    std::vector<E> heapSort(const std::vector<E> & elementsToSort)
    {
        std::vector<E> heapToSort = constructHeap(elementsToSort);
        _heapSort(heapToSort);
        return heapToSort;
    }
}