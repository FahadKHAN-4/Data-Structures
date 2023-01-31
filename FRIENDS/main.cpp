/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 196416
 * Submitted at:  2021-12-05 13:13:54
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    142
 * Problem Name:  FRIENDS (UVa 10608)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int citizens[1000000], sum[1000000];

int search(int temp) {
    if (temp == citizens[temp]){
        return temp;
    }else{
        return citizens[temp] = search(citizens[temp]);
    }
}

int answer(int a, int b, int ans){
    a = search(a);
    b = search(b);
    if (a != b) {
        citizens[a] = b;
        sum[b] += sum[a];
        if (ans < sum[b]){
            ans = sum[b];
        }
    }
    return ans;
}


int main() {
    
    int noOfInputs;
    int ans=0;
    cin >> noOfInputs;
    
    int* answers = new int[noOfInputs];
    
    for(int i=0; i<noOfInputs; i++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            citizens[i] = i;
            sum[i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            int a, b;
            
            cin >> a >> b;
            ans = answer(a, b, ans);
            
        }
        answers[i] = ans;
    }
    
    for(int i=0; i<noOfInputs; i++){
        cout<< answers[i]<<endl;
    }
}