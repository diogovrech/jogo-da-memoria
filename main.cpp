#include <iostream>
#include<time.h>
#include<conio.h>
using namespace std;

int main()
{
    int linha1, coluna1, linha2, coluna2;
    int jogadas=24, fim=0;
    int escolha1, escolha2;
    int mtz [4][4]=  {1,4,5,2,
                      7,2,8,7,
                      3,6,1,4,
                      6,5,3,8};
    int mtz2 [4][4]= {0,0,0,0,
                      0,0,0,0,
                      0,0,0,0,
                      0,0,0,0};
    int mtz3 [4][4]= {0,0,0,0,
                      0,0,0,0,
                      0,0,0,0,
                      0,0,0,0};
    int line1=0;
    int col1=0;
    int num=0;
        srand(time(NULL));
        num=rand()%3;
switch(num){
case 0:for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            mtz2[i][j]=mtz[j][i];
            cout<<mtz2[i][j]<<" ";

        }
        cout << endl;
    }cout<<"invertida"<<endl;
    break;

case 1:for (int i=3; i>=0; i--){
        for (int j=0; j<4; j++){
            mtz2[line1][j]=mtz[i][j];
            cout<<mtz2[line1][j]<<" ";
        }
        line1++;
        cout << endl;
    }cout<<"invertida por linha";
    break;

case 2:for (int i=0; i<4; i++){
        for (int j=3,col1=0; j>=0; j--,col1++){
            mtz2[i][col1]=mtz[i][j];
            cout<<mtz2[i][col1]<<" ";
        }

        cout << endl;
    }
    cout<<"invertida por coluna";
     break;

}   cout<<endl;
    cout<<"|x| |x| |x| |x|"<<endl;
    cout<<"|x| |x| |x| |x|"<<endl;
    cout<<"|x| |x| |x| |x|"<<endl;
    cout<<"|x| |x| |x| |x|"<<endl;

    while(jogadas>0  && fim!=8){
    cout<<"Escolha uma linha e coluna:                  Pontuacao= "<<fim<<"    Jogadas restantes= "<<jogadas<<endl;
    cin>>linha1>>coluna1;
        while(linha1<0 || linha1>3 || coluna1<0 || coluna1>3 || mtz3 [linha1][coluna1] !=0){
            cout<<"Posicao invalida ou ja acertada, tente novamente"<<endl;
            cin>>linha1>>coluna1;
        }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mtz3[i][j] !=0){
                cout<<"|"<<mtz3[i][j]<<"|";
        }
            else if(i==linha1 && j==coluna1){
                cout<<"|"<<mtz2[i][j]<<"|";
                linha1=i;
                coluna1=j;
                escolha1=mtz2[i][j];

        }
            else{
                cout<<"|x|";
        }
    }
    cout<<endl;
    }
    cout<<"Escolha outra linha e coluna:                  Pontuacao= "<<fim<<"    Jogadas restantes= "<<jogadas<<endl;
    cin>>linha2>>coluna2;
        while(linha1<0 || linha1>3 || coluna1<0 || coluna1>3 || mtz3 [linha2][coluna2] !=0 || linha1==linha2 && coluna1==coluna2){
            cout<<"Posicao invalida ou repetida, tente novamente"<<endl;
            cin>>linha2>>coluna2;
        }
    jogadas--;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mtz3[i][j]!=0){
                cout<<"|"<<mtz3[i][j]<<"|";
        }
            else if(i==linha2 && j==coluna2){
                cout<<"|"<<mtz2[i][j]<<"|";
                escolha2=mtz2[i][j];
        }
            else if(linha1==i && coluna1==j){
                cout<<"|"<<mtz2[linha1][coluna1]<<"|";
        }
            else{
                cout<<"|x|";
        }
    }
    cout<<endl;

    }
        if(escolha1 == escolha2){
            cout<<"Muito bem"<<endl;
            mtz3[linha1][coluna1]=escolha1;
            mtz3[linha2][coluna2]=escolha2;

            fim++;

        }
        else{
            cout<<"Tente novamente"<<endl;
        }
        system("pause");
        system("cls");

}
    if(fim==8){
        cout<<"Muito bem, voce conseguiu vencer!";
    }
    else{
        cout<<"Acabaram suas jogadas, tente novamente.";
    }
  return 0;
}




