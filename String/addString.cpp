class Solution {
public:
    string add(string nums1, string nums2){
        //size of nums1 > nums2
        int n1 = nums1.size() - 1;
        int n2 = nums2.size() - 1;
        //hm r->l add krte h hence n1 and n2 are last index
        string ans;
        int carry = 0, sum = 0;
        while (n2 >= 0){
            sum = (nums1[n1] - '0') + (nums2[n2] - '0') + carry; //add num and carry in int form
            carry = sum/10;
            char c = '0' + sum%10; //kitna niche bachta h
            ans +=  c;
            n2--;
            n1--;
        }
        //jb nums2 exhuast ho jaye, nums1 still there
        while (n1 >= 0){
            sum = (nums1[n1] - '0') + carry; //add num and carry in int form
            carry = sum/10;
            char c = '0' + sum%10; //kitna niche bachta h
            ans +=  c;
            n1--;
        }
        //in case carry bach jaye
        if (carry) ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings(string nums1, string nums2) {
        if (nums1.size() < nums2.size()) 
            return add(nums2, nums1);
        else
            return add(nums1, nums2);
    }
};