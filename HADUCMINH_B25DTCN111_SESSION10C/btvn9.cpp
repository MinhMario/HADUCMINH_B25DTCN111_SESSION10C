#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc s?n ph?m
typedef struct {
    int maSP;           // Mã s?n ph?m
    char tenSP[100];    // Tên s?n ph?m
    float giaBan;       // Giá bán
    int soLuong;        // S? lu?ng t?n kho
} SanPham;

int main() {
    // Kh?i t?o danh sách s?n ph?m
    SanPham danhSach[100];
    int soLuong = 6;
    int luaChon;
    
    // Kh?i t?o d? li?u m?u
    danhSach[0].maSP = 103;
    strcpy(danhSach[0].tenSP, "Laptop Dell XPS");
    danhSach[0].giaBan = 25000000;
    danhSach[0].soLuong = 5;
    
    danhSach[1].maSP = 101;
    strcpy(danhSach[1].tenSP, "iPhone 14 Pro");
    danhSach[1].giaBan = 30000000;
    danhSach[1].soLuong = 10;
    
    danhSach[2].maSP = 105;
    strcpy(danhSach[2].tenSP, "Samsung Galaxy S23");
    danhSach[2].giaBan = 22000000;
    danhSach[2].soLuong = 8;
    
    danhSach[3].maSP = 102;
    strcpy(danhSach[3].tenSP, "iPad Air");
    danhSach[3].giaBan = 15000000;
    danhSach[3].soLuong = 12;
    
    danhSach[4].maSP = 104;
    strcpy(danhSach[4].tenSP, "AirPods Pro");
    danhSach[4].giaBan = 6000000;
    danhSach[4].soLuong = 20;
    
    danhSach[5].maSP = 106;
    strcpy(danhSach[5].tenSP, "Smart Watch");
    danhSach[5].giaBan = 8000000;
    danhSach[5].soLuong = 15;
    
    do {
        printf("\n========== QUAN LY SAN PHAM ==========\n");
        printf("1. Hien thi danh sach san pham\n");
        printf("2. Tim kiem san pham theo ma (Binary Search)\n");
        printf("3. Sap xep san pham theo gia (Bubble Sort)\n");
        printf("4. Sap xep san pham theo ma (de chuan bi cho Binary Search)\n");
        printf("5. Them san pham moi\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                // HI?N TH? DANH SÁCH S?N PH?M
                printf("\n=== DANH SACH SAN PHAM ===\n");
                printf("%-10s %-30s %-15s %-10s\n", "Ma SP", "Ten SP", "Gia ban", "So luong");
                printf("--------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    printf("%-10d %-30s %-15.2f %-10d\n", 
                           danhSach[i].maSP, danhSach[i].tenSP, 
                           danhSach[i].giaBan, danhSach[i].soLuong);
                }
                printf("\n");
                break;
                
            case 2: {
                // BINARY SEARCH - TÌM KI?M S?N PH?M THEO MÃ
                
                // Ki?m tra danh sách dã s?p x?p theo mã chua
                int daSapXep = 1;
                for (int i = 0; i < soLuong - 1; i++) {
                    if (danhSach[i].maSP > danhSach[i + 1].maSP) {
                        daSapXep = 0;
                        break;
                    }
                }
                
                if (!daSapXep) {
                    printf("\n[CANH BAO] Danh sach chua duoc sap xep theo ma!\n");
                    printf("Vui long chon '4' de sap xep truoc khi tim kiem.\n");
                } else {
                    int maCanTim;
                    printf("\nNhap ma san pham can tim: ");
                    scanf("%d", &maCanTim);
                    
                    // THU?T TOÁN BINARY SEARCH
                    int left = 0;
                    int right = soLuong - 1;
                    int timThay = 0;
                    int viTri = -1;
                    
                    while (left <= right) {
                        int mid = left + (right - left) / 2;
                        
                        // Tìm th?y s?n ph?m
                        if (danhSach[mid].maSP == maCanTim) {
                            viTri = mid;
                            timThay = 1;
                            break;
                        }
                        
                        // N?u mã c?n tìm l?n hon, tìm ? n?a ph?i
                        if (danhSach[mid].maSP < maCanTim) {
                            left = mid + 1;
                        }
                        // N?u mã c?n tìm nh? hon, tìm ? n?a trái
                        else {
                            right = mid - 1;
                        }
                    }
                    
                    if (timThay) {
                        printf("\n=== TIM THAY SAN PHAM ===\n");
                        printf("Ma SP: %d | Ten: %s | Gia: %.2f | So luong: %d\n", 
                               danhSach[viTri].maSP, danhSach[viTri].tenSP, 
                               danhSach[viTri].giaBan, danhSach[viTri].soLuong);
                    } else {
                        printf("\nKhong tim thay san pham co ma %d!\n", maCanTim);
                    }
                }
                break;
            }
            
            case 3:
                // BUBBLE SORT - S?P X?P THEO GIÁ BÁN
                printf("\n=== SAP XEP THEO GIA BANG BUBBLE SORT ===\n");
                
                for (int i = 0; i < soLuong - 1; i++) {
                    int daSwap = 0;
                    
                    for (int j = 0; j < soLuong - i - 1; j++) {
                        // So sánh giá bán c?a 2 s?n ph?m li?n k?
                        if (danhSach[j].giaBan > danhSach[j + 1].giaBan) {
                            // Hoán d?i 2 s?n ph?m
                            SanPham temp = danhSach[j];
                            danhSach[j] = danhSach[j + 1];
                            danhSach[j + 1] = temp;
                            daSwap = 1;
                        }
                    }
                    
                    // N?u không có swap nào x?y ra, m?ng dã s?p x?p
                    if (!daSwap) {
                        break;
                    }
                }
                
                printf("Da sap xep xong!\n");
                printf("\n=== DANH SACH SAU KHI SAP XEP THEO GIA ===\n");
                printf("%-10s %-30s %-15s %-10s\n", "Ma SP", "Ten SP", "Gia ban", "So luong");
                printf("--------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    printf("%-10d %-30s %-15.2f %-10d\n", 
                           danhSach[i].maSP, danhSach[i].tenSP, 
                           danhSach[i].giaBan, danhSach[i].soLuong);
                }
                break;
                
            case 4:
                // S?P X?P THEO MÃ S?N PH?M (Bubble Sort)
                printf("\n=== SAP XEP THEO MA SAN PHAM ===\n");
                
                for (int i = 0; i < soLuong - 1; i++) {
                    for (int j = 0; j < soLuong - i - 1; j++) {
                        if (danhSach[j].maSP > danhSach[j + 1].maSP) {
                            SanPham temp = danhSach[j];
                            danhSach[j] = danhSach[j + 1];
                            danhSach[j + 1] = temp;
                        }
                    }
                }
                
                printf("Da sap xep xong! San sang cho Binary Search.\n");
                printf("\n=== DANH SACH SAU KHI SAP XEP THEO MA ===\n");
                printf("%-10s %-30s %-15s %-10s\n", "Ma SP", "Ten SP", "Gia ban", "So luong");
                printf("--------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    printf("%-10d %-30s %-15.2f %-10d\n", 
                           danhSach[i].maSP, danhSach[i].tenSP, 
                           danhSach[i].giaBan, danhSach[i].soLuong);
                }
                break;
                
            case 5:
                // THÊM S?N PH?M M?I
                if (soLuong < 100) {
                    printf("\n=== THEM SAN PHAM MOI ===\n");
                    printf("Nhap ma san pham: ");
                    scanf("%d", &danhSach[soLuong].maSP);
                    getchar(); // Xóa ký t? '\n' còn l?i trong buffer
                    
                    printf("Nhap ten san pham: ");
                    fgets(danhSach[soLuong].tenSP, sizeof(danhSach[soLuong].tenSP), stdin);
                    danhSach[soLuong].tenSP[strcspn(danhSach[soLuong].tenSP, "\n")] = 0;
                    
                    printf("Nhap gia ban: ");
                    scanf("%f", &danhSach[soLuong].giaBan);
                    
                    printf("Nhap so luong: ");
                    scanf("%d", &danhSach[soLuong].soLuong);
                    
                    soLuong++;
                    printf("Them san pham thanh cong!\n");
                } else {
                    printf("Danh sach da day!\n");
                }
                break;
                
            case 0:
                printf("Tam biet!\n");
                break;
                
            default:
                printf("Lua chon khong hop le!\n");
        }
        
    } while (luaChon != 0);
    
    return 0;
}
