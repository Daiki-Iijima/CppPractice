#include <iostream>

char board[8][8];

constexpr char kEmpty = 'O';
constexpr char kBlack = 'B';
constexpr char kWhite = 'W';

void Draw() {
    //  マスを表示する
    //  オレンジで表示する
    std::cout << "\033[38;5;214m";
    std::cout << "  0 1 2 3 4 5 6 7" << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << "\033[38;5;214m";
        std::cout << i << " ";
        for (int j = 0; j < 8; j++) {
            //  Bの場合は青で表示する
            if (board[i][j] == 'B') {
                std::cout << "\033[38;5;21m";
            }
            //  Wの場合は赤で表示する
            else if (board[i][j] == 'W') {
                std::cout << "\033[38;5;196m";
                //  Xの場合は緑で表示する
            } else if (board[i][j] == 'X') {
                std::cout << "\033[38;5;46m";
            } else {
                //  それ以外の場合は白で表示する
                std::cout << "\033[0m";
            }

            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//  コマを置くことができるかどうかを判定する
bool CanPut(int x, int y, char self) {
    //  既にコマが置かれている場合は置くことができない
    if (board[x][y] == self) {
        return false;
    }
}

//  文字列を表示しEnterの入力を待つ
void WaitEnter(std::string message) {
    std::cout << message << std::endl;
    std::cin.ignore();
    std::cin.ignore();
}

int main() {
    //  ボードを初期化
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // 真ん中の4マスのうち、左上と右下をWで表示する
            if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
                board[i][j] = kWhite;
                continue;
            }
            //  真ん中の4マスのうち、右上と左下をBで表示する
            else if ((i == 4 && j == 3) || (i == 3 && j == 4)) {
                board[i][j] = kBlack;
                continue;
            } else {
                board[i][j] = kEmpty;
            }
        }
    }

    //  メインループ
    for (;;) {
        //  ターミナルをクリアする
        system("clear");

        //  どこにマスを置くかを入力する
        std::cout << "どこにマスを置くかを入力してください" << std::endl;
        std::cout << "例) 3 4" << std::endl;

        int x, y;
        std::cout << "X:";
        std::cin >> x;
        std::cout << "Y:";
        std::cin >> y;

        //  入力された数値が範囲外の場合は再入力させる
        if (x < 0 || x > 7 || y < 0 || y > 7) {
            WaitEnter("入力された数値が範囲外です");
            continue;
        }

        //  コマを置くことができない場合は再入力させる
        if (!CanPut(x, y, kBlack)) {
            WaitEnter("コマを置くことができません");
            continue;
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //  入力されたマスをXで表示する
                if (i == x && j == y) {
                    board[i][j] = kBlack;
                    continue;
                }
            }
        }

        // マスを表示する
        Draw();

        //  入力待ち
        WaitEnter("Enterを押してください");
    }
    return 0;
}
