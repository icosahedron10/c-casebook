#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void print_startup_message(void) {
    printf("==========\n");
    printf("\n");
    printf("Welcome to the Sneezer and Dad Detective Agency's Client Management Service\n");
    printf("\n");
    printf("==========\n");
}

static void print_main_menu(void) {
    printf("Main Menu:\n");
    printf("\n");
    printf("1: Add client\n");
    printf("2: List clients\n");
    printf("3: Quit\n");
    printf("\n");
    printf("Enter desired menu number >>     ");
}

static void print_add_client_menu(int client_id) {
    char client_name[50];
    char contact_info[50];
    printf("Enter the new clients name\n");
    printf("     >>  ");
    fgets(client_name, 50, stdin);
    printf("\n");
    printf("Enter the new clients contact info:\n");
    printf("     >>  ");
    fgets(contact_info, 50, stdin);
    printf("\n");
    printf("\n");
    printf("Client added: id=%d name=\"%s\" contact=\"%s\"\n",
       client_id,
       client_name,
       contact_info);
    printf("\n");
    printf("==========\n");
    printf("\n");
}

static void print_list_client_menu(void) {
    printf("\n");
    printf("List Client Menu:\n");
    printf("\n");
    printf("1: List clients\n");
    printf("2: Back to main menu\n");
    printf("3: Quit\n");
    printf("\n");
    printf("Enter desired sub-menu number >>     ");
}

static int is_valid_choice(long val, const long *valid, size_t nvalid) {
    for (size_t i = 0; i < nvalid; i++) {
        if (val == valid[i]) return 1;
    }
    return 0;
}

static void print_after_error(char menu_code) {
    if (menu_code == 'm') {
        print_main_menu();
    }
    //else if (menu_code == 'a') {
    //
    //}
    else if (menu_code == 'l') {
        print_list_client_menu();
    }
}

static long read_menu_choice(const long *valid, size_t nvalid, char menu_code) {
    char buffer[100];

    for (;;) {
        char *endptr = NULL;
        if (!fgets(buffer, sizeof buffer, stdin)) {
            return -1; // EOF / error
        }
        errno = 0;
        long val = strtol(buffer, &endptr, 10);

        if (endptr == buffer) {
            printf("****************************************\n");
            printf("***** Error: enter a number.\n");
            printf("****************************************\n");
            print_after_error(menu_code);
            continue;
        }

        while (*endptr == ' ' || *endptr == '\t' || *endptr == '\n') {
            endptr++;
        }
        if (*endptr != '\0') {
            printf("****************************************\n");
            printf("***** Error: please enter a single number.\n");
            printf("****************************************\n");
            print_after_error(menu_code);
            continue;
        }

        if (errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) {
            printf("****************************************\n");
            printf("***** Error: number out of range.\n");
            printf("****************************************\n");
            print_after_error(menu_code);
            continue;
        }

        if (is_valid_choice(val, valid, nvalid)) {
            return val;
        }
        printf("****************************************\n");
        printf("***** Error: make a valid choice.\n");
        printf("****************************************\n");
        print_after_error(menu_code);
    }
}

int main(void) {
    print_startup_message();

    const long main_valid[] = {1, 2, 3};
    const long list_valid[]  = {1, 2, 3};

    int cid = 1;

    for (;;) {
        print_main_menu();
        long choice = read_menu_choice(main_valid, 3, 'm');

        if (choice == -1) {
            printf("\nGoodbye.\n");
            break;
        }

        if (choice == 1) {
            print_add_client_menu(cid);
            cid++;
        } else if (choice == 2) {
            print_list_client_menu();
            long subchoice = read_menu_choice(list_valid, 2, 'l');

            if (subchoice == 1) {
                printf("Persistence comes in P2\n");
                printf("\n");
                continue;
            }
            else if (subchoice == 2) {
                continue; // RESTART LOOP
            } else { // 2 or -1
                printf("Goodbye.\n");
                break;
            }
        } else { // 3
            printf("Goodbye.\n");
            break;
        }
    }

    return 0;
}