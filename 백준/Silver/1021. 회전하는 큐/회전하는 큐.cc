#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int N, M, res;
#define MAXSIZE 50
class CircleQueue{
private:
    int queue[MAXSIZE] = {0,};
    int front;
    int rear;
    int initialSize;
    int currentSize;
public:
    CircleQueue(int n){
        for (int i = 0; i < n; i++){
            queue[i] = 1;
        }
        front = 0;
        rear = n-1;
        initialSize = n;
        currentSize = n;
    }

    void RotateAndPop(int target){
        int moveLeftCount = 0;
        // find
        while (front != target){ 
            do{
            front = (front + 1) % initialSize;
            } while (!queue[front]);
            moveLeftCount++;
        }
        // pop
        queue[front] = 0;
        int add = min(moveLeftCount, currentSize - moveLeftCount);
        currentSize--;
        res += add;

        if (!currentSize) return ;
            do{
            front = (front + 1) % initialSize;
        } while (!queue[front]);

        // rotating after pop
        rear = front;
        do {
            rear = ((rear - 1) + initialSize) % initialSize;
        } while (!queue[rear]);
        

    }
};


int main(){
    cin >> N >> M;

    CircleQueue cq(N);
    while(M--){
        int target;
        cin >> target;
        cq.RotateAndPop(target - 1);
    }
    cout << res;

}