struct game
{
	char **board;
	int r, c, p;
	char p1;
	char p2;
};

bool is_valid_arguments(char **);
void set_game_info(game *, char **);
char** create_table(int, int);
void play_game(game *);
bool check_winner(game);
void delete_table(game *);