#include <stdio.h>
#include <stdlib.h>
#include"avl.c"

void displayMenu() {
    printf("AVL Tree Menu\n");
    printf("1. Initialize AVL tree\n");
    printf("2. Insert node\n");
    printf("3. Remove node\n");
    printf("4. Traverse AVL tree\n");
    printf("5. Destroy AVL tree\n");
    printf("6. Exit\n");
}

int main() {
    avl tree;
    int choice, value;
    

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initAVL(&tree);
                printf("AVL tree initialized.\n");
                break;
            case 2:
                printf("Enter mis to insert: ");
                scanf("%d", &value);
                char label[50];
                printf("Enter name for the value: ");
                scanf("%s", label);
                insertNode(&tree, value, label);
                printf("Node inserted.\n");
                break;
            case 3:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeNode(&tree, value);
                printf("Node removed.\n");
                break;
            case 4:
                printf("Traversing AVL tree: \n");
                traverse(tree);
                printf("\n");
                break;
            case 5:
                destroy(&tree);
                printf("AVL tree destroyed.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
