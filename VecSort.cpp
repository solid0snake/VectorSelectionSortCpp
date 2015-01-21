//============================================================================
// VecSort.cpp
// by Pedro Garate on 01/20/2015
// Description : This program sorts a list of integers (vector) using a selection
// sort algorithm. It takes input from the user through the keyboard until a 
// non-numeric character is entered, it then shows the user all the numbers in 
// the order they were entered and finally it shows all the numbers sorted 
// from low to high.
//============================================================================

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void selectionSort(vector<int>& vec);

int main() {
	cout << "VECTOR SORT:" << endl;
	int imin = std::numeric_limits<int>::min(); // minimum possible value
	int imax = std::numeric_limits<int>::max(); // maximum possible value
	cout << "Keep in mind that this program only accepts values between\n"
		<< imin << " and " << imax << "." << endl;
	cout << "Please type the numbers to be sorted (type any non-numeric\n"
		"character and press ENTER to submit):" << endl;

	int input;
	vector<int> v;
	while (cin >> input) {// while input is int
		v.push_back(input);
	}// end while

	cout << endl << "Your numbers are: " << endl;
	for (unsigned int i = 0; i<v.size(); i++) {
		cout << v[i] << " ";
	}// end for
	cout << endl;

	selectionSort(v);

	cout << endl << "Your sorted numbers are: " << endl;
	for (unsigned int i = 0; i<v.size(); i++) {
		cout << v[i] << " ";
	}// end for
	cout << endl;
	return 0;
}// end main

void selectionSort(vector<int>& vec) {
	unsigned int curPos, minPos;
	size_t size = vec.size();
	for (curPos = 0; curPos < size; curPos++) {
		minPos = curPos;

		for (unsigned int i = curPos + 1; i < size; i++) {
			if (vec[i] < vec[minPos]) {
				minPos = i;
			}// end if
		}// end for

		if (minPos != curPos) { //swap
			std::swap(vec.at(minPos), vec.at(curPos));
		}// end if
	}// end for
}// end selectionSort
