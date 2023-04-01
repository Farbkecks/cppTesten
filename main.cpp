#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

enum Types{
    HEIGHT,
    STRENGE,
    INTELLEGENCE
};

struct Attributes{
    virtual Types getT() = 0;
    virtual double getV() = 0;
};

template<Types T>
struct Attribute: public Attributes{
    Types type;
    double value;
    double getV() override{return  value;}
    Types getT() override{return  type;}
    explicit Attribute(double x): type(T), value(x){}
};

struct Card{
    Card(double height, double strenge, double intellegence)
    {
        card.push_back(make_unique<Attribute<HEIGHT>>(height));
        card.push_back(make_unique<Attribute<STRENGE>>(strenge));
        card.push_back(make_unique<Attribute<INTELLEGENCE>>(intellegence));
    }

    template<Types T>
    bool compare(Card other) const{
        for(int i = 0; i<card.size();i++){
            if(card.at(i)->getT() != T) continue;
            return card.at(i)->getV() > other.card.at(i)->getV();
        }
    }

    vector<shared_ptr<Attributes>> card;
};

int main() {

    Card one(2,3,6);
    Card two(4,1,8);

    cout << one.compare<HEIGHT>(two) << endl;
    cout << one.compare<STRENGE>(two) << endl;
    cout << one.compare<INTELLEGENCE>(two) << endl;

    return 0;
}
