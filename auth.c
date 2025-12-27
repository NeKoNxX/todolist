#include "header.h"

// Function for signup
void signup() {
    FILE *f1;
    char name[20], pass[20], fname[20], fpass[20];
    int user_exists = 0;
    while (getchar() != '\n');
    
    printf("Enter username(without spaces !!): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  
    f1 = fopen("users.txt", "r");
    if (f1) {
        while (fscanf(f1, "%s %s", fname, fpass) != EOF) {
            if (strcmp(fname, name) == 0) {
                user_exists = 1;
                break;
            }
        }
        fclose(f1);
    }

    if (user_exists) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("Username already exists.\n");
        printf("Try some other username.\n"); 
        return;
    }

   
    f1 = fopen("users.txt", "a");
    if (!f1) {
        printf("Error: file not found\n");
        return;
    }

 
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;  

 
    fprintf(f1, "%s %s\n", name, pass);
    fclose(f1);
    clear();
    printf("Signup successful!\n");
    
}


// Function to sign in
int signin(int *i) {
    FILE *f1;
    int j = 0;
    char name[20], pass[20], fname[20], fpass[20];
    
    f1 = fopen("users.txt", "r");
    if (!f1) {
        printf("Error: file not found\n");
        return 0;
    }

    while (getchar() != '\n');
    printf("Enter username: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0; 
    while (fscanf(f1, "%s %s", fname, fpass) != EOF) {
        if (strcmp(fname, name) == 0 && strcmp(fpass, pass) == 0) {
            clear();
            printf("Login successful\n");
            fclose(f1);
            *i = j;
            return 1;
        }
        j++;
    }

    printf("Invalid username or password\n");
    fclose(f1);
    return 0;
}
