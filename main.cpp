#include <iostream>
#include "Map.h"
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    Map map(4);
    map.show();

    cout << "--------------------------------" << endl;

    for(auto x: map){
        cout << x << endl;
    }
    return 0;
}
