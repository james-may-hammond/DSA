#include <iostream>
#include <string>
using namespace std;
class AbstractEmployee{
    // whoever signs abstract emp must sign this method
    virtual void askForPromotion()=0;
};
class Employee:AbstractEmployee{
private:
    string Name;
    string Company;
    int Age;
public:
    void setName(string name){//setter
        Name = name;
    }
    string getName(){//getter
        return Name;
    }
    void setCompany(string company){//setter
        Company = company;
    }
    string getCompany(){//getter
        return Company; 
    }
    void setAge(int age){//setter
        if (age>=18)
            Age = age;
        else
            cout<<"Age cannot be less than 18"<<endl;
    }
    int getAge(){//getter
        return Age;
    }
    void introduce_yourself(){
        cout<<"Hello I am "<<Name<<". I work for "<<Company<<" and I am "<<Age<<" years old. Nice to meet you!"<<endl;
    }
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    void askForPromotion(){
        if(Age>=30)
            cout<<Name<<" got promoted!"<<endl;
        else
            cout<<Name<<" did not get a promotion."<<endl;
    }
};
int main(){
    Employee emp1("Jeremy", "Amazon",26);
    Employee emp2("Joanna", "WSJ",30);
    //emp1.name = "James";
    //emp1.company = "YouTube";
    //emp1.age = 24;
    emp1.introduce_yourself();
    //cout<<emp1.getName()<<" is "<<emp1.getAge()<<" years old."<<endl;
    emp1.askForPromotion();
    emp2.askForPromotion();
}
