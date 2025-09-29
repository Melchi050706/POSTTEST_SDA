#include <iostream>
#include <string>
using namespace std;

struct Item {
    string nama;
    int jumlah;
    string tipe;
    int id;
};

struct Node {
    Item data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;
int panjangList = 0;
int nextID = 1;  // auto increment ID
const int JUMLAH_AWAL = 17;  // dari NIM 117

// Tambah item di depan
void addFirst() {
    Node *newNode = new Node;
    cout << "Masukkan nama item: ";
    cin.ignore();
    getline(cin, newNode->data.nama);
    cout << "Masukkan tipe item: ";
    getline(cin, newNode->data.tipe);

    newNode->data.jumlah = JUMLAH_AWAL;
    newNode->data.id = nextID++;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    panjangList++;
    cout << "Item berhasil ditambahkan di depan!\n";
}

// Tambah item di belakang
void addLast() {
    Node *newNode = new Node;
    cout << "Masukkan nama item: ";
    cin.ignore();
    getline(cin, newNode->data.nama);
    cout << "Masukkan tipe item: ";
    getline(cin, newNode->data.tipe);

    newNode->data.jumlah = JUMLAH_AWAL;
    newNode->data.id = nextID++;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    panjangList++;
    cout << "Item berhasil ditambahkan di belakang!\n";
}

// Tambah di posisi tertentu
void addSpecific(int posisi) {
    if (posisi < 1 || posisi > panjangList + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    if (posisi == 1) {
        addFirst();
        return;
    }
    if (posisi == panjangList + 1) {
        addLast();
        return;
    }

    Node *newNode = new Node;
    cout << "Masukkan nama item: ";
    cin.ignore();
    getline(cin, newNode->data.nama);
    cout << "Masukkan tipe item: ";
    getline(cin, newNode->data.tipe);

    newNode->data.jumlah = JUMLAH_AWAL;
    newNode->data.id = nextID++;

    Node *temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    panjangList++;
    cout << "Item berhasil disisipkan di posisi " << posisi << "!\n";
}

// Tampilkan inventory dari depan
void showList() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY (Depan → Belakang) ===\n";
    Node *temp = head;
    while (temp != NULL) {
        cout << "[" << temp->data.id << "] "
             << temp->data.nama << " | Jumlah: " << temp->data.jumlah
             << " | Tipe: " << temp->data.tipe << endl;
        temp = temp->next;
    }
}

// Traversal dari belakang
void showListReverse() {
    if (tail == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY (Belakang → Depan) ===\n";
    Node *temp = tail;
    while (temp != NULL) {
        cout << "[" << temp->data.id << "] "
             << temp->data.nama << " | Jumlah: " << temp->data.jumlah
             << " | Tipe: " << temp->data.tipe << endl;
        temp = temp->prev;
    }
}

// Cari detail item berdasarkan ID atau nama
void cariDetail() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "Cari berdasarkan:\n1. ID\n2. Nama\nPilihan: ";
    int opsi; cin >> opsi;
    cin.ignore();

    if (opsi == 1) {
        int id;
        cout << "Masukkan ID: ";
        cin >> id;
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data.id == id) {
                cout << "=== Detail Item ===\n";
                cout << "ID: " << temp->data.id << endl;
                cout << "Nama: " << temp->data.nama << endl;
                cout << "Jumlah: " << temp->data.jumlah << endl;
                cout << "Tipe: " << temp->data.tipe << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item dengan ID " << id << " tidak ditemukan!\n";
    }
    else if (opsi == 2) {
        string nama;
        cout << "Masukkan nama item: ";
        getline(cin, nama);
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data.nama == nama) {
                cout << "=== Detail Item ===\n";
                cout << "ID: " << temp->data.id << endl;
                cout << "Nama: " << temp->data.nama << endl;
                cout << "Jumlah: " << temp->data.jumlah << endl;
                cout << "Tipe: " << temp->data.tipe << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item dengan nama \"" << nama << "\" tidak ditemukan!\n";
    }
    else {
        cout << "Pilihan tidak valid!\n";
    }
}

int main() {
    int pilih, posisi;

    do {
        cout << "\n+------------------------------------------------+\n";
        cout << "|         GAME INVENTORY MANAGEMENT              |\n";
        cout << "|           [ Melchi - 117 ]                     |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| 1. Tambah Item Depan                           |\n";
        cout << "| 2. Tambah Item Belakang                        |\n";
        cout << "| 3. Sisipkan Item di Posisi                     |\n";
        cout << "| 4. Tampilkan Inventory (Depan ke Belakang)      |\n";
        cout << "| 5. Tampilkan Inventory (Belakang ke Depan)      |\n";
        cout << "| 6. Cari Detail Item                            |\n";
        cout << "| 0. Keluar                                      |\n";
        cout << "+------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: addFirst(); break;
            case 2: addLast(); break;
            case 3:
                cout << "Masukkan posisi: "; cin >> posisi;
                addSpecific(posisi); break;
            case 4: showList(); break;
            case 5: showListReverse(); break;
            case 6: cariDetail(); break;
            case 0: cout << "Keluar dari program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}
