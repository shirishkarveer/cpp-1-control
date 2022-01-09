#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> numbers {};//init vec of init to empty , test : 1,2,3,4 = pass
    char selection {};//init to empty
    
    do {//logic do-while line 72
        // Display menu
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number"<< endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;//enter selection
//here user has selected at least one of above, now selection logic as below, choice logic, alternate ; switch-case
//i am using if-else ladder type logic
        
        if (selection == 'P' || selection == 'p') {
            if (numbers.size() == 0)//.size is method which returns the size
                cout << "[] - the list is empty" << endl;//tell user if list is empty
            else {//print all nums in list
                cout << "[ ";
                for (auto num: numbers)//range based for loop
                    cout << num << " ";
                cout << "]" << endl;//
            }
        } else if (selection == 'A' || selection == 'a') { // else-if ladder 
            int num_to_add {}; // then we need to add something - VAR to list 
            cout << "Enter an integer to add to the list: "; // o/p to user
            cin >> num_to_add;     
            numbers.push_back(num_to_add); //push_back to back of vector v/s emplace_back 
            cout << num_to_add << " added" << endl;   // test with empty vector
        } else if (selection == 'M' || selection == 'm') {   //vector should not be empty for M because calc mean
            if (numbers.size() == 0)
                cout << "Unable to calculate mean - no data" << endl;
            else {
                int total {};
                for (auto num: numbers)  //loop thru vector again 
                    total += num;     //each iteration total up all nos. tot = tot + num
                cout << "The mean is : " << static_cast<double>(total)/numbers.size() << endl; //coz safe to do so
            }
        } else if (selection == 'S' || selection == 's') {   //case list = empty 
            if (numbers.size() == 0)                          //some data written in the vec, pick a num and assume it's smallest
                cout << "Unable to determine the smallest - list is empty" << endl;
            else {              
                int smallest = numbers.at(0); //init 2 nos at 0
                for (auto num: numbers)
                    if (num < smallest)
                        smallest = num;
                cout << "The smallest number is: " << smallest << endl;
            }
        } else if (selection == 'L' || selection == 'l') {	// user wants largest number
            if (numbers.size() == 0)				//in this case nothing to check
                cout << "Unable to determine largest - list is empty"<< endl;   
            else {				//assume largest is 1st number
                int largest = numbers.at(0);  //same logic as above, 0 th location = 1st number in vector
                for (auto num: numbers)		
                    if (num > largest)
                        largest = num;
                cout << "The largest number is: " << largest << endl;
            }
        } else if (selection == 'Q' || selection == 'q') {//program stops at any case High or lower, test both , Most simple case
            cout << "Goodbye" << endl;
        } else {
            cout << "Unknown selection, please try again" << endl;
        }
    } while (selection != 'q' && selection != 'Q');//single quote coz char

    cout  << endl;
    return 0;
}
