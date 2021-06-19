#include <stdio.h>
#include <stdlib.h>
#define M 1000
#define MAX 5

typedef struct {
    int count;
    int data[100];
}stack;

//fungsi stack
void inisial(stack *s);
void push(stack *s, int x);
int pop(stack *s);

//fungsi utama
void hasil();
void RutePendek(stack *s);
void Warshall();

//fungsi tampil
void tampil();
void cetak(int matriks[MAX][MAX]);

//int Global
int Q[MAX][MAX]={{M, 1, 3, M, M}, {M, M, 1, M, 5}, {3, M , M, 2, M}, {M, M, M, M, 1}, {M, M, M, M, M}};
int P[MAX][MAX]={{0, 1, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};
int R[MAX][MAX]={{M, 1, 1, M, M}, {M, M, 1, M, 1}, {1, M , M, 1, M}, {M, M, M, M, 1}, {M, M, M, M, M}};
int asal, tujuan;

int main(){

    printf("Algoritma Graph Berbasis Warshall\n\n");

    printf("Matriks Warshall asal\n");
    tampil();
    Warshall();
    printf("\nMatriks Warshall tujuan\n");
    tampil();
    puts("");
    hasil();
    return 0;
}


void tampil(){
    puts("Matriks beban (Q)");
    cetak(Q);
    puts("");

    puts("Matriks alur (P)");
    cetak(P);
    puts("");

    puts("Matriks rute (R)");
    cetak(R);
}

void cetak(int matriks[MAX][MAX]){
    int i, j;

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
                printf("%4d ", matriks[i][j]);
        }
        puts("");
    }
}

void Warshall(){
    int k, i, j;
    for(k=0; k<MAX; k++){
        for(i=0; i<MAX; i++){
            for(j=0; j<MAX; j++){
                if((Q[i][k]+Q[k][j]) < Q[i][j]){
                    if(R[k][j]==1)
                        R[i][j]=k+1;
                    else
                        R[i][j]=R[k][j];
                    Q[i][j]=(Q[i][k]+Q[k][j]);
                }
                P[i][j]=P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
}

void inisial(stack *s){
    s->count=NULL;
}

void push(stack *s, int x){
    s->data[s->count]=x;
    s->count++;
}

int pop(stack *s){
    int x;
    x=s->data[--s->count];
    s->data[s->count]=NULL;
    return x;
}

void hasil(){
    stack tumpuk;

    inisial(&tumpuk);
    printf("Masukkan asal : ");
    scanf("%i", &asal);
    fflush(stdin);
    printf("Masukkan tujuan : ");
    scanf("%i", &tujuan);
    fflush(stdin);
    printf("Rute terpendek : ");
    RutePendek(&tumpuk);
    printf("Beban =  %i\n", Q[asal-1][tujuan-1]);
}

void RutePendek(stack *s){
    int i;
    for(i=tujuan-1; i>=0 && R[asal-1][i]!=1; i--)
        push(s, R[asal-1][i]);
        printf("%i-", asal);
    while(s->count>0)
        printf("%i-", pop(s));
        printf("%i\n", tujuan);
}
