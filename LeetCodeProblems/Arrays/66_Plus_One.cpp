class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
	int n = digits.size(), i; 
	for (i = n-1; i>=0; i--) {
		if(digits[i]!=9) {
			break;
		}
	}
	if(i==-1) {
		vector<int> v(n+1, 0);
		v[0]=1;
		return v;
	}
	digits[i]++;
	for(int j = i+1; j<n; j++) 
		digits[j] = 0;
	return digits;
}
};
