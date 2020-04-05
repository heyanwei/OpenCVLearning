#pragma once

#include <string>

namespace person
{
    class HPerson
    {
    private:
        std::string _name;
        bool _ismale;
        int _age;

    public:
        HPerson();
        ~HPerson();

        std::string GetName();
        void SetName(std::string name);
        bool IsMale();
        void SetMale(bool ismale);
        int GetAge();
        void SetAge(int age);
    };
}