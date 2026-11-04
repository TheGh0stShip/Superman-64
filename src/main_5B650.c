float func_8005AA50(int value) {
    int current = value;
    float result = 1.0f;

    for (; current >= 2; current--) {
        result *= current--;
    }
    return result;
}
