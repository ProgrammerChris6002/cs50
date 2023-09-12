#include <cs50.h>
#include <stdio.h>

long get_card_number();
int sum_card_number(long card_number);
int card_is_valid(long card_number, int card_sum);
void check_card_type(long card_number, int is_valid);

int main(void)
{
    long card_number = get_card_number();
    int card_sum = sum_card_number(card_number);
    int is_valid = card_is_valid(card_number, card_sum);

    check_card_type(card_number, is_valid);
}

long get_card_number()
{
    long card_number = get_long("Enter your card number: ");

    return (card_number);
}

int sum_card_number(long card_number)
{
    int card_sum;
    int i, j;
    int sum1 = 0, sum2 = 0, total = 0;
    long card_duplicate = card_number;

    while (card_number > 0)
    {
        i = card_number % 10;
        j = ((card_number / 10) % 10) * 2;

        while (i > 9)
        {
            sum1 += i % 10;
            i /= 10;
        }
        sum1 += i;

        while (j > 9)
        {
            sum2 += j % 10;
            j /= 10;
        }
        sum2 += j;

        card_number /= 100;
    }

    card_sum = sum1 + sum2;

    return (card_sum);
}

int card_is_valid(long card_number, int card_sum)
{
    int card_length = 0;
    long card_number_dup = card_number;

    while (card_number_dup > 0)
    {
        card_number_dup /= 10;
        card_length++;
    }

    if (card_sum % 10 != 0 || card_length < 13)
    {
        return (0);
    }

    return (1);
}

void check_card_type(long card_number, int is_valid)
{
    int i, j;

    if (is_valid == 0)
    {
        printf("INVALID\n");
        return;
    }

    while (card_number > 99)
    {
        card_number /= 10;
    }

    i = card_number / 10;
    j = card_number % 10;

    if (i == 4)
    {
        printf("VISA\n");
    }
    else if ((i == 3 && j == 4) || (i == 3 && j == 7))
    {
        printf("AMEX\n");
    }
    else if ((i == 5 && j == 1) || (i == 5 && j == 2) || (i == 5 && j == 3) || (i == 5 && j == 4) || (i == 5 && j == 5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return;
}
