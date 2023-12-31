#include <cs50.h>
#include <stdio.h>
#include<string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cycle(int winner, int loser);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(candidates[k], name) == 0)
        {
            ranks[rank] = k;
            //printf("%i\n",ranks[k]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            //printf("%i\n", preferences[ranks[i]][ranks[j]]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair p;
                p.winner = i;
                p.loser = j;
                pairs[pair_count++] = p;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    //Selection sort.
    for (int i = 0; i < pair_count - 1; i++)
    {
        //Calculating strength of victory.
        int max_index = i;
        int winner_v = preferences[pairs[i].winner][pairs[i].loser];
        int loser_v = preferences[pairs[i].loser][pairs[i].winner];
        int current_strength = winner_v - loser_v;

        for (int j = i + 1; j < pair_count; j++)
        {
            int winner_votes = preferences[pairs[j].winner][pairs[j].loser];
            int loser_votes = preferences[pairs[j].loser][pairs[j].winner];
            int temp_strength = winner_votes - loser_votes;
            //Finding the maximum.
            if (temp_strength > current_strength)
            {
                max_index = j;
                current_strength = temp_strength;
            }
        }

        //Swapping two pairs according to strength of victory.
        pair temp = pairs[max_index];
        pairs[max_index] = pairs[i];
        pairs[i] = temp;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

//To check whether the chain creates a cycle.
bool cycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }
        if (!found)
        {
            winner = -1;
        }
    }
    if (winner == loser)
    {
        return true;
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    //int can_index = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        //bool found_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                //found_source = false;
                break;
            }
        }
        printf("%s\n", candidates[i]);
        return;
        // if (found_source == true)
        // {
        //     can_index = i;
        //     break;
        // }
        // if (found_source == true)
        // {
        //     printf("%s\n",candidates[can_index]);
        //     return;
        // }
    }
}