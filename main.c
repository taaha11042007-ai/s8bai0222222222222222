#include <stdio.h>

struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int actual_fee;
};

int main() {
    struct UserAccount users[100];
    int n;
    int i;
    int total_revenue = 0;
    int downgraded_count = 0;

    do {
        printf("Nhap so luong tai khoan (1-100): ");
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("So luong khong hop le. Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 100);

    for (i = 0; i < n; i++) {
        printf("\nNhap thong tin tai khoan %d\n", i + 1);

        printf("Ma tai khoan: ");
        scanf("%d", &users[i].user_id);

        printf("Ten tai khoan: ");
        scanf(" %[^\n]", users[i].username);

        do {
            printf("Loai goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &users[i].plan_type);

            if (users[i].plan_type < 1 || users[i].plan_type > 3) {
                printf("Loai goi khong hop le. Vui long nhap lai.\n");
            }
        } while (users[i].plan_type < 1 || users[i].plan_type > 3);

        do {
            printf("So ngay no cuoc: ");
            scanf("%d", &users[i].days_overdue);

            if (users[i].days_overdue < 0) {
                printf("So ngay no khong duoc am. Vui long nhap lai.\n");
            }
        } while (users[i].days_overdue < 0);

        do {
            printf("So thiet bi dang ket noi: ");
            scanf("%d", &users[i].active_devices);

            if (users[i].active_devices < 0) {
                printf("So thiet bi khong duoc am. Vui long nhap lai.\n");
            }
        } while (users[i].active_devices < 0);

        if (users[i].plan_type == 1) {
            users[i].actual_fee = 0;
        } else if (users[i].plan_type == 2) {
            users[i].actual_fee = 120000;
        } else {
            users[i].actual_fee = 250000;
        }
    }

    for (i = 0; i < n; i++) {
        if (users[i].days_overdue >= 3) {
            users[i].plan_type = 1;
            users[i].actual_fee = 0;
            downgraded_count++;
        } else {
            if (users[i].plan_type == 2 && users[i].active_devices > 1) {
                users[i].actual_fee += (users[i].active_devices - 1) * 30000;
            }
        }

        total_revenue += users[i].actual_fee;
    }

    printf("\n================ BAO CAO DOI SOAT ================\n");
    printf("%-10s %-20s %-8s %-12s %-12s %-20s\n",
           "Ma TK",
           "Ten TK",
           "Ma Goi",
           "Thiet Bi",
           "No Cuoc",
           "Phi Thuc Thu");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-8d %-12d %-12d %-20d\n",
               users[i].user_id,
               users[i].username,
               users[i].plan_type,
               users[i].active_devices,
               users[i].days_overdue,
               users[i].actual_fee);
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Tong doanh thu thuc te: %d VND\n", total_revenue);
    printf("So tai khoan bi ha cap ve Free: %d\n", downgraded_count);

    return 0;
}