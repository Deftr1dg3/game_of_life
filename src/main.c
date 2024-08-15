
#include "headers.h"
#include "util_headers.h"

void print_live_cell()
{
    char cell[] = "\x1b[32m1\x1b[0m";
    printf("%s", cell);
}

void print_dead_cell()
{
    char cell[] = "\x1b[30m0\x1b[0m";
    printf("%s", cell);
}

void print_field(int **arr, int rows, int cols)
{
    int i;

    for (i = 0; i < rows; i++)
    {
        print_int_arr(arr[i], cols);
    }
}

void delete_n_rows(int rows)
{
    char delete_line[] = "\x1b[A\x1b[K";

    for (int i = 0; i < rows; i++)
    {
        printf("%s", delete_line);
    }
}

void display_game(int **field, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (field[r][c] == 1)
            {
                print_live_cell();
            }
            else
            {
                print_dead_cell();
            }
            if (c != (cols - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int validate_arg(char *str)
{
    int res;

    res = atoi(str);
    if (res <= 0)
    {
        fprintf(stderr, "Invalid argument [ %s ]. Expected for positive integer.\n", str);
        return (-1);
    }
    return (res);
}

int main(int argc, char **argv)
{
    int rows;
    int cols;
    int delay;

    if (argc == 2)
    {
        fprintf(stderr, "Not enough Arguments.\n");
        return (1);
    }
    else if (argc == 3)
    {
        rows = validate_arg(argv[1]);
        cols = validate_arg(argv[2]);
        delay = 250000;
        if (rows == -1 || cols == -1)
        {
            return (1);
        }
    }
    else if (argc == 4)
    {
        rows = validate_arg(argv[1]);
        cols = validate_arg(argv[2]);
        delay = validate_arg(argv[3]);
        if (rows == -1 || cols == -1 || delay == -1)
        {
            return (1);
        }
        if (delay < 10000)
        {
            fprintf(stderr, "Delay has to be at least 10000 microseconds.\n");
            return (1);
        }
    }
    else if (argc > 4)
    {
        fprintf(stderr, "To much Arguments.\n");
        return (1);
    }
    else
    {
        rows = 10;
        cols = 17;
        delay = 250000;
    }

    int **field = create_field(rows, cols);
    if (field == NULL)
    {
        return (1);
    }

    init_field(field, rows, cols);
    display_game(field, rows, cols);

    while (true)
    {
        usleep(delay);
        delete_n_rows(rows);
        next_field_state(&field, rows, cols);
        display_game(field, rows, cols);
    }

    // system("leaks life_exe ");
    return (0);
}