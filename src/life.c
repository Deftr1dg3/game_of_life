
#include "headers.h"
#include "/Users/stasusbondevito/Documents/PYTHON/C/Utils/util_headers.h"

int **create_field(int rows, int cols)
{
    int i;
    int **field;

    field = malloc(rows * sizeof(int *));
    if (field == NULL)
    {
        return (NULL);
    }
    for (i = 0; i < rows; i++)
    {
        field[i] = calloc(cols, sizeof(int));
        if (field[i] == NULL)
        {
            free(field);
            return (NULL);
        }
    }
    return (field);
}

void init_field(int **field, int rows, int cols)
{
    int i;
    int row;
    int col;

    i = 0;
    while (i < (rows * (cols / 2)))
    {
        row = true_random_range(0, rows - 1);
        col = true_random_range(0, cols - 1);
        if (row != -1 && col != -1)
        {
            field[row][col] = 1;
        }
        i++;
    }
}

void free_field(int ***field, int rows)
{
    for (int r = 0; r < rows; r++)
    {
        free((*field)[r]);
    }
    free(*field);
}

int cycle_col(int index, int cols)
{
    if (index < 0)
    {
        return (cols - 1);
    }
    if (index > (cols - 1))
    {
        return (0);
    }
    return (index);
}

int cycle_row(int index, int rows)
{
    if (index < 0)
    {
        return (rows - 1);
    }
    if (index > (rows - 1))
    {
        return (0);
    }
    return (index);
}

int get_neighbors(int **field, int row, int col, int rows, int cols)
{
    int ngs;

    ngs = 0;
    for (int r = MAX(0, row - 1); r < MIN(row + 2, rows); r++)
    {
        for (int c = MAX(0, col - 1); c < MIN(col + 2, cols); c++)
        {
            if (!(r == row && c == col))
            {
                ngs += field[r][c];
            }
        }
    }
    return (ngs);
}

void next_field_state(int ***field, int rows, int cols)
{
    int ngs;
    int **next_field;

    next_field = create_field(rows, cols);
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            ngs = get_neighbors(*field, r, c, rows, cols);
            if ((*field)[r][c] == 1)
            {
                if (ngs < 2 || ngs > 3)
                {
                    next_field[r][c] = 0;
                }
                else
                {
                    next_field[r][c] = (*field)[r][c];
                }
            }
            else
            {
                if (ngs == 3)
                {
                    next_field[r][c] = 1;
                }
                else
                {
                    next_field[r][c] = (*field)[r][c];
                }
            }
        }
    }
    free_field(field, rows);
    *field = next_field;
}
