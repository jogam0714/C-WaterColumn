#include <stdio.h>
#include <string.h>

int month[3];
int day[3];

int main(int argc, char const *argv[])
{
    month[0]=7;
    day[0]=3;
    Dday;
    return 0;
}



void Dday(int t_month, int t_day, int Dday)
{
    
    printf("오늘 날짜를 입력하세요");
    Dday=0;
    scanf("%d %d", &t_month, &t_day);
    int days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    for (int i=0; i<sizeof(month); i++){
        Dday = (days[month[i]-1]-days[t_month-1])+(day[i]-t_day);
        printf("%d\n", Dday);
    }
}


