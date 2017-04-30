typedef struct historyCommand {
    char * commandName;
    struct historyCommand * next;
    struct historyCommand * prev;
} command;

void startHistory(command ** head, command ** tail, command * curr) {
    // TODO: create head node points to first command
        // create head, tail, curr pointers
    * head = NULL;
    command * dummyNode = (command *)malloc(sizeof(command));
    char * s = "crap";
    dummyNode->commandName = strcpy(dummyNode->commandName, s);
    dummyNode->next = * head;
    * head = dummyNode;
    (* head)->prev = NULL;

    * tail = * head;
    (* tail)->next = NULL;
    printf("history is running\n");
};

void appendHistory(command ** tail, char * cmmand) {
    command * temp;
    command * newcommand;

    newcommand = (command *)malloc(sizeof(command));
    newcommand->commandName = strcpy(newcommand->commandName, cmmand);
    newcommand->next = NULL;

    if(* tail != NULL){
        (* tail)->next = newcommand;
        newcommand->prev = * tail;
    }
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
    int counter = 0;
    command * temp = head;
    while(temp != NULL){
        if(counter > 1) printf("%s\n", temp->commandName);
        temp = temp->next;
        counter++;
    }
}

void printHeadHistory() {
    // first ten
    printf("All commands here head\n");
}

void printTailHistory() {
    // last ten
    printf("All commands here tail\n");
}

void printHistoryHelp() {
    printf("Description\nThis command displays a list of commands that were called by the user. Another feature is that it displays the most recent previous and next command when the keyboard arrows up or down is pressed, respectively. It also allows the user to execute the chosen command when they press enter.\nOptions\n-h: displays help details in this command\n-t: displays the first ten commands that were called by the user\n-e: displays the last ten commands that were called by the user\n");
}