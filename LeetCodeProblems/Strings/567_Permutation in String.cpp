class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> w(26,0), h(26,0);
        for(int i = 0; i<s1.size(); i++){
            w[s1[i]-'a']+=1;
            h[s2[i]-'a']+=1;
        }
        if(w==h) return true;
        for(int i = s1.size(); i<s2.size(); i++){
            h[s2[i-s1.size()]-'a']--;
            h[s2[i]-'a']++;
            if(w==h) return true;
        }
        return false;
    }
};
