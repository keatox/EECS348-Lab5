#include <stdio.h>

int main(){
    int score;
    while (1){
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d",&score);
        if (score < 2){
            break;
        }
        printf("\npossible combinations of scoring plays:\n");
        for (int td2=0;td2*8<=score;td2++){
            for (int td1=0;td1*7<=score;td1++){
                for (int td=0;td*6<=score;td++){
                    for (int fg=0;fg*3<=score;fg++){
                        for(int safety=0;safety*2<=score;safety++){
                            if (8*td2+7*td1+6*td+3*fg+2*safety == score){
                                printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n",td2,td1,td,fg,safety);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}