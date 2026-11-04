char *func_80004160(char *destination, char *source, int value, int condition) {
    char *result;
    char unused[8];

    (void)unused;
    result = destination;
    value = *source;
    destination++;
    source++;
    condition = value;
    *(destination - 1) = value;
    while (condition != 0) {
        value = *source;
        destination++;
        source++;
        condition = value;
        *(destination - 1) = value;
    }
    return result;
}

char *func_800041A4(char *destination, char *source, unsigned int length) {
    char *result;
    char finished;
    unsigned int count;
    result = destination;
    finished = 0;
    count = 0;
    do {
        if ((*destination++ = *source++) == 0) {
            finished++;
        }
        count++;
        if (count > length - 1) {
            *destination++ = 0;
            finished++;
        }
    } while (finished == 0);
    return result;
}

char *func_8000421C(char *destination, char *source, unsigned int length) {
    char *result;
    char finished;
    unsigned int count;
    result = destination;
    finished = 0;
    count = 0;
    do {
        if ((*destination++ = *source++) == 0) {
            finished++;
        }
        count++;
        if (count > length - 2) {
            *destination++ = 0;
            finished++;
        }
    } while (finished == 0);
    return result;
}

char *func_80004294(char *destination, char *source, int value, int copied) {
    char *result;
    char unused[8];

    (void)unused;
    result = destination;
    value = *destination++;
    while (value != 0) {
        value = *destination++;
    }
    copied = *source;
    destination--;
    destination++;
    value = copied;
    source++;
    *(destination - 1) = copied;
    while (value != 0) {
        destination++;
        value = copied = *source++;
        *(destination - 1) = copied;
    }
    return result;
}

int func_800042FC(char *left, char *right) {
    char left_value = *left++;
    char right_value = *right++;

    while (left_value != 0 && right_value != 0) {
        if (left_value == right_value) {
            left_value = *left++;
            right_value = *right++;
        } else {
            left_value = 0;
            right_value = 1;
        }
    }
    if (left_value == 0 && right_value == 0) {
        return 0;
    }
    return -1;
}

int func_800043A8(char *left, char *right, unsigned int length) {
    char left_value = *left++;
    char right_value = *right++;
    unsigned int count;

    count = 0;
    while (left_value != 0 && right_value != 0) {
        if (left_value == right_value) {
            count++;
            if (count == length) {
                return 0;
            }
            left_value = *left++;
            right_value = *right++;
        } else {
            left_value = 0;
            right_value = 1;
        }
    }
    if (left_value == 0 && right_value == 0) {
        return 0;
    }
    return -1;
}
