/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:02 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 16:33:12 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3D.h"

/*
(0,0) (0,1) (0,2) ... (0,map.width)
(1,0) (1,1) (1,2) ... (1,map.width)
.
.
.
(h,0) (h,1) (h,2) ... (h,map.width)

1. 일단 쭉 돌면서 0을 찾는다.
2. 0을 찾는 즉시 상 하 좌 우 순으로 무한정 가면서 1을 찾는다.
3. 1을 찾지 못하고 \0을 만나버린 경우 실패로 벽이 뚫린걸로 간주
4. 상 하 좌 우 모두 1을 만났다면 PASS
5. 1을 다시 시작
*/

/*
	예외처리 : height_idx == 0 이라면 return FALSE; -> 위에가 그냥 뚫린경우
	위로 올라가다가 '/0' 만나면 return FALSE
	위로 올라갔는데 0 만나면 continue
	위로 올라갔는데 1 만나면 return TRUE
	좌표에서 0을 찾았을 경우 상 하 좌 우 를 검사한다.
*/

static t_bool check_right(int height_idx, int width_idx, t_game *game)
{
	int h_cur_idx;
	int w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (width_idx == game->map.width - 1)
		return (FALSE);
	w_cur_idx += 1;
	while (w_cur_idx <= game->map.width - 1)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			w_cur_idx += 1;
		else
			w_cur_idx += 1;
	}
	return (FALSE);
}

static t_bool check_left(int height_idx, int width_idx, t_game *game)
{
	int h_cur_idx;
	int w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (width_idx == 0)
		return (FALSE);
	w_cur_idx -= 1;
	while (w_cur_idx >= 0)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			w_cur_idx -= 1;
		else
			w_cur_idx -= 1;
	}
	return (FALSE);
}

static t_bool check_down(int height_idx, int width_idx, t_game *game)
{
	int h_cur_idx;
	int w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (height_idx == game->map.height - 1)
		return (FALSE);
	h_cur_idx += 1;
	while (h_cur_idx <= game->map.height - 1)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			h_cur_idx += 1;
		else
			h_cur_idx += 1;
	}
	return (FALSE);
}

static t_bool check_up(int height_idx, int width_idx, t_game *game)
{
	int h_cur_idx;
	int w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (height_idx == 0)
		return (FALSE);
	h_cur_idx -= 1;
	while (h_cur_idx >= 0)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			h_cur_idx -= 1;
		else
			h_cur_idx -= 1;
	}
	return (FALSE);
}

t_bool check_wall(int height_idx, int width_idx, t_game *game)
{
	if (check_up(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_down(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_left(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_right(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
