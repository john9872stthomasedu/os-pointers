// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cmath>

typedef struct Student {
    int id;
    std::string f_name;
    std::string l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    std::cout << std::endl;
    student.grades = new double[student.n_assignments];
    for(int i = 0; i < student.n_assignments; i++){
        std::string m = "Please enter the grade for assignment " + std::to_string(i);
        m += ": ";
        student.grades[i] = promptDouble(m, 0, 1000);
    }
    std::string info = "Student: " + student.f_name + " " + student.l_name + " [" + std::to_string(student.id) + "]";
    double *grades2 = new double[student.n_assignments + 1];
    grades2[0] = student.n_assignments;
    for(int i = 0; i < student.n_assignments; i++){
        grades2[i+1] = student.grades[i];
    }
    calculateStudentAverage(&info, grades2);
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int toReturn;
    bool inRange = true;
    std::cout << message;
    std::cin >> toReturn;
    if(toReturn > max || toReturn < min){
        inRange = false;
    }
    while(!inRange){
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cout << message;
        std::cin >> toReturn;
        if(toReturn < max && toReturn > min){
            inRange = true;
        }
    }
    return toReturn;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{  
    double toReturn;
    bool inRange = true;
    std::cout << message;
    std::cin >> toReturn;
    if(toReturn > max || toReturn < min){
        inRange = false;
    }
    while(!inRange){
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cout << message;
        std::cin >> toReturn;
        if(toReturn < max && toReturn > min){
            inRange = true;
        }
    }
    return toReturn;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    std::string& s = *static_cast<std::string*>(object);
    std::cout << s << std::endl;
    double a = 0.0;
    for(int i = 0; i < avg[0]; i++){
        a += avg[i+1];
    }
    a /= avg[0];
    a = a*10;
    a = std::round(a);
    int b = static_cast<int>(a) % 10;
    a = a / 10;
    std::cout << "  Average grade: " + std::to_string(static_cast<int>(a)) + "." + std::to_string(b);
}
