#ifndef FRUIT_H
#define FRUIT_H

#include <string>

using namespace std;

class Fruit {

    protected:
        string name;
        unsigned short weight;

    public:
        Fruit();

        bool operator> (const Fruit &);
        bool operator< (const Fruit &);

        string get_name();
        void set_name(string);

        unsigned short get_weight();
        void set_weight(unsigned short);

};

#endif
