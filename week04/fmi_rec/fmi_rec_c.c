int fmi_rec_c(int *arr, int len, int idx, int max_idx) {
    int max_new = max_idx;

    if (idx >= len) {
        return max_idx;
    }

    if (arr[idx] > arr[max_idx]) {
        max_new = idx;
    }

    return fmi_rec_c(arr, len, idx + 1, max_new);
}
