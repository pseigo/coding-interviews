#include <iostream>
#include "deque.hpp"

int main()
{
  PAJS::Deque<int> d(5);

  for (int i = 1; i < 6; i++) {
    d.push_back(i);
    const int& elem = d.back();
    std::cout << "Back: " << elem << " (pushed " << i << ")\n";
  }
  std::cout << std::flush;

}

namespace PAJS
{
  /* Public interface */
  template <typename T>
  Deque<T>::Deque(size_t initial_size) : m_size{initial_size}
  {
    m_frontIndex = 0;
    m_backIndex = 0;

    if (initial_size) {
      m_array = std::make_unique<T[]>(initial_size);
      std::fill_n(m_array.get(), initial_size, 0);
    } else {
      m_array = nullptr;
    }
  }

  template <typename T>
  void Deque<T>::push_back(const T& val)
  {
    if (full()) {
      expand();
    }

    m_array[m_backIndex] = val;
    m_backIndex = offsetIndex(m_backIndex, 1);
  }

  template <typename T>
  const T& Deque<T>::back() const
  {
    if (empty()) {
      // Undefined behaviour
      // return T();
    }

    const auto nindex = offsetIndex(m_backIndex, -1);
    return m_array[nindex];
  }

    /* Private helpers */
  template <typename T>
  bool Deque<T>::empty() const
  {
    return (m_array == nullptr) || (m_size == 0);
  }

  template <typename T>
  bool Deque<T>::full() const
  {
    return (m_array != nullptr) && (m_frontIndex == m_backIndex);
  }

  // TODO: CLean up
  template <typename T>
  size_t Deque<T>::offsetIndex(size_t index, ssize_t offset) const
  {
    const size_t steps = abs(offset) % m_size;

    if (offset > 0) {
      if (index + steps >= m_size) { // Will wrap around
        const size_t distanceToEnd = m_size - index - 1;
        const size_t stepsForwardFromFront = steps - distanceToEnd - 1;
        index = stepsForwardFromFront;
      } else { // Will not wrap around
        index += steps;
      }
    } else if (offset < 0) {
      if (steps > index) { // Will wrap around
        size_t stepsBackwardFromEnd = steps - index;
        index = m_size - stepsBackwardFromEnd;
      } else { // Will not wrap around
        index -= steps;
      }
    }

    return index;
  }

  template <typename T>
  void Deque<T>::expand()
  {
    resize(m_size * M_GROWTH_FACTOR);
  }

  template <typename T>
  void Deque<T>::resize(size_t size)
  {
    // TODO
  }
}
