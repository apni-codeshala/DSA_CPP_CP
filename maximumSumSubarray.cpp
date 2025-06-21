#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

int maximumSumSubarray(vector<int> &arr, int k) { 
    long int max = -1e7; 
    long int sum = 0; 
    for(int i=0; i<=k-1; i++) 
        sum += arr[i]; 
    max = sum; 
    int l = 0, r = k-1; 
    while (r+1 < arr.size()) { 
        r++; 
        sum += arr[r]; 
        sum -= arr[l]; 
        l++; 
        if(sum > max) { 
            max = sum; 
        } 
    } 
    return max; 
}

int main() { 
    vector<int> inp; 
    string value; 
    cout<<"Enter the values of array one by one: "; 
    while (getline(cin, value)) {
        if (value.empty()) { 
            break; 
        } 
        inp.push_back(stoi(value)); 
    }

    cout<<"Enter the size of subarray: ";
    int sub;
    cin>>sub;

    int max = maximumSumSubarray(inp, sub);
    cout<<"Maximum sum subarray of size "<<sub<<" is "<<max;

    return 0;
}
