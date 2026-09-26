#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int permainan(int jawaban, int minimum, int maksimum, int *percobaan, int iterasi)
{
    int tebakan;

    for (int i = 0; i < iterasi; i++)
    {
        printf("Masukkan tebakkan anda (%d - %d) : ", minimum, maksimum);
        scanf("%d", &tebakan);

        (*percobaan)++;

        if (tebakan < jawaban)
        {
            int digit = 0;
            int selisih = jawaban - tebakan;
            while (selisih != 0)
            {
                selisih /= 10;
                digit++;
            }
            printf("Terlalu kecil! Selisihnya %d digit\n", digit);

            if (*percobaan == iterasi)
            {
                return 0;
            }

            return permainan(
                jawaban,
                minimum,
                maksimum,
                percobaan,
                iterasi);
        }
        else if (tebakan > jawaban)
        {
            int digit = 0;
            int selisih = tebakan - jawaban;
            while (selisih != 0)
            {
                selisih /= 10;
                digit++;
            }

            printf("Terlalu Besar! Selisihnya %d digit\n", digit);

            if (*percobaan == iterasi)
            {
                return 0;
            }

            return permainan(
                jawaban,
                minimum,
                maksimum,
                percobaan,
                iterasi);
        }
        else
        {
            printf(
                "\nSelamat! anda berhasil \nmenebak angka %d dengan %d percobaan.\n",
                jawaban,
                *percobaan);

            return 1;
        }
    }
}

void jalakanPermainan()
{
    int minimum = 1;
    int maksimum = 100;
    int percobaan = 0;
    int iterasi = 0;

    int jawaban = (rand() % (maksimum - minimum + 1)) + minimum;

    printf("\n\n==========================================\n");
    printf("          PERMAINAN TEBAK ANGKA\n");
    printf("==========================================\n");
    printf("Selamat datang di permainan!\n");
    printf("Machine telah memilih angka %d - %d.\n", minimum, maksimum);
    printf("==========================================\n\n");

    while (iterasi <= 0)
    {
        printf("Mau berapa percobaan : ");
        scanf("%d", &iterasi);
    }

    printf("\n==========================================\n");
    printf("              GAME DIMULAI!\n");
    printf("==========================================\n");
    printf("  Kamu memiliki %d kesempatan.\n", iterasi);
    printf("==========================================\n\n");

    int hasil = permainan(
        jawaban,
        minimum,
        maksimum,
        &percobaan,
        iterasi);

    if (hasil == 1)
    {
        float akurasi = ((float)(iterasi - percobaan + 1) / iterasi) * 100;

        printf("\n==========================================\n");
        printf("             HASIL PERMAINAN\n");
        printf("==========================================\n");
        printf("  Angka yang benar : %d\n", jawaban);
        if (akurasi == 100.0)
        {
            printf("  Predikat         : Perfect\n");
        }
        else if (akurasi >= 75.0)
        {
            printf("  Predikat         : Good\n");
        }
        else
        {
            printf("  Predikat         : Biasa aja\n");
        }
        printf("  Jumlah percobaan : %d\n", percobaan);
        printf("  Akurasi          : %.2f%%\n", akurasi);
        printf("==========================================\n");
    }
    else
    {
        printf("\n==========================================\n");
        printf("               GAME OVER!\n");
        printf("==========================================\n");
        printf("  Kesempatan kamu sudah habis!\n");
        printf("  Angka yang benar adalah: %d\n", jawaban);
        printf("==========================================\n");
    }
}

int main()
{
    srand(time(NULL));
    char ulangi;
    do
    {
        ulangi = ' ';
        jalakanPermainan();
        while (ulangi != 'n' && ulangi != 'N' && ulangi != 'Y' && ulangi != 'y')
        {
            printf("Ulangi gamenya? (Y/N) : ");
            scanf(" %c", &ulangi);
        }
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}