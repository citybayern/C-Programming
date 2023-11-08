#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(void)
{
    //프로그램에 내장되어있는 단어들
    vector<string> words = { "apple", "pineapple", "pan", "ppap" };
    int len = static_cast<int>(words.size());

    //ifstream readFromFile;
    //readFromFile.open("words.txt");    //이 두줄을 한줄로 해결하는 방법은 아래방법!
    ifstream readFromFile("word.txt");

    //맨처음 프로그램을 실행하면 파일이 없는 상태일 겁니다.
    //만약, 파일이 없다면 파일을 만들고 기본문자들 세팅
    if (readFromFile.is_open())
    {
        //열렸네? 파일이 존재합니다.

        words.clear(); //새 단어들을 읽어오기 전에 예제 단어들을 삭제한다.

        while (!readFromFile.eof())    //단어장이 끝날때까지.
        {
            //ifstream::getline을 이용해서 char 배열 타입으로 읽어오는 방법은 아래와 같습니다.
            //char arr[256];
            //readFromFile.getline(arr, 256);

            //std::getline 함수를 이용해서 string 타입으로 읽어오는 방법.
            //이 방법이 string을 사용하기 더 편하기 때문에 개인적으로 이 방법을 선호합니다.
            string tmp;
            getline(readFromFile, tmp);
            words.push_back(tmp);            //읽어온 단어 저장
        }
        readFromFile.close();    //꼬리 안밟히게 파일 닫아줍니다.
    }
    else
    {
        //파일이 없네? 없으니 새롭게 파일을 만들어주고, 예시 단어들을 넣어두자.
        //is_open이 false 인 경우는 파일이 없거나, 해당 파일에 접근이 불가능한 경우.
        ofstream writeToFile;
        writeToFile.open("word.txt");    //파일을 새로 만들어줍니다.
        for (int i = 0; i < len; ++i)
        {
            string tmp = words[i];
            if (i != len - 1)
            {
                tmp += "\n";    //마지막 단어 빼고 엔터 넣어주기
            }

            //tmp.c_str() : C++ string -> const char* 타입으로 변환
            writeToFile.write(tmp.c_str(), tmp.size());
        }
        writeToFile.close();    //파일 닫기
    }
    return 0;
}
