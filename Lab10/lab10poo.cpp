#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;



//Clasa MyVector
class MyVector
{
private:
    int numbers[100];
    int length;
    int maxLength;

public:
    MyVector()
    {
        this->length = 0;
        this->maxLength = 100;
    }

    MyVector(int* newNumbers, int n)
    {
        this->maxLength = 100;
        this->length = n;
        for (int i = 0; i < n; i++)
            numbers[i] = newNumbers[i];
    }

    bool Add(int newNumber)
    {
        if (this->length + 1 < this->maxLength)
            this->numbers[this->length++] = newNumber;

        else
            return false;

        return true;
    }

    int GetElem(int index)
    {
        if (index > length)
            throw("An exception occurred. 'index' too big");

        if (index < 0)
            throw("An exception occurred. 'index' can't be negative");

        return numbers[index];
    }

    bool Delete(int index)
    {
        for (int i = index; i < this->length; i++) {
            this->numbers[i] = this->numbers[i + 1];
        }
        this->length--;
        return true;

    }

    MyVector Iterate(int (*func)(int))
    {
        int l = 0;
        int result[100];

        for (int i = 0; i < this->length; i++)
            result[l++] = func(this->numbers[i]);

        MyVector resultObject(result, l);
        return resultObject;
    }

    MyVector Filter(bool (*func)(int))
    {
        int l = 0;
        int result[100];

        for (int i = 0; i < this->length; i++)
            if (func(numbers[i]))
                result[l++] = numbers[i];

        MyVector resultObject(result, l);
        return resultObject;
    }
};



int main()
{
    //Problema 1
    vector<string> sir;
  
    sir.push_back("portocala");
    sir.push_back("ala");
    sir.push_back("portocalb");
    sir.push_back("alb");
    sir.push_back("balabala");
    sir.push_back("bala");

    sort(sir.begin(), sir.end(), [](string& s1, string& s2) -> bool { if (s1.length() != s2.length())
    {
        if (s1 > s2) return 0;
        else return 1;
    }
    return 0; });
    
    cout << "Sorted vector: ";
    for (vector<string>::iterator it = sir.begin(); it != sir.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    //Problema 2
    list<int> integer_list;
    
    integer_list.push_back(7);
    integer_list.push_back(2);
    integer_list.push_back(7);
    integer_list.push_back(10);
    integer_list.push_back(5);
    integer_list.push_back(1);
    integer_list.push_back(13);
    integer_list.push_back(25);
    integer_list.push_back(-4);

    list<int>::iterator it;
    cout << "Integer List: ";
    for ( it = integer_list.begin(); it != integer_list.end(); ++it) {
        cout << *it << "  ";
    }
    cout << endl;

    auto max_el = [](list<int> lst) { 
        int aux = lst.front();
        for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
            if (*it > aux) aux = *it;
        return aux;      
    };

    cout << "Biggest element in list: " << max_el(integer_list);
    cout << endl;
   

    //Problema 3
    MyVector a, b, c;
    a.Add(69);
    a.Add(-30);
    a.Add(420);

    auto increment = [](int x) {return x + 420; };
    auto compare = [](int x) {return x < 0 ? true : false; };

    b = a.Iterate(increment);
    c = a.Filter(compare);

    printf("a: %d, %d, %d\n", a.GetElem(0), a.GetElem(1), a.GetElem(2));
    printf("b: %d, %d, %d\n", b.GetElem(0), b.GetElem(1), b.GetElem(2));
    printf("c: %d \n", c.GetElem(0));
    

    return 0;
    

}
