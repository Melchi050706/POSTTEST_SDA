#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node* head = nullptr;

// Konstanta personalisasi
const int JUMLAH_AWAL = 17;  // dua digit terakhir NIM = 17
const int POSISI_SISIP = 8;  // digit terakhir 7 + 1 = 8

// Fungsi membuat node baru
Node* buatNode(string namaItem, string tipe) {
    Node* newNode = new Node;
    newNode->namaItem = namaItem;
    newNode->jumlah = JUMLAH_AWAL;
    newNode->tipe = tipe;
    newNode->next = nullptr;
    return newNode;
}

// 1. Tambah Item Baru (push_back)
void tambahItem(string namaItem, string tipe) {
    Node* newNode = buatNode(namaItem, tipe);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Item \"" << namaItem << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << ".\n";
}

// 2. Sisipkan Item di posisi khusus
void sisipkanItem(string namaItem, string tipe) {
    Node* newNode = buatNode(namaItem, tipe);

    if (head == nullptr || POSISI_SISIP <= 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp->next != nullptr && count < POSISI_SISIP - 1) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Item \"" << namaItem << "\" berhasil disisipkan di posisi " << POSISI_SISIP << ".\n";
}

// 3. Hapus Item Terakhir
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

// 4. Gunakan Item
void gunakanItem(string namaItem) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->namaItem != namaItem) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << namaItem << "\" tidak ditemukan!\n";
        return;
    }

    temp->jumlah--;

    cout << "Item \"" << namaItem << "\" digunakan. Sisa jumlah: " << temp->jumlah << ".\n";

    if (temp->jumlah == 0) {
        cout << "Jumlah item habis. Item \"" << namaItem << "\" dihapus dari inventory.\n";
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

// 5. Tampilkan Inventory
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n=== Daftar Inventory ===\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem << " | Jumlah: " << temp->jumlah << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "=========================\n";
}

int main() {
    int pilihan;
    string namaItem, tipe;

    do {
        cout << "\n+------------------------------------------------+\n";
        cout << "|         GAME INVENTORY MANAGEMENT              |\n";
        cout << "|         [ Melchi - 117 ]                       |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                            |\n";
        cout << "| 2. Sisipkan Item                               |\n";
        cout << "| 3. Hapus Item Terakhir                         |\n";
        cout << "| 4. Gunakan Item                                |\n";
        cout << "| 5. Tampilkan Inventory                         |\n";
        cout << "| 0. Keluar                                      |\n";
        cout << "+------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                cin >> namaItem;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                tambahItem(namaItem, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                cin >> namaItem;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                sisipkanItem(namaItem, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                cin >> namaItem;
                gunakanItem(namaItem);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program. Bye!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
