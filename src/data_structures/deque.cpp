#include <iostream>
#include "deque.hpp"

int main()
{
  PAJS::Deque<int> d;

  for (int i = 0; i < 5; i++) {
    d.push_back(i);
    const int& elem = d.back();
    std::cout << "Back: " << elem << " (pushed " << i << ")\n";
  }
  std::cout << std::flush;

}

namespace PAJS
{
  template <typename T>
  Deque<T>::Deque(size_t initial_size = 0) : m_size{initial_size}
  {

  }
}
