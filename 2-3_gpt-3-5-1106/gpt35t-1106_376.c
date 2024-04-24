Dummy** dummies = (Dummy**) malloc(sizeof(Dummy*));
err = load_dummies(&dummies, p_num_of_dummies);
if (!*dummies) {
    return 1; // allocation unsuccessful
}
