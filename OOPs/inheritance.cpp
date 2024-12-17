#include <iostream>
using namespace std;
class Employee{
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
class Developer:public Employee{
public:
    string FavProgrammingLang;
    Developer(string name, string company, int age, string favProgrammingLang)
    :Employee(name, company, age){
        FavProgrammingLang = favProgrammingLang;
    }
    void fixBug(){
        cout<<getName()<<" fixed bug using "<<FavProgrammingLang<<endl;
    }
};
class Teacher:public Employee{
public:
  string Subject;
  void prepareLesson(){
      cout<<getName()<<" is preparing "<< Subject<<" lesson."<<endl;
  }
  Teacher(string name, string company, int age, string subject)
  :Employee(name, company, age){
      Subject = subject;
  }
};
int main(){
    Developer dev1 = Developer("Hammond", "BBC",56,"Javascript");
    dev1.fixBug();
    dev1.askForPromotion();
    Teacher t1 = Teacher("Daniel","Music School",35,"Piano");
    t1.prepareLesson();
    t1.askForPromotion();
}
