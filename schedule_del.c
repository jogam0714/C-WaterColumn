


#define MAX 50
int month[MAX];
int day[MAX];
int period[MAX];
char subject[MAX][30];
char exam_name[MAX][30];
int total = 0;


void schedule_del(){
    int del;
    printf("삭제할 수행평가를 선택해주세요\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d.%s\n",i+1,exam_name[i]);
    }
    scanf("%d",&del);
    if(del-1 == 0)
    {
        month[del-1] = 
        day[i] = day[i + 1];
        period[i] = period[i + 1];
        subject[i] = subject[i + 1];
        exam_name[i] = exam_name[i + 1]
    }
    for (int i = del-1; i < total; i++)
    {
        month[i] = month[i + 1];
        day[i] = day[i + 1];
        period[i] = period[i + 1];
        subject[i] = subject[i + 1];
        exam_name[i] = exam_name[i + 1]
    }
    
    
}