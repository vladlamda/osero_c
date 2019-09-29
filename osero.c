#include <stdio.h>

int field[8][8]={0};
int flag=0;

void show(){
  int i,j;
  printf("\n 01 2 3 4 5 6 7\n");
  for(i=0;i<8;i++){
    printf("%d",i);
    for (j=0;j<8;j++){
      switch (field[i][j]) {
        case 0:
          printf("_");
          break;
        case 1:
          printf("x");
          break;
        case 2:
          printf("o");
          break;
        default:
          printf("-");
      }
    }
    printf("%s\n", );
  }
}

int check(int ro,int co,int i,int j,int turn){
  if(field[ro][co]==turn){
    flag=1;
    return turn;
  }else if(field[ro][co==0]){
    return (turn==1?2:1);
  }else{
    field[ro][co]=check(ro+1,ro+j,i,j,turn);
    if(flag=1){
      return turn;
    }else{
      return(turn==1?2:1);
    }
  }
  return -1;
}

int search(int ro,int co,int turn){
  int i,j;
  int success=0;

  for(i=-1;i<=1;i++){
    for(j=-1;j<=1;j++){
      if(!(i==0&&j==0)&&ro+2*i>=0&&ro+2*i<8&&co+2*j>=0&&ro+2*i<8&&field[ro+1][co+j]!=0&&field[ro+i][co+j]!=turn){
        field[ro+i][co+j]=check(ro+2*j,i,j,turn);
        if(flag==1&&success==0){
          success=1;
        }
      }
    }
  }
  return success;
}

int main(){
  int turn=1;//1=o,2=x
  int ro,co;
  int success;

  field[3][3]=1;
  field[4][4]=1;
  field[3][4]=2;
  field[4][3]=2;

  while(1){
    show();
    do{
      printf("turn %s:",(turn==1?"x":"o"));
      scanf("%d %d",&ro,&co);
    }while (field[ro][co]!=0);
    field[ro][co]=turn;
    success=search(ro,co,turn);
    if(success==0){
      printf("can't put\n");
      field[ro][co]==0;
      continue;
    }
    success=0;
    turn=(turn==1?2:1);
  }
  return 0;
}
