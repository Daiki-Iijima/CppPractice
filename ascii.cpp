#include <bitset>
#include <iostream>

//  エントリーポイント
int main(int argc, char* argv[]) {
    //  スペースも含めて入力する場合は以下のようにする
    std::string s;
    std::getline(std::cin, s);

    //  stringをcharに変換する
    char c = s[0];

    //  入力された文字のAsciiコードを取得する
    int n = static_cast<int>(c);

    //  2進数で出力する
    std::cout << "BIN : " << std::bitset<8>(n) << std::endl;
    //  10進数で出力する
    std::cout << "DEC : " << n << std::endl;
    //  16進数で出力する
    std::cout << "HEX : 0x" << std::hex << n << std::endl;

    return 0;
}