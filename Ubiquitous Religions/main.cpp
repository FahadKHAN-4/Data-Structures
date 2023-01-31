/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 215330
 * Submitted at:  2022-05-03 13:14:13
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    141
 * Problem Name:  Ubiquitous Religions (UVa 10583)
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int students[50000];

// return a node
int search(int x){
    while(students[x] != x){
        x = students[x];
    }
    return x;
}

int main(){
    
    vector<string> answers;
    int n, m, stu1, stu2, node1, node2;
    int count, count1 = 1;
    
    while(scanf("%d %d", &n, &m) && (n!=0 || m!=0)){
        
        count = n;
        
        for(int i = 0; i < n; i++){
            students[i] = i;
        }
        
        while(m--){
            scanf("%d %d", &stu1, &stu2);
            
            node1 = search(stu1);
            node2 = search(stu2);
            
            if(node1 != node2) {
                
                students[stu1] = students[node1];
                students[node1] = node2;
                
                count -= 1;
            }
        }
        
        string ans = "Case " + to_string(count1) + ": " + to_string(count);
        count1++;
        
        answers.push_back(ans);
    }
    
    for (auto i = answers.begin(); i != answers.end(); ++i)
                cout << *i << endl;
    
    return 0;
}