#include <iostream>
#include <chrono>
using namespace std;

int main() {
    
    ector<string> v;
    list<string> l;
    set<string> s;
    string nm;

    // read codes.txt into vector
    auto start = high_resolution_clock::now();
    ifstream fin1("codes.txt");
    while (true) {
        getline(fin1, nm);
        v.push_back(nm);
    }
    fin1.close();
    vRead = duration.count();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    
    // read codes.txt into list
    start = high_resolution_clock::now();
    ifstream fin2("codes.txt");
    while (true) {
        getline(fin2, nm);
        l.push_back(nm);
    }
    fin2.close();
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start + 1);

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/