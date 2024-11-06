#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    int success_count = 0, total_count = 0;

    srand(time(NULL));

    while (1) {
        total_count++;

        // 1. 자동차 위치와 참가자의 첫 선택 설정
        int car_door = rand() % 3;
        int first_choice = rand() % 3;

        // 2. 사회자가 염소가 있는 문을 선택하여 열기
        int open_door = (car_door == first_choice)
                        ? (first_choice + 1) % 3
                        : 3 - first_choice - car_door;

        // 3. 참가자가 선택을 바꿔 남은 문 선택
        int changed_choice = 3 - first_choice - open_door;

        // 4. 성공 여부 확인 및 집계
        if (changed_choice == car_door) {
            success_count++;
        }

        // 5. 확률 및 결과 출력
        printf("성공 확률: %.2f%%\n", (double)success_count / total_count * 100.0);
        printf("총 시도: %d, 성공: %d\n\n", total_count, success_count);

        Sleep(5);  // 5ms 지연
    }

    return 0;
}
