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

struct Card{
    // Im Konstruktor die einzelnen Properties zu übergeben beißt sich mit der Voraussetzung, alles dynamisch zu halten
    Card()
    {
        // Nicht am Anfang die Werte initialisieren, sondern einfach eine Map nutzen

    }
    template<TypesEnum T>
    bool compare(Card const & other) const{
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

private:
    map<TypesEnum, double> card;
};

int main() {

    Card one;
    one.setProperty<HEIGHT>(3);
    one.setProperty<STRENGTH>(6);
    one.setProperty<INTELLIGENCE>(5);


    Card two;
    two.setProperty<HEIGHT>(2);
    two.setProperty<STRENGTH>(3);
    two.setProperty<INTELLIGENCE>(8);

    cout << one.compare<HEIGHT>(two) << endl;
    cout << one.compare<STRENGTH>(two) << endl;
    cout << one.compare<INTELLIGENCE>(two) << endl;

    return 0;
}
