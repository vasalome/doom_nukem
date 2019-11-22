//j'esssaye de comprendre son calcul

//mdr

ray_circle({x: info->player.x_pos, y: info->player.y_pos}, {x: info->player.x_pos + info->ray.x_ray_direction, y: info->player.y_pos + info->ray.y_ray_direction}, {x: mapX + 0.5, y: mapY + 0.5}, 0.5);

int     ray_circle(p1, p2, sc, r)
{
    double a, b, c;
    double bb4ac;
    double dp{0, 0};

    dp[0] = p2.x - p1.x;
    dp[1] = p2.y - p1.y;
    a = dp[0] * dp[0] + dp[1] * dp[1];
    b = 2 * (dp[0] * (p1.x - sc.x) + dp[1] * (p1.y - sc.y));
    c = sc.x * sc.x + sc.y * sc.y;
    c += p1.x * p1.x + p1.y * p1.y;
    c -= 2 * (sc.x * p1.x + sc.y * p1.y);
    c -= r * r;
    bb4ac = b * b - 4 * a * c;
    if (bb4ac < 0)
        return(0);
}