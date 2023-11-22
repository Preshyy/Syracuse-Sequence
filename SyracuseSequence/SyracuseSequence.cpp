// SyracuseSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> // Including the string library
#include <vector> // Including the vector library
#include <cmath> // Including the cmath library
#include <algorithm> // Including the algorithm library
using namespace std;

// Collatz Sequence method - calculations included
/**
* Collatz Sequence
* If even number: divide by 2
* If odd number: multiply by 3 and add 1 (3n + 1)
*/

int moves;

void collatz_sequence(double n, vector<double>& sequence) {
	sequence.push_back(n);
	while (n != 1) {
		if (fmod(n, 2) == 0) {
			n = n / 2;
		}
		else {
			n = 3 * n + 1;
		}
		sequence.push_back(n);
		moves++; // Increment the moves counter
	}
}

// Method to display the generated sequence based on user input
void visualize_sequence(const vector<double>& sequence) {
	cout << "Syracuse Sequence: " << endl;
	for (double num : sequence) {
		cout << num << endl;
	}
}

/*
* Bool method to display the status of a generated sequence
* This method displays a comment that points out when a sequence ends in a
* 4-2-1 loop. It also displays a comment that points out when a sequence does not
* end in the loop
*/
bool ends_in_421(const vector<double>& sequence) {
	return sequence.back() == 1;
}

// Main method
int main() {
	int option;
	string start_number_str; // Changing data type to string
	long double start_number; // Data type to store the converted numeric value
	vector<double> collatz_seq;

	// do while loop for reusability
	do {

		moves = 0; // Resets the moves counter for each new sequence

		// User menu
		cout << "Choose an option: " << endl;
		cout << "1. Normal integers" << endl;
		cout << "2. Decimal numbers" << endl;
		cout << "3. Negative numbers" << endl;
		cin >> option;

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer
		// This should fix the space appearing below the menu issue

		// switch to execute the code based on the options chosen by the user
		switch (option) {
		case 1:
			cout << "Enter the starting number for the Syracuse sequence (integer): ";
			break;
		case 2:
			cout << "Enter the starting number for the Syracuse sequence (decimal): ";
			break;
		case 3:
			cout << "Enter the starting number for the Syracuse sequence (negative): ";
			break;
		default:
			cout << "Invalid option. Exiting the program." << endl;
			return 1;
		}

		// Read the input as a string
		// The string will then be converted to integers or decimal numbers
		getline(cin, start_number_str);
		// cout << "\n"; // Visual indentation

		/**
		* Converting the string to numeric values based on the user's menu selection
		* using stoi (string to integer) and stod (string to double)
		*/
		try {
			if (option == 1) {
				start_number = stoi(start_number_str); // Convert to int - stoi
			}
			else if (option == 2) {
				start_number = stod(start_number_str); // Convert to double - stod
			}
			else {
				// For negative numbers, it only needs to be converted to a double since it might be a decimal point
				start_number = stod(start_number_str);
			}
		}
		catch (const exception& e) {
			cout << "Invalid input. Exiting the program." << endl; // Edge case for invalid input
			return 1;
		}

		collatz_seq.clear(); // Clear the previous sequence
		collatz_sequence(start_number, collatz_seq);
		visualize_sequence(collatz_seq);

		// Calling the bool method to check the sequence for the 4-2-1 loop
		if (ends_in_421(collatz_seq)) {
			cout << "The number: " << start_number_str << " ends in the 4-2-1 loop" << endl;
			cout << "Number of moves to 1: " << moves << endl; // Displays the number of moves to 1
			cout << "\n"; // Visual indentation
		}
		else {
			cout << "The number: " << start_number_str << " does not end in the 4-2-1 loop";
		}

		// Repeat prompt
		char repeat;
		cout << "Do you want to generate another sequence? (Y/N): ";
		cin >> repeat;

		if (repeat == 'n' || repeat == 'N') {
			cout << "Have a good day! Exiting program..." << endl;
			break; // Exit the loop if the user does not want to continue
		}
	} while (true);

	return 0;
}

// Summary notes: Things to add to the code - 03/08/2023
/**
- Add a function that displays the "stopping time" of each sequence generated
*/
