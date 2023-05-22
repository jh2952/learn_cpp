// Create a struct to hold students first name and grade.
// Ask the user how many students they want to enter.
// Create a vector to hold all students.
// Prompt user for name and grade.
// Sort in order of highest to lowest grade.

#include <iostream>
#include <algorithm>
#include <vector>

struct Student
{
	std::string name{};
	int grade{};
};

int howManyStudents()
{
	std::cout << "How many students would you like to enter? ";
	int amount{};
	std::cin >> amount;
	return amount;
}

Student enterDetails()
{
	Student student{};
	std::cout << "Enter a name: ";
	std::cin >> student.name;
	std::cout << "Enter a grade: ";
	std::cin >> student.grade;
	return student;

}

bool sortGrade(Student& a, Student& b)
{
	return(a.grade > b.grade);
}

int main()
{
	std::vector<Student> students;
	students.resize(howManyStudents());

	for (auto& student : students)
	{
		student = enterDetails();
	}

	std::sort(students.begin(), students.end(), sortGrade);

	for (auto& student : students)
	{
		std::cout << student.name << " got a grade of " << student.grade << '\n';
	}

}
