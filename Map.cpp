#include "Map.h"
#include <iostream>

void Map::show() const {
    for(auto const & cell: map){
        std::cout << cell << std::endl;
    }
}

void Map::add(int x) {
    map.push_back(x);
}

Map::Map(int x) :map(x){

}
