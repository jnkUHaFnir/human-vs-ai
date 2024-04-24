void *custom_malloc(size_t size) {
    return GC_MALLOC(size);
}
GC_set_malloc_redirect(custom_malloc);
static string printInt(Object self) {
    string str;
    asprintf(&str, "%lu", getValueInt(self));
    return str;
}
