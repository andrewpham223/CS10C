#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned min = index;
    for(unsigned i = index + 1; i < vals.size(); i++) {
        if(vals.at(i) < vals.at(min)) {
            min = i;
        }
    }
    return min;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for(unsigned i = 0; i + 1 < vals.size(); i++) {
        unsigned indexOfMin = min_index(vals, i);
        T tempVal = vals.at(i);
        vals.at(i) = vals.at(indexOfMin);
        vals.at(indexOfMin) = tempVal;
    } 
}

template<typename T>
T getElement(vector<T> vals, int index) {
    unsigned valsIndex = index;

    if(index < 0 || valsIndex >= vals.size()) {
        throw out_of_range("out of range exception occurred\n");
    }

    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main() {
    //Part B
    try {
        srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        int index;
        int numOfRuns = 10;
        while(--numOfRuns >= 0){
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch(out_of_range &except) {
        cout << except.what();
    }
    return 0;
}


