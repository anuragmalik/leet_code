#include<set>
#include<vector>
#include<assert.h>
using namespace std;
bool duplicate3(vector<int>& nums, int k, int t) {
    set<long long> wnd;
    for(int i = 0; i < nums.size(); i++) {
        if(i > k) wnd.erase(nums[i-k-1]);
        auto pos = wnd.lower_bound((long long) nums[i] - t);
        if(pos != wnd.end() && *pos - nums[i] <= t) return true;
        wnd.insert((long long)nums[i]);
    }
    return false;
}

int dup_main() {
    vector<int> v0 = {};
    assert(!duplicate3(v0, 0, 0));

    vector<int> v1 = {9, 4, 1, 6, 12, 6, 10, 24, 8};
    assert(duplicate3(v1, 3, 2));
    assert(duplicate3(v1, 3, 0));
    assert(!duplicate3(v1, 1, 2));

    vector<int> v2 = {-2147483647, -2147483648};
    assert(duplicate3(v2, 1, 1));
}
