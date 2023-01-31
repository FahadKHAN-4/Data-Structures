/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 217854
 * Submitted at:  2022-05-08 23:42:39
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    749
 * Problem Name:  Tree reconstruction
 */

#include <iostream>
#include <vector>
using namespace std;

vector<string> answers;
string ans = "";

int search(int pre, int in[], int no_nodes) {
    
   for (int i = 0; i < no_nodes; ++i) {
      if (in[i] == pre) {
         return i;
      }
   }
    
   return -1;
}

void post(int no_nodes, int pre[], int in[]) {
    
    int rootNode = search(pre[0], in, no_nodes);
    
    if(rootNode !=0 ){
        post(rootNode, pre+1, in);
    }
      
    if (rootNode != no_nodes - 1){
        post(no_nodes - rootNode -1, pre + rootNode + 1, in + rootNode + 1);
    }
    
//    printf("%d ", pre[0]);
    ans += to_string(pre[0]) + " ";
    
}

int main() {
    
    int cases, node;
    int no_nodes;
    cin >> cases;
    
    for (int i = 0; i < cases; i++) {
        
        
        cin >> no_nodes;
        
        int* pre = new int[no_nodes];
        int* in = new int[no_nodes];
            
        for (int j = 0; j < no_nodes; j++) {
            cin >> node;
            pre[j] = node;
        }
        
        for (int j = 0; j < no_nodes; j++) {
            cin >> node;
            in[j] = node;
        }
    
    
    post(no_nodes, pre, in);
//    no_nodes = 2 * no_nodes;
//    ans.replace(no_nodes-1, 1, "");
    answers.push_back(ans);
    ans = "";
        
    }
    
    for (auto i = answers.begin(); i != answers.end(); ++i)
        cout << *i << endl;
    
   return 0;
}