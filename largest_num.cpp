#include<vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool sorter (int i,int j) { return (to_string(i) + to_string(j) > to_string(j) + to_string(i)); }

string larget_num(vector<int>& nums) {
    sort(nums.begin(), nums.end(), sorter);
    string res;
    for(auto val : nums) {
        res += to_string(val);
    }
    while(res[0]=='0' && res.length()>1)
        res.erase(0,1);
    return res;
}

int lrgmain() {
    vector<int> v1 = {3, 30, 34, 5, 9};
    cout << larget_num(v1);
}