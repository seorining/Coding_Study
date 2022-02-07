#include <iostream>

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	/* 이 구문을 추가한 이유

ios_base::sync_with_stdio(false);의 장점

ios_base::sync_with_stdio 구문은 c의 stdio와 cpp의 iostream을 동기화시켜주는 역할을 하는데, 이 때 iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생합니다.
따라서, ios_base::sync_with_stdio(false); 코드를 작성해줌으로써 동기화를 비활성화시켜줍니다.
이로 인해, c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용할 수 없게 되지만, 사용하는 버퍼의 수가 줄어들었기 때문에 실행 속도는 빨라지게 됩니다.
알고리즘 문제를 풀 때는 대부분 싱글 쓰레드 환경이기 때문에 해당 코드를 추가해줘도 문제가 발생하지 않을 확률이 높습니다.


ios_base::sync_with_stdio(false);의 단점

동기화된 C++ 버퍼의 경우 thread-safe하기 때문에 모든 IO의 순서가 예상한 것과 정확히 일치함을 보장할 수 있습니다.
-> (output from different threads may interleave, but you get no data races).
하지만, ios_base::sync_with_stdio(false); 코드를 추가함으로 인해 동기화가 비활성화됐기 때문에 멀티 쓰레드 환경에서는 출력 순서를 보장할 수 없습니다.
그리고 버퍼가 분리되었기 때문에 cin과 C의 scanf, gets, getchar 등을 같이 사용하면 안되고 cout과 C의 printf, puts, putchar 등을 같이 사용하면 엉뚱한 결과가 나올 확률이 높기 때문에 사용하면 안 됩니다.


cin.tie(null);
결론부터 말하자면 cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
기본적으로 cin과 cout은 묶여있고 묶여있는 스트림들은 한 스트림이 다른 스트림에서 각 IO 작업을 진행하기 전에 자동으로 버퍼를 비워줌을 보장합니다.

아래의 코드로 예시를 들어보겠습니다.

cout << "이름을 입력하세요: ";
cin >> name;
위 경우 cin과 cout이 묶여있기 때문에, 이름을 입력하기 전에 "이름을 입력하세요: " 구문이 먼저 출력될 것입니다.
하지만, cin.tie(null); 코드를 추가한다면 cin과 cout의 묶음이 풀리면서 "이름을 입력하세요: "; 구문이 먼저 출력되지도 않았는데 먼저 이름을 입력을 받는 경우가 발생할 수 있습니다.
이는 cout이 기본적으로 버퍼에 추가되고 바로 비워지지 않기 때문입니다. (출력 명령을 내리거나 버퍼가 가득 찼을 경우에만 버퍼를 비우고 출력합니다.)
따라서, cin.tie(null); 코드를 추가했고 name을 입력받기 전에 "이름을 입력하세요: " 구문을 먼저 보고 싶다면 cout으로 "이름을 입력하세요: "를 출력할 때 버퍼를 비워줘야 합니다.

 

결론
알고리즘을 풀 때는 보통 싱글 쓰레드 환경이기 때문에 ios_base::sync_with_stdio(false); 코드를 추가해줘도 결과에 영향이 없고 C와 C++의 버퍼를 분리하기 때문에 속도가 빨라집니다. (이때, c 스타일의 입출력문을 혼용하지 않도록 주의해줘야 합니다.)
기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 알고리즘을 풀 때는 화면에 바로 보이는 것이 중요하지 않습니다. 따라서, 입력과 출력을 여러 번 번갈아가며 반복해야 하는 경우 필수적으로 cin.tie(null); 코드를 추가하여 cout과 cin의 묶음을 풀어줘야 합니다.

 

비고 
추가적으로, c++ 스타일로 알고리즘을 푸는 초보자들은 흔히 endl 구문을 통해 개행을 합니다.
하지만, endl의 경우 개행 문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하기 때문에 딜레이가 발생합니다.

출처: https://jaimemin.tistory.com/1521 [꾸준함]
*/


	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++)
		std::cout << i << "\n";

	return 0;
}