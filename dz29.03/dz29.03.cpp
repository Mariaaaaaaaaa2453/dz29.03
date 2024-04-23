#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
	int day;
	int month;
	int year;
};
class Location {
	string country;
	string region;
	string city;
	string street;
	int house_number;
	char korpus;
};

class PersonalInfo {
	string firstname;
	string surname;
	string lastname;
	Date* birthday;
	Location* location;
};


class UniversityInfo {

	Date start_date;
	int course;
	string group_name;
	string specialization;
	int students_count;
};

class Grades {
	vector <int> dz_rates;
	vector <int> practice_rates;
	vector <int> exam_rates;
	vector <int> zachet_rates;
};


class Student {
	PersonalInfo* personalInfo;
	UniversityInfo* university;
	Grades* grades;
};