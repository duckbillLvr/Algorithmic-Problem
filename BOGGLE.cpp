// 예제: 보글게임(문제 ID: BOGGLE, 난이도: 하)
// 재귀
#include <iostream>
#include <string>
#include <vector>
#define sizeNXN 5
using namespace std;
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

class Boggle
{
public:
    vector<string> board;
    Boggle()
    {
        string str;
        for (int i = 0; i < sizeNXN; i++)
        {
            cin >> str;
            board.push_back(str);
        }
    }
    bool hasWord(int y, int x, const string &word)
    {
        if (!inRange(y, x))
            return false;
        if (board[y][x] != word[0])
            return false;
        if (word.size() == 1)
            return true;
        for (int dir = 0; dir < 8; dir++)
        {
            int nextY = y + dy[dir], nextX = x + dx[dir];
            if (hasWord(nextY, nextX, word.substr(1)))
                return true;
        }
        return false;
    }
    bool inRange(int y, int x)
    {
        if (x >= sizeNXN || x < 0)
            return false;
        if (y >= sizeNXN || y < 0)
            return false;
        return true;
    }
};
void BoggleGame(Boggle &boggle)
{
    int cnt;
    cin >> cnt;
    string word;
    while (cnt--)
    {
        cin >> word;
        bool find = false;
        for (int i = 0; i < sizeNXN; i++)
        {
            for (int j = 0; j < sizeNXN; j++)
            {
                if (boggle.hasWord(j, i, word))
                {
                    find = true;
                    break;
                }
            }
            if (find)
                break;
        }
        if (find)
            cout << word << " YES" << endl;
        else
            cout << word << " NO" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;
    cin >> cnt;
    Boggle boggle;

    while (cnt--)
    {
        BoggleGame(boggle);
    }
    return 0;
}

/*
test case)
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX

result)
PRETTY YES
GIRL YES
REPEAT YES
KARA NO
PANDORA NO
GIAZAPX YES
*/