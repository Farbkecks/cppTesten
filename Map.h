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
    void set(Coordinate const & coord, int value);
    void set(int x, int y, int value);
    int & getReference(Coordinate const & coord);
    typedef std::vector<std::vector<int>> datatype;
    datatype map;
    const int scale;

    struct Iterator{
    private:
        Coordinate coord;
        Map & map;
    public:
        Iterator(Coordinate coord, Map & map) : coord(coord), map(map) {}

        Coordinate getCoordinate() const {return coord; }

        int& operator*() const { return map.getReference(coord); }

        // Prefix increment
        Iterator& operator++();

        // Suffix operator
        Iterator operator++(int);

        bool operator== (const Iterator& other) { return (coord.x == other.coord.x && coord.y == other.coord.y); };
        bool operator!= (const Iterator& other) { return (coord.x != other.coord.x && coord.y != other.coord.y); };
    };

    static std::vector<Coordinate> get_neighbours(Iterator const & it);

    auto begin() { return Iterator(Coordinate(0,0), *this); }
    auto end()   { return Iterator(Coordinate(scale,scale), *this); } // 200 is out of bounds
};

