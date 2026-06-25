#include <stdio.h>
#include <string.h>
#define MAX 50
int month[MAX];                                                // 수행 월
int day[MAX];                                                  // 수행 일
int period[MAX];                                               // 수행 교시
char subject[MAX][30];                                         // 수행 과목
char exam_name[MAX][30];                                       // 수행 이름
int total = 0;                                                 // 수행 개수
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 달 별 일수

void schedule_del();    // 일정 삭제
void schedule_visual(); // 일정 보기
void add_schedule();    // 일정 추가
void Dday();            // 디데이 계산

int main(int argc, char const *argv[])
{   
    char n; // 기능 선택 번호
    while (1)
    {
        printf("\n\n");
        printf("========수행평가 일정 관리 시스템========\n");
        printf("1.일정 추가\n2.전체 일정 보기\n3.D-day보기\n4.일정 삭제\n0.종료\n");
        printf("==================\n");
        printf("원하는 기능의 번호를 입력하세요 : ");
        scanf("%s", &n);    //기능 번호 선택

        switch (n) 
        {
        case '1': // 
            add_schedule(); //일정 추가
            break;

        case '2':
            schedule_visual();  //일정 시각화(달력)
            break;
        case '3':
            Dday(); //D-day알려주기
            break;
        case '4':
            schedule_del(); //일정 삭제
            break;
        case '0':
            printf("종료"); //초기화
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            break;
        }
    }

    return 0;
}

void add_schedule() //입력 형식이 맞을 때만 일정 추가
{
    char a[30], b[30];
    int c, d, e;
    printf("과목 입력: ");
    scanf("%s", &a);

    for (int i = 0; i == 0;)
    {
        if (a[0] >= '0' && a[0] <= '9')
        { // 입력값이 문자일때만 추가
            printf("입력 형식을 확인해주세요.\n");
            printf("과목 입력: ");
            scanf("%s", &a);
        }
        else
        {
            strcpy(subject[total], a);  //입력값이 문자일 때까지 계속 입력
            i = 1;
        }
    }

    printf("수행이름 입력: ");
    scanf("%s", &b);
    for (int i = 0; i == 0;)
    {
        if (b[0] >= '0' && b[0] <= '9')
        {
            printf("입력 형식을 확인해주세요.\n");
            printf("수행이름 입력: ");
            scanf("%s", &b);
        } // 입력값이 문자일 때만 추가

        else
        {
            strcpy(exam_name[total], b);
            i = 1;
        }
    }
    printf("월 입력: ");
    while (1)
    {

        if (scanf("%d", &c) == 1)
        {
            if (c >= 1 && c <= 12)
            {
                month[total] = c;
                break;
            }
            else
            {
                printf("입력 형식을 확인해주세요.\n");
                printf("월 입력: ");
            }
        }
        else
        {

            printf("입력 형식을 확인해주세요.\n");
            printf("월 입력: ");
            while (getchar() != '\n') 
                ;
        }
    }
    printf("일 입력: ");
    while (1)
    {
        if (scanf("%d", &d) == 1)
        {
            if (d >= 1 && d <= 31)
            {
                if (d <= days[c - 1])
                {
                    day[total] = d;
                    break;
                } // 입력값이 월에 있는 날일 때만 추가
                else
                {
                    printf("%d월에 없는 일입니다.\n", c);
                    printf("일 입력: ");
                    while (getchar() != '\n')
                        ;
                }
            }
            else
            {
                printf("%d월에 없는 일입니다.\n", c);
                printf("일 입력: ");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            printf("입력 형식을 확인해주세요.\n");
            printf("일 입력: ");
            while (getchar() != '\n')
                ;
        }
    }

    printf("교시 입력: ");
    while (1)
    {
        if (scanf("%d", &e) == 1)
        {

            if (e >= 1 && e <= 7)
            {
                period[total] = e; // 7교시까지만 추가
                break;
            }
            else
            {
                printf("입력 형식을 확인해주세요.\n");
                printf("교시 입력: ");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            printf("입력 형식을 확인해주세요.\n");
            printf("교시 입력: ");
            while (getchar() != '\n')
                ;
        }
    }
    total++;
}

void Dday()
{
    int t_month, t_day;
    printf("오늘 날짜를 입력하세요(월 일): ");
    int Dday = 0;
    int sumM = 0;
    int sumTM = 0;
    scanf("%d %d", &t_month, &t_day);
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < month[i] - 1; j++)
        {
            sumM += days[j]; // 1.1부터 수행일까지 일수
        }
        for (int j = 0; j < t_month - 1; j++)
        {
            sumTM += days[j]; // 1.1부터 오늘까지 일수
        }
        Dday = sumM + day[i] - (sumTM + t_day); // 오늘부터 수행일까지 남은 기간
        printf("%sD-%d\n", exam_name[i], Dday);
        Dday = 0;   //디데이 초기화 
        sumM = 0;
        sumTM = 0;
    }
}

void schedule_visual()
{

    int m, i, column; // m = 월, i = 일, column = 열
    int startDay[13] = {0, 4, 0, 0, 2, 4, 1, 3, 6, 2, 4, 0, 2};
    // 0 = 일, 1 = 월, 2 = 화, 3 = 수, 4 = 목, 5 = 금, 6 = 토
    printf("\n몇 월을 입력하시겠습니까? ");
    while (1) // 무한 루프
    {
        if (scanf("%d", &m) == 1) // 입력값이 정수일 때만 추가
        {

            if (m >= 1 && m <= 12) // 입력값이 1~12 사이일 때만 추가
            {
                printf("\n%d월의 일정입니다.\n", m); // 달력 출력
                printf("\n"); // 달력 출력
                printf("+-----+-----+-----+-----+-----+-----+-----+\n"); // 달력 출력
                printf("| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n"); // 달력 출력
                printf("+-----+-----+-----+-----+-----+-----+-----+\n"); // 달력 출력
                column = 0; // 달력 출력
                printf("|"); // 달력 출력
                for (column = 0; column < startDay[m]; column++) // 달력 출력
                {
                    printf("     |"); // 달력 출력
                }
                column = startDay[m]; // 달력 출력
                for (i = 1; i <= days[m - 1]; i++) // 달력 출력
                {
                    int hasExam = 0; // 달력 출력
                    for (int k = 0; k < total; k++) // 달력 출력
                    {
                        if (month[k] == m && day[k] == i) // 달력 출력
                        {
                            hasExam = 1; // 달력 출력
                        }
                    }
                    if (hasExam) // 수행 있는 날이면 별표 표시
                    {
                        printf(" *%2d*|", i); // *로 표시
                    }
                    else
                    {
                        printf("  %2d |", i); // 그렇지 않으면 그냥 표시
                    }
                    column++; // 마지막 주가 7칸을 다 채우지 못했을 경우 남은 빈 칸 출력
                    if (column == 7) 
                    {
                        printf("\n+-----+-----+-----+-----+-----+-----+-----+\n"); // 달력 출력
                        if (i != days[m-1]) // 
                        {
                            printf("|"); 
                        }
                        column = 0;
                    }
                }
                // 마지막 주가 7칸을 다 채우지 못했을 경우 남은 빈 칸 출력
                while (column != 0 && column < 7) 
                {
                    printf("     |");
                    column++;
                }
                // 해당 월의 수행평가 일정 목록 출력
                printf("\n+-----+-----+-----+-----+-----+-----+-----+\n");
                printf("\n%d월의 수행평가 일정\n", m);
                printf("----------------------------------\n");
                int found = 0; 
                for (int k = 0; k < total; k++) // // 해당 월의 수행평가 일정 목록 출력
                {
                    if (month[k] == m)
                    {
                        printf("%d월 %d일 %d교시 %s %s\n", month[k], day[k], period[k], subject[k], exam_name[k]);
                        // 
                        found = 1;
                    }
                }
                if (!found)
                {
                    printf("일정이 없습니다.\n");
                    break;
                }
                break;
            }
            else
            {
                printf("잘못된 입력입니다.\n1에서 12 사이의 숫자를 입력해주세요.\n");
                printf("몇 월을 입력하시겠습니까? ");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            printf("잘못된 입력입니다.\n1에서 12 사이의 숫자를 입력해주세요.\n");
            printf("몇 월을 입력하시겠습니까? ");
            while (getchar() != '\n')
                ;
        }
    }
}

void schedule_del()
{
    int del = 0;
    if (total == 0) //추가된 일정 수==0
    {
        printf("등록된 수행평가가 없습니다.");
        return;
    }

    printf("삭제할 수행평가를 선택해주세요\n");
    printf("==================\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d.%s\n", i + 1, exam_name[i]);
    }
    printf("==================\n");
    while (1)   //무한 반복
    {
        if (scanf("%d", &del) == 1)
        {
            if (del >= 0 && del <= total)
            {

                for (int i = del - 1; i < total; i++)
                {
                    if (i == total)
                    {
                        month[i] = '\0';
                        day[i] = '\0';
                        period[i] = '\0';
                        strcpy(subject[i], '\0');
                        strcpy(exam_name[i], '\0');
                    }
                    else
                    {
                        month[i] = month[i + 1];
                        day[i] = day[i + 1];
                        period[i] = period[i + 1];
                        strcpy(subject[i], subject[i + 1]);
                        strcpy(exam_name[i], exam_name[i + 1]);
                    }
                }
                total--;
                break;
            }
            else
            {
                printf("잘못된 입력입니다.\n");
                printf("삭제할 수행평가를 선택해주세요\n");
                printf("==================\n");
                for (int i = 0; i < total; i++)
                {
                    printf("%d.%s\n", i + 1, exam_name[i]);
                }
                printf("==================\n");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            printf("잘못된 입력입니다.\n");
            printf("삭제할 수행평가를 선택해주세요\n");
            printf("==================\n");
            for (int i = 0; i < total; i++)
            {
                printf("%d.%s\n", i + 1, exam_name[i]);
            }
            printf("==================\n");
            while (getchar() != '\n')
                ;
        }
    }
}
