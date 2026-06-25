#include <stdio.h>
#include <string.h>
void add_schdeule(int a);
int main(int argc, char const *argv[])
{

}


void add_schdeule()
{
        printf("과목 입력: ");
        scanf("%s", subject[total]);
        printf("수행이름 입력: ");
        scanf("%s", exam_name[total]);
        printf("월 입력: ");
        scanf("%d", &month[total]);
        printf("일 입력: "); 
        scanf("%d", &day[total]);
        printf("교시 입력: ");
        scanf("%d", &period[total]);
        total++;
        printf("일정이 추가되었습니다.\n");
}




        printf("과목 입력: ");
        scanf("%s", subject[total]);
        printf("수행이름 입력: ");
        scanf("%s", exam_name[total]);
        printf("월 입력: ");
        scanf("%d", &month[total]);
        printf("일 입력: "); 
        scanf("%d", &day[total]);
        printf("교시 입력: ");
        scanf("%d", &period[total]);
        total++;
        printf("일정이 추가되었습니다.\n");