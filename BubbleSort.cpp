#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::ifstream;
using std::vector;

int main(int argc, char* argv[]) {
    int size;
    // Get command line input
    if (argc > 1) {
        size = stoi(argv[1]);
    } else {
        size = 10000;
    }
    cout << "Looking for size: " << size << endl;
    
    // TODO: Declare a vector of longs to store the numbers
    vector<long> nums;
    long num;
    
    // TODO: Read size numbers from numbers.txt x
    ifstream inFile;
    inFile.open("numbers.txt");
    while (inFile && inFile.peek() != EOF && nums.size() < size) {
        inFile >> num;
        nums.push_back(num);
    }
    inFile.close();
    
    // TODO: Print the vector size (to make sure it matches the size printed above) x
    cout << "Vector size: " << nums.size() << endl;
    
    // TODO: Bubble Sort the vector x
    bool swapped = true;
    long temp;
    int maxIndex = nums.size()-1;
    while(swapped) {
        swapped = false;
        for (int i = 0; i < maxIndex; ++i) {
            //compare items at indices i and i+1, swap if needed
            if (nums[i] > nums[i+1]) {
                temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                //update swapped
                swapped = true;
            }
        }
        //update maxIndex
        maxIndex -= 1;
    }
    
    // TODO: Print the first and last ten numbers from the vector to the console x
    cout << "To show that it worked, here are the first ten and last ten numbers: " << endl;
    //first 10 numbers
    for (int j = 0; j < 10; j++) {
        if (j <= 8) {
            cout << nums[j] << ", ";
        }
        else {
            cout << nums[j];
        }
    }
    cout << endl;
    cout << "..." << endl;

    for (int k = nums.size() - 10; k < nums.size(); k++){
        if (k <= nums.size() - 2) {
            cout << nums[k] << ", ";
        }
        else {
            cout << nums[k];
        }
    }
    cout << endl;

    return 0;
}
