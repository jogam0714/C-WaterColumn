void schedule_visual(void)
{
    int m, i, column;
    int startDay[13] = {0, 4, 0, 0, 2, 4, 1, 3, 6, 2, 4, 0, 2};
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 0 = 일, 1 = 월, 2 = 화, 3 = 수, 4 = 목, 5 = 금, 6 = 토
    printf("\n몇 월을 입력하시겠습니까? ");
    scanf("%d", &m);
    
    printf("\n%d월의 일정입니다.\n", m);
    printf("\n");
    printf("+-----+-----+-----+-----+-----+-----+-----+\n");
    printf("| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n");
    printf("+-----+-----+-----+-----+-----+-----+-----+\n");
    column = 0;
    printf("|");
    for (column = 0; column < startDay[m]; column++) {
        printf("     |");
    }
    column = startDay[m];
    for(i = 1; i <= daysInMonth[m]; i++) {
        printf(" %3d |", i);
        column++;
        if (column == 7) {
            printf("\n+-----+-----+-----+-----+-----+-----+-----+\n");
            if(i != daysInMonth[m]){
                printf("|");
            }
            column = 0;
        }
    }
    while(column != 0 && column < 7){
        printf("     |");
        column++;
        
    }

    printf("\n+-----+-----+-----+-----+-----+-----+-----+\n");
}
