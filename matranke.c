#include <stdio.h>
#include <stdbool.h>
#define SO_DINH 12 
const char* ten_tinh[] = {"", "Ha Noi", "Hai Duong", "Hai Phong", "Uong Bi", "Bac Giang", 
                           "Bac Ninh", "Thai Nguyen", "Son Tay", "Hoa Binh", "Phu Ly", "Hung Yen"};
int hang_doi[SO_DINH * 2];
int dau = 0, cuoi = -1;

void day_vao(int v) { hang_doi[++cuoi] = v; }
int lay_ra() { return hang_doi[dau++]; }
bool hang_doi_rong() { return dau > cuoi; }
int main() {
    int ma_tran[SO_DINH][SO_DINH] = {0};
    bool da_tham[SO_DINH] = {false};
    int cac_canh[][2] = {{1,2}, {2,11}, {11,10}, {10,1}, {1,9}, {1,8}, {1,7}, {1,6}, {6,5}, {5,4}, {6,4}, {4,3}, {3,2}};
    int so_canh = sizeof(cac_canh) / sizeof(cac_canh[0]);
    for (int i = 0; i < so_canh; i++) {
        int u = cac_canh[i][0];
        int v = cac_canh[i][1];
        ma_tran[u][v] = ma_tran[v][u] = 1;
    }
    printf("--- BFS dung Ma tran ke (Uu tien so lon den be) ---\n");

    da_tham[1] = true;
    day_vao(1);

    while (!hang_doi_rong()) {
        int u = lay_ra();
        printf("%s (%d) -> ", ten_tinh[u], u);
        for (int v = SO_DINH - 1; v >= 1; v--) {
            if (ma_tran[u][v] == 1 && !da_tham[v]) {
                da_tham[v] = true;
                day_vao(v);
            }
        }
    }
    printf("Ket thuc.\n");

    return 0;
}