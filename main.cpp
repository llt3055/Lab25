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

    long  vRead, lRead, sRead;
    long  vSort, lSort, sSort;
    long  vIns, lIns, sIns;
    long  vDel, lDel, sDel;

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
    start = high_resolution_clock::now();
    auto itL = l.begin();
    advance(itL, l.size() / 2);
    l.insert(itL, "TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lIns = duration.count();

   // Set Insert
    start = high_resolution_clock::now();
    s.insert("TESTCODE");
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sIns = duration.count();

    // Vector Delete
    start = high_resolution_clock::now();
    end = high_resolution_clock::now();
    v.erase(v.begin() + v.size()+1);
    

    // List Delete
    start = high_resolution_clock::now();
    itL = l.begin();
    advance(itL, l.size() / 2);
    l.erase(itL);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    lDel = duration.count();
 
    vDel = duration.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/