#include <iostream>
#include <algorithm>
#include <memory>
#include <map>

using namespace std;

enum TypesEnum{
    HEIGHT,
    STRENGTH,
    INTELLIGENCE
};

struct CardBase{

    CardBase() = delete;

    template<TypesEnum T>
    bool compare(CardBase const & other) const{
        return getProperty<T>() > other.getProperty<T>();
    }

    template<TypesEnum T>
    double getProperty() const
    {
        if(card.count(T) == 0)
            return 0.0;
        return card.at(T);
    }

    template<TypesEnum T>
    void setProperty(double value)
    {
        card[T] = value;
    }

protected:
    map<TypesEnum, double> card;
};


struct Card: public CardBase{
    Card(double h, double s, double i){
        setProperty<HEIGHT>(h);
        setProperty<STRENGTH>(s);
        setProperty<INTELLIGENCE>(i);
    }
};

int main() {

    Card one(1,5,3);
    Card two(5,2,9);

    cout << one.compare<HEIGHT>(two) << endl;
    cout << one.compare<STRENGTH>(two) << endl;
    cout << one.compare<INTELLIGENCE>(two) << endl;

    return 0;
}
