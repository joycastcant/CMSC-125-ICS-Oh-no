#define KEY_UP  151
#define KEY_DOWN 152

typedef struct historyCommand {
    char commandName[512];
    struct historyCommand * next;
    struct historyCommand * prev;
} command;

command * head = NULL;
command * tail = NULL;
command * curr = NULL;

int historyCommandFlag = 0;

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
        strcpy(tempComm, (*curr)->commandName);
        if ((*curr)->prev != NULL) {
          (*curr) = (*curr)->prev;
        }
      } else if (direction == 0) {
        strcpy(tempComm, (*curr)->commandName);
        if ((*curr)->next != NULL){
          (*curr) = (*curr)->next;
        }
      }
}

// moves the pointer depending on user's input
char * movePointerHistory(command ** curr, char * prompt, int initial, DEX32_DDL_INFO *ddl, char * prevComm) {
  char * tempComm = "";
  char direction;
  int i;
  int prevLen = strlen(prevComm) + strlen(prompt);

  if (initial == 1){
    moveCurr(1, curr, tempComm);
    for (i = 0; i < prevLen; i++) {
      if (Dex32GetX(ddl)==0)
        Dex32SetX(ddl,79);
      else
        Dex32SetX(ddl,Dex32GetX(ddl)-1);

      Dex32PutChar(ddl,Dex32GetX(ddl),Dex32GetY(ddl),' ',Dex32GetAttb(ddl));
      update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));
    }
    Dex32SetY(ddl,Dex32GetY(ddl)-1);
    update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));

    textcolor(MAGENTA);
    printf("\n%s", prompt);
    textcolor(LIGHTRED);
    printf("%s", tempComm);
  } else if (initial == 0) {
    moveCurr(0, curr, tempComm);
    for (i = 0; i < prevLen; i++) {
      if (Dex32GetX(ddl)==0)
        Dex32SetX(ddl,79);
      else
        Dex32SetX(ddl,Dex32GetX(ddl)-1);

      Dex32PutChar(ddl,Dex32GetX(ddl),Dex32GetY(ddl),' ',Dex32GetAttb(ddl));
      update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));
    }
    Dex32SetY(ddl,Dex32GetY(ddl)-1);
    update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));

    textcolor(MAGENTA);
    printf("\n%s", prompt);
    textcolor(LIGHTRED);
    printf("%s ", tempComm);
  }

  while(1) {
    unsigned char direction = getch();
    if(direction == KEY_UP){
      moveCurr(1, curr, tempComm);
      for (i = 0; i < prevLen; i++) {
        if (Dex32GetX(ddl)==0)
          Dex32SetX(ddl,79);
        else
          Dex32SetX(ddl,Dex32GetX(ddl)-1);

        Dex32PutChar(ddl,Dex32GetX(ddl),Dex32GetY(ddl),' ',Dex32GetAttb(ddl));
        update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));
      }
      Dex32SetY(ddl,Dex32GetY(ddl)-1);
      update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));

      textcolor(MAGENTA);
      printf("\n%s", prompt);
      textcolor(LIGHTRED);
      printf("%s\n", (*curr)->commandName);
    }
    else if (direction == KEY_DOWN){
      moveCurr(0, curr, tempComm);
      for (i = 0; i < prevLen; i++) {
        if (Dex32GetX(ddl)==0)
          Dex32SetX(ddl,79);
        else
          Dex32SetX(ddl,Dex32GetX(ddl)-1);

        Dex32PutChar(ddl,Dex32GetX(ddl),Dex32GetY(ddl),' ',Dex32GetAttb(ddl));
        update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));
      }
      Dex32SetY(ddl,Dex32GetY(ddl)-1);
      update_cursor(Dex32GetY(ddl),Dex32GetX(ddl));

      textcolor(MAGENTA);
      printf("\n%s", prompt);
      textcolor(LIGHTRED);
      printf("%s\n", (*curr)->commandName);
    } else {
      return tempComm;
    }
  }
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
    int count = 0, i = 0;
    while ((tempCurr != NULL) && (count < 10)) {
      // printf("%s\n", tempCurr->commandName);
      tempCurr = tempCurr->prev;
      count++;
    }

    if (count < 10) tempCurr = head;
    while (i < count) {
      printf("%s\n", tempCurr->commandName);
      tempCurr = tempCurr->next;
      i++;
    }
  }

void printHistoryHelp() {
    printf("Description\nThis command displays a list of commands that were called by the user.\nAnother feature is that it displays the most recent previous\nand next command when the keyboard arrows up or down is pressed, respectively.\nIt also allows the user to execute the chosen command when they press enter.\n\nOptions\n\t-h: displays help details in this command\n\t-t: displays the first ten commands that were called by the user\n\t-e: displays the last ten commands that were called by the user\n");
}
