#include <stdio.h>

#define MAKS_MHS 5
#define JMLH_MK 3

// prototype khusus C
int inputData(char nama[][30], int nilai[][JMLH_MK], int jumlah);
float hitungAvg(int nilai[][JMLH_MK], int index);
char tentukanGrade(float avg);
void tampilkanRapor(char nama[][30], int nilai[][JMLH_MK], float avg[], int jumlah);
int nilaiTertinggi(int nilai[][JMLH_MK], int jumlah, int ada[]);
int nilaiTerendah(int nilai[][JMLH_MK], int jumlah, int ada[]);
int mahasiswaTerbaik(float avg[], int jumlah);
int cariMahasiswa(char cari[30], char nama[][30], int jumlah);

int main()
{
    // deklarasi
    char nama[MAKS_MHS][30];
    int nilai[MAKS_MHS][JMLH_MK];
    float avg[MAKS_MHS];
    int jumlah, totalJMK, posisi;

    char matkul[JMLH_MK][30] = {
        "Algoritma",
        "Pemrograman",
        "Basis Data"};

    int tertinggi;
    int ada[JMLH_MK];

    // COUT
    printf("===================================================================\n");
    printf("%*s%*s\n", 43, "SISTEM RAPOR DIGITAL", 24, "");
    printf("===================================================================\n");

    // input jumlah mahasiswa
    printf("-------------------------------------------------------------------\n");
    printf("Jumlah mahasiswa (1-%d): ", MAKS_MHS);
    if (scanf("%d", &jumlah) != 1)
    {
        printf("Input jumlah mahasiswa harus berupa angka.\n");
        return 1;
    }

    if (jumlah < 1 || jumlah > MAKS_MHS)
    {
        printf("Jumlah mahasiswa tidak valid!\n");
        return 1;
    }
    // manggil fungsi mhs
    if (!inputData(nama, nilai, jumlah))
    {
        return 1;
    }

    for (int i = 0; i < jumlah; i++)
    {
        avg[i] = hitungAvg(nilai, i);
    }

    tampilkanRapor(nama, nilai, avg, jumlah);

    printf("\n===================================================================\n");
    printf("%*s%*s\n", 38, "RINGKASAN", 29, "");
    printf("-------------------------------------------------------------------\n");
    // Tertinggi
    printf("\nNilai tertinggi   : %d (", nilaiTertinggi(nilai, jumlah, ada));

    totalJMK = 0;
    for (int j = 0; j < JMLH_MK; j++)
    {
        if (ada[j] == 1)
        {
            totalJMK++;
        }
    }

    posisi = 0;
    for (int j = 0; j < JMLH_MK; j++)
    {
        if (ada[j] == 1)
        {
            posisi++;

            printf("%s", matkul[j]);

            if (totalJMK == 2)
            {
                if (posisi == 1)
                    printf(" dan ");
            }
            else if (totalJMK == 3)
            {
                if (posisi == 1)
                    printf(", ");
                else if (posisi == 2)
                    printf(", dan ");
            }
        }
    }
    printf(")\n");

    // Terendah
    printf("Nilai terendah    : %d (", nilaiTerendah(nilai, jumlah, ada));

    totalJMK = 0;
    for (int j = 0; j < JMLH_MK; j++)
    {
        if (ada[j] == 1)
        {
            totalJMK++;
        }
    }

    posisi = 0;
    for (int j = 0; j < JMLH_MK; j++)
    {
        if (ada[j] == 1)
        {
            posisi++;

            printf("%s", matkul[j]);

            if (totalJMK == 2)
            {
                if (posisi == 1)
                    printf(" dan ");
            }
            else if (totalJMK == 3)
            {
                if (posisi == 1)
                    printf(", ");
                else if (posisi == 2)
                    printf(", dan ");
            }
        }
    }
    printf(")\n");

    printf("Mahasiswa terbaik : %s dengan rata-rata %.2f\n", nama[mahasiswaTerbaik(avg, jumlah)], avg[mahasiswaTerbaik(avg, jumlah)]);
    printf("===================================================================\n");

    char cari[30];
    printf("\nMasukkan nama yang ingin dicari : ");
    if (scanf("%29s", cari) != 1)
    {
        printf("Gagal membaca nama mahasiswa.\n");
        return 0;
    }
    int index = cariMahasiswa(cari, nama, jumlah);
    printf("\n===================================================================\n");
    printf("%*s%*s\n", 41, "HASIL PENCARIAN", 26, "");
    printf("-------------------------------------------------------------------\n");
    printf("Nama        : %s\n", nama[index]);
    printf("Rata-rata   : %.2f\n", avg[index]);
    printf("Grade       : %c\n", tentukanGrade(avg[index]));
    printf("Status      : %s\n", avg[index] >= 70 ? "Lulus" : "Tidak Lulus"); // Ternary biar ganteng
    printf("===================================================================\n");

    return 0;
}

int inputData(char nama[][30], int nilai[][JMLH_MK], int jumlah)
{

    for (int i = 0; i < jumlah; i++)
    {
        printf("\n-------------------------------------------------------------------\n");
        printf("Mahasiswa ke-%d\n", i + 1);
        printf("Nama              : ");
        if (scanf("%29s", nama[i]) != 1)
        {
            printf("Gagal membaca nama mahasiswa.\n");
            return 0;
        }

        for (int j = 0; j < JMLH_MK; j++)
        {
            if (j == 0)
            {
                printf("Nilai Algoritma   : ");
            }
            else if (j == 1)
            {
                printf("Nilai Pemrograman : ");
            }
            else
            {
                printf("Nilai Basis Data  : ");
            }
            if (scanf("%d", &nilai[i][j]) != 1)
            {
                printf("Nilai harus berupa angka.\n");
                return 0;
            }

            if (nilai[i][j] < 0 || nilai[i][j] > 100)
            {
                printf("Nilai harus berada pada rentang 0-100.\n");
                return 0;
            }
        }
    }

    return 1;
}

float hitungAvg(int nilai[][JMLH_MK], int index)
{
    int total = 0;

    for (int j = 0; j < JMLH_MK; j++)
    {
        total += nilai[index][j];
    }

    return (float)total / JMLH_MK;
}

char tentukanGrade(float avg)
{
    if (avg >= 90)
        return 'A';
    else if (avg >= 80)
        return 'B';
    else if (avg >= 70)
        return 'C';
    else if (avg >= 60)
        return 'D';
    else
        return 'E';
}

void tampilkanRapor(char nama[][30], int nilai[][JMLH_MK], float avg[], int jumlah)
{
    printf("\n===================================================================\n");
    printf("%*s%*s\n", 40, "RAPOR DIGITAL", 27, "");
    printf("===================================================================\n");
    printf("%-15s%-8s%-8s%-8s%-10s%-7s%-11s\n", "Nama", "Alg", "Prog", "BD", "Rata-rata", "Grade", "Status");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < jumlah; i++)
    {
        printf("%-15s", nama[i]);

        for (int j = 0; j < JMLH_MK; j++)
        {
            printf("%-8d", nilai[i][j]);
        }

        printf("%-10.2f%-7c", avg[i], tentukanGrade(avg[i]));

        if (avg[i] >= 70)
        {
            printf("%s", "LULUS");
        }
        else
        {
            printf("%s", "TIDAK LULUS");
        }
        printf("\n");
    }
    printf("===================================================================\n");
}

int nilaiTertinggi(int nilai[][JMLH_MK], int jumlah, int ada[])
{
    int tertinggi = nilai[0][0];

    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < JMLH_MK; j++)
        {
            if (tertinggi < nilai[i][j])
            {
                tertinggi = nilai[i][j];
            }
        }
    }

    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < JMLH_MK; j++)
        {
            if (nilai[i][j] == tertinggi)
            {
                ada[j] = 1;
            }
            else
            {
                ada[j] = 0;
            }
        }
    }
    return tertinggi;
}

int nilaiTerendah(int nilai[][JMLH_MK], int jumlah, int ada[])
{
    int terendah = nilai[0][0];

    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < JMLH_MK; j++)
        {
            if (terendah > nilai[i][j])
            {
                terendah = nilai[i][j];
            }
        }
    }

    for (int j = 0; j < JMLH_MK; j++)
    {
        ada[j] = 0;
    }

    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < JMLH_MK; j++)
        {
            if (nilai[i][j] == terendah)
            {
                ada[j] = 1;
            }
        }
    }
    return terendah;
}

int mahasiswaTerbaik(float avg[], int jumlah)
{
    int mhs = 0;
    for (int i = 0; i < jumlah; i++)
    {
        if (i > 1)
        {
            if (avg[i - 1] < avg[i])
            {
                mhs = i;
            }
        }
    }
    return mhs;
}

int cariMahasiswa(char cari[30], char nama[][30], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        int j = 0;

        while (nama[i][j] == cari[j] && nama[i][j] != '\0')
        {
            j++;
        }

        if (nama[i][j] == '\0' && cari[j] == '\0')
        {
            return i;
        }
    }

    return -1;
}
