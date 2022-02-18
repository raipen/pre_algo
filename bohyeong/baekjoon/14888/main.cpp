//���� 14888��(������ �����ֱ�)
//Ʋ������: max�� min�� ã�� if���� sum����ϴ� �ݺ����ȿ� �־ Ʋ����,,
//����� ���� ������ �� �������.
//ó�� ����Ҷ��� oper�� ������ �� �ٷιٷ� ����ϵ��� �ߴµ� �׷��� �ϸ��� ���� ó�� ����� index�� ����� �����ʱ� ������ 000, 10, 100 �̷������� ��µȴ�
//�׷��� ������ ���Ϳ� �־ �ѹ��� ����ϵ��� �ϸ� �� ó�� index�� ������ ������ �� �ְ� i = 0-> i=1�� �Ѿ�� �����ǹǷ� �̷��� ������
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
#define DEBUG 0 //���� �� 0
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
vector<int> v1; //���� �����ϴ� ����
vector<int> oper; //+ - * %
vector<int> temp; //�����ڼ��� �����ϴ� ����
//main function

int factorial(int num) { //���� ���� �ִ� ���� ����Ϸ��� ���丮�� �˰���
    if (num <= 1) {
        return 1;
    }
    return num* factorial(num - 1);
}

void cal_oper(int index) {//������ ����ϴ� �Լ�
 
        if (ct == n - 1) {//������ ī��Ʈ ������ n-1�̶��
            for (int i = 0; i < temp.size(); i++) { //������ ������ŭ �ݺ�
                if (!i) { // i==0�϶�, �� �� ó���϶� sum�� v1�̶�� ��ƾ��� ���߿� ����� �� ����
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