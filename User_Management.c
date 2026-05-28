#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

// User အချက်အလက်များကို သိမ်းဆည်းရန် Structure သတ်မှတ်ခြင်း
struct User {
    char name[50];
    int age;
    char address[100];
};

// Function Declarations (အသုံးပြုမည့် Function များကို ကြိုတင်ကြေညာခြင်း)
void displayMenu();
void createUser(struct User list[], int *count);
void readAllUsers(struct User list[], int count);
void updateUser(struct User list[], int count);
void deleteUser(struct User list[], int *count);

int main() {
    struct User userList[MAX_USERS];
    int userCount = 0;
    int option;

    do {
        displayMenu();
        printf("Enter your option :->");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // input buffer ကို ရှင်းထုတ်ခြင်း
            continue;
        }
        getchar(); // scanf ပြီးနောက်ကျန်ခဲ့သော newline (\n) ကို ဖယ်ထုတ်ခြင်း

        switch(option) {
            case 1:
                createUser(userList, &userCount);
                break;
            case 2:
                readAllUsers(userList, userCount);
                break;
            case 3:
                updateUser(userList, userCount);
                break;
            case 4:
                deleteUser(userList, &userCount);
                break;
            case 0:
                printf("Exiting Program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    } while(option != 0);

    return 0;
}

// Menu ပြသပေးမည့် Function
void displayMenu() {
    printf("1. Create User\n");
    printf("2. Read All User\n");
    printf("3. Update User\n");
    printf("4. Delete User\n");
    printf("0. Exit\n");
}

// User အသစ်ဆောက်မည့် Function (Option 1)
void createUser(struct User list[], int *count) {
    if (*count >= MAX_USERS) {
        printf("Storage Full! Cannot add more users.\n");
        return;
    }

    printf("Create User Page\n");
    printf("****************\n");

    printf("Enter name ::");
    fgets(list[*count].name, sizeof(list[*count].name), stdin);
    list[*count].name[strcspn(list[*count].name, "\n")] = 0; // newline ဖယ်ရှားရန်

    printf("Enter age ::");
    scanf("%d", &list[*count].age);
    getchar(); // newline ဖယ်ရှားရန်

    printf("Enter address ::");
    fgets(list[*count].address, sizeof(list[*count].address), stdin);
    list[*count].address[strcspn(list[*count].address, "\n")] = 0; // newline ဖယ်ရှားရန်

    (*count)++; // User အရေအတွက်ကို ၁ တိုးခြင်း
}

// ရှိသမျှ User အားလုံးကို ပြပေးမည့် Function (Option 2)
void readAllUsers(struct User list[], int count) {
    printf("Reading All Users\n");
    printf("*****************\n");

    if (count == 0) {
        printf("No users found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("[%d] Name: %s, Age: %d, Address: %s\n", i + 1, list[i].name, list[i].age, list[i].address);
    }
}

// User အချက်အလက်ကို ပြန်ပြင်မည့် Function (Option 3)
void updateUser(struct User list[], int count) {
    printf("Update User Page\n");
    printf("****************\n");

    if (count == 0) {
        printf("No users available to update!\n");
        return;
    }

    int index;
    printf("Enter user number to update (1 to %d): ", count);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count) {
        printf("Invalid user number!\n");
        return;
    }

    int i = index - 1; // Array Index က 0 ကစလို့ ၁ နှုတ်ပေးရခြင်း ဖြစ်သည်
    printf("Enter new name (Current: %s) ::", list[i].name);
    fgets(list[i].name, sizeof(list[i].name), stdin);
    list[i].name[strcspn(list[i].name, "\n")] = 0;

    printf("Enter new age (Current: %d) ::", list[i].age);
    scanf("%d", &list[i].age);
    getchar();

    printf("Enter new address (Current: %s) ::", list[i].address);
    fgets(list[i].address, sizeof(list[i].address), stdin);
    list[i].address[strcspn(list[i].address, "\n")] = 0;

    printf("User updated successfully!\n");
}

// User ကို ဖျက်ပစ်မည့် Function (Option 4)
void deleteUser(struct User list[], int *count) {
    printf("Delete User Page\n");
    printf("****************\n");

    if (*count == 0) {
        printf("No users available to delete!\n");
        return;
    }

    int index;
    printf("Enter user number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *count) {
        printf("Invalid user number!\n");
        return;
    }

    int i = index - 1;
    // Pointers/Dynamic Memory မသုံးထားသောကြောင့် array element များကို ရှေ့သို့တစ်ဆင့်တိုး၍ overwrite လုပ်ခြင်း
    for (; i < *count - 1; i++) {
        list[i] = list[i + 1];
    }

    (*count)--; // Total count ကို တစ်ခုလျှော့ချခြင်း
    printf("User deleted successfully!\n");
}