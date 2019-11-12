/*
 * This program implements a seats reservation system for a Colossus's airplane.
 * The airplane provides one flight per day, and there are 12 seats each flight.
 *
 * Declares a structure array, each structure has a identifier, assigned or not,
 * first name and last name of the passenger.
 *
 * And implements following menu and all features:
 * a) Show number of empty seats
 * b) Show list of empty seats
 * c) Show alphabetical list of seats
 * d) Assign a customer to a seat assignment
 * e) Delete a seat assignment
 * f) Quit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define PLACES 12
#define NAMESIZE 11

struct Seat {
    int identifier;
    bool assigned;
    struct {
        char first_name[NAMESIZE];
        char last_name[NAMESIZE];
    };
};

void read_file(FILE ** fp, int size, struct Seat seats[size]);
void write_file(FILE ** fp, int size, struct Seat seats[size]);
char print_menu();
void show_number_empty_seats(int size, struct Seat seats[size]);
void show_list_empty_seats(int size, struct Seat seats[size]);
void show_alphabet_seats(int size, struct Seat seats[size]);
void assign_seat(int size, struct Seat seats[size]);
void delete_seat(int size, struct Seat seats[size]);

int compare(const void * p1, const void * p2);  /* Used to sort the array in (c) */

int main(void)
{
    FILE * fp;
    char choice;
    bool loop = true;

    /* (a) */
    struct Seat seats[PLACES];

    /* Reads the file contents and puts the contents in array */
    read_file(&fp, PLACES, seats);

    /* (b), (c), (d), (e) */
    while (loop)
    {
        choice = print_menu();

        switch(choice)
        {
            case 'a' : show_number_empty_seats(PLACES, seats);
                       break;
            case 'b' : show_list_empty_seats(PLACES, seats);
                       break;
            case 'c' : show_alphabet_seats(PLACES, seats);
                       break;
            case 'd' : assign_seat(PLACES, seats);
                       break;
            case 'e' : delete_seat(PLACES, seats);
                       break;
            case 'f' : loop = false;
                       break;
            default  : break;
        }
        puts("");
    }
    puts("Bye!");

    write_file(&fp, PLACES, seats);
    fclose(fp);

    return 0;
}

void read_file(FILE ** fp, int size, struct Seat seats[size])
{
    if (((*fp) = fopen("08_input", "r+")) == NULL)
    {
        printf("Can't open 08_input\n");
        exit(1);
    }
    
    int scanf_result;
    int index = 0;
    int identifier;
    int assigned;
    char first_name[NAMESIZE], last_name[NAMESIZE];

    while (fscanf(*fp, "%d %d", &identifier, &assigned) == 2)
    {
        seats[index] = (struct Seat) { identifier, (bool) assigned, "", "" };

        if (assigned == 1)
        {
            fscanf(*fp, "%s %s", first_name, last_name);
            strncpy(seats[index].first_name, first_name, NAMESIZE);
            strncpy(seats[index].last_name ,  last_name, NAMESIZE);
        }
        index++;
    }
}

void write_file(FILE ** fp, int size, struct Seat seats[size])
{
    fclose(*fp);
    if (((*fp) = fopen("08_input", "w+")) == NULL)
    {
        printf("Can't open 08_input\n");
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(*fp, "%d %d", seats[i].identifier, (seats[i].assigned == true) ? 1 : 0);
        if (seats[i].assigned == true)
            fprintf(*fp, " %s %s", seats[i].first_name, seats[i].last_name);
        fprintf(*fp, "\n");
    }
}

char print_menu()
{
    int valid;
    char choice;

    do
    {
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Quit");
        valid = scanf("%c", &choice);
        if (valid != 1 || choice < 'a' || choice > 'f')
            puts("You should only enter a~f, try again.");

        while (getchar() != '\n')
            continue;
    } while (valid != 1);

    return choice;
}

void show_number_empty_seats(int size, struct Seat seats[size])
{
    int empty = 0;

    for (int i = 0; i < size; i++)
        if (seats[i].assigned == false)
            empty++;

    printf("There are %d empty seats.\n", empty);
}

void show_list_empty_seats(int size, struct Seat seats[size])
{
    for (int i = 0; i < size; i++)
        if (seats[i].assigned == false)
            printf("The seat %2d is empty\n", seats[i].identifier);
}

void show_alphabet_seats(int size, struct Seat seats[size])
{
    struct Seat dup_seats[size];

    memcpy(dup_seats, seats, sizeof(struct Seat) * size);

    /* Sort the duplicated seats array by first name and last name */
    qsort(dup_seats, size, sizeof(struct Seat), compare);

    puts("Seat_ID | First name | Last name");
    for (int i = 0; i < size; i++)
    {
        if (dup_seats[i].assigned == true)
            printf("%7d %12s %11s\n", dup_seats[i].identifier, dup_seats[i].first_name, dup_seats[i].last_name);
    }
}

void assign_seat(int size, struct Seat seats[size])
{
    /* Check that if there is any empty seat */
    /* Otherwise end the assignment          */
    bool has_empty_seat = false;

    for (int i = 0; i < size; i++)
    {
        if (seats[i].assigned == false)
        {
            has_empty_seat = true;
            break;
        }
    }
    if (has_empty_seat != true)
    {
        puts("There are no empty seats, end the assignment.");
        return;
    }

    bool assignment = false;
    int identifier;
    
    while (assignment != true)
    {
        puts("Enter the seat identifier you want to seat (enter -1 to cancel):");
        while ((scanf("%d", &identifier)) != 1 || ( identifier != -1 && (identifier < 1 || identifier > 12)))
        {
            puts("You should only enter integer 1~12, try again (enter -1 to cancel):");
            while (getchar() != '\n')
                continue;
        }

        if (identifier == -1)
        {
            while (getchar() != '\n')
                continue;
            break;
        }
        while (getchar() != '\n')
            continue;

        for (int i = 0; i < size; i++)
        {
            if (seats[i].identifier == identifier)
            {
                if (seats[i].assigned == true)
                    printf("The seat %2d had assigned to somebody, please choose another seat.\n", identifier);
                else
                {
                    puts("Please enter your first name and last name (each up to 10 characters):");
                    scanf("%s %s", seats[i].first_name, seats[i].last_name);
                    seats[i].assigned = true;
                    assignment = true;
                    while (getchar() != '\n')
                        continue;
                }
                break;
            }
        }
    }
}

void delete_seat(int size, struct Seat seats[size])
{
    /* Check that if there is any assigned seat */
    /* Otherwise end the deletion               */
    bool has_assigned_seat = false;

    for (int i = 0; i < size; i++)
    {
        if (seats[i].assigned == true)
        {
            has_assigned_seat = true;
            break;
        }
    }
    if (has_assigned_seat != true)
    {
        puts("There are no assigned seats, end the deletion.");
        return;
    }

    puts("You can delete following assignments:");
    puts("Seat_ID | First name | Last name");
    for (int i = 0; i < size; i++)
    {
        if (seats[i].assigned == true)
            printf("%7d %12s %11s\n", seats[i].identifier, seats[i].first_name, seats[i].last_name);
    }

    bool deletion = false;
    int identifier;
    
    while (deletion != true)
    {
        puts("Enter the seat identifier you want to delete (enter -1 to cancel):");
        while ((scanf("%d", &identifier)) != 1 || (identifier != -1 && (identifier < 1 || identifier > 12)))
        {
            puts("You should only enter integer 1~12, try again (enter -1 to cancel):");
            while (getchar() != '\n')
                continue;
        }

        if (identifier == -1)
            break;

        while (getchar() != '\n')
            continue;

        for (int i = 0; i < size; i++)
        {
            if (seats[i].identifier == identifier)
            {
                if (seats[i].assigned == true)
                {
                    printf("Delete the seat %2d successfully.\n", identifier);
                    seats[i].assigned = false;
                    seats[i].first_name[0] = '\0';
                    seats[i].last_name[0] = '\0';
                    deletion = true;
                }
                else
                    printf("The seat %2d hasn't been assigned yet, please choose another seat.\n", identifier);
                break;
            }
        }
    }
}

int compare(const void * p1, const void * p2)
{
    const struct Seat * s1 = (const struct Seat *) p1;
    const struct Seat * s2 = (const struct Seat *) p2;
    int result;

    result = strcmp(s1->last_name, s2->last_name);
    if (result != 0)
        return result;
    else
        return strcmp(s1->first_name, s2->first_name);
}
