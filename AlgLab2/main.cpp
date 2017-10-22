// E = (A & ~B) & (C || D)

#include <iostream>
#include <time.h>

class Object_array {
private:
    //Мощность универсума
    static int UNIVERSE_POWER;
    //Тег
    char tag;
    bool *bArray;
public:

    Object_array operator | (const Object_array &) const;

    Object_array operator & (const Object_array &) const;

    Object_array operator ~ () const;

    Object_array operator = (const Object_array &);

    void display() {
        std::cout << this->tag << " =[";
        for (int i = 0; i < UNIVERSE_POWER; i++)
            std::cout << this->bArray[i];
        std::cout << "]" << std::endl;
    }

    Object_array();

    Object_array(char);

    Object_array(const Object_array &);

};

int Object_array::UNIVERSE_POWER = 10;

Object_array::Object_array(): tag('0'), bArray(new bool[UNIVERSE_POWER]) {
    bArray[0] = 0;
}

Object_array::Object_array(char symb): tag(symb), bArray(new bool[UNIVERSE_POWER])  {
    for (int i = 0; i < UNIVERSE_POWER; i++) {
        bArray[i] = (rand() % 1024 >> i) & 1;
    }
}

Object_array::Object_array(const Object_array & B): tag(B.tag), bArray(new bool[UNIVERSE_POWER]) {
    memcpy(bArray, B.bArray, (size_t)UNIVERSE_POWER);
}

Object_array Object_array::operator&(const Object_array &B) const {
    Object_array *result = new Object_array(*this);
    for (int i = 0; i < UNIVERSE_POWER; i++) {
        if (this->bArray[i] == B.bArray[i])
            (*result).bArray[i] = this->bArray[i];
        else
            (*result).bArray[i] = 0;
    }
    return *result;
}

Object_array Object_array::operator|(const Object_array &B) const {
    Object_array *result = new Object_array(*this);
    for (int i = 0; i < UNIVERSE_POWER; i++) {
        if (this->bArray[i] || B.bArray[i])
            result->bArray[i] = 1;
        else result->bArray[i] = 0;
    }
    return *result;
}

Object_array Object_array::operator~() const {
    for (int i = 0; i < UNIVERSE_POWER; i++)
        bArray[i] = !bArray[i];
    return *this;
}

Object_array Object_array::operator=(const Object_array &B) {
    if (this != &B) {
        bArray = B.bArray;
        memcpy(bArray, B.bArray, (size_t)UNIVERSE_POWER);
        tag = 'E';
    }
    return *this;
}

int main() {
    srand(time(nullptr));
    clock_t start = clock();
    for (int i = 0; i < 10000; i++) {
        Object_array A('A'), B('B'), C('C'), D('D'), E;
        E = (A & ~B) & (C | D);
    }
    clock_t end = clock();
    std::cout << "time = " << end - start << std::endl;
    return 0;
}