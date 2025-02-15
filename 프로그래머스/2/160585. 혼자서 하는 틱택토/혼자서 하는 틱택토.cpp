#include <string>
#include <vector>

using namespace std;
/*
1. cnt o == x || o + 1 > x

2. o win -> cnt o == x

*/
enum {
    L, D, DR, UR
};
enum {
   O = 1, X = 2, BOTH = 3
};
int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};
int checkWinner(vector<string> & b){
    int oWin = 0;
    int xWin = 0;
    
    
    if (b[0][0] != '.' && b[0][0] == b[0][1] && b[0][0] == b[0][2]) {
        if (b[0][0] == 'O') oWin++;
        else if (b[0][0] == 'X') xWin++;
    }
    if (b[1][0] != '.' && b[1][0] == b[1][1] && b[1][0] == b[1][2]) {
        if (b[1][0] == 'O') oWin++;
        else if (b[1][0] == 'X') xWin++;
    }
    if (b[2][0] != '.' && b[2][0] == b[2][1] && b[2][0] == b[2][2]) {
        if (b[2][0] == 'O') oWin++;
        else if (b[2][0] == 'X') xWin++;
    }
    
    if (b[0][0] != '.' && b[0][0] == b[1][0] && b[0][0] == b[2][0]) {
        if (b[0][0] == 'O') oWin++;
        else if(b[0][0] == 'X') xWin++;
    }
    if (b[0][1] != '.' && b[0][1] == b[1][1] && b[0][1] == b[2][1]) {
        if (b[0][1] == 'O') oWin++;
        else if(b[0][1] == 'X') xWin++;
    }
    if (b[0][2] != '.' && b[0][2] == b[1][2] && b[0][2] == b[2][2]) {
        if (b[0][2] == 'O') oWin++;
        else if(b[0][2] == 'X') xWin++;
    }
    if (b[0][0] != '.' && b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
        if (b[0][0] == 'O') oWin++;
        else if(b[0][0] == 'X') xWin++;
    }
    if (b[2][0] != '.' && b[2][0] == b[1][1] && b[2][0] == b[0][2]) {
        if (b[2][0] == 'O') oWin++;
        else if(b[2][0] == 'X') xWin++;
    }
    
    
    
    if (oWin && xWin) return BOTH;
    else if (oWin) return O;
    else if (xWin) return X;
    return 0;
    
}

int solution(vector<string> board) {
    int answer = -1;
    answer = 1;
    int oCnt = 0, xCnt = 0;
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j <3 ; j++){
            if (board[i][j] == 'O') oCnt++;
            else if (board[i][j] == 'X') xCnt++;
        }
    }
    int winner = checkWinner(board);
    
    if (winner == BOTH) return 0;
    if (winner == O && oCnt == xCnt) return 0;
    if (winner == X && oCnt != xCnt) return 0;
    if (!(oCnt == xCnt || oCnt == xCnt + 1)) return 0;
    
    return answer;
}