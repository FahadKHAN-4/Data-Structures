/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 198020
 * Submitted at:  2021-12-09 19:37:46
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    185
 * Problem Name:  Andy's First Dictionary (UVa 10815)
 */

#include<iostream>
#include<string>
#include<set>
#include <sstream>

using namespace std;

int main()
{
    set<string> dictionary;
    string s, word;

    while(cin>>s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i])){
                s[i] = tolower(s[i]);
            }
            else {
                s[i] = ' ';
            }
        }
        
        stringstream sstream(s);
        while (sstream >> word) {
            dictionary.insert(word);
        }
        
    }
    set<string>::iterator itr;
    for(itr=dictionary.begin(); itr!=dictionary.end(); ++itr){
        cout << *itr <<endl;
    }
    
    return 0;
}