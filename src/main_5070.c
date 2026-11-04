void func_80004470(char *text) {
    if (*text != '\0') {
        do {
            if (*text >= 'A' && *text < '[') {
                *text += 'a' - 'A';
            }
            text++;
        } while (*text != '\0');
    }
}

void func_800044C0(char *text) {
    if (*text != '\0') {
        do {
            if (*text >= 'a' && *text < '{') {
                *text -= 'a' - 'A';
            }
            text++;
        } while (*text != '\0');
    }
}
