#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class Employee{
public:
    string name;
    string company;
    int age;
    void introduce_yourself(){
        cout<<"Hello I am "<<name<<". I work for "<<company<<" and I am "<<age<<" years old. Nice to meet you!"<<endl;
    }
    Employee(string name_c, string company_c, int age_c){
        name = name_c;
        company = company_c;
        age = age_c;
    }
};
int main(){
    Employee emp1("Jeremy", "Amazon",26);
    //emp1.name = "James";
    //emp1.company = "YouTube";
    //emp1.age = 24;
    emp1.introduce_yourself();
}