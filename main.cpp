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
    
    ector<string> v;
    list<string> l;
    set<string> s;
    string nm;

    long long vRead, lRead, sRead;

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
        s.insert(nm); // 对应 set 示例: drinks.insert(nm)
    }
    fin3.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    sRead = duration.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/