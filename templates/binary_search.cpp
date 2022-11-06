#include <vector>
#include <iostream>

using namespace std;

/**
 * Binary search universal template
 * 
 * Key:
 *  1. use l < r
 *  2. use one of
 *      a. lean left: l + (r - l) / 2, l = mid+1 and r = mid
 *      b. lean right: l + (r - l + 1) / 2, l = mid, and r = mid -1
 *  3. Always output l
*/  

int upper_bound(vector<int>& v, int val) {
    int m = v.size();
    int l = 0, r = m;
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] <= val) l = mid + 1;
        else r = mid;
    }
    
    return l;
}

int lower_bound(vector<int>& v, int val) {
    int m = v.size();
    int l = 0, r = m;
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] < val) l = mid + 1;
        else r = mid;
    }
    
    return l;
}

int lu_bound(vector<int>& v, int val) {
    int m = v.size();
    int l = 0, r = m;
    
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (v[mid] <= val) l = mid;
        else r = mid - 1;
    }
    
    return l;
}

void display(vector<int> & v, int index) {
    for (auto c: v) cout << c << ' ';
    cout << endl;
    cout << string(2*index, ' ') << '^' << endl;
}

int main() {
    vector<int> v = {0, 1, 1, 1, 1, 2};
    cout << "vector: ";
    for (auto c: v) cout << c << ' ';
    cout << endl;

    cout << "Upper bound of 1" << endl;
    display(v, upper_bound(v, 1));
    cout << "Upper bound of 0" << endl;
    display(v, upper_bound(v, 0));;
    cout << "Lower bound of 0" << endl;
    display(v, lower_bound(v, 0));
    cout << "Lower bound of 1" << endl;
    display(v, lower_bound(v, 1));
    cout << "Lower bound of 2" << endl;
    display(v, lower_bound(v, 2));
    cout << "Last element of 1" << endl;
    display(v, lu_bound(v, 1));
}