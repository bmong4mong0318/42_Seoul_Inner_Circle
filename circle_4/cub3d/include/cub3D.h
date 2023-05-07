/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:49:24 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 16:42:22 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../mlx/mlx.h"
#include "libft.h"
#include "vector.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define TEX_WIDTH 64
#define TEX_HEIGHT 64

#define X_EVENT_move_player 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17

#define RGB_RED 16711680	// 255*65536+0+0
#define RGB_GREEN 65280		// 0*65536+255*256+0
#define RGB_BLUE 255		// 0*65536+0*256+255
#define RGB_WHITE 16777215	// 255*65536+255*256+255
#define RGB_YELLOW 16776960 // 255*65536+255*256+0

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124

enum
{
	WALL_EA,
	WALL_WE,
	WALL_SO,
	WALL_NO
};

typedef unsigned int t_ui;

typedef enum e_info_type
{
	NO,
	SO,
	WE,
	EA,
	FLOOR_OR_CEILING
} t_info_type;

typedef struct s_rgb
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int color;
} t_rgb;

typedef struct s_wall
{
	char *no;
	char *so;
	char *ea;
	char *we;
} t_wall;

typedef struct s_info
{
	t_info_type type;
	char *name;
	char *value;
} t_info;

typedef struct s_map
{
	char **map_array;
	int width;
	int height;
	int n_cnt;
	t_bool is_n_continue;
} t_map;

typedef struct s_img
{
	void *img;
	int *data;
	int size_l;
	int bpp;
	int endian;
	int img_width;
	int img_height;
} t_img;

typedef struct s_game
{
	int map_fd;
	int line_idx;
	t_wall wall;
	t_rgb *floor;
	t_rgb *ceiling;
	t_map map;
	char player;
	void *mlx;
	void *win;
	t_vec pos;
	t_vec dir;
	t_vec plane;
	double move_speed;
	double rot_speed;
	t_img img;
	int buf[WINDOW_HEIGHT][WINDOW_WIDTH];
	int **texture;
	int re_buf;
} t_game;

int main_loop(t_game *game);

#endif
