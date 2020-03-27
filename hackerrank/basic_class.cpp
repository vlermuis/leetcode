/*
https://www.hackerrank.com/challenges/c-tutorial-class/problem



*/

#include <iostream>
#include <sstream>

using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
    private:
    int age;
    int standard;
    string first_name;
    string last_name;

    public:
    Student();
    int get_age();
    void set_age(int new_age);
    string get_first_name();
    void set_first_name(string new_name);
    string get_last_name();
    void set_last_name(string new_name);
    int get_standard();
    void set_standard(int new_standard);
    string to_string();
};
Student::Student()
{
    age = 0;
    first_name = "";
    last_name = "";
    standard = 0;
}
int Student::get_age()
{
    return age;
}
void Student::set_age(int new_age)
{
    age = new_age;
}
string Student::get_first_name()
{
    return first_name;
}
void Student::set_first_name(string new_name)
{
    first_name = new_name;
}
string Student::get_last_name()
{
    return last_name;
}
void Student::set_last_name(string new_name)
{
    last_name = new_name;
}
int Student::get_standard()
{
    return standard;
}
void Student::set_standard(int new_standard)
{
    standard = new_standard;
}
string Student::to_string()
{
    stringstream ss; 
    ss << age;
    string s;
    ss >> s;
    string result = ""; 
    result += s;
    result += " ";
    result += first_name;
    result += " ";
    result += last_name;
    result += " ";
    ss << standard;
    ss >> s;
    result += s;


    return result;
}
int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}