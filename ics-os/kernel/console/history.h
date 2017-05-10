#define up_key 'a'
#define down_key 'z'
#define enter 'k'
#define KEY_UP  151
#define KEY_DOWN 152

typedef struct historyCommand {
    char commandName[512];
    struct historyCommand * next;
    struct historyCommand * prev;
} command;

command * head;
command * tail;
command * curr;

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

void appendHistory(command ** head, command ** tail, command ** curr, char * cmmand) {
    char temps[512];

    if ((strcmp(cmmand, "move") == 0))
      return;

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
    * curr = tail;
}

// moves and prints the curr command whenever it is called
void moveCurr(int direction, command ** curr, char * tempComm) {
      if (direction == 1) {
        if ((*curr)->prev != NULL)
          (*curr) = (*curr)->prev;
      } else if (direction == 0) {
        if ((*curr)->next != NULL)
          (*curr) = (*curr)->next;
      }

      // printf("%s\n",(*curr)->commandName);
      strcpy(tempComm, (*curr)->commandName);
}

// moves the pointer depending on user's input
char * movePointerHistory(command ** curr, char * prompt) {
  char * tempComm = "";
  char direction;

  while(1) {
    unsigned char direction = getch();
    if(direction == KEY_UP){
      moveCurr(1, curr, tempComm);
      printf("%s%s\n", prompt, (*curr)->commandName);
    }
    else if (direction == KEY_DOWN){
      moveCurr(0, curr, tempComm);
    } else {
      return tempComm;
    }
  }
  // printf("exec: %s\n", tempComm);
  return tempComm;
}

void printAllHistory(command * head) {
    // print all commands in history
    command * temp = head;
    while(temp != NULL){
        printf("%s \n", temp->commandName);
        temp = temp->next;
    }
}

void printHeadHistory(command * head) {
    // first ten commands
    // printf("%s\n", head->commandName);
    command * tempCurr = head;
    int count = 0;
    while ((tempCurr != NULL) && (count < 10)) {
      printf("%s\n", tempCurr->commandName);
      tempCurr = tempCurr->next;
      count++;
    }
}

void printTailHistory(command * tail) {
    // last ten commands
    // printf("All commands here tail\n");
    command * tempCurr = tail;
    int count = 0;
    while ((tempCurr != NULL) && (count < 10)) {
      printf("%s\n", tempCurr->commandName);
      tempCurr = tempCurr->prev;
      count++;
    }}

void printHistoryHelp() {
    printf("Description\nThis command displays a list of commands that were called by the user.\nAnother feature is that it displays the most recent previous\nand next command when the keyboard arrows up or down is pressed, respectively.\nIt also allows the user to execute the chosen command when they press enter.\n\nOptions\n\t-h: displays help details in this command\n\t-t: displays the first ten commands that were called by the user\n\t-e: displays the last ten commands that were called by the user\n");
}
