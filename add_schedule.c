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
