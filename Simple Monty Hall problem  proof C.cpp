#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    int success_count = 0, total_count = 0;
    int door[3];

    srand(time(NULL));

    while (1) {
        total_count++;

        // 1. 문 초기화 및 자동차 위치 설정
        int car_door = rand() % 3;
        int first_choice = rand() % 3;

        // 2. 사회자가 염소가 있는 문 열기 (참가자가 고른 문이 아닌 염소 문)
        int open_door = 0;
        for (int i = 0; i < 3; i++) {
            if (i != first_choice && i != car_door) {
                open_door = i;
                break;
            }
        }

        // 3. 참가자가 선택을 바꾸기 (열린 문과 첫 선택 문을 제외한 나머지)
        int changed_choice = 3 - first_choice - open_door;

        // 4. 자동차 있는지 확인 및 성공 횟수 집계
        if (changed_choice == car_door) {
            success_count++;
        }

        // 5. 결과 출력
        printf("성공 확률: %.2f%%\n", (double)success_count / total_count * 100.0);
        printf("성공: %d, 총 시도: %d\n\n", success_count, total_count);

        Sleep(5);  // 5ms 지연
    }

    return 0;
}
