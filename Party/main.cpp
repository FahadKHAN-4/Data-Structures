/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 189972
 * Submitted at:  2021-11-27 18:19:17
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    438
 * Problem Name:  Party
 */

#include <iostream>
using namespace std;

int main(){

    int n,m;
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> m;

    if (m==0 || m==1){
        cout << 0 << endl;
    } else {
        cout << m-2 << endl;
    }
    }

    return 0;
}