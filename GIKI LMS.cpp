#include<iostream>
#include<vector>
#include<string>
using namespace std;

class User {
protected:
    string userID;
    string name;

public:
    User(string id, string name) : userID(id), name(name) {}
    virtual void viewProfile() {
        cout << "User ID: " << userID << endl;
        cout << "Name: " << name << endl;
    }
    void editProfile(string newName) {
        name = newName;
        cout << "Profile updated successfully!" << endl;
    }
};

class Student : public User {
private:
    vector<string> enrolledCourses;
    vector<float> grades;

public:
    Student(string id, string name) : User(id, name) {}

    void enrollCourse(string courseID) {
        enrolledCourses.push_back(courseID);
        grades.push_back(0.0); // Default grade
        cout << "Enrolled in course: " << courseID << endl;
    }

    void viewGrades() {
        cout << "Grades for " << name << ":\n";
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            cout << "Course: " << enrolledCourses[i] << " - Grade: " << grades[i] << endl;
        }
    }

    void updateGrade(string courseID, float grade) {
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            if (enrolledCourses[i] == courseID) {
                grades[i] = grade;
                cout << "Grade updated for course: " << courseID << endl;
                return;
            }
        }
        cout << "Course not found!" << endl;
    }
};

class Teacher : public User {
private:
    vector<string> teachingCourses;

public:
    Teacher(string id, string name) : User(id, name) {}

    void addCourse(string courseID) {
        teachingCourses.push_back(courseID);
        cout << "Added course to teaching list: " << courseID << endl;
    }

    void viewTeachingCourses() {
        cout << "Courses taught by " << name << ":\n";
        for (const auto& course : teachingCourses) {
            cout << course << endl;
        }
    }
};

class Course {
private:
    string courseID;
    string courseName;
    vector<string> enrolledStudents;

public:
    Course(string id, string name) : courseID(id), courseName(name) {}

    void addStudent(string studentID) {
        enrolledStudents.push_back(studentID);
        cout << "Student " << studentID << " added to course " << courseName << endl;
    }

    void listStudents() {
        cout << "Students enrolled in " << courseName << ":\n";
        for (const auto& student : enrolledStudents) {
            cout << student << endl;
        }
    }
};

class LMS {
private:
    vector<User*> users;
    vector<Course> courses;

public:
    void displayMenu() {
        cout << "---- Welcome to GIKI LMS ----" << endl;
        cout << "1. Login" << endl;
        cout << "2. Logout" << endl;
        cout << "3. Add User" << endl;
        cout << "4. Add Course" << endl;
        cout << "5. Assign Teacher to Course" << endl;
        cout << "6. Enroll Student to Course" << endl;
        cout << "7. Generate Report" << endl;
        cout << "8. Save Data to File" << endl;
        cout << "9. Load Data from File" << endl;
        cout << "10. Exit" << endl;
        cout << "---------------------------" << endl;
    }

    void login() {
        string userID;
        cout << "Enter your user ID: ";
        cin >> userID;
        // Add logic to verify user credentials
        cout << "Login successful for user: " << userID << endl;
    }

    void logout() {
        cout << "You have successfully logged out." << endl;
    }

    void addUser(User* user) {
        users.push_back(user);
        cout << "User added successfully." << endl;
    }

    void addCourse(Course course) {
        courses.push_back(course);
        cout << "Course added successfully." << endl;
    }

    void assignTeacherToCourse(string teacherID, string courseID) {
        cout << "Teacher " << teacherID << " assigned to course " << courseID << endl;
    }

    void enrollStudentToCourse(string studentID, string courseID) {
        for (auto& course : courses) {
            if (courseID == courseID) {
                course.addStudent(studentID);
                return;
            }
        }
        cout << "Course not found!" << endl;
    }

    void generateReport(string studentID) {
        cout << "Generating report for student: " << studentID << endl;
    }
};

int main() {
    LMS lms;
    int choice;

    do {
        lms.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lms.login();
                break;
            case 2:
                lms.logout();
                break;
            case 3: {
                string userID, name;
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Name: ";
                cin >> name;
                lms.addUser(new User(userID, name));
                break;
            }
            case 4: {
                string courseID, courseName;
                cout << "Enter Course ID: ";
                cin >> courseID;
                cout << "Enter Course Name: ";
                cin >> courseName;
                lms.addCourse(Course(courseID, courseName));
                break;
            }
            case 5: {
                string teacherID, courseID;
                cout << "Enter Teacher ID: ";
                cin >> teacherID;
                cout << "Enter Course ID: ";
                cin >> courseID;
                lms.assignTeacherToCourse(teacherID, courseID);
                break;
            }
            case 6: {
                string studentID, courseID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Course ID: ";
                cin >> courseID;
                lms.enrollStudentToCourse(studentID, courseID);
                break;
            }
            case 7: {
                string studentID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                lms.generateReport(studentID);
                break;
            }
            case 8:
                cout << "Data saved to file." << endl;
                break;
            case 9:
                cout << "Data loaded from file." << endl;
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
