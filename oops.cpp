#include<bits/stdc++.h>
using namespace std;

class Animal
{
private:
public:
    Animal();
    int leg = 4;
    void display();
};
Animal::Animal(){}
void Animal::display()
{
    cout << "leg = " <<leg << endl;
}
class Dog : public Animal
{
private:
public:
    Dog();
    int tail = 1;
    void display()
    {
        cout << "leg = " << leg << " "<< "tail =" << tail<<endl;
    }
};
Dog::Dog(){}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Animal sol1;
    Dog sol2;
    sol1.display();
    sol2.display();
    return 0;
}
