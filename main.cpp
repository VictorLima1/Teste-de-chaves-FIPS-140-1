//
//  main.cpp
//  Chaves
//
//  Created by Victor on 21/09/20.
//

#include <chrono>
#include <iostream>
#include <fstream>
#include <string.h>
#include <bitset>
#include <vector>
#include <stdio.h>

using namespace std;

int runsTeste(string chave){
    //cout << "Vou começar o run teste" << endl;
    int flips = 0, seq2 = 0, seq3 = 0, seq4 = 0, seq5 = 0, seq6 = 0;
    for(int i = 0; i < chave.size() - 1; i++){
        if (chave.at(i) != chave.at(i + 1))
            flips++;
    }

    if (flips < 2267 || flips > 2733)
        return 0;

    for(int i = 0; i < chave.size() - 1; i = i + 2){
        if (chave.at(i) == chave.at(i + 1))
            seq2++;
    }

    if (seq2 < 1079 || seq2 > 1421)
        return 0;

    for(int i = 0; i < chave.size() - 2; i = i + 3){
        if (chave.at(i) == chave.at(i + 1) && chave.at(i + 1) == chave.at(i + 2))
            seq3++;
    }

    if (seq3 < 502 || seq3 > 748)
        return 0;

    for(int i = 0; i < chave.size() - 3; i = i + 4){
        if (chave.at(i) == chave.at(i + 1) && chave.at(i + 1) == chave.at(i + 2) && chave.at(i + 2) == chave.at(i + 3))
            seq4++;
    }

    if (seq4 < 223 || seq4 > 402)
        return 0;

    for(int i = 0; i < chave.size() - 4; i = i + 5){
        if (chave.at(i) == chave.at(i + 1) && chave.at(i + 1) == chave.at(i + 2) && chave.at(i + 2) == chave.at(i + 3) && chave.at(i + 3) == chave.at(i + 4))
            seq5++;
    }

    if (seq5 < 90 || seq5 > 223)
        return 0;

    for(int i = 0; i < chave.size() - 5; i = i + 6){
        if (chave.at(i) == chave.at(i + 1) && chave.at(i + 1) == chave.at(i + 2) && chave.at(i + 2) == chave.at(i + 3) && chave.at(i + 3) == chave.at(i + 4) && chave.at(i + 4) == chave.at(i + 5))
            seq6++;
    }

    if (seq6 < 90 || seq6 > 223)
        return 0;

    return 1;
}

int pokerTest(string chave){
    
    int vetor[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, soma = 0, pos = 5000;

    //char matriz[16][5] = { "0000", "0001", "0010", "0100", "1000", "0011", "0101", "1001", "1010", "1100", "0110", "0111", "1011", "1101", "1110", "1111" };
    char atual[5];

    for(int k = 0; k < 4; k++){
        for(int i = pos - 5000; i < pos; i+=4){
            for(int j = 0; j < 4; j++)
                atual[j] = chave.at(i + j);

            int x = stoi(atual, nullptr, 2);

            //cout << atual;

            vetor[x]++;
                /*for(int k = 0; k < 16; k++){
                    if(strcmp(atual, matriz[k]) == 0){
                        cout << "Encontrei um igual" << endl;
                        igual++;
                    }
                        
                }*/
        }

        for(int i = 0; i < 16; i++)
            soma += vetor[i] * vetor[i];

        //cout << soma << endl; 

        int y = 0.0032 * soma - 5000;

        if(y < 1.03 && y > 57.4)
            return 0;

        pos += 5000;

        soma = 0;
    }

    /*for(int i = 0; i < 16; i++)
        cout << "Repeti " << i + 1 << " essa quantidade: " << vetor[i] << endl;*/

    return 1;
}

    /*for(int i = 0; i < 16; i++)
        cout << "Em " << i << " repeti " << vetor[i] << " vezes" << endl;*/

int longRunTest(string chave){
    int zeroCount = 0, oneCount = 0;

    for(int i = 0; i < chave.length() - 1; i++){
        if (chave.at(i) == '1' && chave.at(i + 1) == '1')
            oneCount++;
        else
            oneCount = 0;
        
        if (chave.at(i) == '0' && chave.at(i + 1) == '0')
            zeroCount++;
        else
            zeroCount = 0;

        if(oneCount >= 34 || zeroCount >= 34)
            return 0;
    }

    return 1;
}

int testeMonobit(string chave){
    int oneCount = 0;

    for(int i = 0; i < chave.length(); i++){
        if (chave.at(i) == '1')
            oneCount++;
    }
    
    if(oneCount > 9654 && oneCount < 10346)
        return 1;
    else
        return 0;
}

string converteBinario(string chave) {
    //cout << "Vou converter" << endl;
    string stringBinaria = "";
    for (char& _char : chave) {
        stringBinaria +=bitset<8>(_char).to_string();
    }
    //cout << "Converti" << endl;
    return stringBinaria;
}

int main(int argc, const char * argv[]) {
    string chaves;

    int chave = 0;
    
    ifstream myfile ("Chaves de Criptografia.txt");

    //cout << "Abri o arquivo" << endl;

    //getline(myfile, chaves);

    //chaves.erase(0, 1);
    //cout << "Apaguei o começo" << endl;



    //chaves.erase(5000, 1);

    //cout << "Apaguei os apóstrofos" << endl;

    //chaves = converteBinario(chaves);

    //cout << chaves << endl;


    while(getline(myfile, chaves)){
        chaves.erase(0, 1);

        chaves.erase(5000, 1);

        chaves = converteBinario(chaves);

        if(testeMonobit(chaves) == 1){
            cout << "A chave " << chave << " passou no teste monobit" << endl;

            if(pokerTest(chaves) == 1){
                cout << "A chave " << chave << " passou no poker test" << endl;

                if(runsTeste(chaves) == 1){
                    cout << "A chave " << chave << " passou no run teste" << endl;

                    if(longRunTest(chaves) == 1)
                        cout << "A chave " << chave << " passou no long run teste e é aleatória" << endl;

                    else
                        cout << "A chave " << chave << " não passou no long run teste" << endl;
                }

                else
                    cout << "A chave " << chave << " não passou no run teste" << endl;
            }

            else
                cout << "A chave " << chave << " não passou no poker test" << endl;
        }

        else
            cout << "A chave " << chave << " não passou no teste monobit, logo, não é aleatória" << endl;


        chaves.clear();

        chave++;
    }

    /*while(getline(myfile, chaves)){
        chaves.erase(0, 1);

        chaves.erase(5000, 1);

        chaves = converteBinario(chaves);

        if(testeMonobit(chaves) == 1)
            cout << "Essa chave passou no teste monobit" << endl;
        else
            cout << "Essa chave não passou no teste monobit" << endl;

        if(longRunTest(chaves) == 1)
            cout << "Essa chave passou no teste long run" << endl;

        chaves.clear();
    }*/

    myfile.close();
    
    return 0;
}
