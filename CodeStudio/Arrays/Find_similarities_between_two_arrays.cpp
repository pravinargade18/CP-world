pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        um[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
        um[arr2[i]]++;
    }
    int count=0;
    for(auto i : um){
        if(i.second == 2){
            count++;
        }
    }
//     int s=um.size();
    return {count,um.size()};

}
