#include<iostream>
using namespace std;

//I used C++ to find the equilibrium index of an array because this method is efficient. 

//Pass the size of the array as a parameter.
//Assume that the array is not empty.
int balanced(int arr[], int n){
        //First, initialize sum of the whole array.
        int sum=0;
        for(int i=0;i<n;i++){  //Then, find the sum of the whole array.
                sum+=arr[i];
        }
//Initialize sum of elements on left indices equal to the first element and sum of elements on right indices equal to sum minus the first element.
        int leftSum=arr[0], rightSum=sum-arr[0];
        //Loop through indices 1 and n-2.
        for(int i=1;i<n-1;i++){
       //Check if leftSum and rightSum minus current element are equal.
                if(leftSum==(rightSum-arr[i])){
                        //returning i.
                        return i;
                  }else{
                        //Or add current element to leftSum.
                        leftSum+=arr[i];
                        //Subtract from the right sum.
                        rightSum-=arr[i];
                }
        }
        //If no equilibrium index is found, then return -1.
        return -1;
}
//An approach that I wanted to consider solving this problem was to use two loops, but I did not utilize that method because it would be inefficient. 
//I chose this approach of obtaining the total array of the sum first because I will not have to use another loop to find the sum of elements on the left and right on each iteration of the loop, which will increase the overall running time of the function.
int main(){
//Driver code to test all the test cases provided in the question.
        int a1[]={-8, 2, 6, 2, -5, 4, 1};
        cout<<balanced(a1,7)<<endl; //3
        int a2[]={2, 4, 6};
        cout<<balanced(a2,3)<<endl; //-1
        int a3[]={4, -3, 5, 1, 2, 5, -1};
        cout<<balanced(a3,7)<<endl; //3
        int a4[]={16, 8, 2, 4, 4, 6};
        cout<<balanced(a4,6)<<endl; //1
        int a5[]={2, 4, 4, 0, -3, 3, 1, 6};
        cout<<balanced(a5,8)<<endl; //4 or 5 
        
//For the test case above, the output could be 4 or 5. 
//Both are true because if you select index 4, the sum of [2, 4, 4, 0] will be equal to the sum of [3, 1, 6]. 
//If you select index 5, the sum of [2, 4, 4, 0, -3] will be equal to the sum of [1, 6]. 
//The loop from left to right, will return 4 as an output instead. 
    
        int a6[]={2, 3, 5, 5, 2};
        cout<<balanced(a6,5)<<endl; //-1
        return 0;
}
