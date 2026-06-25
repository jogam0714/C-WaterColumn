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
