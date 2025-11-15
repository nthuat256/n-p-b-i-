#include <stdio.h>
int main() {
    int arr[100];
    int n = 0,i;
    int choice;
    do {
        printf("\n+---Chuong trinh quan ly danh sach so nguyen---+\n");
        printf("|---------------------MENU---------------------|\n");
        printf("|1. Khoi tao mang ban dau                      |\n");
        printf("|2. Hien thi danh sach phan tu                 |\n");
        printf("|3. Chen them 1 so vao vi tri nhap vao         |\n");
        printf("|4. Xoa theo vi tri                            |\n");
        printf("|5. Cap nhat gia tri theo vi tri               |\n");
        printf("|6. Thoat chuong trinh                         |\n");
        printf("+----------------------------------------------+\n");
        printf("->> Moi ban nhap chuc nang : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\n---------------------#1#------------------------\n");
                printf("Nhap so luong phan tu can khoi tao : ");
                scanf("%d", &n);
                for( i = 0; i < n; i++) {
                    printf("\n----------------Phan tu %d-----------------------\n", i+1);
                    printf("Nhap gia tri phan tu : ");
                    scanf("%d", &arr[i]);
                }

                printf("\n<<--- Nhap thanh cong %d phan tu vao mang --->>\n", n);
                break;
            }
            case 2: {
                printf("\n---------------------#2#------------------------\n");
                printf("-------DANH SACH CAC PHAN TU TRONG MANG---------\n[");
                for( i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("]\n");
                break;
            }
            case 3: {
                printf("\n---------------------#3#------------------------\n");
                int pos, value;
                printf("Nhap vi tri can them phan tu : ");
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Nhap gia tri can them tai vi tri %d : ", pos);
                scanf("%d", &value);
                for( i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;

                printf("\n<<--Them thanh cong so %d vao vi tri index %d-->>\n", value, pos);
                break;
            }
            case 4: {
                printf("\n---------------------#4#------------------------\n");
                int pos;
                char confirm;
                printf("Nhap vao vi tri can xoa phan tu : ");
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Ban co chac chan muon xoa phan tu nay khong(Y/N)?\n");
                scanf(" %c", &confirm);
                if(confirm == 'Y' || confirm == 'y') {
                    for( i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("\n<<--Da xoa thanh cong phan tu tai vi tri %d!!-->>\n", pos);
                } else {
                    printf("Huy thao tac xoa!\n");
                }
                break;
            }
            case 5: {
                printf("\n---------------------#5#------------------------\n");
                int pos, newValue;
                printf("Nhap vao vi tri phan tu can cap nhat : ");
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Nhap vao gia tri moi (gia tri cu(%d)): ", arr[pos]);
                scanf("%d", &newValue);

                arr[pos] = newValue;
                printf("\n<<Da cap nhat thanh cong phan tu tai vi tri %d>>\n", pos);
                break;
            }
            case 6:
                printf("\nDang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 6);
    return 0;
}

