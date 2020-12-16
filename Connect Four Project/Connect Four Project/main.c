#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int rowGet, columnGet, highGet;
int Score[100]={0};
int chooseLoad;
int loadCounter=0;
char read;

void checkAvailability(int *play,int column,int A[][100]){
    int plays;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (1){
        if(*play==1000 || *play==2000 || *play==3000){
            break ;
        }
        else if (0<*play && *play<=column){
            if (A[1][*play]!='X' && A[1][*play]!='O'){
                break ;
            }
            else {
                SetConsoleTextAttribute(hConsole, 12);
                printf("\aError!please try again:\n");
                while (scanf("%d", &plays) != 1){
                    while (getchar() != '\n');
                    SetConsoleTextAttribute(hConsole, 12);
                    printf ("\aError!please try again:\n");
                }
                *play=plays;
            }
        }
        else {
                SetConsoleTextAttribute(hConsole, 12);
                printf("\aError!please try again:\n");
                while (scanf("%d", &plays) != 1){
                    while (getchar() != '\n');
                    SetConsoleTextAttribute(hConsole, 12);
                    printf ("\aError!please try again:\n");
                }
                *play=plays;
        }
    }
}

int updatecheck(int row,int column,int A[][100])
{
    int H, V, D, D2;
    H=0;
    V=0;
    D=0;
    D2=0;
    int ScorePlay=0;
    H=checkhorizontal(row,column,A);
    V=checkverticle(row,column,A);
    D=checkdiagonl(row,column,A);
    D2=checkoppositediagonl(row,column,A);
    ScorePlay=H+V+D+D2;
    return ScorePlay;
}

int checkdiagonl(int row , int column,int A[][100])
{
    int i=1, j=1;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
            if(A[i][j]=='X' && A[i][j]==A[i+1][j+1] && A[i][j]==A[i+2][j+2] && A[i][j]==A[i+3][j+3])
                {
                    counter++;
                }
        }
    }
    return counter;
}

int checkoppositediagonl(int row , int column,int A[][100])
{
    int i, j;
    int counter=0;
    for(i=row; i>=1; i--)
    {
        for(j=column; j>=1; j--)
        {
            if(A[i][j]=='X' && A[i][j]==A[i+1][j-1] && A[i][j]==A[i+2][j-2] && A[i][j]==A[i+3][j-3])
                {
                    counter++;
                }
        }
    }
    return counter;
}

int checkhorizontal(int row , int column,int A[][100])
{
    int i, j;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
            if(A[i][j] == 'X' && A[i][j]==A[i][j+1] && A[i][j]==A[i][j+2] && A[i][j]==A[i][j+3])
                counter++;
        }
    }
    return counter;
}

int checkverticle(int row , int column,int A[][100])
{
    int i, j;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
    if(A[i][j] == 'X' && A[i][j]==A[i+1][j] && A[i][j]==A[i+2][j] && A[i][j]==A[i+3][j])
                counter++;
        }
    }
    return counter;
}

int updatecheck2(int row,int column,int A[][100])
{
    int H, V, D, S;
    H=0;
    V=0;
    D=0;
    S=0;
    int ScorePlay=0;
    H=checkhorizontal2(row,column,A);
    V=checkverticle2(row,column,A);
    D=checkdiagonl2(row,column,A);
    S=checkoppositediagonl2(row,column,A);
    ScorePlay=H+V+D+S;
    return ScorePlay;
}

int checkdiagonl2(int row , int column,int A[][100])
{
    int i=1, j=1;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
            if(A[i][j]=='O' && A[i][j]==A[i+1][j+1] && A[i][j]==A[i+2][j+2] && A[i][j]==A[i+3][j+3])
                {
                    counter++;
                }
        }
    }
    return counter;
}

int checkoppositediagonl2(int row , int column,int A[][100])
{
      int i, j;
      int counter=0;

    for(i=row; i>=1; i--)
    {
        for(j=column; j>=1; j--)
        {
            if(A[i][j]=='O' && A[i][j]==A[i+1][j-1] && A[i][j]==A[i+2][j-2] && A[i][j]==A[i+3][j-3])
                {
                    counter++;
                }
        }
    }
    return counter;
}

int checkhorizontal2(int row , int column,int A[][100])
{
    int i, j;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
            if(A[i][j] == 'O' && A[i][j]==A[i][j+1] && A[i][j]==A[i][j+2] && A[i][j]==A[i][j+3])
                counter++;
        }
    }
    return counter;
}

int checkverticle2(int row , int column,int A[][100])
{
    int i, j;
    int counter=0;
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
    if(A[i][j] == 'O' && A[i][j]==A[i+1][j] && A[i][j]==A[i+2][j] && A[i][j]==A[i+3][j])
                counter++;
        }
    }
    return counter;
}

int table (int row , int column ,int A[][100],int choose){

    // color definition
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //////////////////
    if(row == 0 || column == 0){
    SetConsoleTextAttribute(hConsole, 12);
    printf("\aError! dimensions cannot be zero.\ndefault dimensions will be taken.");
    row=6;
    column=7;
    }
    int ScoreOfPlay1=0, ScoreOfPlay2=0, loadChoose=0;
    int undo1[1000]={0};
    int redo1[1000]={0};
    int undo2[1000]={0};
    int redo2[1000]={0};
    int indexUndo1=0,indexUndo11=0;
    int indexUndo2=0,indexUndo22=0;
    int counterUndo1=0 , counterRedo1=0 ;
    int counterUndo2=0 , counterRedo2=0 ;
    int indexRedo1=0 , indexRedo2=0;
    int indexRedo11=0 , indexRedo22=0;
    int play1 , play2;
    int row2=row;
    int found=0 , found2=0;
    int i, j;
    // making area of playing spaces
    if (choose ==1){
        for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
                A[i][j]=' ';
            }
        }
    }
    //player 1
    while(1){
        SetConsoleTextAttribute(hConsole, 7);
        if (loadCounter==0 || loadCounter==1){
            print(row,column,A);
            printf("Player one turn:\n");
            while (scanf("%d", &play1) != 1){
                while (getchar() != '\n');
                SetConsoleTextAttribute(hConsole, 12);
                printf ("\aError!please try again:\n");
            }
            // check play
            checkAvailability(&play1,column,A);

            // undo function
            while(play1==1000){
                for(i=1;i<=row;i++){
                    for(j=1;j<=column;j++){
                        if(A[i][j]==' ')
                        continue ;
                        found2=1;
                    }
                }
                if (found2==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\aThere is no undo \n");
                    SetConsoleTextAttribute(hConsole, 7);
                    printf("Player one turn:\n");
                    scanf("%d",&play1);
                    checkAvailability(&play1,column,A);
                }
                else {
                    if(indexUndo22-2>=0){
                        while(A[(undo2[indexUndo22-2])][(undo2[indexUndo22-1])]==' '){
                            indexUndo22-=2;
                        }
                        A[(undo2[indexUndo22-2])][(undo2[indexUndo22-1])]=' ';
                        redo2[indexRedo2]=undo2[indexUndo22-2];
                        indexRedo2++;
                        redo2[indexRedo2]=undo2[indexUndo22-1];
                        indexRedo2++;
                        indexRedo22=indexRedo2;
                        counterUndo2++;
                        indexUndo22-=2;

                        print(row,column,A);
                        break ;
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, 12);
                        printf("\aThere is no undo \n");
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("Player one turn:\n");
                        scanf("%d",&play1);
                        checkAvailability(&play1,column,A);
                    }
                }
            }

            // redo function
            while (play1==2000){
                if(counterRedo1<counterUndo1 && counterUndo1!=0 ){
                        A[(redo1[indexRedo1-2])][(redo1[indexRedo1-1])]='X';
                        indexRedo1-=2;
                        indexUndo11+=2;
                        counterRedo1++;
                        print(row,column,A);
                        break ;
                }
                else{
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("There is no redo \n");
                    SetConsoleTextAttribute(hConsole, 7);
                    printf("Player one turn:\n");
                    scanf("%d",&play1);
                    checkAvailability(&play1,column,A);

                }
            }
            if(play1!=1000 && play1!=2000 && play1!=3000){

                while (A[row2][play1]=='X' || A[row2][play1]=='O'){
                    row2=row2-1;
                }
                A[row2][play1]='X';
                undo1[indexUndo1]=row2;
                indexUndo1++;
                undo1[indexUndo1]=play1;
                indexUndo1++;
                indexUndo11=indexUndo1;
                counterRedo1=0;
                counterUndo1=0;
            }
            row2=row;
            // here print function
            print(row,column,A);
            // score function
            SetConsoleTextAttribute(hConsole, 7);
            ScoreOfPlay1=updatecheck(row,column,A);
            ScoreOfPlay2=updatecheck2(row,column,A);
            frameForScores(ScoreOfPlay1,ScoreOfPlay2);
            // check if the board is finished
            for(i=1;i<=row;i++){
                for(j=1;j<=column;j++){
                    if(A[i][j]!=' ')
                        continue;
                    found=1;
                }
            }
            if (found==0){
                SetConsoleTextAttribute(hConsole,10);
                if (ScoreOfPlay1>ScoreOfPlay2){
                    printf("PLAYER ONE WINS\nCONGRATULATION\n");
                    return ScoreOfPlay1;
                }
                else if(ScoreOfPlay1==ScoreOfPlay2){
                    SetConsoleTextAttribute(hConsole,14);
                    printf("DRAW\n");
                    return ScoreOfPlay1;
                }
                else
                    printf("PLAYER TWO WINS\nCONGRATULATION\n");
                    return ScoreOfPlay2;
            }
            if (play1==3000){
                save(row,column,A,ScoreOfPlay1,ScoreOfPlay2,0);
            }
            found=0;
            found2=0;
        }
        loadCounter=0;
        // player 2

        print(row,column,A);
        SetConsoleTextAttribute(hConsole,7);
        printf("Player two turn:\n");
        while (scanf("%d", &play2) != 1){
            while (getchar() != '\n');
            SetConsoleTextAttribute(hConsole, 12);
            printf ("\aError!please try again:\n");
        }
        // check play
        checkAvailability(&play2,column,A);
        // undo function
        while(play2==1000){
            for(i=1;i<=row;i++){
                for(j=1;j<=column;j++){
                    if(A[i][j]==' ')
                    continue ;
                    found2=1;
                }
            }
            if (found2==0){
                SetConsoleTextAttribute(hConsole, 12);
                printf("\aThere is no undo \n");
                SetConsoleTextAttribute(hConsole, 7);
                printf("Player two turn:\n");
                scanf("%d",&play2);
                checkAvailability(&play2,column,A);
            }
            else {
                if(indexUndo11-2>=0){
                    while(A[(undo1[indexUndo11-2])][(undo1[indexUndo11-1])]==' '){
                        indexUndo11-=2;
                    }
                    A[(undo1[indexUndo11-2])][(undo1[indexUndo11-1])]=' ';
                    redo1[indexRedo1]=undo1[indexUndo11-2];
                    indexRedo1++;
                    redo1[indexRedo1]=undo1[indexUndo11-1];
                    indexRedo1++;
                    indexRedo11=indexRedo1;
					counterUndo1++;
					indexUndo11-=2;

                    print(row,column,A);
                    break ;
                }
                else{
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\aThere is no undo \n");
                    SetConsoleTextAttribute(hConsole, 7);
                    printf("Player two turn:\n");
                    scanf("%d",&play2);
                    checkAvailability(&play2,column,A);
                }
            }
        }
        //redo function
        while (play2==2000){
            if(counterRedo2<counterUndo2&& counterUndo2!=0){
                    A[(redo2[indexRedo22-2])][(redo2[indexRedo22-1])]='O';
                    indexRedo22-=2;
                    indexUndo22+=2;
                    counterRedo2++;
                    print(row,column,A);
                    break ;
            }
            else{
                SetConsoleTextAttribute(hConsole, 12);
                printf("\aThere is no redo \n");
                SetConsoleTextAttribute(hConsole, 7);
                printf("Player two turn:\n");
                scanf("%d",&play2);
                checkAvailability(&play2,column,A);
            }
        }
        if(play2!=1000 && play2!=2000 && play2!=3000){
            while (A[row2][play2]=='X' || A[row2][play2]=='O'){
                row2=row2-1;
            }
            A[row2][play2]='O';
            undo2[indexUndo2]=row2;
            indexUndo2++;
            undo2[indexUndo2]=play2;
            indexUndo2++;
            indexUndo22=indexUndo2;
            counterRedo2=0;
            counterUndo2=0;
        }
        row2=row;
        // here print function
        print(row,column,A);
        // score function
        SetConsoleTextAttribute(hConsole, 7);
        ScoreOfPlay1=updatecheck(row,column,A);
        ScoreOfPlay2=updatecheck2(row,column,A);
        frameForScores(ScoreOfPlay1,ScoreOfPlay2);
        // check if the board is finished
        if (play2==3000){
            save(row,column,A,ScoreOfPlay1,ScoreOfPlay2,0);
        }
        for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
                if(A[i][j]!=' ')
                    continue;
                found=1;
            }
        }
        printf("\n");
        if (found==0){
            SetConsoleTextAttribute(hConsole,10);
            if (ScoreOfPlay1>ScoreOfPlay2){
                printf("PLAYER ONE WINS\nCONGRATULATION\n");
                return ScoreOfPlay1;
            }
            else if(ScoreOfPlay1==ScoreOfPlay2){
                SetConsoleTextAttribute(hConsole,14);
                printf("DRAW\n");
                return ScoreOfPlay1;
            }
            else
                printf("PLAYER TWO WINS\nCONGRATULATION\n");
                return ScoreOfPlay2;
        }
        found=0;
        found2=0;
    }
}

int computertable (int row , int column ,int A[][100],int choose){

    // color definition
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //////////////////
    if(row == 0 || column == 0){

    printf("\aError! dimensions cannot be zero.\ndefault dimensions will be taken.");
    row=6;
    column=7;
    }
    int ScoreOfPlayer=0 , computerscore=0, loadChoose=1;
    int undo[1000]={0};
    int redo[1000]={0};
    int indexUndo1=0,indexUndo11=0;
    int counterUndo=0 , counterRedo=0 ;
    int indexRedo1=0 , indexRedo11=0;
    int play;
    int row2=row;
    int found=0 , found2=0;
    int flag =0;
    int i, j;
    // making area of playing spaces
    if (choose ==1){
        for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
                A[i][j]=' ';
            }
        }
    }
    //player
    while(1){
        print(row,column,A);
        printf("Player one turn:\n");
        while (scanf("%d", &play) != 1){
            while (getchar() != '\n');
            printf ("\aError!please try again:\n");
        }
        // check play
        checkAvailability(&play,column,A);

        // undo function
        while(play==1000){
            for(i=1;i<=row;i++){
                for(j=1;j<=column;j++){
                    if(A[i][j]==' ')
                    continue ;
                    found2=1;
                }
            }
            if (found2==0){
                printf("There is no undo \n");
                printf("Player one turn:\n");
                scanf("%d",&play);
                checkAvailability(&play,column,A);
            }
            else {
                if(indexUndo11-4>=0){
                    while(A[(undo[indexUndo11-2])][(undo[indexUndo11-1])]==' ' ||  A[(undo[indexUndo11-4])][(undo[indexUndo11-3])]==' '){
                        indexUndo11-=2;
                    }
                    A[(undo[indexUndo11-2])][(undo[indexUndo11-1])]=' ';
                    A[(undo[indexUndo11-4])][(undo[indexUndo11-3])]=' ';
                    redo[indexRedo1]=undo[indexUndo11-2];
                    indexRedo1++;
                    redo[indexRedo1]=undo[indexUndo11-1];
                    indexRedo1++;
                    redo[indexRedo1]=undo[indexUndo11-4];
                    indexRedo1++;
                    redo[indexRedo1]=undo[indexUndo11-3];
                    indexRedo1++;
                    indexRedo11=indexRedo1;
                    counterUndo++;
                    indexUndo11-=4;

                    print(row,column,A);
                    break ;
                }
                else {
                    printf("\aThere is no undo \n");
                    printf("Player one turn:\n");
                    scanf("%d",&play);
                    checkAvailability(&play,column,A);
                }
            }
        }

        // redo function
        while (play==2000){
            if(counterRedo<counterUndo && counterUndo!=0 ){
                    A[(redo[indexRedo1-2])][(redo[indexRedo1-1])]='X';
                    A[(redo[indexRedo1-4])][(redo[indexRedo1-3])]='O';
                    indexRedo1-=4;
                    indexUndo11+=4;
                    counterRedo++;
                    print(row,column,A);
                    break ;
            }
            else{
                printf("\aThere is no redo \n");
                printf("Player one turn:\n");
                scanf("%d",&play);
                checkAvailability(&play,column,A);

            }
        }

        if(play!=1000 && play!=2000 && play!=3000){
            while (A[row2][play]=='X' || A[row2][play]=='O'){
                row2=row2-1;
            }
            A[row2][play]='X';
            undo[indexUndo1]=row2;
            indexUndo1++;
            undo[indexUndo1]=play;
            indexUndo1++;
            indexUndo11=indexUndo1;
            counterUndo=0;
            counterRedo=0;
            // check if the board is finished
            for(i=1;i<=row;i++){
                for(j=1;j<=column;j++){
                    if(A[i][j]!=' ')
                        continue;
                    found=1;
                }
            }
            if (found==0){
                SetConsoleTextAttribute(hConsole,10);
                if (ScoreOfPlayer>computerscore){
                    printf("PLAYER ONE WINS\nCONGRATULATION\n");
                    return ScoreOfPlayer;
                }
                else if(ScoreOfPlayer==computerscore){
                    SetConsoleTextAttribute(hConsole,14);
                    printf("DRAW\n");
                    return ScoreOfPlayer;
                }
                else
                    printf("COMPUTER WINS\n");
                    return computerscore;
            }
            found=0;
            found2=0;
            // check the first line
            if (row2!=1){
                A[row2-1][play]='O';
                undo[indexUndo1]=row2-1;
                indexUndo1++;
                undo[indexUndo1]=play;
                indexUndo1++;
                indexUndo11=indexUndo1;
            }
            else {
                for(i=row;i>=1;i--){
                    for(j=1;j<=column;j++){
                        if(A[i][j]==' '){
                            flag=1;
                            A[i][j]='O';
                            undo[indexUndo1]=i;
                            indexUndo1++;
                            undo[indexUndo1]=j;
                            indexUndo1++;
                            indexUndo11=indexUndo1;
                            break ;
                        }
                        if(flag == 1){
                            break ;
                        }
                    }
                }

            }
        }
        row2=row;
        flag =0;
        // here print function
        print(row,column,A);
        // score function
        ScoreOfPlayer=updatecheck(row,column,A);
        computerscore=updatecheck2(row,column,A);
        frameForScores2(ScoreOfPlayer,computerscore);
        // check if the board is finished
        for(i=1;i<=row;i++){
            for(j=1;j<=column;j++){
                if(A[i][j]!=' ')
                    continue;
                found=1;
            }
        }
        if (found==0){
            SetConsoleTextAttribute(hConsole,10);
            if (ScoreOfPlayer>computerscore){
                printf("PLAYER ONE WINS\nCONGRATULATION\n");
                return ScoreOfPlayer;
            }
            else if(ScoreOfPlayer==computerscore){
                SetConsoleTextAttribute(hConsole,14);
                printf("DRAW\n");
                return ScoreOfPlayer;
            }
            else
                printf("COMPUTER WINS\n");
                return computerscore;
        }
        found=0;
        found2=0;
        if (play==3000){
            save(row,column,A,ScoreOfPlayer,computerscore,1);
        }

    }
}

void print(int rows,int columns,int B[][100])
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 87);
    int i , j ,k ;
    //print the table
    for(i=1; i<=rows; i++)
    {
        if(i==1)
        {
            for(j=1; j<=columns; j++)
            printf("  %d ",j);
            printf("\n");
        }
        for(j=1; j<=columns; j++)
        {
            printf("| %c ", B[i][j]);

        }
        printf("|\n");
        for(k=0; k<columns; k++){
        printf(" ---");
        }
        printf("\n");
    }

}

void save(int row,int column,int B[][100] ,int ScoreOfPlay1, int ScoreOfPlay2, int choose)
{
    FILE * input_file;
    input_file=fopen("Saves.txt","w");
    int i , j ;
    //save input and output
    fprintf(input_file,"%d",choose);
    fprintf(input_file,"\n");
    fprintf(input_file,"%d",ScoreOfPlay1);
    fprintf(input_file,"\n");
    fprintf(input_file,"%d",ScoreOfPlay2);
    fprintf(input_file,"\n");
    fprintf(input_file,"%d",rowGet);
    fprintf(input_file,"\n");
    fprintf(input_file,"%d",columnGet);
    fprintf(input_file,"\n");
    fprintf(input_file,"%d",highGet);
    fprintf(input_file,"\n");


    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
        {
            fprintf(input_file,"%d ",B[i][j]);
        }
        fprintf(input_file,"\n");
    }
    fclose(input_file);
}

void load(int B[][100])
{
    FILE * load_file;
    load_file=fopen("Saves.txt","r");
    int checkPlay, counter1=0, counter2=0;
    int score1, score2;

    fscanf(load_file,"%d",&chooseLoad); //chooseLoad to differ between computer or player VS. player
    fscanf(load_file,"%d",&score1);
    fscanf(load_file,"%d",&score2);
    fscanf(load_file,"%d",&rowGet);
    fscanf(load_file,"%d",&columnGet);
    fscanf(load_file,"%d",&highGet);

    int i , j ;

    if(chooseLoad == 0)
    {
       for(i=1; i<=rowGet; i++)
       {
         for(j=1; j<=columnGet; j++)
         {
            fscanf(load_file,"%d ",&B[i][j]);
            checkPlay=B[i][j];

            if(checkPlay=='X') counter1++;

            else if(checkPlay=='O') counter2++;

            else if(B[i][j] != 'X' && B[i][j] != 'O' && B[i][j] !=' ')
            {
                //check if the file contain elements expect X O ' '
                printf("Error loading There are some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                table(rowGet,columnGet,B,1);
            }
         }
       }
       if(counter1 >counter2) loadCounter=2;
       if(counter1-counter2 > 1)
       {
                //check if x greater than o more than 1
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                table(rowGet,columnGet,B,1);
       }
       else if(counter2-counter1 > 1)
       {
                //check if o greater than x more than 1
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                table(rowGet,columnGet,B,1);
       }
       else if(score1 != updatecheck(rowGet,columnGet,B))
       {
                //score one in the file not equal true score
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                table(rowGet,columnGet,B,1);
       }
       else if(score2 != updatecheck2(rowGet,columnGet,B))
       {
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                table(rowGet,columnGet,B,1);
       }
    }

    else if(chooseLoad == 1)
    {
       for(i=1; i<=rowGet; i++)
       {
         for(j=1; j<=columnGet; j++)
         {
            fscanf(load_file,"%d ",&B[i][j]);
            checkPlay=B[i][j];

            if(checkPlay=='X') counter1++;

            else if(checkPlay=='O') counter2++;

            else if(B[i][j] != 'X' && B[i][j] != 'O' && B[i][j] !=' ')
            {
                //check if the file contain elements expect X O ' '
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                computertable(rowGet,columnGet,B,1);
            }
         }
       }
       if(counter1-counter2 > 1)
       {
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                computertable(rowGet,columnGet,B,1);
       }
       else if(counter2-counter1 > 1)
       {
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                computertable(rowGet,columnGet,B,1);
       }
       else if(score1 != updatecheck(rowGet,columnGet,B))
       {
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                computertable(rowGet,columnGet,B,1);
       }
       else if(score2 != updatecheck2(rowGet,columnGet,B))
       {
                printf("Error loading There is some thing wrong in the file\n ");
                printf("***********New Game*********\n");
                computertable(rowGet,columnGet,B,1);
       }
    }
}

int HighScore(int NumberOfHighScore)
{
    int i;
    static int l=99;
    Score[l]=NumberOfHighScore;
    l--;
    FILE *output_file;
    output_file=fopen("High Score1.txt","w");
    for(i=0; i<100; i++)
    {
        fprintf(output_file,"%d\n",Score[i]);
    }
    fclose(output_file);
}

int maximum()
{
    int maxmum=0;
    int i, j , k,u=100,temp;
    int counter;
    int A[100]={0};

    FILE*input_file;
    input_file=fopen("High Score1.txt","r");
       FILE*output_file;
    output_file=fopen("High Score.txt","w");

    for(i=0; i<100; i++)
    {
        fscanf(input_file,"%d",&A[i]);
    }
    maxmum=A[0];
    for(j=0; j<100; j++)
    {
        if(A[j]>maxmum)
        {
         maxmum=A[j];
         u=j;
        }
    }
         //swapping
         temp=A[0];
         A[0]=maxmum;
         A[u]=temp;
         counter=1;
         while(counter<=99)
         {
             maxmum=A[counter];
             for(j=counter; j<100; j++)
               {
                 if(A[j]>maxmum)
                   {
                     maxmum=A[j];
                     u=j;
                   }
               }
             temp=A[counter];
             A[counter]=maxmum;
             A[u]=temp;
             counter++;
         }

         for(k=0; k<100; k++)
           {
             fprintf(output_file,"%d\n",A[k]);
           }
           fclose(output_file);
}

void printHighScore(int numberOfHighScoreTerms)
{
    int i , j;
    int scorePrint[100]={0};

    FILE*output_file;
    output_file=fopen("High Score.txt","r");
    for(i=0; i<numberOfHighScoreTerms; i++)
    {
        fscanf(output_file,"%d",&scorePrint[i]);
    }
    printf("High Score List :\n");
    for(j=0; j<numberOfHighScoreTerms; j++)
    {
        printf("High Score[%d] = %d\n",j,scorePrint[j]);
    }
}

void loadHighScore()
{
    int i;
      FILE*output_file;
    output_file=fopen("High Score.txt","r");

    for(i=0; i<100; i++)
    {
        fscanf(output_file,"%d",&Score[i]);
    }
    fclose(output_file);
}

void frame()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n");
    printf("*      Welcome to Connect four Game          *  \n");
    printf("*                                            *  \n");
    printf("*            Play new Game                   *  \n");
    printf("*                                            *  \n");
    printf("*          Load the last Game                *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  \n");
    printf("*       to play new game press   1           *  \n");
    printf("*       to load last game press  2           *  \n");
    printf("*                                            *  \n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  ");
}

void frame2()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n");
    printf("*      Welcome to Connect four Game          *  \n");
    printf("*                                            *  \n");
    printf("*            player Vs. player               *  \n");
    printf("*                                            *  \n");
    printf("*            player Vs. Computer             *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*                                            *  \n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  \n");
    printf("*       player Vs. player press    1         *  \n");
    printf("*       player Vs. Computer press  2         *  \n");
    printf("*                                            *  \n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  ");
}

void frameForScores(int n, int m)
{
    printf("\t\t*****************************\n");
    printf("\t\t* Play 1      * play 2      *\n");
    printf("\t\t*   %d         *   %d         *\n",n,m);
    printf("\t\t*****************************\n");
    printf("\t\t* Redo 1000     save 3000   *\n");
    printf("\t\t* Undo 2000                 *\n");
    printf("\t\t*****************************\n");
}

void frameForScores2(int n, int m)
{
    printf("\t\t*****************************\n");
    printf("\t\t* Play 1      * computer    *\n");
    printf("\t\t*   %d         *   %d         *\n",n,m);
    printf("\t\t*****************************\n");
    printf("\t\t* Redo 1000     save 3000   *\n");
    printf("\t\t* Undo 2000                 *\n");
    printf("\t\t*****************************\n");
}
void xml()
{
    int flag1=0,flag2=0,flag3=0;
    char x1[20];
    int x1counter=0;
    char x2[20];
    int x2counter=0;
    char x3[20];
    int x3counter=0;
    char x4[20];
    int x4counter=0;
    char x5[20];
    int x5counter=0;
    char x6[20];
    int x6counter=0;
    char x7[20];
    int x7counter=0;
    char x8[20];
    int x8counter=0;
    int d,i,j;
   // int  row, column, High;
    FILE * input_file;
    input_file = fopen("mmm.xml","r");
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x1[x1counter]=read;
            x1counter++;
            fscanf(input_file,"%c",&read);
            }
            x1[x1counter]='>';
            x1counter++;
        }
    }
    if(x1[0] != '<' || x1[1] != 'C' || x1[2] != 'o' || x1[3] != 'n' || x1[4] != 'f' || x1[5] != 'i' || x1[6] != 'g' ||
       x1[7] != 'u' || x1[8] != 'r' || x1[9] != 'a' || x1[10] != 't' || x1[11] != 'i' || x1[12] != 'o' || x1[13] != 'n' ||
       x1[14] != 's' || x1[15] != '>' )
    {
       printf("Error!\n") ;
       rowGet = 6;
       columnGet=7;
       highGet=5;
       return ;
    }

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x2[x2counter]=read;
            x2counter++;
            fscanf(input_file,"%c",&read);
            }
            x2[x2counter]='>';
            x2counter++;
        }
    }

    if(x2[0] != '<' || x2[1] != 'W' || x2[2] != 'i' || x2[3] != 'd' || x2[4] != 't' || x2[5] != 'h' || x2[6] != '>' )
    {
        printf("Error width!\n") ;
        flag1=1;
        columnGet=7;
    }

    fscanf(input_file,"%d",&columnGet);
    if (flag1==1){
        columnGet=7;
    }
    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x3[x3counter]=read;
            x3counter++;
            fscanf(input_file,"%c",&read);
            }
            x3[x3counter]='>';
            x3counter++;
        }
    }

    if(x3[0] != '<' || x3[1] != '/' || x3[2] != 'W' || x3[3] != 'i' || x3[4] != 'd' || x3[5] != 't' || x3[6] != 'h' ||
       x3[7] != '>' )
    {
        printf("Error width! \n") ;
        columnGet=7;
    }

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x4[x4counter]=read;
            x4counter++;
            fscanf(input_file,"%c",&read);
            }
            x4[x4counter]='>';
            x4counter++;
        }
    }
    if(x4[0] != '<' || x4[1] != 'H' || x4[2] != 'e' || x4[3] != 'i' || x4[4] != 'g' || x4[5] != 'h' || x4[6] != 't' ||
       x4[7] != '>')
    {
        printf("Error hight!\n") ;
        flag2=1;
        rowGet = 6;
    }

    fscanf(input_file,"%d",&rowGet);
    if(flag2==1){
        rowGet=6;
    }
    d=rowGet;

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x5[x5counter]=read;
            x5counter++;
            fscanf(input_file,"%c",&read);
            }
            x5[x5counter]='>';
            x5counter++;
        }
    }
    if(x5[0] != '<' || x5[1] != '/' || x5[2] != 'H' || x5[3] != 'e' || x5[4] != 'i' || x5[5] != 'g' || x5[6] != 'h' ||
       x5[7] != 't' || x5[8] != '>')
    {
        printf("Error hight!\n") ;
        rowGet = 6;
    }

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x6[x6counter]=read;
            x6counter++;
            fscanf(input_file,"%c",&read);
            }
            x6[x6counter]='>';
            x6counter++;
        }
    }
    if(x6[0] != '<' || x6[1] != 'H' || x6[2] != 'i' || x6[3] != 'g' || x6[4] != 'h' || x6[5] != 's' || x6[6] != 'c' ||
       x6[7] != 'o' || x6[8] != 'r' || x6[9] != 'e' || x6[10] != 's' || x6[11] != '>' )
    {
        printf("Error high score!\n");
        flag3=1;
        highGet=5;
    }

    fscanf(input_file,"%d",&highGet);
    if (flag3==1){
        highGet=5;
    }
    d=highGet;

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x7[x7counter]=read;
            x7counter++;
            fscanf(input_file,"%c",&read);
            }
            x7[x7counter]='>';
            x7counter++;
        }
    }
    if(x7[0] != '<' || x7[1] != '/' || x7[2] != 'H' || x7[3] != 'i' || x7[4] != 'g' || x7[5] != 'h' || x7[6] != 's' ||
       x7[7] != 'c' || x7[8] != 'o' || x7[9] != 'r' || x7[10] != 'e' || x7[11] != 's' || x7[12] != '>')
    {
        printf("Error high score!\n");
        highGet=5;
    }

    read=' ';
    while(read!='>')
    {
        fscanf(input_file,"%c",&read);

        if (read!=' ' && read!='\n' && read!='\t'){
            while (read!='>'){
            x8[x8counter]=read;
            x8counter++;
            fscanf(input_file,"%c",&read);
            }
            x8[x8counter]='>';
            x8counter++;
        }
    }
    if(x8[0] != '<' || x8[1] != '/' || x8[2] != 'C' || x8[3] != 'o' || x8[4] != 'n' || x8[5] != 'f' || x8[6] != 'i' ||
       x8[7] != 'g' || x8[8] != 'u' || x8[9] != 'r' || x8[10] != 'a' || x8[11] != 't' || x8[12] != 'i' || x8[13] != 'o' ||
       x8[14] != 'n' || x8[15] != 's' || x8[16] != '>')
    {
        printf("Error\n") ;
        rowGet = 6;
        columnGet=7;
        highGet=5;
        return ;
    }

}


int main()
{
    int choose=0,choose2;
    int A[100][100];
    int highScoreGet;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    frame();
    SetConsoleTextAttribute(hConsole, 7);
    printf("\nEnter your choose:\n");
    while (scanf("%d", &choose) != 1){
        while (getchar() != '\n');
        SetConsoleTextAttribute(hConsole, 12);
        printf ("\aError!please try again\n");
        }
    while(choose!=1 && choose!=2){
        SetConsoleTextAttribute(hConsole, 12);
        printf("\aError!please try again\n");
        while (scanf("%d", &choose) != 1){
            while (getchar() != '\n');
            SetConsoleTextAttribute(hConsole, 12);
            printf ("\aError!please try again\n");
        }
    }
    if(choose == 1)
    {
         xml();
         frame2();
         printf("\nEnter your choose:\n");
         scanf("%d",&choose2);
         if(choose2==1)
         {
              loadHighScore();
              highScoreGet=table(rowGet,columnGet,A,choose);
              HighScore(highScoreGet);
              maximum();
              printHighScore(highGet);
         }
         else if(choose2 == 2)
         {
              loadHighScore();
              highScoreGet=computertable(rowGet,columnGet,A,choose);
              HighScore(highScoreGet);
              maximum();
              printHighScore(highGet);
         }
    }
    else if(choose == 2)
    {
        loadHighScore();
        load(A);
        if(chooseLoad == 0)
        {
           highScoreGet=table(rowGet,columnGet,A,choose);
           HighScore(highScoreGet);
           maximum();
           printHighScore(highGet);
        }
        else if(chooseLoad == 1)
        {
           highScoreGet=computertable(rowGet,columnGet,A,choose);
           HighScore(highScoreGet);
           maximum();
           printHighScore(highGet);
        }
    }

    return 0;
}
