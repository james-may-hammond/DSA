#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bool comp(int a, int b){
    return a>b;
}
bool comp2(int a, int b){
    return a<b;
}
void printv(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> v = {6,3,1,5,7};
    printv(v);
    //notice the comp function it returns elements in decreasing order
    sort(v.begin(),v.end(), comp);
    printv(v);
    sort(v.begin(),v.end(), comp2);
    printv(v);
    //returns maximum element
    int maxVal = *max_element(v.begin(), v.end());
    return 0;

}