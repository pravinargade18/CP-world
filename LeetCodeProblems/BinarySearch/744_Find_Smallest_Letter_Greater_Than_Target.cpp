class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       int s=0;
        int e=letters.size()-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            
            if(letters[mid]<=target){
               s=mid+1;
                
            }
            else {
                e=mid;
            }
        }
        if(letters[s]>target){
            return letters[s];
        }
        return letters[0] ;
    }
};
