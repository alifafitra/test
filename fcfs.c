#include <stdio.h>
#include <string.h>

int main(void)
{
    // n = banyak proses
    // AT = Arrival Time, WT = Waiting Time, TAT = TurnAround Time
    // b = burst time, TotWT = Total Waiting Time, TotTA = Total TurnAround time
    // name = nama proses, AvWT = Average Waiting Time, AvTA = Average TurnAround time

    int n, AT[100], b[100], i, j, tmp, WT[100], TAT[100], time[101];
    int TotWT = 0, TotTA = 0;
    float AvWT, AvTA;
    char name[20][20], tmpName[20];

    printf("\t Algoritma CPU Scheduling FCFS \n");
    puts("");
    printf("Jumlah Proses\t= ");
    if (scanf("%d", &n) != 1) return 0;
    puts("");

    // Masukkan data yang diproses
    for (i = 0; i < n; i++) {
        // bersihkan newline tersisa sebelum membaca string (jika perlu)
        while (getchar() == '\n') {
            /* kosong - consume newline */
            break;
        }

        printf("Nama Proses\t= ");
        if (scanf("%19s", name[i]) != 1) return 0;

        printf("Arrival time\t= ");
        if (scanf("%d", &AT[i]) != 1) return 0;

        printf("Burst time\t= ");
        if (scanf("%d", &b[i]) != 1) return 0;

        puts("");
    }

    // Urutkan Data berdasarkan arrival time (FCFS)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (AT[i] > AT[j]) {
                // tukar nama
                strcpy(tmpName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmpName);

                // tukar arrival time
                tmp = AT[i];
                AT[i] = AT[j];
                AT[j] = tmp;

                // tukar burst
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    time[0] = AT[0];

    puts("\n\t Tabel Proses ");
    puts("==========================================");
    printf("| no | proses\t | time arrival\t | burst |\n");
    puts("------------------------------------------");

    for (i = 0; i < n; i++) {
        printf("| %2d | %s\t | \t%d\t | %d\t |\n", i + 1, name[i], AT[i], b[i]);
        time[i + 1] = time[i] + b[i]; // menghitung time pada gantt chart
        WT[i] = time[i] - AT[i];
        TAT[i] = time[i + 1] - AT[i];
        TotWT += WT[i];
        TotTA += TAT[i];
    }

    puts("==========================================");
    printf("\tTotal waiting time\t= %d \n", TotWT);
    printf("\tTurn around time\t= %d \n", TotTA);
    puts("\n\t Tabel Waktu Proses ");
    puts("==================================================");
    printf("| no | proses\t | waiting time\t | turn arround\t |\n");
    puts("--------------------------------------------------");

    for (i = 0; i < n; i++) {
        printf("| %2d | %s\t | \t%d\t | \t%d\t |\n", i + 1, name[i], WT[i], TAT[i]);
    }

    puts("==================================================");

    // untuk Gantt Chart
    puts("\n");
    puts("\t Gantt-Chart \n");
    for (i = 0; i < n; i++) {
        printf(" %s\t ", name[i]);
    }

    puts("");
    for (i = 0; i < n; i++) {
        printf("|=========");
    }

    printf("|\n");
    for (i = 0; i <= n; i++) {
        printf(" %d\t ", time[i]);
    }
    printf("\n// diperoleh dari penjumlahan Burst\n");

    puts("\n");
    AvWT = (float)TotWT / n;
    AvTA = (float)TotTA / n;
    printf("\tAverage Waiting Time : %f\n", AvWT);
    printf("\tAverage Turn Around Time : %f\n", AvTA);

    return 0;
}
