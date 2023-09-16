#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Defining a struct to represent student data
struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {
    // Opening the input file
    std::ifstream inputFile("StudentData.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1; // Exit with an error code
    }

    // Creating a vector to store student objects
    std::vector<STUDENT_DATA> studentVector;

    // Reading data from the input file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Parsing the line by splitting on the comma
        size_t commaPos = line.find(",");
        if (commaPos != std::string::npos) {
            // Extracting first name and last name
            std::string lastName = line.substr(0, commaPos);
            std::string firstName = line.substr(commaPos + 1);

            // Creating a student object and adding it to the vector
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            studentVector.push_back(student);
        }
    }

    // Closing the input file
    inputFile.close();
    // Debug functionality (only if compiled in debug mode)
#ifdef _DEBUG
    std::cout << "Information of students" << std::endl;
    std::cout << std::endl;
    for (const auto& student : studentVector) {

        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << std::endl;
    }
#endif

   
    return 0; // Exit successfully
}
