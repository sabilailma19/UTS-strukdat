#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct camp {
    struct mahasiswa;
      char nama [20];
      char gender [2];
};

struct mahasiswa{
	camp *next;
};

typedef struct camp camp;

//========================================================

void tambahAwal(camp **head);
void tambahGender(camp **head);
void tambahData(camp **head);
void tranverse(camp **head, camp *pPre, camp *pNew);
void insertNode(camp **head);
void tambahAkhir(camp **head);
void hapusAwal(camp **head);
void hapusTengah(camp **head, char nama [20], char gender [2]);
void hapusAkhir(camp **head);
void cariData(camp **head, char nama [20], char gender [2]);

//========================================================

int main()
{
   camp *head;
    char pilih;

    head = NULL;
    do{
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. Tambahkan data Mahasiswa atau Mahasiswi diawal\n");
        printf("2. tambah data Mahasiswa atau Mahasiswi di tengah list\n");
        printf("3. tambah data Mahasiswa atau Mahasiswi di akhir list\n");
        printf("4. tambah data gender mahasiswa atau mahasiswi\n");
        printf("5. hapus data awal mahasiswa atau mahasiswi\n");
        printf("6. hapus data di tengah Mahasiswa atau Mahasiswi\n");
        printf("7. hapus data di akhir Mahasiswa atau Mahasiswi\n");
        printf("8. cari data Mahasiswa atau Mahasiswi\n");
        printf("9. cetak isi Mahasiswa atau Mahasiswi\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4');
            tambahGender(&head);
        else (pilih == '9'){
            tranverse(head);
            getch();
        }
        else if (pilih == '5');
            hapusAwal(&head);
        else if (pilih == '6'){
            char mahasiswa;
            printf("Masukkan Mahasiswa atau Mahasiswi yang ingin dihapus: ");
            scanf("%d", &mahasiswa);
            hapusTengah(&head,camp);  
        }
        else if (pilih == '7')
            hapusAkhir(&head);
        else if (pilih == '8'){
            char Mahasiswa;
            printf("Masukkan Mahasiswa atau Mahasiswi yang ingin dicari: ");
            scanf("%d", &mahasiswa);
            cariData(head, camp);
        }
    } while (pilih != 'q');

    return 0;
}

void tambahAwal(camp **head){

    char nama [20];
    char gender [2];
    camp **pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan Mahasiswa atau Mahasiswi : ");
    fflush(stdin);
    scanf("%d", &nama);
    pNew = (camp *)malloc(sizeof(camp));

    if (pNew != NULL){
        pNew->mahasiswa = nama;
        pNew->next = NULL;
        //add before first logical node or to an empty list
        pNew -> next = *head;
        *head = pNew;
    }
    else{
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
void tambahData(camp **head){
   int char nama [20] and gender [2];
    camp *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi Mahasiswa atau mahasiswi");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nmahasiswa");
    fflush(stdin);
    scanf("%d", &nama);

    pCur = *head;
    while (pCur != NULL && pCur -> data != pos) {
        pCur = pCur -> next;
    }

    pNew = (camp *)malloc(sizeof(camp));

    if (pCur == NULL){
        printf("\nnode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL){
        printf("\nalokasi memeori gagal");
        getch();
    }
    else{
        pNew->mahasiswa = nama and gender;
        pNew->next = NULL;
        pNew -> next = pCur -> next;
        pCur -> next = pNew;
    }
}

//========================================================

void tranverse(camp *head){
    //traverse a linked list
    camp *pWalker;

    system("cls");
        pWalker = head;
    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("\n");
}

//========================================================

void tambahAkhir(camp **head) {
    int bil;
    camp *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("masukkan Mahasiswa atau Mahasiswi : ");
    fflush(stdin);
    scanf("%d", &mahasiswa);
    pNew = (camp *)malloc(sizeof(camp));

    if (pNew != NULL) {
        pNew->data = nama and gender;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != NULL) {
                pLast = pLast->next;
            }
            pLast->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(camp **head) {
    camp *pTemp;

    if (*head != NULL) {
        pTemp = *head;
        *head = (*head)->camp;
        free(pTemp);
    } else {
        printf("List kosong");
        getch();
    }
}

//========================================================

void hapusTengah(camp **head, char nama) {
    camp *pCur, *pPre;

    pPre = NULL;
    pCur = *head;
    while (pCur != NULL && pCur->data != bil) {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur != NULL) {
        if (pPre == NULL) {
            *head = pCur->next;
        } else {
            pPre->next = pCur->next;
        }
        free(pCur);
    } else {
        printf("Node tidak ditemukan");
        getch();
    }
}

//========================================================

void hapusAkhir(camp **head) {
    camp *pCur, *pPre;

    pPre = NULL;
    pCur = *head;
    while (pCur->next != NULL) {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur != NULL) {
        if (pPre == NULL) {
            *head = NULL;
        } else {
            pPre->next = NULL;
        }
        free(pCur);
    } else {
        printf("List kosong");
        getch();
    }
}

//========================================================

void cariData(camp *head, char nama) {
    camp *pWalker;

    pWalker = head;
    while (pWalker != NULL) {
        if (pWalker->nama == mahasiswa) {
            printf("Data ditemukan");
            getch();
            return;
        }
        pWalker = pWalker->next;
    }
    printf("Data tidak ditemukan");
    getch();
}

//========================================================

void insertNode(camp **head, camp *pPre, camp *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
        pNew -> next = *head;
        *head = pNew;
    }
    else {
       //add in the middle or at the end
        pNew -> next = pPre -> next;
        pPre -> next = pNew;
    }
}

