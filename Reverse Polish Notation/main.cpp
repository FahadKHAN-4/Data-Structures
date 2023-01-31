/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202241
 * Submitted at:  2022-02-24 14:08:10
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    751
 * Problem Name:  Reverse Polish Notation
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solve(string notation){
    
    stack<int> stk;
    stk.push(0);
    
    for(int i=0; i<notation.length(); i++){
        
        if(notation[i] == '+'){
            int top1 = stk.top();
            stk.pop();
            int top2 = stk.top();
            stk.pop();

            stk.push((top1 + top2));
            
        }else if(notation[i] == '-'){
            
            int top1 = stk.top();
            stk.pop();
            int top2 = stk.top();
            stk.pop();
            
            stk.push((top2 - top1));
            
        }else if(notation[i] == '*'){
            
            int top1 = stk.top();
            stk.pop();
            int top2 = stk.top();
            stk.pop();
            
            stk.push((top1 * top2));
            
        }else if(notation[i] == ' '){
            continue;
        }else{
            stk.push(notation[i] - '0');
        }
    }

    return stk.top();
    
}

int main() {
     
    vector<int> answers;
    string input;
    
    
    getline(cin, input);
    
    do{
        answers.push_back(solve(input));
        getline(cin, input);
        
    }while(input.size() != 0);
    
    for (auto i = answers.begin(); i != answers.end(); ++i)
            cout << *i << endl;
    
    return 0;
}