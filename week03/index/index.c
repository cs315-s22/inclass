#define ARR_LEN 4

int index1_s(int *arr, int len);
int index2_s(int *arr, int len);
int index3_s(int *arr, int len);

int main(int argc, char **argv) {
    int arr[ARR_LEN] = {37, 19, 3, 41};
    int len = index1_s(arr, ARR_LEN);

    len = index2_s(arr, ARR_LEN);
    len = index3_s(arr, ARR_LEN);
    return 0;
}
