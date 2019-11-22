//j'esssaye de comprendre son calcul

//mdr

ray_circle(info, 0.5);

int     ray_circle(t_info *info, double r)
{
    double a, b, c;
    double bb4ac;
    double *dp = {0, 0};
    double intersectDist1;
    double intersectDist2;

    dp[0] = (info->player.x_pos + info->ray.x_ray_direction) - info->player.x_pos;
    dp[1] = (info->player.y_pos + info->ray.y_ray_direction) - info->player.y_pos;
    a = dp[0] * dp[0] + dp[1] * dp[1];
    b = 2 * (dp[0] * (info->player.x_pos - (floor(info->player.x_pos) + 0.5)) + dp[1] * (info->player.y_pos - (floor(info->player.y_pos) + 0.5)));
    c = (floor(info->player.x_pos) + 0.5) * (floor(info->player.x_pos) + 0.5) + (floor(info->player.y_pos) + 0.5) * (floor(info->player.y_pos) + 0.5);
    c += info->player.x_pos * info->player.x_pos + info->player.y_pos * info->player.y_pos;
    c -= 2 * ((floor(info->player.x_pos) + 0.5) * info->player.x_pos + (floor(info->player.y_pos) + 0.5) * info->player.y_pos);
    c -= r * r;
    bb4ac = b * b - 4 * a * c;
    if (bb4ac < 0)
        return(0);
    intersectDist1 = (-b + sqrt(bb4ac)) / (2 * a);
    intersectDist2 = (-b - sqrt(bb4ac)) / (2 * a);

   return(intersectDist1, intersectDist2);
}