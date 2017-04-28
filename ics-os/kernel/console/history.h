typedef struct historyCommand {
    char commandName[512];
    struct historyCommand * next;
    struct historyCommand * prev;
} command;

void startHistory() {
    // TODO: create head node points to first command
        // create head, tail, curr pointers

    printf("history is running\n");
};

void appendHistory() {
    // APPENDS
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

void printAllHistory() {
    // AAAALLL
    printf("All commands here\n");
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
    // last ten
    printf("All commands here help\n");
}