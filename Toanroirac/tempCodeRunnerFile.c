int compare(const void *a, const void *b) {
    return ((Node *)a)->distance - ((Node *)b)->distance;
}
