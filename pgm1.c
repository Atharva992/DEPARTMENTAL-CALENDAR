#include <stdio.h>

void printCalendar(int year, int month);
int getFirstDayOfYear(int year);
int isLeapYear(int year);

int main() {
    int year, month;

    printf("Enter year (e.g., 2024): ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month! Please enter a value between 1 and 12.\n");
        return 1;
    }

    printCalendar(year, month);

    return 0;
}

// Function to print the calendar for a specific year and month
void printCalendar(int year, int month) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // Update February for leap year
    }

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int firstDayOfYear = getFirstDayOfYear(year);
    int firstDayOfMonth = firstDayOfYear;

    for (int i = 0; i < month - 1; i++) {
        firstDayOfMonth = (firstDayOfMonth + daysInMonth[i]) % 7;
    }

    for (int i = 0; i < firstDayOfMonth; i++) {
        printf("     ");
    }

    for (int day = 1; day <= daysInMonth[month - 1]; day++) {
        printf("%5d", day);

        if ((firstDayOfMonth + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to determine the first day of the year (0 = Sunday, 1 = Monday, ...)
int getFirstDayOfYear(int year) {
    int day = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    return day % 7;
}
