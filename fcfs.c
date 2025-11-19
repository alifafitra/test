#include <stdio.h>
#include <string.h>

main()
{
    // n= banyak proses, AT= Arrival Time, WT= Waiting Time, TAT= Turnaround Time
    // b= burst time, TotWT= Total Waiting Time, TotTA= Total TurnAround time
    // name= nama proses, AWT= Average Waiting Time, AVTA= Average TurnAround time

    int n, AT[100], b[100], i, j, tmp, WT[100], TAT[100], time[100];
    int TotWT=0, TotTA=0;
    float AWT, A VTA;
    char name[20][20], tmpName[20];

    printf("\t Algoritma CPU Scheduling FCFS\n");
    puts("");
    printf("Jumlah Proses\t: "); scanf("%d", &n);
    puts("");

    // Masukkan data yang diproses
    for(i=0; i<n; i++){
        fflush(stdin);
        printf("Nama Proses\t: "); scanf("%s", name[i]);
        printf("Arrival time\t: "); scanf("%d", &AT[i]);
        printf("Burst time\t: "); scanf("%d", &b[i]);
        puts("");
    }

    // Urutkan data berdasarkan arrival time
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(AT[i] > AT[j]){
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

    puts("\n\t\t Tabel Proses ");
    puts("============================================");
    printf("|\t no | proses\t| time arrival\t| burst |\n");

    for(i=0; i<n; i++)
        printf("|\t %d |\t %s\t| \t%d\t| \t%d\t|\n", i+1, name[i], AT[i], b[i]);

    for(i=0; i<n; i++){
        time[i+1] = time[i] + b[i];   // menghitung selesai proses
        WT[i] = time[i] - AT[i];
        TAT[i] = time[i+1] - AT[i];
        TotWT += WT[i];
        TotTA += TAT[i];
    }

    puts("\n============================================");
    printf("\tTotal waiting time\t= %d\n", TotWT);
    printf("\tTurn around time\t= %d\n", TotTA);
    puts("\n\t Tabel Waktu Proses ");
    puts("============================================");
    printf("|\t no | proses\t| waiting time\t| turn around\t|\n");

    for(i=0; i<n; i++)
        printf("|\t %d |\t %s\t| \t%d\t| \t%d\t|\n", i+1, name[i], WT[i], TAT[i]);

    puts("\n============================================");
    // Untuk Gantt Chart
    puts("\n\tGantt chart\n");
    printf("|");

    for(i=0; i<n; i++)
        printf(" %s |", name[i]);

    puts("");
    printf("0");

    for(i=0; i<n; i++)
        printf("   %d", time[i+1]);

    printf("\n");

    AWT = (float)TotWT/n;
    AVTA = (float)TotTA/n;

    puts("\n(diperoleh dari penjumlahan Burst)");
    printf("\tAverage Waiting Time : %f\n", AWT);
    printf("\tAverage Turn Around Time : %f\n", AVTA);
}
