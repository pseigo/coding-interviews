#if !defined(CODING_INTERVIEWS_DATA_STRUCTURES_DEQUE)
#define CODING_INTERVIEWS_DATA_STRUCTURES_DEQUE

#include <memory>

/**
 * Double-ended queue implemented with a growable circular buffer. Not thread
 * safe.
 */
namespace PAJS
{
  template <typename T> class Deque
  {
  public:
    Deque(size_t initial_size = 0);

    void push_back(const T &val);
    // void push_front(const T &val);
    void pop_back();
    // void pop_front();

    // T& back();
    // T& front();
    // T& at(size_t index);
    const T& back() const;
    // const T& front() const;
    // const T& at(size_t index) const;

    bool empty() const;
    size_t size() const;
    size_t max_size() const;

  private:
    bool full() const;
    size_t offsetIndex(size_t index, ssize_t offset) const;
    void expand();
    void resize(size_t size);

    static constexpr size_t M_GROWTH_FACTOR = 2;

    size_t m_max_size;
    size_t m_actual_max_size;
    std::unique_ptr<T[]> m_array;
    size_t m_frontIndex;
    size_t m_backIndex;
  };
}

#endif // CODING_INTERVIEWS_DATA_STRUCTURES_DEQUE
