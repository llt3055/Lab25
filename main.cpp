#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    
    vector<string> v;
    list<string> l;
    set<string> s;
    string nm;

    long long vRead, lRead, sRead;
    long long vSort, lSort, sSort;
    long long vIns, lIns, sIns;

    // read codes.txt into vector
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    while (getline(fin1, nm)) {
        v.push_back(nm);
    }
    fin1.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    vRead = duration.count();
    
    // read codes.txt into list
    start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
    while (getline(fin2, nm)) {
        l.push_back(nm);
    }
    fin2.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lRead = duration.count();

    // Set Read
    start = high_resolution_clock::now();
    ifstream fin3("codes.txt");
    while (getline(fin3, nm)) {
        s.insert(nm); 
    }
    fin3.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sRead = duration.count();

    // List Sort
    start = high_resolution_clock::now();
    l.sort();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lSort = duration.count();

    // Set (Already sorted by design)
    sSort = -1;

    // Vector Insert
    start = high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    vIns = duration.count();
    

    // List Insert
    auto itL = l.begin();
    start = high_resolution_clock::now();
    advance(itL, l.size());
    end = high_resolution_clock::now();
    l.insert(itL, "TESTCODE");
    duration = duration_cast<nanoseconds>(end - start -1);
    lIns = duration.count();

    // Set Insert

    duration = duration_cast<nanoseconds>(end - start);
    start = high_resolution_clock::now();
    end = high_resolution_clock::now();
    sIns = duration.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/