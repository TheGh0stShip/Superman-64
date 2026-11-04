typedef struct RuntimeChild RuntimeChild;

typedef struct {
    unsigned int pad00[5];
    int childCount;
    unsigned int pad18;
    RuntimeChild **children;
} RuntimeOwner;

int func_800C9AE0(RuntimeOwner *owner, int operation, RuntimeChild *child) {
    RuntimeChild **children = owner->children;

    if (operation == 2) {
        children[owner->childCount] = child;
        owner->childCount++;
    }
    return 0;
}
