#include <iostream>
#include <vector>
using namespace std;
// passing the vector by refrence &v is more efficient as the entire vector is not passed through
void printv(vector<int> &v) {
    for (int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v = {1,2,3,4,5};
    printv(v);
    // Inserting and deleting elements from specefic places
    v.insert(v.begin()+1,9);
    printv(v);
    v.erase(find(v.begin(),v.end(),9));
    printv(v);
    return 0;
}