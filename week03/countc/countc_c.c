int find_char_index_c(char c, char *str, int start, int end) {
    int i;
    int rv = -1;

    for (i = start; i < end; i++) {
        if (str[i] == c) {
            rv = i;
            break;
        }
    }

    return rv;
}

int count_char_c(char c, char *str, int len) {
    int start = 0;
    int count = 0;
    int r;
        
    while (1) {
        r = find_char_index_c(c, str, start, len);
        if (r != -1) {
            count += 1;
        } else {
            break;
        }
        start = r + 1;
    }

    return count;
}
