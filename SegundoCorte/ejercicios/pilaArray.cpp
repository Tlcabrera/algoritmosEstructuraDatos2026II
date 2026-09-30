#include <cassert>
#include <memory>
#include <utility>

template <class T>
class ArrayStack {
    std::unique_ptr<T[]> a;
    size_t n = 0, cap = 0;

    void resize(size_t c) {
        std::unique_ptr<T[]> b(new T[c]);
        for (size_t i = 0; i < n; ++i) b[i] = std::move(a[i]);
        a = std::move(b);
        cap = c;
    }

public:
    void push(const T& x) {
        if (n == cap) resize(cap ? 2 * cap : 4);
        a[n++] = x;
    }
    void pop() {
        assert(n > 0);
        --n;
        if (cap > 4 && n <= cap / 4) resize(cap / 2);
    }
    T& top() { assert(n > 0); return a[n - 1]; }
    bool empty() const { return n == 0; }
    size_t size() const { return n; }
};