#include <stdio.h>

//  FAT形式のファイルシステムを扱うクラス
class FatFileSystem {
   public:
    FatFileSystem(const char* path);
    void Output();

   private:
    //  読み取ったボリュームイメージを格納するバッファ
    char* volumeImage;
};

//  エントリーポイント
int main(int argc, char* argv[]) {
    FatFileSystem fatFileSystem(argv[1]);
    fatFileSystem.Output();
    return 0;
}

FatFileSystem::FatFileSystem(const char* path) {
    //  指定されたパスのボリュームイメージ開く
    FILE* fp = fopen(path, "rb");
    //  ファイルの終端までシークしてサイズを取得
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    //  ボリュームイメージを格納するバッファを確保
    volumeImage = new char[size];

    //  ボリュームイメージを読み込む
    //  ファイルポインタを先頭に戻してから読み込む
    fseek(fp, 0, SEEK_SET);
    //  ボリュームイメージを読み込む
    fread(volumeImage, size, 1, fp);
    //  ファイルを閉じる
    fclose(fp);
}

void FatFileSystem::Output() {
    //  volumeImageを16バイトずつ16進数で出力する
    for (int i = 0; i < 512; i++) {
        printf("%02x ", volumeImage[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
}
