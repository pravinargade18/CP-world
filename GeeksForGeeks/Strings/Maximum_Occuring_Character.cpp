// approach-1
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
       vector<int>v(26,0);
       for(int i=0;i<str.length();i++){
           char ch=str[i];
           int number=0;
           number=ch-'a';
           v[number]++;
       }
       
       int maxi=-1,ans=0;
       for(int i=0;i<26;i++){
           if(v[i]>maxi){
               maxi=v[i];
               ans=i;
           }
       }
        return 'a'+ans;
    }

};

// approach - 2-->using unordered_map
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        unordered_map<char,int>m;
        vector<char>v;
        for(auto i:str){
            m[i]++;
        }
        int maxi=0;
        for(auto j:m){
            maxi=max(maxi,j.second);
        }
        for(auto k:m){
            if(k.second==maxi){
                v.push_back(k.first);
            }
        }
        char min_ch=v[0];
        for(int i=0;i<v.size();i++){
            min_ch=min(min_ch,v[i]);
        }
        return min_ch;
        
    }

};
