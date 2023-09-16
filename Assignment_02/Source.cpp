#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Defining a struct to store student data
struct STUDENT_DATA {
    std::string first_name;
    std::string last_name;
    std::string email;
};

// Defining the PRE_RELEASE macro to enable pre-release mode
//#define PRE_RELEASE

int main() {
    // Creating a vector to store student data
    std::vector<STUDENT_DATA> student_vector;

    // Opening and checking the input file (StudentData.txt)
    std::ifstream input_file("StudentData.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open StudentData.txt" << std::endl;
        return 1;
    }

    // Reading each line from the input file
    std::string line;
    while (std::getline(input_file, line)) {
        // Parsing the line by finding the comma separator
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) {
            // Creating a student object and populate first_name and last_name
            STUDENT_DATA student;
            student.last_name = line.substr(0, comma_pos);
            student.first_name = line.substr(comma_pos + 1);

            // Adding the student to the vector
            student_vector.push_back(student);
        }
    }

    // Checking if the code is compiled using the PRE_RELEASE directive
#ifdef PRE_RELEASE
    std::cout << "Application is running in pre-release mode." << std::endl;
    std::cout << std::endl;
    // Opening and checking the email input file (StudentData_Emails.txt)
    std::ifstream email_file("StudentData_Emails.txt");
    if (!email_file.is_open()) {
        std::cerr << "Error: Could not open StudentData_Emails.txt" << std::endl;
        return 1;
    }

    // Reading email addresses from StudentData_Emails.txt and associating them with students
    for (size_t i = 0; i < student_vector.size(); ++i) {
        std::string email;
        if (std::getline(email_file, email)) {
            student_vector[i].email = email;
        }
        else {
            std::cerr << "Error: Unable to read email data for student " << i + 1 << std::endl;
        }
    }

    // Closing the email file stream
    email_file.close();
#else
    std::cout << "Application is running in standard mode." << std::endl;
    std::cout << std::endl;
#endif

    // Displaying student information
    std::cout<<"STUDENT's INFORMATION" << std::endl;
    std::cout << std::endl;
    for (const auto& student : student_vector) {
        std::cout << "First Name: " << student.first_name << ", Last Name: " << student.last_name;

#ifdef PRE_RELEASE
        // Printing email addresses only in pre-release mode
        std::cout << ", Email: " << student.email;
#endif

        std::cout << std::endl;
    }

    // Closing the input file stream
    input_file.close();

    return 0;
}
