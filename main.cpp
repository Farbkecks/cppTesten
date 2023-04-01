#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

enum Types{
    HEIGHT,
    STRENGE
};

struct Attribute{
    Types type;
    double value;
    explicit Attribute(Types t, double x): type(t), value(x){}
};

struct Card{
    Card(Attribute height, Attribute strenge){
        card.push_back(height);
        card.push_back(strenge);
    }
    vector<Attribute> card;
};

bool compare(Types t, Card one, Card two){
    for(int i=0; one.card.size(); i++){
        if(one.card.at(i).type != t) continue;
        return one.card.at(i).value > two.card.at(i).value;
    }
}

int main() {

    Card one(Attribute(HEIGHT, 2), Attribute(STRENGE, 3));
    Card two(Attribute(HEIGHT, 1), Attribute(STRENGE, 6));

    cout << compare(HEIGHT, one, two) << endl;
    cout << compare(STRENGE, one, two) << endl;

    return 0;
}
