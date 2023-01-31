/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 217320
 * Submitted at:  2022-05-08 17:31:14
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    22
 * Problem Name:  Prime Path
 */

#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int isPrime( int n){
    
    int i,t;
    t=sqrt(n+0.0);
    
    for (i=2;i<=t;i++){
        if (n%i==0) return -2;
    }
    return -1;
    
}

int main(){
    
    vector<int> answers;
    const int S=10050;
    int prime[S],ans[S],w[4];
    
    int i,TestCases,case1,case2,temp,t;
    
    for (i=2;i<S;i++){
        prime[i]=isPrime(i);
    }
    
    cin>>TestCases;
    
    while (TestCases--){
        
        cin>>case1>>case2;
        
        memcpy(ans,prime,S*sizeof(int));
        
        ans[case1]=0;
        
        queue<int> q;
        q.push(case1);
        
        while (!q.empty()&&(ans[case2]==-1))
        {
            t=q.front();
            temp=t;
            q.pop();

            for (i=0;i<=3;i++) {w[i]=temp%10;temp/=10;}
           
            for (i=0;i<=9;i++)
            {
                temp=i+10*w[1]+100*w[2]+1000*w[3];
                if (ans[temp]==-1) {
                    ans[temp]=ans[t]+1;
                    q.push(temp);
                }
            }
           
            for (i=0;i<=9;i++)
            {
                temp=w[0]+10*i+100*w[2]+1000*w[3];
                if (ans[temp]==-1) {
                    ans[temp]=ans[t]+1;
                    q.push(temp);
                }
            }
            
            for (i=0;i<=9;i++)
            {
                temp=w[0]+10*w[1]+100*i+1000*w[3];
                if (ans[temp]==-1) {
                    ans[temp]=ans[t]+1;
                    q.push(temp);
                }
            }
            
            for (i=1;i<=9;i++)
            {
                temp=w[0]+10*w[1]+100*w[2]+1000*i;
                if (ans[temp]==-1) {
                    ans[temp]=ans[t]+1;
                    q.push(temp);
                }
            }

        }
        
        if (ans[case2]!=-1){
            answers.push_back(ans[case2]);
        }
        
    }
    
    for (auto i = answers.begin(); i != answers.end(); ++i){
        if (*i!=-1){
            cout << *i << endl;
        }else{
            cout<<"Impossible"<< endl;
        }
    }
            
    return 0;
}