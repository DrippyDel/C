#include <stdio.h>

#define candidate1 "Jhon Doe"
#define candidate2 "Ima Knight"
#define candidate3 "Hillary Clark"
#define candidate4 "William Smith"
#define MAX_CANDIDATES 4

typedef struct {

  int candidate1Vote;
  int candidate2Vote;
  int candidate3Vote;
  int candidate4Vote;
  
}vote_t;

// Prototypes
void castVote(vote_t *vote);
void votesCount(vote_t *vote);
char* getLeadingCandidate(vote_t *vote);
void end(vote_t *vote, char* winner);

int main()
{
  // Start each candidate's vote to 0
  vote_t vote = {
      .candidate1Vote = 0,
      .candidate2Vote = 0,
      .candidate3Vote = 0,
      .candidate4Vote = 0,
  };
  vote_t *votePtr = &vote;
  int menu = 1;
  int choice;
  // Dummy value just to hold a value
  char *winner = "Ucf";

  printf("\n###### Welcome to Election/Voting 2023 ######\n\n");

  while (menu != 0)
  {
    printf("1. Cast Vote \n");
    printf("2. View Vote Count \n");
    printf("3. Find Leading Candidate \n");
    printf("4. Exit \n");
    printf("---------------------------------------\n");

    printf("Please select an option: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      printf("Cast your vote!\n");
      castVote(votePtr);
    }

    else if (choice == 2)
    {
      printf("Here's the Election voting count %d \n", choice);
      votesCount(votePtr);
    }

    else if (choice == 3)
    {
      winner = getLeadingCandidate(votePtr);
    }

    else if (choice == 4)
    {
      printf("Thanks for using the Election/Voting 2023 database\n");
      printf("GoodBye!!\n");
      end(votePtr,winner);
      menu = 0;
    }

    else
    {
      printf("Invalid Choice Please Choose an Option from the Menu\n");
      printf("---------------------------------------\n");
    }
  }
}

void castVote(vote_t *vote)
{
  int menu = 1;
  int choice;

  printf("\n###### Here's your candidates ######\n\n");

  while (menu != 0)
  {
    printf("---------------------------------------\n");
    printf("1. %s \n",candidate1);
    printf("2. %s \n",candidate2);
    printf("3. %s \n",candidate3);
    printf("4. %s \n",candidate4);
    printf("5. None of These\n");
    printf("---------------------------------------\n");

    printf("Please Enter your choice (1 - 5): ");
    scanf(" %d", &choice);

    if (choice == 1)
    {
      printf("%s was selected\n",candidate1);
      vote->candidate1Vote = vote->candidate1Vote + 1;
      printf("Thanks for your Vote! \n");
      menu = 0;
    }

    else if (choice == 2)
    {
      printf("%s was selected\n",candidate2);
      vote->candidate2Vote = vote->candidate2Vote + 1;
      printf("Thanks for your Vote! \n");
      menu = 0;
    }

    else if (choice == 3)
    {
      printf("%s was selected \n",candidate3);
      vote->candidate3Vote = vote->candidate3Vote + 1;
      printf("Thanks for your Vote! \n");
      menu = 0;
    }

    else if (choice == 4)
    {
      printf("%s was selected\n",candidate4);
      vote->candidate4Vote = vote->candidate4Vote + 1;
      printf("Thanks for your Vote! \n");
      menu = 0;
    }

    else if (choice == 5)
    {
      printf("You have chosen no one\n");
      printf("Thanks for your Vote! \n");
      menu = 0;
    }

    else
    {
      printf("Invalid Choice Please Choose an Option from the Menu\n");
      printf("---------------------------------------\n");
    }
  }
}

void votesCount(vote_t *vote)
{
  printf("---------------------------------------\n");
  printf("%s - %d \n",candidate1, vote->candidate1Vote);
  printf("%s - %d \n",candidate2, vote->candidate2Vote);
  printf("%s - %d \n",candidate3, vote->candidate3Vote);
  printf("%s - %d \n",candidate4, vote->candidate4Vote);
  printf("---------------------------------------\n");
}

char* getLeadingCandidate(vote_t *vote)
{
  int maxVotes = 0;
  int maxIndex = 0;
  int numMaxCandidates = 0;

  int voteArray[4];
  voteArray[0] = vote->candidate1Vote;
  voteArray[1] = vote->candidate2Vote;
  voteArray[2] = vote->candidate3Vote;
  voteArray[3] = vote->candidate4Vote;

  char *candidateArray[] = {"Jhon Doe", "Ima Knight", "Hillary Clark", "William Smith"};

  for (int i = 0; i < MAX_CANDIDATES; i++)
  {
    if(voteArray[i] > maxVotes)
    {
      maxVotes = voteArray[i];
      maxIndex = i;
      numMaxCandidates = 1;
    }
    else if (voteArray[i] == maxVotes)
    {
      numMaxCandidates++;
    }
  }

  //char *winner = candidateArray[maxIndex];

  printf("[%s]\n", candidateArray[maxIndex]);

  if (numMaxCandidates > 1)
  {
    printf("There is a tie between %d candidates. \n", numMaxCandidates );
  }

  return candidateArray[maxIndex];
}

void end(vote_t *vote, char* winner)
{
  FILE *filePtr = fopen("Results.txt", "w");
  if (filePtr == NULL)
  {
    printf("Error opening file. \n");
  }
  else
  {
    fprintf(filePtr,"Winner: %s \n\n",winner);

    fprintf(filePtr,"###### Final Results ######\n");

    fprintf(filePtr,"%s - %d \n",candidate1, vote->candidate1Vote);
    fprintf(filePtr,"%s - %d \n",candidate2, vote->candidate2Vote);
    fprintf(filePtr,"%s - %d \n",candidate3, vote->candidate3Vote);
    fprintf(filePtr,"%s - %d \n",candidate4, vote->candidate4Vote);
  }
  fclose(filePtr);
}
