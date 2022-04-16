#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> rorkxdlehfflrl(vector<vector<int>> &k)
{
    vector<vector<int>> temp(k.size(),vector<int>(k.size()));
    for (int i = 0; i < k.size(); i++)
    {
        for (int j = 0; j < k.size(); j++)
        {
            temp[i][j]=k[k.size()-1-j][i];
        }
    }
    return temp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    int lock_size = lock.size();
    int key_size =key.size();
    vector<vector<int>> board(lock_size *3, vector<int>(lock_size * 3));

    for (int i = 0; i < lock_size; i++)
    {
        for (int j = 0; j < lock_size; j++)
        {
            board[lock_size + i][lock_size + j] = lock[i][j];
        }
    }
    bool check = true;

    for (int p = 0; p < 4; p++)
    {
       
        for (int i = 0; i <lock_size * 2; i++)
        {
            for (int j = 0; j <lock_size * 2; j++)
            {   
                check=true;
                for (int q = 0; q < key.size(); q++)
                {
                    for (int k = 0; k < key.size(); k++)
                    {
                        board[i + q][j + k] += key[q][k];
                    }
                }
                for (int q = 0; q < lock_size; q++)
                {
                    for (int k = 0; k < lock_size; k++)
                    {
                        if (board[lock_size + q][lock_size + k] != 1)
                        {
                            check = false;
                            break;
                        }
                    }
                    if (!check)
                        break;
                }
                if (check)
                    return true;
                for (int q = 0; q < key.size(); q++)
                {
                    for (int k = 0; k < key.size(); k++)
                    {
                        board[i + q][j + k] -= key[q][k];
                    }
                }
            }
        }
        key=rorkxdlehfflrl(key);
    }

    return answer;
}


int main()
{
    bool answer = solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    cout << answer << "\n";
}