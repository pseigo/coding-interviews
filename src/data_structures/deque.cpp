#include <iostream>
#include <deque>
#include "deque.hpp"

int main()
{
  PAJS::Deque<int> d(6);

  for (int i = 1; i < 8; i++) {
    d.push_back(i);
    const int& elem = d.back();
    std::cout << "Back: " << elem << " (pushed " << i
      << ". size: " << d.size()
      << ". max size: " << d.max_size() << ")\n";
  }
  std::cout << std::flush;

  for (int i = 0; i < 10; i++) {
    d.pop_back();
    const int& elem = d.back();
    std::cout << "New back: " << elem << " (size: " << d.size()
      << ". max size: " << d.max_size() << ")\n";
  }
  std::cout << std::flush;

  // Testing the std deque.
  // std::deque<int> sd;
  // sd.push_back(42);
  // std::cout << &(sd.back()) << std::endl;
  // sd.pop_back();
  // std::cout << &(sd.back()) << std::endl;
  // std::cout << &(sd.back()) << std::endl;
  // sd.pop_back();
  // std::cout << &(sd.back()) << std::endl;
}

namespace PAJS
{
  /* Public interface */
  template <typename T>
  Deque<T>::Deque(size_t initial_size) :
    m_max_size{initial_size},
    m_actual_max_size{initial_size + 1}
  {
    m_frontIndex = 3;
    m_backIndex = 3;

    if (initial_size) {
      m_array = std::make_unique<T[]>(m_actual_max_size);
      std::fill_n(m_array.get(), m_actual_max_size, 0);
    } else {
      m_array = nullptr;
    }
  }

  template <typename T>
  void Deque<T>::push_back(const T& val)
  {
    if (full()) {
      // TODO: Uncomment expand() once implemented.
      // expand();
      return;
    }

    m_array[m_backIndex] = val;
    m_backIndex = offsetIndex(m_backIndex, 1);
  }

  template <typename T>
  void Deque<T>::pop_back()
  {
    if (empty()) {
      return;
    }

    // TODO: Memory leak? Is there some way to "free" a generic element and
    // is that something we'd even want to do? We could just leave it in
    // memory.
    m_backIndex = offsetIndex(m_backIndex, -1);
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

  template <typename T>
  bool Deque<T>::empty() const
  {
    return (m_array == nullptr) || (size() == 0);
  }

  template <typename T>
  size_t Deque<T>::size() const
  {
    if (m_frontIndex <= m_backIndex) {
      return m_backIndex - m_frontIndex;
    } else {
      return m_actual_max_size - (m_frontIndex - m_backIndex);
    }
    return 0;
  }

  template <typename T>
  size_t Deque<T>::max_size() const
  {
    return m_max_size;
  }

  /* Private helpers */
  template <typename T>
  bool Deque<T>::full() const
  {
    size_t fullIndex = offsetIndex(m_frontIndex, -1);
    return (m_array != nullptr) && (m_backIndex == fullIndex);
  }

  // TODO: CLean up
  template <typename T>
  size_t Deque<T>::offsetIndex(size_t index, ssize_t offset) const
  {
    const size_t steps = abs(offset) % m_actual_max_size;

    if (offset > 0) {
      if (index + steps >= m_actual_max_size) { // Will wrap around
        const size_t distanceToEnd = m_actual_max_size - index - 1;
        const size_t stepsForwardFromFront = steps - distanceToEnd - 1;
        index = stepsForwardFromFront;
      } else { // Will not wrap around
        index += steps;
      }
    } else if (offset < 0) {
      if (steps > index) { // Will wrap around
        size_t stepsBackwardFromEnd = steps - index;
        index = m_actual_max_size - stepsBackwardFromEnd;
      } else { // Will not wrap around
        index -= steps;
      }
    }

    return index;
  }

  template <typename T>
  void Deque<T>::expand()
  {
    resize(m_max_size * M_GROWTH_FACTOR + 1);
  }

  /* Takes O(size) time and space. */
  template <typename T>
  void Deque<T>::resize(size_t size)
  {
    // TODO: Implement iterators so I don't have to struggle over this.
    if (size >= 0) {
      std::unique_ptr<T[]> expanded = std::make_unique<T[]>(size);

      for (size_t i = 0; i < m_actual_max_size; i++) {
        expanded[i] = m_array[i];
      }

      m_array = std::move(expanded);
      m_actual_max_size = size;
      m_max_size = m_actual_max_size - 1;
    }
  }
}
