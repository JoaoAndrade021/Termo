#include <iostream>

using namespace std;

void ComoJogar() {
    cout << "Descubra a palavra certa em 6 tentativas! "
            "Depois de cada tentativa, as peças mostram o quão perto você está da solução." << endl;
    cout << "As palavras podem possuir letras repetidas." << endl;
}

void Jogo() {
    cout << "Jogo" << endl;
}

//TODO Dar include na biblioteca de palavras - João
//TODO Arrumar o menu - Laus
//TODO Dar a quantidade de palavras selecionadas - Laus
//TODO Esconder as palavras - João
//TODO Chances, acertos(nos lugares errados também), erros e tentativas anteriores - Laus e João
//TODO Colocar cores - João

int main() {

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

    cout << "1) Jogar" << endl;
    cout << "2) Como jogar" << endl;
    cout << "3) Sair" << endl;

    cin >> xDecisao;

    if (xDecisao == 1) {
        Jogo();
    } else if (xDecisao == 2) {
        ComoJogar();
    } else if (xDecisao == 3) {
        cout << "Sair" << endl;
    } else {
        cout << "Opção inválida!" << endl;
    }

    return 0;
}