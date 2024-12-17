#include <iostream>
using namespace std;
class Employee{
private:
    string Company;
    int Age;
protected:
    string Name;
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
    virtual void work(){
        cout<<Name<<" is checking email, task backlog, performing tasks...... "<<endl;
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
    void work(){
        cout<<Name<<" is writting "<<FavProgrammingLang<<" code."<<endl;
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
  void work(){
      cout<<Name<<" is teaching "<<Subject<<"."<<endl;
  }

};
int main(){
    Developer dev1 = Developer("Hammond", "BBC",56,"Javascript");
    Teacher t1 = Teacher("Daniel","Music School",35,"Piano");
    Employee *emp1 = &dev1;
    Employee *emp2 = &t1;
    emp1->work();
    emp2->work();
    
}
