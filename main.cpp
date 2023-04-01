#include <iostream>
#include <algorithm>
#include <memory>
#include <map>

using namespace std;

enum PropertyEnum{
    HEIGHT,
    STRENGTH,
    INTELLIGENCE,
    OTHER_PROPERTY
};


template<PropertyEnum... Properties>
class Card
{
private:
    map<PropertyEnum, double> card;

    template<PropertyEnum T>
    void setProperty(double value)
    {
        card[T] = value;
    }
public:

    template<PropertyEnum T>
    double getProperty() const
    {
        static_assert(((Properties == T) ||  ...), "Property does not exist in this Asset");
        if(card.count(T) == 0)
            return 0.0;
        return card.at(T);
    }


    template<typename... Args>
    Card(Args... args)
    {
        static_assert(sizeof...(args) == sizeof...(Properties), "Number of arguments does not match number of properties");

        // initialize properties
        (setProperty<static_cast<PropertyEnum>(Properties)>(args), ...);
    }

    template<PropertyEnum Property>
    bool compare(Card<Properties...> other)
    {
        return getProperty<Property>() > other.getProperty<Property>();
    }
};

int main() {

    typedef Card<HEIGHT, STRENGTH,INTELLIGENCE> HeroCard;


    HeroCard heroOne(1,2,5);

    cout << heroOne.getProperty<STRENGTH>() << std::endl;

    HeroCard heroTwo(2,3,3);


    cout << heroOne.compare<HEIGHT>(heroTwo) << endl;
    cout << heroOne.compare<STRENGTH>(heroTwo) << endl;
    cout << heroOne.compare<INTELLIGENCE>(heroTwo) << endl;

    Card<HEIGHT, STRENGTH> invalidHero(3,4);
    // conversion not possible
    //cout << heroOne.compare<HEIGHT>(invalidHero);
    //cout << heroOne.compare<OTHER_PROPERTY>(heroTwo);
    return 0;
}