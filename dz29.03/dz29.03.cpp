#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Basic class to hold date information
class BasicDate {
public:
    int day;
    int month;
    int year;

    BasicDate(int d, int m, int y) : day(d), month(m), year(y) {}
};

// Class to encapsulate address details
class Address {
public:
    string country;
    string state;
    string city;
    string street;
    int houseNumber;
    char building;

    Address(string c, string s, string ct, string st, int hn, char b)
        : country(c), state(s), city(ct), street(st), houseNumber(hn), building(b) {}
};

// Class to manage personal details
class PersonDetails {
public:
    string firstName;
    string lastName;
    string middleName;
    BasicDate* birthDate;
    Address* residence;

    PersonDetails(string fn, string ln, string mn, BasicDate* bd, Address* addr)
        : firstName(fn), lastName(ln), middleName(mn), birthDate(bd), residence(addr) {}
};

// Class to manage university related information
class AcademicInfo {
public:
    BasicDate admissionDate;
    int currentCourse;
    string groupID;
    string fieldOfStudy;
    int totalStudents;

    AcademicInfo(BasicDate ad, int cc, string gid, string fs, int ts)
        : admissionDate(ad), currentCourse(cc), groupID(gid), fieldOfStudy(fs), totalStudents(ts) {}
};

// Class to manage student grades
class AcademicPerformance {
public:
    vector<int> homeworkScores;
    vector<int> projectScores;
    vector<int> examScores;
    vector<int> creditScores;

    void addHomeworkScore(int score) {
        homeworkScores.push_back(score);
    }

    void addProjectScore(int score) {
        projectScores.push_back(score);
    }

    void addExamScore(int score) {
        examScores.push_back(score);
    }

    void addCreditScore(int score) {
        creditScores.push_back(score);
    }
};

// Main student class encapsulating all personal and academic information
class Student {
private:
    PersonDetails* personalDetails;
    AcademicInfo* academicDetails;
    AcademicPerformance* performance;

public:
    Student(PersonDetails* pd, AcademicInfo* ad, AcademicPerformance* perf)
        : personalDetails(pd), academicDetails(ad), performance(perf) {}

    ~Student() {
        delete personalDetails->birthDate;
        delete personalDetails->residence;
        delete personalDetails;
        delete academicDetails;
        delete performance;
    }

    void displayStudentInfo() {
        cout << "Student: " << personalDetails->firstName << " " << personalDetails->lastName << endl;
        cout << "Born: " << personalDetails->birthDate->day << "/"
             << personalDetails->birthDate->month << "/" << personalDetails->birthDate->year << endl;
        cout << "Studying: " << academicDetails->fieldOfStudy << " in group " << academicDetails->groupID << endl;
        cout << "Address: " << personalDetails->residence->street << ", " 
             << personalDetails->residence->city << ", " << personalDetails->residence->country << endl;
    }
};

int main() {
    // Example usage
    BasicDate* date = new BasicDate(12, 8, 1999);
    Address* addr = new Address("USA", "CA", "San Francisco", "Sunset Blvd", 10, 'A');
    PersonDetails* pd = new PersonDetails("John", "Doe", "Edward", date, addr);
    AcademicInfo* ad = new AcademicInfo(*date, 3, "CS101", "Computer Science", 30);
    AcademicPerformance* perf = new AcademicPerformance();

    Student john(pd, ad, perf);
    john.displayStudentInfo();
    return 0;
}