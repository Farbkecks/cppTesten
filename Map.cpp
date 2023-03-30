#include "Map.h"
#include <iostream>


void Map::show() const {
    using std::cout;
    using std::endl;
    for(auto const & row: map){
        for(auto const &  cell: row){
            if(cell < 10) cout << "0";
            cout << cell << " ";
        }
        cout << "\n";
    }
}

void Map::add(int x, int y, int value) {
    map.at(x).at(y) = value;
}

void Map::add(Coordinate const & coord, int value) {
    add(coord.x, coord.y, value);
}

Map::Map(int x) :map(x), scale(x){
    int count = 0;
    for(auto & row: map){
        row.resize(x);
        for(auto & cell: row){
            cell = count++;
        }
    }
}

Map::Iterator &Map::Iterator::operator++() {
    ptr_y++;
    if(*ptr_y == (*ptr_x)[scale]){
        ptr_x++;
        ptr_y = & (*ptr_x)[0];
    }
    return *this;
}
