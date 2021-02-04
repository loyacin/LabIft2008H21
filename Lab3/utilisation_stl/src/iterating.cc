#include <iostream>
#include <vector>
#include <list>


int main(int argc, char **argv) {
  std::vector<int> v {1, 2, 3, 4, 5};

  /* iteration for-range-loop style */
  for(int &i: v) {
    std::cout << i << std::endl;
  }

  /* manual iteration style */
  for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }

  /* 1. faites le même exercice pour std::list */
  /* 2. itérez maintenant par index sur le vecteur */
  /* 3. écrivez une fonction template qui effectue le même travail d'impression,
     peu importe le conteneur itérable que vous lui passez par référence */

  return 0;
}
