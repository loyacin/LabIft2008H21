#include <iostream>


template <typename element_type>
class Array {
  size_t size_;
  element_type *data;
  friend class iterator;

  class iterator {
    Array &array;
    size_t position;
    friend class Array;

    inline iterator(Array &array, const size_t &position): array(array), position(position) {}

  public:
    inline iterator &operator ++ () { // pré-incrément
      // 1.
      ++position;

      return *this;
    }

    inline iterator &operator ++ (int) { // post-incrément
      // 2.
      position++;

      return *this;
    }

    inline element_type &operator * () {
      // 3.
      return *(array.data + position);
    }

    inline const element_type &operator * () const {
      // 4.
      return **this;
    }

    inline bool operator == (const iterator &other) const {
      // 5.
      return position == other.position;
    }

    inline bool operator != (const iterator &other) const {
      return !(*this == other);
    }
  };

public:
  inline Array(size_t size): size_(size), data(new element_type [size]) {}

  inline iterator begin() {
    // 6.
    return iterator(*this, 0);
  }

  inline iterator end() {
    // 7.
    return iterator(*this, size_);
  }

  inline size_t size() const {
    return size_;
  }
};


int main(int argc, char **argv) {
  Array<int> array(10);

  for(auto &element: array) {
    std::cout << element << std::endl;
  }

  return 0;
}
