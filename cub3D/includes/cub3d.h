/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:05 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/24 17:12:09 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0

# define WIDTH 1080
# define HEIGHT 720
# define TX_WIDTH 512
# define TX_HEIGHT 512
# define MOVESPEED 0.025
# define ROTSPEED 0.05

//COLORS
# define RED	"\001\033[1;31m\002"
# define GREEN	"\001\033[1;32m\002"
# define YELLOW	"\001\033[1;33m\002"
# define BLUE	"\001\033[1;34m\002"
# define PURPLE	"\001\033[1;95m\002"
# define CYAN	"\001\033[1;36m\002"
# define WHITE	"\001\033[1;37m\002"
# define END	"\001\033[0m\002"

typedef struct s_data	t_data;
typedef struct s_game	t_game;
typedef struct s_pj		t_pj;
typedef struct s_ray	t_ray;

struct s_data
{
	char	**doc;
	char	**map;
	int		map_lines;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	char	*f_color;
	char	*c_color;
	int		total_line;
	int		ceiling;
	int		floor;
	int		moved;
	int		win_width;
	int		win_height;
	t_game	*game;
	t_pj	*pj;
};

struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tx_hit;
	mlx_texture_t	*tx_north;
	mlx_texture_t	*tx_south;
	mlx_texture_t	*tx_east;
	mlx_texture_t	*tx_west;
	mlx_texture_t	*tx_door;
	mlx_texture_t	*tx_kart;
	mlx_image_t		*im_north;
	mlx_image_t		*im_south;
	mlx_image_t		*im_east;
	mlx_image_t		*im_west;
	mlx_image_t		*im_door;
	mlx_image_t		*im_kart;
	mlx_texture_t	*icon;
};

struct s_pj
{
	double	pos_x;
	double	pos_y;
	char	view;
	int		angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
	int		rotate;
};

struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		door;
};


//----------- MAIN ------------------
void	free_all(t_data *data);

//----------- GAME ------------------
bool	init_game(t_data *data);
void	init_player_dir(t_data *data);
void	key_pressed(t_data *data, keys_t key);
void	key_released(t_data *data, keys_t key);
void	rotate_player(t_data *data, double rotdir);
void	move_player(t_data *data);


//----------- RENDER ----------------
void	render(void *data);
void	raycast(t_pj *player, t_data *data);
void	render_raycast(t_data *data);
void	update_pixels(t_data *data, t_ray *ray, int x);
bool	has_resized(int win, int new);
void	texture_paint(t_data *data, t_ray *ray, int x, int *y);

//textures
bool	save_textures(t_game *game, t_data *data);
void	free_game_textures(t_game *game);

//images
bool	save_images(t_game *game);
void	free_images(t_game *game);

//----------- PARSE -----------------
bool	check_holes(char **map, int total_line);
bool	extract_color(char **doc, t_data *data);
bool	extract_rgba(t_data *data);
bool	extract_texture(char **doc, t_data *data);
void	free_texture(t_data *data, int tx);
bool	init_parse(t_data *data, char *arg);
bool	parse_map(t_data *data);
void	my_keyhook(mlx_key_data_t keydata, void* param);


//find_rgb
bool	check_str_color(char *color);
char	*find_blue(char *blue, char *color);
char	*find_green(char *green, char *color);
char	*find_red(char *red, char *color);

//----------- ERROR -----------------
void	free_map(t_data *data);
void	free_texture(t_data *data, int tx);
void	print_error(char *text);

#endif