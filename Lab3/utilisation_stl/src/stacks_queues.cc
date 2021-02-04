#include <iostream>
#include <stack>
#include <queue>


int main(int argc, char **argv) {
  std::stack<int> stack;

  /* empiler */
  for(int i: {1, 2, 3, 4, 5, 6, 7}) {
    stack.push(i);
  }

  /* dépiler */
  while(!stack.empty()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }

  /* 1. observer l'effet actuel */
  /* 2. refaire l'exercice précédent avec une std::queue et voir l'effet */
  /* N.B.: Utiliser .back() et .front() au lieu de .top() */

  return 0;
}
