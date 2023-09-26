#include <cstdio>
#include <cmath>

int main()
{
    std::puts("please enter a, b and c for 'ax^2 + bx + c = 0' : ");

    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    float D = 0;
    D = b * b - 4 * a * c;
    if (D > 0)
    {
        float x1 = (-b + std::sqrt(D)) / (2 * a);
        float x2 = (-b - std::sqrt(D)) / (2 * a);
        std::printf("solution: %f %f\n", x1, x2);
    }
    else if (D == 0)
    {
        float x = -b / (2 * a);
        std::printf("solution: %f\n", x);
    }
    else
    {
        std::printf("no decision");
    }
}