#include <stdio.h>
void add();
void rshiftop();
void subtract();
int a[4] = {0, 0, 0, 0}, q[4] = {0, 0, 1, 1}, q1 = 0, m[4] = {0, 1, 1, 1}, count = 4, m_real[4] = {0, 1, 1, 1};
int copya[4], copyq[4];
int sum[4], subsum[4];

int main()
{
    // printf("%d\n", q[3]);
    // printf("%d\n", q1);
    while (count != 0)
    {
        if (q[3] == q1)
        {

            printf("11 and 00\n");
            rshiftop();
        }
        if (q[3] == 1 && q1 == 0)
        {
            printf("-1 0\n");
            subtract();
        }
        if (q[3] == 0 && q1 == 1)
        {
            printf("-0 1\n");
            add();
        }
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d", a[i]);
    // }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", q[i]);
    }
    // printf("%d", count);
}
void add()
{
    printf("adding\n");
    int carry = 0;

    for (int i = 3; i >= 0; i--)
    {
        a[i] = (a[i] + m_real[i] + carry) % 2;
        carry = (a[i] + m_real[i] + carry) / 2;
        // printf("%d", a[i]);
    }
    rshiftop();
}

void rshiftop()
{
    count--;
    printf("shifting\n");
    for (int i = 0; i < 4; i++)
    {
        copya[i] = a[i];
        copyq[i] = q[i];
    }

    a[0] = copya[0];
    a[1] = copya[0];
    a[2] = copya[1];
    a[3] = copya[2];
    q[0] = copya[3];
    q[1] = copyq[0];
    q[2] = copyq[1];

    q[3] = copyq[2];
    q1 = copyq[3];

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d", a[i]);
    // }
    // printf("\n");
}

void subtract()
{
    printf("subtractiong\n");

    int temp, carry = 0;
    //subtract a-m and rs
    for (int i = 3; i >= 0; i--)
    {
        if (m[i] == 1)

        {
            temp = i;
            break;
        }
    }
    for (int i = 0; i < temp; i++)
    {
        if (m[i] == 1)
        {
            m[i] = 0;
        }
        else
        {
            m[i] = 1;
        }
    }
    for (int i = 3; i >= 0; i--)
    {
        a[i] = (a[i] + m[i] + carry) % 2;
        carry = (a[i] + m[i] + carry) / 2;
    }
    rshiftop();
    // if (carry == 1)
    // {
    //     rshiftop();
    // }
    // else
    // {
    //     for (int i = 3; i >= 0; i--)
    //     {
    //         if (m[i] == 1)

    //         {
    //             temp = i;
    //             break;
    //         }
    //     }
    //     for (int i = 0; i < temp; i++)
    //     {
    //         if (m[i] == 1)
    //         {
    //             m[i] = 0;
    //         }
    //         else
    //         {
    //             m[i] = 1;
    //         }
    //     }
    //     //----------------- feri original value ma lyauna paryo ni ta next time ko lagi
    //     for (int i = 0; i < 4; i++)
    //     {
    //         m[i] = m_real[i];
    //     }

    //     //------------------
    //     rshiftop();
    // }
}

// if (q[3] == q1)
// {
//     //a,q,q1 rs
//     for (int i = 0; i < 4; i++)
//     {
//         copya[i] = a[i];
//         copyq[i] = q[i];
//     }
//     a[0] = copya[0];
//     a[1] = copya[0];
//     a[2] = copya[1];
//     a[3] = copya[2];
//     q[0] = copya[3];
//     q[1] = copyq[0];
//     q[2] = copyq[1];

//     q[3] = copyq[2];
//     q1 = copyq[3];
// }

// if (q[3] == 1 && q1 == 0)
// {
//     int sum[4];
// //subtract a-m and rs
// for (int i = 3; i >= 0; i--)
// {
//     if (m[i] == 1)

//     {
//         temp = i;
//         break;
//     }
// }
// for (int i = 0; i < temp; i++)
// {
//     if (m[i] == 1)
//     {
//         m[i] = 0;
//     }
//     else
//     {
//         m[i] = 1;
//     }
// }
// for (int i = 3; i >= 0; i--)
// {
//     sum[i] = (a[i] + m[i] + carry) % 2;
//     carry = (a[i] + m[i] + carry) / 2;
// }
// printf("%d\n", carry);
// for (int i = 0; i < 4; i++)
// {
//     printf("%d", sum[i]);
// }
// for (int i = 0; i < 4; i++)
// {
//     copya[i] = a[i];
//     copyq[i] = q[i];
// }

//     a[0] = copya[0];
//     a[1] = copya[0];
//     a[2] = copya[1];
//     a[3] = copya[2];
//     q[0] = copya[3];
//     q[1] = copyq[0];
//     q[2] = copyq[1];

//     q[3] = copyq[2];
//     q1 = copyq[3];
// }
// if (q[3] == 0 && q1 == 1)
// {
//     //add a+m and rs
//     printf("heram");

//     for (int i = 3; i >= 0; i--)
//     {
//         a[i] = (a[i] + m[i] + carry) % 2;
//         carry = (a[i] + m[i] + carry) / 2;
//     }
//     // for (int i = 0; i < 4; i++)
// {
//     printf("%d", a[i]);
// }
// printf("\n");
// for (int i = 1; i < 4; i++)
// {
//     // a[i+1]=a[i-1];
//     // a[1+1]=a[1-1]
//     copya[i] = a[i];
//     copyq[i] = q[i];
// }

// a[0] = copya[0];
// a[1] = copya[0];
// a[2] = copya[1];
// a[3] = copya[2];
// q[0] = copya[3];
// q[1] = copyq[0];
// q[2] = copyq[1];

// q[3] = copyq[2];
// q1 = copyq[3];
// }
// printf("%d", copya[1]);
// printf("%d", q1);
// printf("\n");
// for (int i = 0; i < 4; i++)
// {
//     printf("%d", a[i]);
// }
