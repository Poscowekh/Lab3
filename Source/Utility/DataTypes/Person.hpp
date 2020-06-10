#ifndef PERSON_HPP
#define PERSON_HPP
#include <utility>
#include <time.h>

using namespace std;

class Person
{
    private:
        size_t id;
        char* first_name;
        char* middle_name;
        char* last_name;
        time_t birth_date;
    public:
        Person()
        {
            id = birth_date = 0;
            first_name = middle_name = last_name = 0;
        };
        Person(const Person* other)
        {
            id = other->id;
            birth_date = other->birth_date;
            first_name = other->first_name;
            middle_name = other->middle_name;
            last_name = other->last_name;
        };
        Person(size_t new_id, time_t bdate, char* f_name, char* m_name, char* l_name)
        {
            id = new_id;
            birth_date = bdate;
            first_name = f_name;
            middle_name = m_name;
            last_name = l_name;
        };
        size_t ID()
        {
            return id;
        };
        time_t BirthDate()
        {
            return birth_date;
        };
        char* FirstName()
        {
            return first_name;
        };
        char* MiddleName()
        {
            return middle_name;
        };
        char* LastName()
        {
            return last_name;
        };
        ~Person(){};
};

#endif // PERSON_HPP
