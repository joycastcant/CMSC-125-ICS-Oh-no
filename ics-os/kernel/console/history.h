typedef struct historyCommand {
    char commandName[512];
    struct historyCommand * next;
    struct historyCommand * prev;
} command;

void startHistory(command ** head, command ** tail, command * curr) {
    // TODO: create head node points to first command
        // create head, tail, curr pointers
    * head = NULL;
    * tail = NULL;
    (* head)->next = NULL;
    (* head)->prev = NULL;
    (* tail)->next = NULL;
    (* tail)->prev = NULL;
};

void appendHistory(command ** head, command ** tail, char * cmmand) {
    char temps[512];

    command * temp = * head;
    command * newcommand = (command *)malloc(sizeof(command));
    strcpy(newcommand->commandName, cmmand);
    newcommand->prev = NULL;
    newcommand->next = NULL;

    if(* head == NULL) {
      * head = newcommand;
      * tail = newcommand;
      return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = newcommand;
    newcommand->prev = temp;

    * tail = newcommand;
}

void copyHistory() {
    // COPIES
}

char * movePointerHistory(int direction) {
    // 1 == UP; 0 == DOWN
    // if 1 -> prev
    // if 0 -> next


    // note: catch yung dulo dulo
}
//console_execute(movePointerHistory(int d))

void printAllHistory(command * head) {
    // AAAALLL
    command * temp = head;
    while(temp != NULL){
        printf("%s \n", temp->commandName);
        temp = temp->next;
    }
}

void printHeadHistory(command * head) {
    // first ten
    printf("All commands here head\n");
    printf("%s\n", head->commandName);
}

void printTailHistory(command * tail) {
    // last ten
    printf("All commands here tail\n");
    printf("%s\n", tail->commandName);
}

void printHistoryHelp() {
    printf("Description\nThis command displays a list of commands that were called by the user.\nAnother feature is that it displays the most recent previous\nand next command when the keyboard arrows up or down is pressed, respectively.\nIt also allows the user to execute the chosen command when they press enter.\n\nOptions\n\t-h: displays help details in this command\n\t-t: displays the first ten commands that were called by the user\n\t-e: displays the last ten commands that were called by the user\n");
}