#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
vector<int> getSecondLargest(vector<int> &arr) {
       int max = -1;
       int max2 = -1;
       int max3 = -1;

        for (int i = 0;i<arr.size();i++){
            if (arr[i]>max){
                max3=max2;
                max2=max;
                max=arr[i];
            }
            else if(arr[i]<max && arr[i]>max2){
                max3=max2;
                max2 = arr[i];
            }
            else if(arr[i]<max && arr[i]<max2 && arr[i]>max3){
                max3 = arr[i];
            }
        }
        vector<int> res;
        if (max==max2 && max2==max3){
            res[0] = max;
        } else if (max == max2 && max2!=max3){
            res[0] = max;
            res[1] = max3;
        } else if (max2 == max3 && max!=max3){
            res[0] = max;
            res[1] = max3;
        } else if (max == max3 && max!=max2){
            res[0] = max;
            res[1] = max2;
        } else {
            res[0] = max;
            res[1] = max2;
            res[2] = max3; 
        }
    //we have used both erase and remove as remove removes the element and erase deletes the address
    res.erase(remove(res.begin(), res.end(), -1),res.end());
    return res;
}
int main() {
    
    return 0;
}