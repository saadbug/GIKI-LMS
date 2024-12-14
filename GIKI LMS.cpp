#include<iostream>
using namespace std;

class LMS {
    private: 
        
public:
    void displayMenu() {
        cout<<"----Welcome go GIKI LMS----";
        cout<<"";
        
    }
    void login() {}
    void logout() {}
    void addUser(User* user) {}
    void addCourse(Course course) {}
    void assignTeacherToCourse(string teacherID, string courseID) {}
    void enrollStudentToCourse(string studentID, string courseID) {}
    void generateReport(string studentID) {}
    void saveDataToFile() {}
    void loadDataFromFile() {}
    User* findUserByID(string userID) {}
    Course* findCourseByID(string courseID) {}
    void applyGradingPolicy(string courseID) {}
    void saveToFile() {}
    void loadFromFile() {}
    void exportStudentReport(string studentID) {}
};

class User {
private:
    string name;
    
public:
    void viewProfile() {}
    void editProfile() {}
};

class Student : public User {
private:
    string userID;
    string DOB;
    int currentsemester;
    string currentCourses[8];
    int coursegrades[8];
    int semesterGPA[8];
    int cGPA;

public:
    void enrollCourse(Course course) {}
    void viewGrades() {}
    float calculateGrade() {}
    float calculateGPA() {}
    void submitAssignment(string assignmentName, string courseID) {}
    void viewAssignments() {}
};

class Teacher : public User {
private:
    string teacherID;
    string DOB;
    string course;

public:
    void addAssignment(Course course, string assignmentName) {}
    void gradeAssignment(string courseID, string studentID, float marks) {}
    void viewClassGrades(Course course) {}
    void listAssignments(string courseID) {}
};

class Course {
private:
    string coursename;
    int classstrength;
    float classaverage;
    string students[30];

public:
    void addStudentToCourse(string studentID) {}
    void removeStudentFromCourse(string studentID) {}
    void listEnrolledStudents() {}
    void addAssignment(string assignmentName, string dueDate) {}
    void calculateCourseAverage() {}
};

class Assignment {
private:
    string Course;
    string 
public:
    void addSubmission(string studentID, float marks) {}
    float getMarks(string studentID) {}
    void listSubmissions() {}
    void updateMarks(string studentID, float newMarks) {}
    void calculateAssignmentAverage() {}
};

bool isValidUserID(string userID) {}
bool isValidCourseID(string courseID) {}
void printMainMenu() {}
void printCourseMenu(string courseID) {}

int main() {
    cout << "meow" << endl;
}
