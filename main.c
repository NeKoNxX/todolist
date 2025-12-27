#include "header.h"

int main() {
    int index = -1;
    int choice;

    while (1) {
        clear();
        menu1();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (signin(&index)) {
                    menu2(index);
                }
                break;
            case 2:
                signup();
                break;
            case 3: 
                printf("Exiting the program");
                fflush(stdout);
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        printf(".");
                        fflush(stdout);
                        sleep(1);
                    }
                    printf("\rExiting the program      \rExiting the program");
                    fflush(stdout);
                    if(i==2 ) break;
                    sleep(1);
                }
                fflush(stdout);
                clear();
                printf("Exited successfully.\n");
                sleep(1);
                return 0;
            default: printf("Invalid choice\n");
                     sleep(1);
        }
    }
}
