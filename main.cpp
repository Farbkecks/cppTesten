#include <iostream>
#include "Map.h"
#include <algorithm>

using namespace std;

int main() {
    Map map(8);
    fill(begin(map), end(map), 3);
    map.show();
    return 0;
}
