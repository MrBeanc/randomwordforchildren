#include <stdlib.h>
#include <stdio.h>
#include <time.h>
char b,c[100];
typedef struct word
{
   char  lettermean[300];
   int word_id;

} word;

void printstar()
{
    int i1, j1, k1, i2, j2, k2, i3, j3, k3, i4, j4, k4, m4, n4;

    printf("\n\n" );

    for ( i1 = 1; i1 < 6; i1++ )                    /*这是五角星的上面一个角*/
    {
        for ( j1 = 1; j1 < 19 - i1; j1++ )
            printf( " " );
        for ( k1 = 1; k1 <= 2 * i1 - 1; k1++ )
            printf( "*" );
        printf( "\n" );
    }

    for ( i2 = 1; i2 < 5; i2++ )                    /*这是五角星的中间两个角*/
    {
        for ( j2 = 1; j2 < 3 * i2 - 3; j2++ )
            printf( " " );
        for ( k2 = 1; k2 <= 42 - 6 * i2; k2++ )
            printf( "*" );
        printf( "\n" );
    }

    for ( i3 = 1; i3 < 3; i3++ ) /*这是中间与下部相接的部分*/
    {
        for ( j3 = 1; j3 < 12 - i3; j3++ )
            printf( " " );
        for ( k3 = 1; k3 <= 12 + 2 * i3; k3++ )
            printf( "*" );
        printf( "\n" );
    }

    for ( i4 = 1; i4 < 5; i4++ ) /*这是五角星的下面两个角*/
    {
        for ( j4 = 1; j4 < 10 - i4; j4++ )
            printf( " " );
        for ( k4 = 1; k4 <= 10 - 2 * i4; k4++ )
            printf( "*" );
        for ( m4 = 1; m4 < 6 * i4 - 3; m4++ )
            printf( " " );
        for ( n4 = 1; n4 <= 10 - 2 * i4; n4++ )
            printf( "*" );
        printf( "\n" );
    }

    printf("\n\n" );
}

void RandomizeArray(word *A,int size)
{

    for(int i=0;i<=size-1;i++){
            srand(time(NULL));
            int random_index = rand()%(size-1-i+1)+i;
            int temp = A[i].word_id;
            A[i].word_id=A[random_index].word_id;
            A[random_index].word_id=temp;
        }

}

void print_sort(word *words,int size)
    {
        int i=0;
        int j=0;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(i==words[j].word_id){
                    printf("id:%d    %s\n",words[j].word_id,words[j].lettermean);
                }
            }
        }
    }


int get_line1()
    {
        int c,l=0;
        FILE *fp = fopen("brother.txt", "r");
        while((c = fgetc(fp)) != EOF) if(c == '\n') l++;
            l++;
        l=l-1;
        //printf("%d\n",l);
        return l;
    }

int get_line2()
    {
        int c,l=0;
        FILE *fp = fopen("sister.txt", "r");
        while((c = fgetc(fp)) != EOF) if(c == '\n') l++;
            l++;
        //printf("%d\n",l);
        l=l-1;
        return l;
    }

int get_file1(word *words)
    {
        FILE * fp1 = fopen("brother.txt", "r");//打开输入文件
    int i;
    int k=0;
    int size;
    size=get_line1();

    if (fp1==NULL) {//若打开文件失败则退出
        puts("不能打开文件！");
        return 0;
    }
    while(k<size)
        {
            fgets(words[k].lettermean,100,(FILE*)fp1);//从输入文件读取一行字符串
            words[k].word_id=k;
            k++;
        }
    fclose(fp1);
    return 0;
    }

int get_file2(word *words)
    {
        FILE * fp1 = fopen("sister.txt", "r");//打开输入文件
    int i;
    int k=0;
    int size;
    size=get_line2();

    if (fp1==NULL) {//若打开文件失败则退出
        puts("不能打开文件！");
        return 0;
    }
    while(k<size)
        {
            fgets(words[k].lettermean,100,(FILE*)fp1);//从输入文件读取一行字符串
            words[k].word_id=k;
            k++;
        }
    fclose(fp1);
    return 0;
    }

int main()
    {
        int i;
        int flag;
        int flag2;
        printf("哥哥的单词本还是妹妹的单词本？哥哥的单词本输入1，妹妹的单词本输入2，再次随机输入3，退出输入0\n");
        printstar();
        while(true){
            scanf("%d",&flag);
            if(flag==1){
                flag2=1;
                word words1[1000];
                get_file1(words1);
                int size=get_line1();
                for(i=0;i<size;i++){
                    printf("%d    %s",words1[i].word_id,words1[i].lettermean);
                    }
                RandomizeArray(words1,size);
                printf("---------------------\n\n");
                print_sort(words1,size);
            }

             if(flag==2){
                flag2=2;
                word words2[1000];
                get_file2(words2);
                int size=get_line2();
                for(i=0;i<size;i++){
                    printf("%d    %s",words2[i].word_id,words2[i].lettermean);
                    }
                RandomizeArray(words2,size);
                printf("---------------------\n\n");
                print_sort(words2,size);
            }

             if(flag==3){
                printf("---------------------\n\n");
                if(flag2==1){
                    word words1[1000];
                    get_file1(words1);
                    int size=get_line1();
                    RandomizeArray(words1,size);
                    printf("---------------------\n\n");
                    print_sort(words1,size);
                }

                if(flag2==2){
                    word words2[1000];
                    get_file2(words2);
                    int size=get_line2();
                    RandomizeArray(words2,size);
                    printf("---------------------\n\n");
                    print_sort(words2,size);
                }
             }


             if(flag==0){
                break;
             }
              printf("哥哥的单词本还是妹妹的单词本？哥哥的单词本输入1，妹妹的单词本输入2，再次随机输入3，退出输入0\n");

        }
    }
