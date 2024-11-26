#include <iostream>
#include <string>
using namespace std;

// 定義每個音符所需的手指
void getFingers(char note, bool fingers[10])
{
    // 初始化手指陣列為 false
    for (int i = 0; i < 10; ++i)
    {
        fingers[i] = false;
    }

    switch (note) {
    case 'c': // finger 2∼4, 7∼10
        fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 2, 3, 4
        fingers[6] = true; fingers[7] = true; fingers[8] = true; fingers[9] = true; // finger 7, 8, 9, 10
        break;
    case 'd': // finger 2∼4, 7∼9
        fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 2, 3, 4
        fingers[6] = true; fingers[7] = true; fingers[8] = true; // finger 7, 8, 9
        break;
    case 'e': // finger 2∼4, 7, 8
        fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 2, 3, 4
        fingers[6] = true; fingers[7] = true; // finger 7, 8
        break;
    case 'f': // finger 2∼4, 7
        fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 2, 3, 4
        fingers[6] = true; // finger 7
        break;
    case 'g': // finger 2∼4
        fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 2, 3, 4
        break;
    case 'a': // finger 2, 3
        fingers[1] = true; fingers[2] = true; // finger 2, 3
        break;
    case 'b': // finger 2
        fingers[1] = true; // finger 2
        break;
    case 'C': // finger 3
        fingers[2] = true; // finger 3
        break;
    case 'D': // finger 1∼4, 7∼9
        fingers[0] = true; fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 1, 2, 3, 4
        fingers[6] = true; fingers[7] = true; fingers[8] = true; // finger 7, 8, 9
        break;
    case 'E': // finger 1∼4, 7, 8
        fingers[0] = true; fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 1, 2, 3, 4
        fingers[6] = true; fingers[7] = true; // finger 7, 8
        break;
    case 'F': // finger 1∼4, 7
        fingers[0] = true; fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 1, 2, 3, 4
        fingers[6] = true; // finger 7
        break;
    case 'G': // finger 1∼4
        fingers[0] = true; fingers[1] = true; fingers[2] = true; fingers[3] = true; // finger 1, 2, 3, 4
        break;
    case 'A': // finger 1∼3
        fingers[0] = true; fingers[1] = true; fingers[2] = true; // finger 1, 2, 3
        break;
    case 'B': // finger 1∼2
        fingers[0] = true; fingers[1] = true; // finger 1, 2
        break;
    }
}

int main()
{
    int t;
    cin >> t; // 讀取測試案例數
    cin.ignore(); // 忽略換行符

    while (t--)
    {
        string song;
        getline(cin, song); // 讀取歌曲

        // 用於計算每個手指按壓的次數
        int pressCounts[10] = { 0 };
        bool previousFingers[10] = { false }; // 之前的手指狀態

        for (int n = 0; n < song.length(); n++)
        {
            char note = song[n];
            bool currentFingers[10];
            getFingers(note, currentFingers); // 獲取當前音符的手指使用情況

            // 計算按壓次數
            for (int i = 0; i < 10; ++i)
            {
                // 如果當前手指需要且之前未按壓，則按壓
                if (currentFingers[i] && !previousFingers[i])
                {
                    pressCounts[i]++;
                }
            }

            // 更新之前的手指狀態
            for (int i = 0; i < 10; ++i)
            {
                previousFingers[i] = currentFingers[i];
            }
        }

        // 輸出每個手指按壓的次數
        for (int i = 0; i < 10; ++i)
        {
            cout << pressCounts[i];
            //輸出最後一位後面不加空格
            if (i != 9)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
