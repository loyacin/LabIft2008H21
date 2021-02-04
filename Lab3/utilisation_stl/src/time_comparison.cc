#include <iostream>
#include <vector>
#include <chrono>
#include <type_traits>

#define LENGTH 1000000

class NonTriviallyCopyable {
  int i;

public:
  inline NonTriviallyCopyable(int _i): i(_i) {}

  inline NonTriviallyCopyable(const NonTriviallyCopyable &ntc): i(ntc.i) {}

  inline operator int () {
    return i;
  }
};


void fill_vector(std::vector<NonTriviallyCopyable> &vector) {
  for(int i = 0; i < LENGTH; ++i) {
    vector.push_back(i);
  }
}


void function_byvalue(std::vector<NonTriviallyCopyable> vector) {
}

void function_byref(std::vector<NonTriviallyCopyable> &vector) {
}


std::vector<NonTriviallyCopyable> function_return() {
  std::vector<NonTriviallyCopyable> tmp_vector;
  fill_vector(tmp_vector);

  return tmp_vector;
}

void function_fill(std::vector<NonTriviallyCopyable> &vector) {
  fill_vector(vector);
}

void function_swap(std::vector<NonTriviallyCopyable> &vector) {
  std::vector<NonTriviallyCopyable> tmp_vector;
  fill_vector(tmp_vector);

  vector.swap(tmp_vector);
}

void function_move(std::vector<NonTriviallyCopyable> &vector) {
  std::vector<NonTriviallyCopyable> tmp_vector;
  fill_vector(tmp_vector);

  vector = std::move(tmp_vector);
}

void function_assign(std::vector<NonTriviallyCopyable> &vector) {
  std::vector<NonTriviallyCopyable> tmp_vector;
  fill_vector(tmp_vector);

  vector = tmp_vector;
}


template<typename duration_type = std::chrono::nanoseconds, typename callable_type>
std::ostream &time_experiment(const std::string &title,
                              std::ostream &os,
                              callable_type callable) {
  std::chrono::high_resolution_clock clock;
  auto t0 = clock.now();

  callable();

  auto t1 = clock.now();
  auto duration = std::chrono::duration_cast<duration_type>(t1 - t0);
  os << title << ':' << " Took " << duration.count() << " nanoseconds" << std::endl;

  return os;
}

int main() {
  // Vérifier que la classe n'est pas triviallement copiable
  std::cout << std::boolalpha << std::is_trivially_copyable<int>() << std::endl;
  std::cout << std::boolalpha << std::is_trivially_copyable<NonTriviallyCopyable>() << std::endl;

  std::cout << std::endl;


  // vérifier la différence entre le passage par valeur vs reference
  time_experiment("byvalue", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;
      fill_vector(v);

      function_byvalue(v);
    });

  time_experiment("byref  ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;
      fill_vector(v);

      function_byref(v);
    });

  std::cout << std::endl;


  // vérifier la différence entre le retour par valeur et
  // les autres facons de retourner par paramètre présentées
  time_experiment("return ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;

      v = function_return();
    });

  time_experiment("fill   ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;

      function_fill(v);
    });

  time_experiment("swap   ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;

      function_swap(v);
    });

  time_experiment("move   ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;

      function_move(v);
    });

  time_experiment("assign ", std::cout, [&]() {
      std::vector<NonTriviallyCopyable> v;

      function_assign(v);
    });


  /*1. rouler plusieurs fois le code, qu'observez-vous? */
  /*2. ajouter un appel à v.reserve(LENGTH), après chaque déclaration de v, que se passe-t-il avec le temps d'exécution? */

  return 0;
}
