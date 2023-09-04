#include <iostream>
#include <dicionario.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void ComoJogar() {
    cout << endl;
    cout << "Descubra a palavra certa em 7 tentativas! "
            "Depois de cada tentativa, as peças mostram o quão perto você está da solução." << endl;
    cout << "As palavras podem possuir letras repetidas." << endl;
    cout << endl;
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

//TODO Dar include na biblioteca de palavras - João (Feito)
//TODO Arrumar o menu - Laus (Quase resolvido, vamos resolver juntos)
//TODO Dar a quantidade de palavras selecionadas - Laus (Feito)
//TODO Esconder as palavras - João (Feito)
//TODO Chances, acertos(nos lugares errados também), erros e tentativas anteriores - Laus e João
//TODO Colocar cores - João

int main() {

    cout << "Trabalho feito por João Martini e Gabriel Laus" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "___________                               .___                                  .__  \n"
            "\\__    ___/__________  _____   ____     __| _/____  ______    ____  __ _________|__| \n"
            "  |    |_/ __ \\_  __ \\/     \\ /  _ \\   / __ |/  _ \\/  ___/   / ___\\|  |  \\_  __ \\  | \n"
            "  |    |\\  ___/|  | \\/  Y Y  (  <_> ) / /_/ (  <_> )___ \\   / /_/  >  |  /|  | \\/  | \n"
            "  |____| \\___  >__|  |__|_|  /\\____/  \\____ |\\____/____  >  \\___  /|____/ |__|  |__| \n"
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
                    cout << "Opcao Invalida, escolha de novo." << endl;
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
    } while (xDecisao == 2);

    return 0;
}