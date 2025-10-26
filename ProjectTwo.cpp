#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Course structure
struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// Function to load data from file into a hash table
unordered_map<string, Course> LoadDataStructure(string fileName) {
    unordered_map<string, Course> courses;
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return courses;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2) {
            cout << "Warning: Invalid line format -> " << line << endl;
            continue;
        }

        Course course;
        course.courseNumber = tokens[0];
        course.title = tokens[1];

        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        // Store in hash table using courseNumber as key
        courses[course.courseNumber] = course;
    }

    file.close();
    cout << "Data loaded successfully!" << endl;
    return courses;
}

// Function to print the entire course list in alphanumeric order
void PrintCourseList(const unordered_map<string, Course>& courses) {
    if (courses.empty()) {
        cout << "No data loaded. Please load the file first." << endl;
        return;
    }

    vector<string> keys;
    for (auto const& pair : courses) {
        keys.push_back(pair.first);
    }

    sort(keys.begin(), keys.end());

    cout << "\nHere is a sample schedule:\n" << endl;

    for (auto const& key : keys) {
        cout << key << ", " << courses.at(key).title << endl;
    }
    cout << endl;
}

// Function to print details for a specific course
void PrintCourse(const unordered_map<string, Course>& courses, string courseNumber) {
    if (courses.empty()) {
        cout << "No data loaded. Please load the file first." << endl;
        return;
    }

    // Convert input to uppercase to match stored keys
    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);

    auto it = courses.find(courseNumber);
    if (it == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }

    Course course = it->second;
    cout << course.courseNumber << ", " << course.title << endl;

    if (!course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    else {
        cout << "Prerequisites: None" << endl;
    }
}

// Display menu
void DisplayMenu() {
    cout << "\n1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit\n" << endl;
    cout << "What would you like to do? ";
}

int main() {
    unordered_map<string, Course> courses;
    string fileName;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the file name to load: ";
            //Ignore spaces in file name
            cin.ignore();
            getline(cin, fileName);
            courses = LoadDataStructure(fileName);
            break;

        case 2:
            PrintCourseList(courses);
            break;

        case 3: {
            string courseNum;
            cout << "What course do you want to know about? ";
            cin >> courseNum;
            PrintCourse(courses, courseNum);
            break;
        }

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << "\n" << choice << " is not a valid option.\n" << endl;
            break;
        }
    }

    return 0;
}
