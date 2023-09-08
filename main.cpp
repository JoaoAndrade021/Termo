#include <iostream>
#include <dicionario.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>

using namespace std;

void ComoJogar() {
    cout << endl;
    cout << "Descubra a palavra certa em 7 tentativas! "
            "Depois de cada tentativa, as peças mostram o quão perto você está da solução." << endl;
    cout << "As palavras podem possuir letras repetidas." << endl;
    cout << endl;
}

void ImprimirLetraComCor(char letra, int cor) {
    switch (cor) {
        case 1: // Verde
            cout << "\033[32m" << letra << "\033[0m";
            break;
        case 2: // Amarelo
            cout << "\033[33m" << letra << "\033[0m";
            break;
        case 3: // Preto
            cout << "\033[31m" << letra << "\033[0m";
            break;
        default:
            cout << letra;
            break;
    }
}

void Jogo(int pQtdPalavras) {
    srand(time(NULL));

    vector<string> xPalavrasEscolhidas;

    for (int i = 0; i < pQtdPalavras; i++) {
        string xPalavraEscolhida = lista[rand() % TAM_LISTA];
        xPalavrasEscolhidas.push_back(xPalavraEscolhida);
    }

    int xTentativas = 7;

    vector<string> xPalavrasAsteriscos;

    for (const string &palavra: xPalavrasEscolhidas) {
        string palavraAsteriscos(palavra.length(), '*');
        xPalavrasAsteriscos.push_back(palavraAsteriscos);
    }

    while (xTentativas > 0) {
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

        for (int i = 0; i < pQtdPalavras; i++) {
            if (xTentativa == xPalavrasEscolhidas[i]) {
                cout << "Parabéns, você acertou a palavra " << i + 1 << ": " << xPalavrasEscolhidas[i] << endl;
                xPalavrasAsteriscos[i] = xPalavrasEscolhidas[i];
                xAcertou = true;
                xTentativas--;
            } else {
                for (int j = 0; j < xPalavrasEscolhidas[i].size(); j++) {
                    char letraPalavra = xPalavrasEscolhidas[i][j];
                    char letraTentativa = xTentativa[j];

                    // Verifique se a letra da tentativa é igual à letra da palavra
                    if (letraTentativa == letraPalavra) {
                        ImprimirLetraComCor(letraTentativa, 1); // Verde para letras corretas
                        xPalavrasAsteriscos[i][j] = xPalavrasEscolhidas[i][j];
                    } else if (xPalavrasEscolhidas[i].find(letraTentativa) != string::npos) {
                        ImprimirLetraComCor(letraTentativa, 2); // Amarelo para letras na palavra em outra posição
                    } else {
                        ImprimirLetraComCor(letraTentativa, 3); // Cinza para letras que não estão na palavra
                    }
                }

                cout << " (" << xPalavrasEscolhidas[i].size() << ")" << endl;
            }
        }

        if (!xAcertou) {
            cout << "Tentativa incorreta!" << endl;
            xTentativas--;
        }

        bool xTodasPalavrasDescobertas = true;

        for (int i = 0; i < pQtdPalavras; i++) {
            if (xPalavrasAsteriscos[i] != xPalavrasEscolhidas[i]) {
                xTodasPalavrasDescobertas = false;
                break;
            }
        }

        if (xTodasPalavrasDescobertas) {
            cout << "\n" << endl;
            cout << "Parabéns, você acertou todas as palavras!" << endl;
            break;
        }
    }

    if (xTentativas == 0) {
        cout << "\n" << endl;
        cout << "Você perdeu! As palavras eram:" << endl;
        for (const string &palavra: xPalavrasEscolhidas) {
            cout << palavra << endl;
        }
    }
}

void Menu(){
    cout << "Trabalho feito por João Martini e Gabriel Laus" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "___________                               .___                                  .__  \n"
            "\\__    __/_________  _____   ____     _| _/___  ______    ____  __ _________|__| \n"
            "  |    |/ __ \\  __ \\/     \\ /  _ \\   / __ |/  _ \\/  __/   / ___\\|  |  \\  __ \\  | \n"
            "  |    |\\  __/|  | \\/  Y Y  (  <_> ) / /_/ (  <_> )__ \\   / /_/  >  |  /|  | \\/  | \n"
            "  |___| \\__  >_|  |__|_|  /\\____/  \\___ |\\___/___  >  \\___  /|____/ |__|  |__| \n"
            "             \\/            \\/              \\/          \\/  /_____/                   " << endl;
    cout << "Pressione enter para iniciar o jogo!" << endl;

    cin.get();

    int xDecisao = 0;
    int XEscolhaDePalavras = 0;

    cout << "1) Jogar" << endl;
    cout << "2) Como jogar" << endl;
    cout << "3) Sair" << endl;
    cout << endl;

    do {
        do {
            cout << "Escolha: ";
            cin >> xDecisao;
            if (cin.fail()){
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
                cin >> XEscolhaDePalavras;
                if (XEscolhaDePalavras != 1 && XEscolhaDePalavras != 2 && XEscolhaDePalavras != 3 &&
                    XEscolhaDePalavras != 4) {
                    cout << endl;
                    cout << "Opção Invalida, escolha de novo." << endl;
                    cout << endl;
                }
            } while (XEscolhaDePalavras != 1 && XEscolhaDePalavras != 2 && XEscolhaDePalavras != 3 &&
                     XEscolhaDePalavras != 4);
            if (XEscolhaDePalavras == 1) {
                Jogo(XEscolhaDePalavras);
            }

            if (XEscolhaDePalavras == 2) {
                Jogo(XEscolhaDePalavras);
            }

            if (XEscolhaDePalavras == 3) {
                Jogo(XEscolhaDePalavras);
            }

            if (XEscolhaDePalavras == 4) {
                Jogo(XEscolhaDePalavras);
            }

        } else if (xDecisao == 2) {
            ComoJogar();
        }
        else if ( xDecisao == 3 ) {
            cout<<"Saindo do Jogo..."<<endl;
        }
    } while (xDecisao == 2);
}

//TODO Dar include na biblioteca de palavras - João (Feito)
//TODO Arrumar o menu - Laus (Quase resolvido, vamos resolver juntos)
//TODO Dar a quantidade de palavras selecionadas - Laus (Feito)
//TODO Esconder as palavras - João (Feito)
//TODO Chances, acertos(nos lugares errados também), erros e tentativas anteriores - Laus e João (Feito)
//TODO Colocar cores - João (Feito)

int main() {
    Menu();
    return 0;
}