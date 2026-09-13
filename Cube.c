#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 40
#define PI 3.14159265358979323846f

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

typedef struct {
    int x;
    int y;
} Point;

Vec3 rotate(Vec3 p, float ax, float ay, float az)
{
    float cx = cosf(ax);
    float sx = sinf(ax);
    float cy = cosf(ay);
    float sy = sinf(ay);
    float cz = cosf(az);
    float sz = sinf(az);

    float y = p.y * cx - p.z * sx;
    float z = p.y * sx + p.z * cx;

    p.y = y;
    p.z = z;

    float x = p.x * cy + p.z * sy;
    z = -p.x * sy + p.z * cy;

    p.x = x;
    p.z = z;

    x = p.x * cz - p.y * sz;
    y = p.x * sz + p.y * cz;

    p.x = x;
    p.y = y;

    return p;
}

Point project(Vec3 p)
{
    Point result;

    float distance = 5.0f;
    float scale = 24.0f / (p.z + distance);

    result.x = (int)(WIDTH / 2 + p.x * scale);
    result.y = (int)(HEIGHT / 2 - p.y * scale * 0.5f);

    return result;
}

void plot(char screen[HEIGHT][WIDTH], int x, int y)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        screen[y][x] = '#';
}

void line(
    char screen[HEIGHT][WIDTH],
    int x0,
    int y0,
    int x1,
    int y1
)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        plot(screen, x0, y0);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = err * 2;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void cube(float ax, float ay, float az)
{
    char screen[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            screen[y][x] = ' ';

    Vec3 vertices[8] = {
        {-1, -1, -1},
        { 1, -1, -1},
        { 1,  1, -1},
        {-1,  1, -1},
        {-1, -1,  1},
        { 1, -1,  1},
        { 1,  1,  1},
        {-1,  1,  1}
    };

    int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    Point points[8];

    for (int i = 0; i < 8; i++)
        points[i] = project(rotate(vertices[i], ax, ay, az));

    for (int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        line(
            screen,
            points[a].x,
            points[a].y,
            points[b].x,
            points[b].y
        );
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
            putchar(screen[y][x]);

        putchar('\n');
    }
}

int main(void)
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    printf("\033[2J");
    printf("\033[?25l");

    while (1)
    {
        printf("\033[H");

        cube(x, y, z);

        printf("\n");
        printf("3D CUBE\n");
        printf("X: %.2f  Y: %.2f  Z: %.2f\n", x, y, z);
        printf("Press Ctrl+C to exit.\n");

        x += 0.035f;
        y += 0.055f;
        z += 0.025f;

        if (x >= 2.0f * PI)
            x -= 2.0f * PI;

        if (y >= 2.0f * PI)
            y -= 2.0f * PI;

        if (z >= 2.0f * PI)
            z -= 2.0f * PI;

        fflush(stdout);
        usleep(30000);
    }

    printf("\033[?25h");

    return 0;
}
