#include <stdio.h>

int dayOfWeek(int d, int m, int y) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

const char* getDayName(int day) {
    const char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return days[day];
}

int isValidDate(int d, int m, int y) {
    if (m < 1 || m > 12) return 0;
    if (d < 1) return 0;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 윤년 계산
    if (m == 2) {
        int isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (isLeap) {
            if (d > 29) return 0;
        } else {
            if (d > 28) return 0;
        }
    } else {
        if (d > daysInMonth[m - 1]) return 0;
    }

    return 1;
}

int main() {
    int day, month, year;
    printf("Enter date (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    if (year < 2000) {
        printf("2000년도부터 입력해주세요.\n");
        return 1;
    }

    if (!isValidDate(day, month, year)) {
        printf("유효하지 않은 날짜입니다.\n");
        return 1;
    }

    int dayIndex = dayOfWeek(day, month, year);
    printf("The day is: %s\n", getDayName(dayIndex));

    return 0;
}