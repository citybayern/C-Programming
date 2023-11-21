v#include<iostream>
using namespace std;

	namespace kitae
	{
		int f() { return 1; }
		int m() { return -1; }
	}

	int main()
	{
		std::cout << "Hi" << std::endl << "Hello" << std::endl;  //cout 객체  c++ 표준 출력 스트림 객체 
												                                  	 //std:: 접두어: cout으 이름 공간 
													                                   //endl 조작자: 다음 줄로 넘어가기 위한 조작자 \n과 비슷한 역할
		int n = kitae::f();
		int m = kitae::m();

		cout << "Hello" << endl;

		int width, height;

		cout << "너비와 높이 입력 : ";
		cin >> width >> height; //enter키 칠 떄 키 값 전달
		return 0;
	}
