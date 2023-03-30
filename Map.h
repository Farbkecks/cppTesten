#pragma once

#include <vector>

struct Coordinate
{
    Coordinate() = delete;
    Coordinate(int x, int y)
            : x(x), y(y) {}
    int x{}, y{};
};

class Map {
public:
    explicit Map(int x);
    void show() const;
    void add(Coordinate const & coord, int value);
    void add(int x, int y, int value);

    struct Iterator{

        Iterator(std::vector<int>* ptr_x, int* ptr_y, int scale) : ptr_x(ptr_x),ptr_y(ptr_y), scale(scale) {}

        int& operator*() const { return *ptr_y; }

        // Prefix increment
        Iterator& operator++();

        friend bool operator== (const Iterator& a, const Iterator& b) { return (a.ptr_x == b.ptr_x && a.ptr_y == b.ptr_y); };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return (a.ptr_x != b.ptr_x && a.ptr_y != b.ptr_y); };

        std::vector<int>* ptr_x;
        int* ptr_y;
        int scale;
    };

    auto begin() { return Iterator(&map[0], &map[0][0], scale); }
    auto end()   { return Iterator(&map[scale],&map[scale][scale], scale); } // 200 is out of bounds

    std::vector<std::vector<int>> map;
    const int scale;
};

