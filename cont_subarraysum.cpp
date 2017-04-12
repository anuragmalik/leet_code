#include<vector>
#include<map>
#include<assert.h>
using namespace std;
bool find_contsubarray(vector<int>& nums, int k) {
    if (nums.size() <= 1) return false;
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] == 0 && nums[i + 1] == 0) return true;

    if (k == 0) return false;
    if(k < 0) k *= -1;
    map<int, int> rem_map;
    rem_map.insert(make_pair(0,-1));
    int sum = 0;
    for(int i=0; i < nums.size(); i++) {
        sum += nums[i];
        if(k > 0) sum %= k;
        map<int, int>::iterator pos = rem_map.find(sum);
        if(pos != rem_map.end()) {
            if (i - (pos->second) > 1) return true;
        }

        rem_map.insert(make_pair(sum, i));
    }
    return false;
}

int summain() {
    vector<int> v1 = {1, 2, 3};
    assert(find_contsubarray(v1, 5));
}