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
