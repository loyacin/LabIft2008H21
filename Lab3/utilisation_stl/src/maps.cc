#include <iostream>
#include <string>
#include <map>


int main(int argc, char **argv) {
  std::map<std::string, int> map {
    {"1", 1},
    {"2", 2},
    {"3", 3},
  };

  // accéder à une valeur par sa clef et l'opérateur [ ]
  std::cout << map["1"] << std::endl;

  std::cout << map.at("1") << std::endl;

  // itérable avec des std::pair constantes
  for(const std::pair<std::string, int> &pair: map) {
    std::cout << pair.first << " : " << pair.second << std::endl;
  }

  // 1. essayer l'effet de l'opérateur [ ] si la clé n'existe pas

  // 2. essayer l'effet de at() si la clé n'existe pas

  // 3. essayer d'ajouter des éléments avec [ ]

  return 0;
}
