#include <iostream>

class Object_array
{
private:
    //Мощность универсума
    static int UNIVERSE_POWER;
    //Мощность множества
    int cardinality;
    //Тег и память для множества
    char tag, *A;
public:
    Object_array operator | (const Object_array&) const;
    Object_array operator & (const Object_array&) const;
    Object_array operator ~ () const;
    Object_array operator = (const Object_array &);
    Object_array operator = (Object_array &&);
    void display();
    int get_cardinality() { return cardinality; }
    Object_array();
    Object_array(char);
    Object_array(const Object_array &);
    Object_array(Object_array &&);
    ~object_array() { delete [] A; }
};

int Object_array :: UNIVERSE_POWER = 10;

Object_array& Object_array ::operator&(const Object_array & B) const {
    Object_array* set = new Object_array;
    for (int i = 0; i < cardinality; i++) {
        for (int j = 0; j < B.cardinality; j++) {
            if (A[i] == B.A[j]) {
                set->A[set->cardinality++] = A[i];
            }
        }
    }
    set->A[set->cardinality] = 0;
    return *set;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}