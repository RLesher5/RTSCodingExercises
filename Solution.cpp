using namespace std;

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution{
public:
    string stringRotation(string s, int i){
        //Adjustment for large rotation input
        i %= s.length();
        
        //Adjustment for negative rotation input
        if(i < 0){
            i += s.length();
        }
        
        //Base Case: Empty String, Single Character, No Rotation
        if(s.empty() || s.length() == 1 || i == 0){
            return s;
        }
        
        //Reverse Prefix
        reverse(s.begin(), s.end()-i);

        //Reverse Suffix
        reverse(s.end()-i, s.end());

        //Reverse String
        reverse(s.begin(), s.end());

        //Return Rotated String
        return s;
    }

    unordered_map<string, int> aboveBelow(vector<int> nums, int target) {
        //Base Case Size Equals 0
        if(nums.size() == 0){
            return unordered_map<string, int> {{"above", 0}, {"below", 0}};
        }
        
        //Base Case Size Equals 1
        if(nums.size() == 1){
            //Above Target
            if(nums[0] > target){
                return unordered_map<string, int> {{"above", 1}, {"below", 0}};
            }
            //Below Target
            else if(nums[0] < target){
                return unordered_map<string, int> {{"above", 0}, {"below", 1}};
            }
            //Equals Target
            else{
                return unordered_map<string, int> {{"above", 0}, {"below", 0}};
            }
        }
        
        //Create output map
        unordered_map<string, int> count;
        
        //Sort vector in increasing order
        sort(nums.begin(), nums.end());
        
        //Loop over vector entries while value below target
        int i;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] >= target){
                break;
            }
        }
        
        //Add count for below
        count["below"] = i;
        
        //Skip over values equal to target
        while(nums[i] == target){
            i++;
        }
        
        //Add count of remaining indexes for above
        count["above"] = nums.size()-i;
        
        //Return Map
        return count;
    }
};

int main() {
    Solution s;
    
    string str = "MyString";
    int num = 2;
    cout << "Original String: " << str << endl;
    cout << "Rotated String:  " << s.stringRotation(str, num) << endl;
    
    vector<int> nums = {1, 5, 2, 1, 10};
    int val = 6;
    unordered_map<string, int> count = s.aboveBelow(nums, val);
    cout << "{ above : " << count["above"] << " , below : " << count["below"] << " }" << endl;
}
