#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SO_DINH 12
const char* ten_tinh_ds[] = {"", "Ha Noi", "Hai Duong", "Hai Phong", "Uong Bi", "Bac Giang", 
                              "Bac Ninh", "Thai Nguyen", "Son Tay", "Hoa Binh", "Phu Ly", "Hung Yen"};
struct Nut {
    int dinh;
    struct Nut* tiep_theo;
};
struct Nut* ds_ke[SO_DINH] = {NULL};
void them_canh_ds(int u, int v) {
    struct Nut* moi = (struct Nut*)malloc(sizeof(struct Nut));
    moi->dinh = v;
    
    // Chèn vào danh sách sao cho thứ tự giảm dần
    if (ds_ke[u] == NULL || ds_ke[u]->dinh < v) {
        moi->tiep_theo = ds_ke[u];
        ds_ke[u] = moi;
    } else {
        struct Nut* hien_tai = ds_ke[u];
        while (hien_tai->tiep_theo != NULL && hien_tai->tiep_theo->dinh > v) {
            hien_tai = hien_tai->tiep_theo;
        }
        moi->tiep_theo = hien_tai->tiep_theo;
        hien_tai->tiep_theo = moi;
    }
}
int q[SO_DINH * 2], d = 0, c = -1;
int main() {
    int cac_canh[][2] = {{1,2}, {2,11}, {11,10}, {10,1}, {1,9}, {1,8}, {1,7}, {1,6}, {6,5}, {5,4}, {6,4}, {4,3}, {3,2}};
    int so_canh = sizeof(cac_canh) / sizeof(cac_canh[0]);
    for (int i = 0; i < so_canh; i++) {
        them_canh_ds(cac_canh[i][0], cac_canh[i][1]);
        them_canh_ds(cac_canh[i][1], cac_canh[i][0]);
    }
    bool da_tham[SO_DINH] = {false};
    printf("--- BFS dung Danh sach ke (Uu tien so lon den be) ---\n");
    da_tham[1] = true;
    q[++c] = 1;
    while (d <= c) {
        int u = q[d++];
        printf("%s (%d) -> ", ten_tinh_ds[u], u);
        struct Nut* tam = ds_ke[u];
        while (tam != NULL) {
            int v = tam->dinh;
            if (!da_tham[v]) {
                da_tham[v] = true;
                q[++c] = v;
            }
            tam = tam->tiep_theo;
        }
    }
    printf("Ket thuc.\n");
    return 0;
}