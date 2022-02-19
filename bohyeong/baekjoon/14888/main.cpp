//백준 14888번(연산자 끼워넣기)
//틀린이유: max와 min을 찾는 if문을 sum계산하는 반복문안에 넣어서 틀렸음,,
//상당히 순열 구현할 때 힘들었다.
//처음 사고할때는 oper가 존재할 때 바로바로 출력하도록 했는데 그렇게 하면은 제일 처음 출력한 index가 출력이 되지않기 때문에 000, 10, 100 이런식으로 출력된다
//그렇기 때문에 벡터에 넣어서 한번에 출력하도록 하면 맨 처음 index가 여전히 존재할 수 있고 i = 0-> i=1로 넘어갈때 삭제되므로 이렇게 구성함
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <tuple>
#include <sstream>
#include <cmath>
#define DEBUG 0 //제출 시 0
#define endl    '\n'
#define INF 987654321
#define SHARING 100001

using namespace std;

int dirY[] = { -1, 0, 1, 0 };
int dirX[] = { 0, 1, 0, -1 };
int n, num, allcase;
int ct = 0; int aa=0;
int maxn = -1000000001; int minn = 1000000001;
int sum = 0;
vector<int> v1; //숫자 저장하는 벡터
vector<int> oper; //+ - * %
vector<int> temp; //연산자순열 저장하는 벡터
//main function

int factorial(int num) { //같은 것이 있는 순열 계산하려고 팩토리얼 알고리즘
    if (num <= 1) {
        return 1;
    }
    return num* factorial(num - 1);
}

void cal_oper(int index) {//연산자 계산하는 함수
 
        if (ct == n - 1) {//연산자 카운트 개수가 n-1이라면
            for (int i = 0; i < temp.size(); i++) { //연산자 개수만큼 반복
                if (!i) { // i==0일때, 즉 맨 처음일때 sum을 v1이라고 잡아야지 나중에 계산할 때 편함
                    sum = v1[i];
                }

                if (temp[i] == 0) {
                    sum += v1[i + 1];
                }
                else if (temp[i] == 1) {
                    sum -= v1[i + 1];
                }
                else if (temp[i] == 2) {
                    sum *= v1[i + 1];
                }
                else {
                    sum /= v1[i + 1];
                }
            }
            if (sum > maxn) {
                maxn = sum;
            }
            if (sum < minn) {
                minn = sum;
            }

            aa++;
            return;
        }

 
        for (int i = 0; i < 4; i++) {
            if (oper[i] != 0) {
  
                oper[i]--;
                ct++;
                temp.push_back(i);
               
                cal_oper(i);
                oper[i]++;
                temp.pop_back();
                ct--;
            }
        }
     
  
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        v1.push_back(num);
    }

    for (int i = 0; i < 4; i++) {
        cin >> num;
        oper.push_back(num);
    }

    if (DEBUG) {
        allcase = factorial(n - 1);
        for (int i = 0; i < 4; i++) {
            if (oper[i] > 1) {
                allcase /= oper[i];
            }
        }
        cout << allcase << endl;
        cout << aa << endl;
    }
   
    cal_oper(0);
    cout << maxn << endl;
    cout << minn << endl;
    return 0;
}