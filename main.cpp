#include <iostream>

const int duration = 100000;

class Object_array
{
private:
    //Мощность универсума
    static int UNIVERSE_POWER;
    //Мощность множества
    int cardinality;
    //Тег и память для множества
    char tag, *array;
public:
    Object_array operator | (const Object_array&) const;
    Object_array operator & (const Object_array&) const;
    Object_array operator ~ () const;
    Object_array operator = (const Object_array &);
    void display();
//    int get_cardinality() { return cardinality; }
    Object_array();
    Object_array(char);
    Object_array(const Object_array &);
};

//class Object_list
//{
//private:
//    char symb;
//    Object_list* next;
//public:
//    Object_list() {}
//    Object_list(char s, Object_list* n = nullptr) : symb(s), next(n) {  std::cout << "+" << symb << std::endl;    }
//    ~Object_list() {
//        if (next) {
//            delete next;
//        }
//        std::cout << "-" << symb << std::endl;
//    }
//
//
//};



//class Object_list
//{
//private:
//    Object_list* head;
//    Object_list* last;
//public:
//    Object_list* get_head() { return head;}
//    void set_head(Object_list* new_head)  { head = new_head; }
//
//};



int Object_array :: UNIVERSE_POWER = 10;

Object_array Object_array ::operator&(const Object_array & B) const {
    Object_array* set = new Object_array;
    for (int i = 0; i < cardinality; i++) {
        for (int j = 0; j < B.cardinality; j++) {
            if (array[i] == B.array[j]) {
                set->array[set->cardinality++] = array[i];
            }
        }
    }
    set->array[set->cardinality] = 0;
    return *set;
}

Object_array Object_array ::operator|(const Object_array & B) const {
    Object_array* set = new Object_array(*this);
    for (int i = 0; i < B.cardinality; i++) {
        bool flag = true;
        for (int j = 0; j < cardinality; j++) {
            if(B.array[i] == array[j]) {
                flag = false;
            }
        }
        if(flag) {
            set->array[set->cardinality++] = B.array[i];
        }
    }
    set->array[set->cardinality] = 0;
    return *set;
}

Object_array Object_array ::operator~() const {
    Object_array* set = new Object_array;
    for (char ch = '0'; ch <= '9'; ch++) {
        bool flag = true;
        for (int j = 0; j < cardinality; j++) {
            if (ch == array[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            set->array[set->cardinality++] = ch;
        }
    }
    set->array[set->cardinality] = 0;
    return *set;
}

void Object_array :: display() {
    std::cout << tag << " = [" << array << "]" << std::endl;
}

Object_array::Object_array(): cardinality(0), tag('0'), array(new char[UNIVERSE_POWER + 1]) {
    array[0] = 0;
}


Object_array::Object_array(char symb): tag(symb), cardinality(0), array(new char[UNIVERSE_POWER + 1]) {
    for (int i = 0; i < UNIVERSE_POWER; i++) {
        if(rand() % 2) {
            array[cardinality++] =(char) (i +'0');
        }
    }
    array[cardinality] = 0;
    std::cout << tag << " =[" << array << "]" << std::endl;
}

Object_array::Object_array(const Object_array & B): tag(B.tag), cardinality(B.cardinality), array(new char[UNIVERSE_POWER + 1]) {
    memcpy(array, B.array, (size_t)UNIVERSE_POWER + 1);
}

Object_array Object_array :: operator = (const Object_array& B) {
    if(this != &B) {
        cardinality = B.cardinality;
        memcpy(array, B.array, (size_t)UNIVERSE_POWER + 1);
        tag = 'E';//result
    }
    return *this;
}

//commit test

int main() {
    std::cout << "Hello, World!" << std::endl;

    srand(time(nullptr));
    Object_array A('A'), B('B'), C('C'), D('D'), E;
    clock_t start = clock();
    for (int i = 0; i < duration; i++) {
        E = (A & ~B) & (C | D);
    }
    clock_t end = clock();
    std::cout << "Time = " << end - start << std::endl;
    return 0;
}