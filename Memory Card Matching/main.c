#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ROW 6
#define COL 6

char board[ROW][COL];
char header[] = "    1   2   3   4   5   6  ";
char tempArray[ROW][COL];
int score=0;

void filltemp(){
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COL;j++){
      tempArray[i][j]='$';
    }
  }
}
void fill(){
    board[0][0]='A';
    board[0][1]='T';
    board[0][2]='C';
    board[0][3]='X';
    board[0][4]='Y';
    board[0][5]='T';
    board[1][0]='C';
    board[1][1]='H';
    board[1][2]='H';
    board[1][3]='Z';
    board[1][4]='E';
    board[1][5]='M';
    board[2][0]='N';
    board[2][1]='L';
    board[2][2]='G';
    board[2][3]='P';
    board[2][4]='V';
    board[2][5]='J';
    board[3][0]='Z';
    board[3][1]='N';
    board[3][2]='A';
    board[3][3]='Y';
    board[3][4]='J';
    board[3][5]='W';
    board[4][0]='G';
    board[4][1]='M';
    board[4][2]='P';
    board[4][3]='E';
    board[4][4]='S';
    board[4][5]='U';
    board[5][0]='V';
    board[5][1]='L';
    board[5][2]='W';
    board[5][3]='U';
    board[5][4]='S';
    board[5][5]='X';
}
void tahta(){
  printf("%s\n",header);
  for(int i=0;i<ROW;i++){
    printf("%d:",i+1);
    for(int j=0;j<COL;j++){
      printf(" [$]");
    }
    printf("\n");
  }
}
void play(){
  int x,x1,y,y1,a,a1,b,b1;
  char p;
  lab1:
  printf("Enter a coordinate:");
  scanf(" %d", &x);
  scanf(" %d", &y);
  x1=x-1;
  y1=y-1;
  if(((x>6)||(x<=0)||(y>6)||(y<=0))){
    printf("Wrong move!\n");
    goto lab1;
  }
  if(tempArray[x1][y1]!='$'){
    printf("Wrong move!\n");
    goto lab1; 
  }
  lab2:
  printf("Enter a coordinate:");
  scanf(" %d", &a);
  scanf(" %d", &b);
  a1=a-1;
  b1=b-1;
  if(((a>6)||(a<=0)||(b>6)||(b<=0))){
    printf("Yanlış hamle\n");
    goto lab2;
  }
  if(tempArray[a1][b1]!='$'){
    printf("Yanlış hamle\n");
    goto lab2; 
  }
  printf("%s\n",header);
  for(int i=0;i<ROW;i++){
    printf("%d:",i+1);
    for(int j=0;j<COL;j++){
      if((i==x1)&&(j==y1)){
        printf(" [%c]",board[x1][y1]);
        continue;
      }
      if((i==a1)&&(j==b1)){
        printf(" [%c]",board[a1][b1]);
      }
      else
        printf(" [%c]",tempArray[i][j]);
    }
    printf("\n");
  }
  if(board[x1][y1]==board[a1][b1]){
    score=score+3;
    tempArray[x1][y1]=board[x1][y1];
    tempArray[a1][b1]=board[a1][b1];
  }
  else if (board[x1][y1]!=board[a1][b1]){
    score=score-1;
    sleep(5);
    system("clear");
    printf("%s\n",header);
    for(int i=0;i<ROW;i++){
      printf("%d:",i+1);
      for(int j=0;j<COL;j++){
        printf(" [%c]",tempArray[i][j]);
      }
    printf("\n");
  }
    
  }
}
int match(){
  int counter=0;
  for(int i=0;i<ROW;i++){
      for(int j=0;j<COL;j++){
        if(tempArray[i][j]!='$'){
          counter=counter+1;
        }
      }
    }
  if(counter==36){
    return 1;
  }
  return 0;
}
int main(){
  filltemp();
  fill();
  tahta();
  while(1){
    play();
    printf("Your score is %d\n",score);
    if(match()){
      printf("End Game!\n");
      break;
    }
  }
    
  
}