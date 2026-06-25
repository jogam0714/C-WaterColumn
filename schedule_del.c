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
