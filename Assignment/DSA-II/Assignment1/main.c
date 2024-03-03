#include <stdio.h>
#include "tree.h"

int main() {
    BST myTree;
    initBST(&myTree);

    int choice, MIS;
    char Name[50];

    do {
        printf("\n\n------ Binary Search Tree Menu ------\n");
        printf("1. Insert Node\n");
        printf("2. Remove Node\n");
        printf("3. Search Node\n");
        printf("4. Count Nodes\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter MIS: ");
                scanf("%d", &MIS);
                printf("Enter Name: ");
                scanf("%s", Name);
                insertNode(&myTree, MIS, Name);
                break;
            case 2:
                printf("Enter MIS to remove: ");
                scanf("%d", &MIS);
                removeNode(&myTree, MIS);
                break;
            case 3:
                printf("Enter MIS to search: ");
                scanf("%d", &MIS);
                if (search(myTree, MIS)) {
                    printf("Node with MIS %d found!\n", MIS);
                } else {
                    printf("Node with MIS %d not found.\n", MIS);
                }
                break;
            case 4:
                printf("Total number of nodes: %d\n", Count(myTree));
                break;
            case 5:
                printf("Inorder Traversal: ");
                inorder(myTree);
                printf("\n");
                break;
            case 6:
                printf("Preorder Traversal: ");
                preorder(myTree);
                printf("\n");
                break;
            case 7:
                printf("Postorder Traversal: ");
                postorder(myTree);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
