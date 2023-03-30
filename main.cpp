#include <iostream>
#include "Map.h"
#include <algorithm>
#include <memory>

using namespace std;

int main() {

    Map map(4);
    map.show();

    cout << "--------------------------------" << endl;

    for(auto i: map) {
        cout << i << endl;
    }

    cout << "--------------------------------" << endl;

    Map::Iterator ptr(Coordinate(1,1), map);
    cout << *ptr << endl;
    auto neighbours = Map::get_neighbours(ptr);
    for(auto i: neighbours){
        cout << map.getReferance(i) << endl;
    }

    return 0;
}
