#include <iostream>
using namespace std;

int Expo, Row, Col;
int Ans;

void FindZ(int, int, int);

int main(void)
{
    cin >> Expo >> Row >> Col;

    FindZ(0, 0, (1 << Expo));
 }

void FindZ(int y, int x, int size)
{
    if (y == Row && x == Col)
    {
        cout << Ans << '\n';
        return;
    }

    if (Row < y + size && y <= Row && Col < x + size && x <= Col)
    {
        FindZ(y, x, size / 2);
        FindZ(y, x + size / 2, size / 2);
        FindZ(y + size / 2, x, size / 2);
        FindZ(y + size / 2, x + size / 2, size / 2);
    }
    else Ans += size * size;
}