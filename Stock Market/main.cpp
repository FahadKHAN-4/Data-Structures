/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 195537
 * Submitted at:  2021-12-04 21:21:08
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    755
 * Problem Name:  Stock Market
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long int MaxArea(long long int hist[], long long int size)
{
    long long int maxArea = 0, stTop, areaTopBar;
    long long int i = 0;
    stack<long long int> st;

    while (i < size)
    {
        if (st.empty() || hist[st.top()] <= hist[i])
            st.push(i++);
 
        else
        {
            stTop = st.top();
            st.pop();
            
            if(st.empty()){
                areaTopBar = hist[stTop] * i;
            }else{
                areaTopBar = hist[stTop] * (i-st.top()-1);
            }
 
            if (maxArea < areaTopBar){
                maxArea = areaTopBar;
            }
        }
    }
 
    while (st.empty() == false)
    {
        stTop = st.top();
        st.pop();
        
        if(st.empty()){
            areaTopBar = hist[stTop] * i;
        }else{
            areaTopBar = hist[stTop] * (i-st.top()-1);
        }
 
        if (maxArea < areaTopBar){
            maxArea = areaTopBar;
        }
    }

    return maxArea;
}

int main()
{
    int noOfInputs;
    
    cin >> noOfInputs;
    
    long long int* maxArea = new long long int[2];
    
    for(int i=0; i<noOfInputs; i++){
        
        long long int size;
        
        cin >> size;
        
        long long int* hist = new long long int[size];
        
        
        for (int i=0; i<size;i++){
            cin >> hist[i];
        }
        maxArea[i] = MaxArea(hist, size);
    }
    
    for(int i=0; i<noOfInputs; i++){
        cout << maxArea[i] << endl;
    }
     
    return 0;
}