    #include<iostream>
    using namespace std;

    class LMS
    {
    void displayMenu(){}

    void login(){}

    void logout(){}

    void addUser(User* user){}

    void addCourse(Course course){}

    void assignTeacherToCourse(String teacherID, string courseID){}

    void enrollStudentToCourse(string studentID, string courseID){}

    void generate report(string studentID){}

    void saveDataToFile(){}

    void loadDataToFile()
    
    User* findUserByID(string UserID){}

    Course* findCourseByID(string courseID){}

    void applyGradingPolicy(string courseID){}

    void saveToFile(){}

    void loadFromFile(){}

    void exportStudentReport(){}

    
    };

    class User{
        void viewProfile(){}

        void editProfile(){}

    };

    class Student : public User{
        void enrollCourse(Course course){}

        void viewGrade(){}

        float calculateGrade(){}

        float calculateGPA(){}

        void submitAssignment(string assignmentName, string courseID){}

        void viewAssignment(){}

    };

    class teacher : public User{
        void addAssignment(Course course, string assignmentName){}

        void gradeAssignment(string course ID, string student ID, float marks){}

        void viewClassGrades(Course course){}

        void listAssignment(string courseID)
    };

    class Course{
        void addStudent(string studnetID){}

        void removeStudent(string studentID){}

        void listStudents(){}

        void addAssignment(string assignmentName, string dueDate){}

        void calculateCourseAverage(){}
    };

    class Assignment{
        void addSubmission(string studentID, float marks){}

        float getMarks(string studentID)

        void listSubkissions(){}

        void updateMarks(string studentID, float newMarks){}

        void calculateASsignmentAverage(){}
    };

    bool isValidUserID(string userID){}

    bool isValidCourseID(string courseID){}

    void printMainMenu(){}

    void printCourseMenu(string courseID)

    int main()
    {
        cout<<"meow";
    }