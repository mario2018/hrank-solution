#include <iostream>
#include <vector>

using namespace std;

void minimumBribes(vector<int> q){
    bool swapped = false;
    int swaps = 0;
    int q_length = q.size();
    for(int i=0; i<q_length; i++){
        if(q[i]-1-i > 2){
            cout<<"Too chaotic"<<endl;
            //We can simply write return statement in a void fun(). 
            //In-fact it is considered a good practice (for readability of code) to write return; statement to indicate end of function.
            return; 
        }
    }
    //bubbling sort
    for(int j=0; j<q_length; j++){
        for(int k=0; k<q_length-j; k++){
            if(q[k]>q[k+1]){
                int temp = q[k+1];
                q[k+1] = q[k];
                q[k] = temp;
                swaps+=1;
                swapped = true;
            }
        }
        if(swapped){
            swapped = false;
        }else{
            break;
        }
    }
    cout<<swaps<<endl;
}

int main(){
    //vector<int> q = {2,1,5,3,4};
    vector<int> q = {2,5,1,3,4};
    minimumBribes(q);

    return 0;
}