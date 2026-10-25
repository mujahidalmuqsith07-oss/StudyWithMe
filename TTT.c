#include <stdio.h>

char papan[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void tampilkanPapan() {
    printf("\n");
    printf(" %c | %c | %c \n", papan[0], papan[1], papan[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", papan[3], papan[4], papan[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", papan[6], papan[7], papan[8]);
    printf("\n");
}

int cekMenang() {
    int pola[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}             
    };

    for (int i = 0; i < 8; i++) {
        if (papan[pola[i][0]] == papan[pola[i][1]] &&
            papan[pola[i][1]] == papan[pola[i][2]]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int giliran = 0;
    int langkah = 0;
    int pilihan;
    char simbol;

    printf("=== GAME TIC TAC TOE ===\n");
    printf("Pemain 1 = X, Pemain 2 = O\n");

    while (langkah < 9) {
        tampilkanPapan();

        simbol = (giliran == 0) ? 'X' : 'O';
        printf("Giliran Pemain %d (%c), pilih angka 1-9: ", giliran + 1, simbol);

        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid, masukkan angka!\n");
            continue;
        }

        if (pilihan < 1 || pilihan > 9) {
            printf("Angka harus antara 1 sampai 9!\n");
            continue;
        }
        if (papan[pilihan - 1] == 'X' || papan[pilihan - 1] == 'O') {
            printf("Kotak sudah terisi, pilih yang lain!\n");
            continue;
        }

        papan[pilihan - 1] = simbol;
        langkah++;

        if (cekMenang()) {
            tampilkanPapan();
            printf("SELAMAT! Pemain %d (%c) MENANG!\n", giliran + 1, simbol);
            return 0;
        }

        giliran = 1 - giliran;
    }

    tampilkanPapan();
    printf("Permainan SERI!\n");
    return 0;
}