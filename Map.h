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
    int & getReferance(Coordinate const & coord);
    typedef std::vector<std::vector<int>> datatype;
    datatype map;
    const int scale;

    struct Iterator{

        Iterator(Coordinate coord, Map & map) : coord(coord), map(map) {}

        int& operator*() const { return map.getReferance(coord); }

        // Prefix increment
        Iterator& operator++();

        friend bool operator== (const Iterator& a, const Iterator& b) { return (a.coord.x == b.coord.x && a.coord.y == b.coord.y); };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return (a.coord.x != b.coord.x && a.coord.y != b.coord.y); };

        Coordinate coord;
        Map & map;
    };

    static std::vector<Coordinate> get_neighbours(Iterator const & it);

    auto begin() { return Iterator(Coordinate(0,0), *this); }
    auto end()   { return Iterator(Coordinate(scale,scale), *this); } // 200 is out of bounds



};

