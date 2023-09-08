#include <iostream>
#include <dicionario.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>

using namespace std;

void ComoJogar() {
    //Explicando como o jogo funciona.
    cout << endl;
    cout << "Descubra a palavra certa em 7 tentativas! "
            "Depois de cada tentativa, as peças mostram o quão perto você está da solução." << endl;
    cout << "As palavras podem possuir letras repetidas. Voce pode jogar com 1, 2, 3 ou 4 palavras." << endl;
    cout << endl;
}

void ImprimirLetraComCor(char xLetra, int xCor) {
    //Função para imprimir as letras com cores diferentes.
    switch (xCor) {
        case 1: // Verde
            cout << "\033[32m" << xLetra << "\033[0m";
            break;
        case 2: // Amarelo
            cout << "\033[33m" << xLetra << "\033[0m";
            break;
        case 3: // Preto
            cout << "\033[31m" << xLetra << "\033[0m";
            break;
        default:
            cout << xLetra;
            break;
    }
}

void Jogo(int pQtdPalavras) {
    srand(time(NULL));

    //Guarda as palavras em um vetor.
    vector<string> xPalavrasEscolhidas;

    for (int i = 0; i < pQtdPalavras; i++) {  //Sorteio de Palavras.
        string xPalavraEscolhida = lista[rand() % TAM_LISTA];
        xPalavrasEscolhidas.push_back(xPalavraEscolhida);
    }

    int xTentativas = 7;

    vector<string> xPalavrasAsteriscos;

    for (const string &xPalavra: xPalavrasEscolhidas) {  //Esconder as palavras com asteriscos.
        string xPalavraAsteriscos(xPalavra.length(), '*');
        xPalavrasAsteriscos.push_back(xPalavraAsteriscos);
    }

    //Jogo em si.
    while (xTentativas > 0) {
        //Imprimir as palavras
        for (int i = 0; i < pQtdPalavras; i++) {
            cout << "\n" << endl;
            cout << "Palavra " << i + 1 << " " << xPalavrasAsteriscos[i] << " (" << xPalavrasEscolhidas[i].size()
                 << ")" << endl;
        }
        cout << "\n" << endl;
        cout << "Tentativas restantes: " << xTentativas << endl;
        cout << "Digite uma palavra completa: ";
        string xTentativa;
        cin >> xTentativa;

        bool xAcertou = false;

        // Verifica se a tentativa é igual a alguma das palavras
        for (int i = 0; i < pQtdPalavras; i++) {
            if (xTentativa == xPalavrasEscolhidas[i]) {
                cout << "Parabéns, você acertou a palavra " << i + 1 << ": " << xPalavrasEscolhidas[i] << endl;
                xPalavrasAsteriscos[i] = xPalavrasEscolhidas[i];
                xAcertou = true;
                xTentativas--;
            } else {
                // Imprime a tentativa com cores diferentes para cada letra, conforme a palavra soletrada
                for (int j = 0; j < xPalavrasEscolhidas[i].size(); j++) {
                    char xLetraPalavra = xPalavrasEscolhidas[i][j];
                    char xLetraTentativa = xTentativa[j];

                    // Verifique se a letra da tentativa é igual à letra da palavra
                    if (xLetraTentativa == xLetraPalavra) {
                        ImprimirLetraComCor(xLetraTentativa, 1); // Verde para letras corretas
                        xPalavrasAsteriscos[i][j] = xPalavrasEscolhidas[i][j];
                    } else if (xPalavrasEscolhidas[i].find(xLetraTentativa) != string::npos) {
                        ImprimirLetraComCor(xLetraTentativa, 2); // Amarelo para letras na palavra em outra posição
                    } else {
                        ImprimirLetraComCor(xLetraTentativa, 3); // Vermelho para letras que não estão na palavra
                    }
                }

                // Imprime o restante da palavra com asteriscos
                cout << " (" << xPalavrasEscolhidas[i].size() << ")" << endl;
            }
        }

        // Se não acertou nenhuma palavra, diminui uma tentativa
        if (!xAcertou) {
            cout << "Tentativa incorreta!" << endl;
            xTentativas--;
        }

        bool xTodasPalavrasDescobertas = true;

        // Verifica se todas as palavras foram descobertas
        for (int i = 0; i < pQtdPalavras; i++) {
            if (xPalavrasAsteriscos[i] != xPalavrasEscolhidas[i]) {
                xTodasPalavrasDescobertas = false;
                break;
            }
        }

        // Se todas as palavras foram descobertas, o jogo acaba
        if (xTodasPalavrasDescobertas) {
            cout << "\n" << endl;
            cout << "Parabéns, você acertou todas as palavras!" << endl;
            break;
        }
    }

    // Se acabaram as tentativas, o jogo acaba
    if (xTentativas == 0) {
        cout << "\n" << endl;
        cout << "Você perdeu! As palavras eram:" << endl;
        for (const string &palavra: xPalavrasEscolhidas) {
            cout << palavra << endl;
        }
    }
}

void Menu(){

    //Menu Principal do Jogo.

    cout << "Trabalho feito por João Vitor Martini e Gabriel Beltrão Laus" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "___________                               .___                                  .__ \n"
            "\\__    ___/__________  _____   ____     __| _/____  ______    ____  __ _________|__|\n"
            "  |    |_/ __ \\_  __ \\/     \\ /  _ \\   / __ |/  _ \\/  ___/   / ___\\|  |  \\_  __ \\  |\n"
            "  |    |\\  ___/|  | \\/  Y Y  (  <_> ) / /_/ (  <_> )___ \\   / /_/  >  |  /|  | \\/  |\n"
            "  |____| \\___  >__|  |__|_|  /\\____/  \\____ |\\____/____  >  \\___  /|____/ |__|  |__|\n"
            "             \\/            \\/              \\/          \\/  /_____/                  " << endl;
    cout << "Pressione enter para iniciar o jogo!" << endl;

    cin.get();

    int xDecisao = 0;
    int xEscolhaDePalavras = 0;

    cout << "1) Jogar" << endl;
    cout << "2) Como jogar" << endl;
    cout << "3) Sair" << endl;
    cout << endl;

    do {  //Caso seja a opção 2.
        do { //Caso seja a opção 1.
            cout << "Escolha: ";
            cin >> xDecisao;
            if (cin.fail()){ //Caso escreva um palavra ou letra nas escolhas do código.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            if (xDecisao != 1 && xDecisao != 2 && xDecisao != 3) {
                cout << endl;
                cout << "Opcao Invalida, escolha de novo." << endl;
                cout << endl;
            }
        } while (xDecisao != 1 && xDecisao != 2 && xDecisao != 3);

        if (xDecisao == 1) {
            cout << "Com quantas palavras você gostaria de jogar?" << endl;
            cout << endl;
            cout << "1) Uma palavras" << endl;
            cout << "2) Duas palavras" << endl;
            cout << "3) Tres palavras" << endl;
            cout << "4) Quatro palavras" << endl;
            cout << endl;
            do {
                cout << "Escolha: ";
                cin >> xEscolhaDePalavras;

                if (cin.fail()){ //Caso escreva um palavra ou letra nas escolhas do código.
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }

                if (xEscolhaDePalavras != 1 && xEscolhaDePalavras != 2 && xEscolhaDePalavras != 3 &&
                    xEscolhaDePalavras != 4) {
                    cout << endl;
                    cout << "Opção Invalida, escolha de novo." << endl;
                    cout << endl;
                }
            } while (xEscolhaDePalavras != 1 && xEscolhaDePalavras != 2 && xEscolhaDePalavras != 3 &&
                     xEscolhaDePalavras != 4);
            if (xEscolhaDePalavras == 1) {
                Jogo(xEscolhaDePalavras);
            }

            if (xEscolhaDePalavras == 2) {
                Jogo(xEscolhaDePalavras);
            }

            if (xEscolhaDePalavras == 3) {
                Jogo(xEscolhaDePalavras);
            }

            if (xEscolhaDePalavras == 4) {
                Jogo(xEscolhaDePalavras);
            }

        } else if (xDecisao == 2) {
            ComoJogar();
        }
        else if ( xDecisao == 3 ) {
            cout<<"Saindo do Jogo..."<<endl;
        }
    } while (xDecisao == 2);
}

int main() {
    Menu();
    return 0;
}