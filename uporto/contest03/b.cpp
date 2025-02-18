/*
 * Nome do arquivo: b.cpp
 * Autor: Pedro Arthur de Oliveira Barreto 
 * Data de criação: 12/02/2025
 * Descrição: 
 * Plataforma: 
 * Solução: 
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// Declaração de variáveis
int N;
string stringSignal;

// Função principal
int main() {
    fast_io;
    cin >> N;
    cin >> stringSignal;
    // Dado o caso de teste:
    // 
    // Input:
    // 5
    // ?????
    // Output:
    // 6
    //  
    // Percebi que a resposta seria EEDDD, ou seja, buscando maximizar as interações de ED,
    // a melhor estratégia adotada seria tentar manter a quantidade de 'E' e 'D' de cada 
    // lado a mais próxima possível, dando prioridade para que a quantidade de 'D' seja maior

    // Um vetor de prefixo que calcula a quantidade de 'E' e '?'
    vector<int> prefix_sum(N+1, 0);
    for(int i=0; i < N; i++) {
        prefix_sum[i+1] = prefix_sum[i] + ((stringSignal[i] == 'E' || stringSignal[i] == '?') ? 1 : 0);
    }

    // Melhor fazer a iteração da direita para esquerda, visto que estamos interessados na
    // quantidade de 'D' que vieram depois de cada 'E', ou seja, contamos os 'D' que vimos e 
    // adicionamos ao total quando encontrarmos um 'E'
    long long answer = 0;
    int d_count = 0;
    for(int i=N-1; i >= 0; i--) {
        char c = stringSignal[i];
        if (c == 'D') {
            // Aumentamos o contador de 'D'
            d_count++;
        } else if (c == 'E') {
            // Somamos a resposta a quantidade de interações, ou seja, a quantidade 
            // de 'D' a direita desse caracter
            answer += d_count;
        } else {
            // Aqui que faremos a escolha se iremos substituir o '?' por 'E' ou 'D'
            // O meu d_count me diz a quantidade de 'D' a minha direita e o meu prefix_sum
            // a quantidade de 'E' e '?' a minha esquerda, como queremos sempre manter esses
            // números próximos, caso o d_count for maior que o prefix_sum desse caracter, podemos
            // adicionar um 'E', ou seja, adicionar o d_count a nossa resposta. Do contrário, precisamos
            // aumentar o nosso d_count, adicionando o 'D' nessa posição
            if ( d_count > prefix_sum[i]) {
                answer += d_count;
            } else {
                d_count++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
