#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

// Node class for Linked List
class Node {
public:
    string data;
    Node* next;

    Node(string val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(string data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Class Definitions
class Course {
public:
    string courseID;
    string courseName;
    vector<string> enrolledStudents; // Array for enrolled students
    vector<float> grades; // Grades for students

    Course(string id, string name) : courseID(id), courseName(name) {}

    void addStudent(string studentID) {
        enrolledStudents.push_back(studentID);
        grades.push_back(0.0); // Initialize grade to 0
    }

    void listStudents() {
        cout << "Students in " << courseName << ":\n";
        for (size_t i = 0; i < enrolledStudents.size(); ++i) {
            cout << enrolledStudents[i] << " - Grade: " << grades[i] << endl;
        }
    }

    void updateGrade(string studentID, float grade) {
        for (size_t i = 0; i < enrolledStudents.size(); ++i) {
            if (enrolledStudents[i] == studentID) {
                grades[i] = grade;
                return;
            }
        }
        cout << "Student not found in this course." << endl;
    }

    float calculateAverage() {
        float total = 0;
        for (float grade : grades) {
            total += grade;
        }
        return grades.empty() ? 0 : total / grades.size();
    }
};

class User {
public:
    string userID;
    string name;

    User(string id, string n) : userID(id), name(n) {}
};

class Student : public User {
public:
    vector<string> enrolledCourses; // Array for courses
    vector<float> grades; // Array for grades in each course

    Student(string id, string n) : User(id, n) {}

    void enroll(string courseID) {
        enrolledCourses.push_back(courseID);
        grades.push_back(0.0); // Initialize grade to 0
    }

    void listCourses() {
        cout << name << "'s Courses:\n";
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            cout << enrolledCourses[i] << " - Grade: " << grades[i] << endl;
        }
    }

    float calculateCGPA() {
        float total = 0;
        for (float grade : grades) {
            total += grade;
        }
        return grades.empty() ? 0 : total / grades.size();
    }

    void updateGrade(string courseID, float grade) {
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            if (enrolledCourses[i] == courseID) {
                grades[i] = grade;
                return;
            }
        }
        cout << "Course not found." << endl;
    }
};

class Teacher : public User {
public:
    vector<string> assignedCourses; // Array for courses

    Teacher(string id, string n) : User(id, n) {}

    void assignCourse(string courseID) {
        assignedCourses.push_back(courseID);
    }

    void listCourses() {
        cout << name << "'s Assigned Courses:\n";
        for (string& course : assignedCourses) {
            cout << course << endl;
        }
    }

    void gradeStudent(Course& course, string studentID, float grade) {
        course.updateGrade(studentID, grade);
    }
};

class LMS {
private:
    vector<User*> users;
    vector<Course> courses;
    LinkedList activityLog; // Linked List for logs

public:
    void addUser(User* user) {
        users.push_back(user);
        activityLog.insert("User added: " + user->userID);
    }

    void addCourse(string id, string name) {
        courses.push_back(Course(id, name));
        activityLog.insert("Course added: " + id);
    }

    void enrollStudentToCourse(string studentID, string courseID) {
        for (Course& course : courses) {
            if (course.courseID == courseID) {
                course.addStudent(studentID);
                activityLog.insert("Student " + studentID + " enrolled in course " + courseID);
                return;
            }
        }
        cout << "Course not found." << endl;
    }

    Course* findCourse(string courseID) {
        for (Course& course : courses) {
            if (course.courseID == courseID) {
                return &course;
            }
        }
        return nullptr;
    }

    void listCourses() {
        cout << "Available Courses:\n";
        for (Course& course : courses) {
            cout << course.courseID << " - " << course.courseName << endl;
        }
    }

    void displayActivityLog() {
        cout << "Activity Log:\n";
        activityLog.display();
    }

    void interactiveMenu() {
        int choice;
        do {
            cout << "\n---- Welcome to GIKI LMS ----\n";
            cout << "1. Add Course\n";
            cout << "2. Add User\n";
            cout << "3. Enroll Student in Course\n";
            cout << "4. List Courses\n";
            cout << "5. Display Activity Log\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string id, name;
                    cout << "Enter Course ID: ";
                    cin >> id;
                    cout << "Enter Course Name: ";
                    cin.ignore();
                    getline(cin, name);
                    addCourse(id, name);
                    break;
                }
                case 2: {
                    int userType;
                    cout << "Enter User Type (1 for Student, 2 for Teacher): ";
                    cin >> userType;
                    string id, name;
                    cout << "Enter User ID: ";
                    cin >> id;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    if (userType == 1) {
                        addUser(new Student(id, name));
                    } else if (userType == 2) {
                        addUser(new Teacher(id, name));
                    } else {
                        cout << "Invalid user type." << endl;
                    }
                    break;
                }
                case 3: {
                    string studentID, courseID;
                    cout << "Enter Student ID: ";
                    cin >> studentID;
                    cout << "Enter Course ID: ";
                    cin >> courseID;
                    enrollStudentToCourse(studentID, courseID);
                    break;
                }
                case 4:
                    listCourses();
                    break;
                case 5:
                    displayActivityLog();
                    break;
                case 6:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 6);
    }
};

// Main function
int main() {
    LMS lms;
    lms.interactiveMenu();
    return 0;
}
