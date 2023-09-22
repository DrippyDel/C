// Delali Ekpeh
// de770238
#include <stdio.h>
#include <stdlib.h>

//Prototypes
int base(int bp, int l);
void printStuff();

//Macro Constant
#define ARRAY_SIZE 512

// Global Variable

// Program counter - points to the next instruction to excuted
int pc = 0;

// Base pointer - points to the base of the current activation record
int bp = 0;

// Stack pointer - points to the current top of the stack. Stack grows upward
int sp = 0;

// Instruction register - Store the instruction to be executed
int ir = 0;

// Operation code [lit , 0 , M] (Lit)
int op = 0;

// Lexicographical level [lit, 0 , M] (0)
int l = 0;

// Number?? [lit, 0 , M] (M)
int m = 0;

// Start of stack
int stack = 0;

// Process address space(PAS) - two segements "text" (instruction) and "stack"
// Initialized all elements in array to zero
int pas[ARRAY_SIZE] = {0};

int main()
{

  FILE *file;

  file = fopen("elfFile.txt", "r");

  int i = 0;
  int num = 0;
  int counter = 0;
  while (fscanf(file, "%d", &num) == 1)
  {
    pas[i] = num;
    i++;
  }

  // pas[n < i] is the instruction
  // pas[n >= i] is the stack

  /* Fetch cycle
    Where the instruction pointed by the program counter (PC) is fetched from
  the "text segement" (instruction array in our case), placed in the instruction
  register (IR) and the PC is incremented to the point to the next instruction
  code list.
  */

  /* Execute cycle
    The Operation code (OP) in the Instruction register (IR) indicates the
  operation to be eecuted.
  Honestly just follow the key on Appendix A and use the pseudo code on Appendix
  B.
  */

  // PM/0 initial/Default values
  bp = i;
  stack = bp;
  sp = bp - 1;
  pc = 0;

  printf("                PC  BP  SP  stack\n");
  printf("Initial values: %d   %d  %d       \n", pc, bp, sp);
  printf("\n");

  // Loops until last instruction
  while (counter < i)
  {
    // Fetch Cycle
    // Step 1
    op = pas[pc++];

    l = pas[pc++];

    m = pas [pc++];

    // Operation code runs the whole program
    // Execute cycle
    switch(op)
    {
      case 1:
        //printf("LIT \n");
        sp = sp + 1;
        pas[sp] = m;
        printf("    LIT  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
        //pc = pc + 3;
        break;

      case 2:
      //  printf("OPR \n");

    // Identity of arithmetic/relational operation associated to the OPR op-code
    // printf("m = %d \n", m);
        switch(m)
        {
          case 0:
          //  printf("RTN \n");
            sp = bp - 1;
            bp = pas[sp + 2];
            pc = pas[sp + 3];
            printf("    RTN  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 1:
            //printf("ADD \n");
            pas[sp - 1] = pas[sp - 1] + pas[sp];
            sp = sp - 1;
            printf("    ADD  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 2:
            //printf("SUB \n");
            pas[sp - 1] = pas[sp - 1] - pas[sp];
            sp = sp - 1;
            printf("    SUB  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 3:
            //printf("MUL \n");
            pas[sp - 1] = pas[sp - 1] * pas[sp];
            sp = sp - 1;
            printf("    MUL  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 4:
            //printf("DIV \n");
            pas[sp - 1] = pas[sp - 1]/pas[sp];
            sp = sp - 1;
            printf("    DIV  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 5:
            //printf("EQL \n");
            pas[sp - 1] = pas[sp - 1] == pas[sp];
            sp = sp - 1;
            printf("    EQL  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 6:
          //  printf("NEQ \n");
            pas[sp - 1] = pas[sp - 1] != pas[sp];
            sp = sp - 1;
            printf("    NEQ  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 7:
            //printf("LSS \n");
            pas[sp - 1] = pas[sp - 1] < pas[sp];
            sp = sp - 1;
            printf("    LSS  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 8:
            //printf("LEQ \n");
            pas[sp - 1] = pas[sp - 1] <= pas[sp];
            sp = sp - 1;
            printf("    LEQ  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 9:
            //printf("GTR \n");
            pas[sp - 1] = pas[sp - 1] > pas[sp];
            sp = sp - 1;
            printf("    GTR  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;

          case 10:
            //printf("GEQ \n");
            pas[sp - 1] = pas[sp - 1] >= pas[sp];
            sp = sp - 1;
            printf("    GEQ  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
            printStuff();
            break;
        }
      //  pc = pc + 3;
        break;

      case 3:
        //printf("LOD \n");
        sp = sp + 1;

        int var = base(bp,l);

        pas[sp] = pas[var + m];
        printf("    LOD  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
      //  pc = pc + 3;
        break;

      case 4:
        //printf("STO \n");
        pas[base(bp,l) + m] = pas[sp];
        sp = sp - 1;
        printf("    STO  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
      //  pc = pc + 3;
        break;

      case 5:
        //printf("CAl \n");

        // Static Link
        pas[sp + 1] = base(bp, l);

        // Dynamic  Link
        pas[sp + 2] = bp;

        // Return address
        pas[sp + 3] = pc;
        bp = sp + 1;
        pc = m;
        printf("    CAL  %d  %d   %d   %d  %d ", l, m, pc, bp, sp);
        printStuff();
        break;

      case 6:
      //  printf("INC \n");
        sp = sp + m;
        printf("    INC  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
        break;

      case 7:
        //printf("JMP \n");
        pc = m;
        printf("    JMP  %d  %d  %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
        //pc = pc + 3;
        break;

      case 8:
        //printf("JPC \n");
        if (pas[sp] == 0)
        {
          pc = m;
        }
        sp = sp - 1;
        printf("    JPC  %d  %d  %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
      //  pc = pc + 3;
        break;

      case 9:
        switch(m)
        {
          case 1:
            printf("Output result is: %d\n", pas[sp]);
            sp = sp - 1;
            break;

          case 2:
            sp = sp + 1;
            printf("Please Enter an Integer: ");
            scanf("%d", &pas[sp]);

          case 3:
          // End of program
          //printf("\n");
            //exit(0);
            break;
        }
        printf("    SYS  %d  %d   %d  %d  %d ", l, m, pc, bp, sp);
        printStuff();
        break;
    }
    // Fetch Cycle
    // Step 2
    // pc = pc + 3;
    counter = counter + 3;
  }




  fclose(file);

  return 0;
}

void printStuff()
{
  printf(" ");
  for (int j = stack; j <= sp; j++)
  {
    if (j != stack && j % 6 == 0)
    {
      printf("| ");
    }
    printf("%d ", pas[j]);
  }
  printf("\n");
}


int base(int bp, int l)
{
  // arb = Activation record base
  int arb = bp;

  // Find base l levels down
  while (l > 0)
  {
    arb = pas[arb];
    l--;
  }
  return arb;
}
