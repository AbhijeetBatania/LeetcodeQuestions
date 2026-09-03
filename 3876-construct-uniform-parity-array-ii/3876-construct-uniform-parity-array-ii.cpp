class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sodd = INT_MAX;

        for(int i : nums1){
            if(i%2 == 1){
                sodd = min(sodd, i);
            }
        }

        bool eflag = true;
        bool oflag = true;

        for(int i : nums1){
            if(eflag == true && i%2 == 0){  // make all odd
                if( i-sodd < 1){
                    eflag = false;
                }
            }
            else if(oflag == true && i%2 == 1){  // make all even
                if( i-sodd < 1){
                    oflag = false;
                }
            }  
        }
        return eflag || oflag;
    }
};




