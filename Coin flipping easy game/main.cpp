/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 215142
 * Submitted at:  2022-05-02 21:31:39
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    741
 * Problem Name:  Coin flipping easy game
 */

#include <iostream>
using namespace std;

int table[100][10];
int row = 0, column = 0, ans = 0, sum = 0;


void Flip(int digit) {
    if (digit == column) {
        int sum = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                sum += table[i][j];
            }
        }
        
        int operand = sum;
        for (int i = 0; i < row; i++) {
            
            sum = 0;
            for (int j = 0; j < column; j++) {
                sum += table[i][j];
            }
            if (sum < column / 2) {
                
                sum = 0;
                for (int j = 0; j < column; j++) {
                    sum += table[i][j];
                }
                operand = operand + column - (2 * sum);
            }
        }
        if (operand > ans) {
            ans = operand;
        }
    }

    if (digit < column) {
        digit += 1;
        Flip(digit);
        
        int counter = digit;
        counter -= 1;
        for (int i = 0; i < row; i++) {
            if (table[i][counter] != 0) {
                
                table[i][counter] = 0;
            }
            else {
                
                table[i][counter] = 1;
            }
        }
        Flip(digit);
    }

}
int main() {
    string binaryString;
    
    while (cin >> row >> column) {
        ans = 0;
        
        for (int i = 0; i < row; i++) {
            
            cin >> binaryString;
            
            for (int j = 0; j < column; j++) {
                table[i][j] = binaryString[j] - '0';
            }
        }
        
        Flip(0);
        cout << ans << endl;
    }
    
    return 0;
}