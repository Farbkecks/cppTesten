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

int & Map::getReferance(const Coordinate &coord){
    return map[coord.x][coord.y];
}

std::vector<Coordinate> Map::get_neighbours(const Map::Iterator &it) {
    std::vector<Coordinate> out;
    for(int x = -1; x<2;x++){
        for(int y = -1; y<2; y++){
            if(x == 0 && y == 0) continue;
            out.emplace_back(it.coord.x + x, it.coord.y + y);
        }
    }
    return out;
}

Map::Iterator &Map::Iterator::operator++() {
    coord.y++;
    if(coord.y == map.scale){
        coord.x++;
        coord.y = 0;
    }
    return *this;
}
