#pragma once

#include <vector>

class Map {
public:
    void show() const;
    void add(int x);
    explicit Map(int x);

    struct Iterator{
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;  // or also value_type*
        using reference         = int&;  // or also value_type&

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        // Prefix increment
        Iterator& operator++() { m_ptr++; return *this; }

        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
    private:

        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&map[0]); }
    Iterator end()   { return Iterator(&map[map.size()]); } // 200 is out of bounds
private:
    std::vector<int> map;
};

