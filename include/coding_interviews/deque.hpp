#if !defined(CODING_INTERVIEWS_ALGORITHMS_DEQUE)
#define CODING_INTERVIEWS_ALGORITHMS_DEQUE

/**
 * Double-ended queue implemented with a growable circular buffer.
 */
namespace PAJS
{
  template <typename T> class Deque
  {
  public:
    Deque(size_t initial_size = 0);

    void push_back(const T &val);
    void push_front(const T &val);
    void pop_back();
    void pop_front();

    T& back();
    T& front();
    T& at(size_t index);
    const T& back() const;
    const T& front() const;
    const T& back(size_t index) const;
  private:
    size_t m_size;

  }
}

#endif // CODING_INTERVIEWS_ALGORITHMS_DEQUE
