class Solution
{
    public:
    int sum(int a , int b)
    {
    int carry = 0;
       while(b && 1){
           carry = a & b;
           a = a ^ b;
           b = carry << 1;
       }
       return a;
    }
};
